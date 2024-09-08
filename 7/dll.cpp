#include <stdio.h>
#include <stdlib.h>

class list{
    struct node{
        struct node *prev;
        int data;
        struct node *next;
    };
    struct node *head;
    public:
    list(){
        head = NULL;
    }
    void insert(int,int);
    void dele(int,int);
    void search(int);
    void display();
    void ptrnode(list &dll);
    
};

void list::insert(int data,int pos){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode -> data = data;
    if (head == NULL){
        newnode -> next = NULL;
        newnode -> prev = NULL;
        head = newnode;
        return;
    }
    else if (pos == 1){
        newnode -> next = head -> next;
        newnode -> prev = NULL;
        head = newnode;
        return;
    }
    else{
        struct node *temp = head;
        for (int i=1;i<pos-1 && temp!=NULL;i++){
            temp = temp -> next;
        } 
        if (temp == NULL){
            printf("The position is out of bounds!!\n");
            return;
        }
        else{
            newnode -> next = temp -> next;
            newnode -> prev = temp;
            temp -> next = newnode;
            return;
        }
    }
}
void list::dele(int data,int bol){
    if(head == NULL){
        printf("THE LIST IS EMPTY.\n");
        return;
    }
    else{
        struct node *temp = head;
        struct node *temp1 ;
        if (bol == 0){
            if (head -> data == data){
                if (head -> next == NULL){
                    head = NULL;
                    printf("DELETION SUCCESSFULL.\n");
                    return;
                }
                else{
                    head = head -> next;
                    head -> prev = NULL;
                    printf("DELETION SUCCESSFULL.\n");
                    return;
                }
            }
            else{
                while (temp != NULL){   
                    if (temp -> data == data){
                        temp1 = temp -> prev;
                        temp1 -> next = temp -> next;
                        if (temp -> next != NULL){
                            temp -> next -> prev = temp1;
                        }     
                        printf("DELETION SUCCESSFULL.\n");
                        return;
                    }
                    temp=temp->next; 
                }
            }
            printf("The element is not found!!!\n");
            return;
        }
        else if(bol==1){
            int i = 0;
            while (temp != NULL) {
                if (head->data == data) {
                    if (head->next == NULL) {
                        head = NULL;
                    } 
                    else {
                        head = head->next;
                        head->prev = NULL;
                    }
                    i++;
                    printf("DELETION SUCCESSFUL %d.\n", i);
                    temp = head; 
                } 
                else if (temp->data == data) {
                    temp1 = temp->prev;
                    temp1->next = temp->next;
                    if (temp->next != NULL) {
                        temp->next->prev = temp1;
                    }
                    temp = temp->next; 
                    i++;
                    printf("DELETION SUCCESSFUL %d.\n", i);
                } 
                else {
                    temp = temp->next;
                }
            }
            if (i < 1) {
                printf("The element is not found!!!\n");
            }
            return;
        }

    }
}
void list::search(int data){
    struct node *temp = head;
    if (head == NULL){
        printf("The list is empty!!!\n");
        return;
    }
    else{
        for (int i=1;temp != NULL;i++){
            if (temp -> data == data){
                printf("The number is found at position %d\n",i);
                return;
            }
            temp = temp -> next;
        }
        printf("The number is not found!!!\n");
        return;
    }
}
void list::display(){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    if (head == NULL){
        printf("The list is empty.\n");
        return;
    }
    else{
        temp = head;
        printf("NULL ");
        while(temp != NULL){
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
        printf("NULL\n");
        return;
    }
}

void list::ptrnode(list &dll){
    struct node *ptr = head;
    int ptrch,data;
    if (ptr == NULL){
        printf("THE LIST IS EMPTY OR YOU HAVE REACHED THE END OF THE LIST.\n");
        return;
    }
    else{
        do{
                    printf("THE DATA OF THE CURRENT POINTER IS %d\n",ptr->data);
                    printf("The address of the ptr is %p\n",ptr);
                    printf("POINTER MENU:\n");
                    printf("1.LEFT\n2.RIGHT\n3.DELETE\n4.MODIFY\n5.EXIT POINTER NODE\n");
                    scanf("%d",&ptrch);
                    switch (ptrch){
                        case 1:
                            printf("MOVE LEFT:\n");
                            if (ptr -> prev == NULL){
                                printf("YOU ARE AT THE BEGINNING OF THE LIST CANNOT MOVE LEFT!!\n");
                            }
                            else{
                                ptr = ptr -> prev;
                            }
                            break;
                        case 2:
                            printf("MOVE RIGHT:\n");
                            if (ptr -> next == NULL){
                                printf("YOU ARE AT THE END OF THE LIST CANNOT MOVE RIGHT!!\n");
                            }
                            else{
                                ptr = ptr -> next;
                            }
                            break;
                        case 3:
                            printf("DELETE:\n");
                            if(ptr == head){ 
                                head = ptr->next;
                                if(head != NULL){
                                    head->prev = NULL;
                                }
                            }
                            else{
                                if(ptr->prev != NULL){
                                    ptr->prev->next = ptr->next;
                                }
                                if(ptr->next != NULL){
                                    ptr->next->prev = ptr->prev;
                                }
                            }
                            if(ptr->next != NULL){
                                ptr = ptr->next;
                            }
                            else if(ptr->prev != NULL){
                                ptr = ptr->prev;
                            }
                            else{
                                ptr = NULL;
                            }
                            printf("Node deleted.\n");
                            dll.display();
                            break;
                        case 4:
                            printf("MODIFY THE CURRENT NODE:\n");
                            printf("Enter the data to replace node data with: ");
                            scanf("%d",&data);
                            ptr -> data = data;
                            dll.display();
                            break;
                        case 5:
                            printf("EXIT\n");
                            break;
                        default:
                            printf("INVALID input!!!");
                            break;
                    }                   
                }while (ptrch != 5);
    }
}

int main(){
    list dll;
    int data,pos,ch,ch2,bol;
    do{
        printf("MAIN MENU: \n");
        printf("1.INSERT\n2.DELETE\n3.SEARCH\n4.DISPLAY\n5.ENTER POINTER NODE\n6.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                printf("INSERTION:\n");
                printf("Enter the number and position to enter the data: ");
                scanf("%d %d",&data,&pos);
                dll.insert(data,pos);
                break;
            case 2:
                printf("DELETION:\n");
                printf("Enter the number to delete the value: ");
                scanf("%d",&data);
                printf("Enter 1 if you want to delete all values of data or 0 for the first occurence: ");
                scanf("%d",&bol);
                dll.dele(data,bol);
                break;
            case 3:
                printf("SEARCH:\n");
                printf("Enter the number to search : ");
                scanf("%d",&data);
                dll.search(data);
                break;
            case 4:
                printf("DISPLAY:\n");
                dll.display();
                break;
            case 5:
                printf("POINTER NODE:\n");
                dll.ptrnode(dll);
                break;
            case 6:
                printf("Exiting program!!!!!!\n");
                break;
            default:
                printf("INVALID INPUT!!!!\n");
        }
    }while (ch != 6);
}
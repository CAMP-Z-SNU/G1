#include <stdio.h>
#include <stdlib.h>

class list{
    struct node{
        int data;
        struct node* next;
        struct node* prev;
    };
    public:
    struct node* head;
    list(){
        head = NULL;
    }
    void insertion(int data, int position);
    void deletion(int data);
    void display();
    int searchNode(int data);
    void pointerMode(list &L);
};

int curPos = 0;

int main(){
    list L;
    int choice, data, position;
    int duplicates;
    struct node* head = (struct node*)malloc(sizeof(struct node*));
    do{
        printf("\nenter \n1 for insertion(0 index based)");
        printf("\n2 for deletion");
        printf("\n3 for display list");
        printf("\n4 for search node");
        printf("\n5 to enter pointer mode");
        printf("\n6 to exit\n");

        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("enter data: ");
                scanf("%d",&data);
                printf("enter position: ");
                scanf("%d",&position);
                L.insertion(data, position);
                break;
            case 2:
                printf("enter data: ");
                scanf("%d",&data);
                printf("enter 0 to delete single and 1 to delete all duplicates: ");
                scanf("%d",&duplicates);
                if(duplicates==0){
                    L.deletion(data);
                }else if(duplicates==1){
                    do{
                    L.deletion(data);
                    }while(L.searchNode(data)!=0);
                }else{
                    printf("Invalid input");
                }
                break;
            case 3:
                L.display();
                break;
            case 4:
                printf("enter data: ");
                scanf("%d",data);
                if(L.searchNode(data)==1){
                    printf("Present");
                }else{
                    printf("Absent");
                }
                break;
            case 5:
                printf("Welcome to pointer node!!");
                L.pointerMode(L);
                break;
            case 6:
                printf("Thank You");
                return 0;
            default:
                printf("invalid input");
                break;
        }

    }while(choice!=6);
}

void list::insertion(int data, int position){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = head;
    newnode->data=data;
    newnode->next=NULL;
    newnode->prev=NULL;
    if(position==0){
        newnode->next=head;
        if(head != NULL){
            head->prev=newnode;
        }
        head=newnode;
    }else{
        for(int i=0;i<position-1;i++){
            temp=temp->next;
        }if(temp!=NULL){
            newnode->next=temp->next;
            if(temp->next != NULL){
                temp->next->prev = newnode;
            }
            temp->next=newnode;
            newnode->prev=temp;
        }else{
            printf("out of boundary");
        }
    } //free(newnode);
}

void list::deletion(int data){
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        struct node* temp1 = head;
        struct node* temp2 = head;

        while(temp1->data != data){
            temp1=temp1->next;
            curPos++;
        }
        for(int i=0;i<curPos-1;i++){
            temp2=temp2->next;
        }
        temp2->next=temp2->next->next;
        temp2->prev=temp1->prev;
    }
}

void list::display(){
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        struct node* temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int list::searchNode(int data){
    struct node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

void list::pointerMode(list &L){ 
    int pointerChoice;
    struct node* ptr = head;
    do{
        if(ptr == NULL){
            printf("\nList is empty or you have reached the end of the list.\n");
            return;
        }

        printf("\nYou are at node with data: %d\n", ptr->data);
        printf("Address of current node: %p", ptr);
        printf("\nEnter:\n1 to move left (prev)\n2 to move right (next)\n3 to delete current node\n4 to modify current node\n5 to exit pointer mode\n");
        scanf("%d", &pointerChoice);

        switch(pointerChoice){
            case 1:
                if(ptr->prev == NULL){
                    printf("Already at the leftmost node (NULL)\n");
                }else{
                    ptr = ptr->prev;
                    printf("Moved left. Current data: %d\n", ptr->data);
                }
                break;
            case 2:
                if(ptr->next == NULL){
                    printf("Already at the rightmost node (NULL)\n");
                }else{
                    ptr = ptr->next;
                    printf("Moved right. Current data: %d\n", ptr->data);
                }
                break;
            case 3:
                if(ptr == head){ 
                    head = ptr->next;
                    if(head != NULL){
                        head->prev = NULL;
                    }
                }else{
                    if(ptr->prev != NULL){
                        ptr->prev->next = ptr->next;
                    }
                    if(ptr->next != NULL){
                        ptr->next->prev = ptr->prev;
                    }
                }
                struct node* temp = ptr; 
                if(ptr->next != NULL){
                    ptr = ptr->next;
                }else if(ptr->prev != NULL){
                    ptr = ptr->prev;
                }else{
                    ptr = NULL;
                }
                free(temp);
                printf("Node deleted.\n");
                L.display();
                break;
            case 4:  //
                int modifyData;
                printf("Enter new data: ");
                scanf("%d", &modifyData);
                ptr->data = modifyData;
                L.display();
                break;
            case 5:
                printf("Exiting pointer mode...\n");
                break;
            default:
                printf("Invalid input. Try again.\n");
        }

    } while(pointerChoice != 5 && ptr != NULL);
}

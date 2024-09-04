#include<stdio.h>
#include<stdlib.h>

class list{
    struct node{
        int data;
        struct node *next;
    };
    struct node *head;
public:
    list(){
        head = NULL;
    }
    void insert(int,int);
    int dele(int);
    void display();
    void search(int);
};

int main(){
    int data,pos,del,ch;
    list l;
    do{
        printf("________MAIN MENU:_________\n");
        printf("1.INSERTION\n2.DELETION\n3.DISPLAY\n4.SEARCH\n5.EXIT\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch (ch){
        case 1:
            printf("Insertion:\n");
            printf("Enter the value to be inserted: ");
            scanf("%d",&data);
            printf("Enter the position to insert data: ");
            scanf("%d",&pos);
            l.insert(data,pos);
            break;
        case 2:
            printf("DELETION:\n");
            printf("Enter the position to delete the data: ");
            scanf("%d",&pos);
            del = l.dele(pos);
            if (del != 0){
                printf("The deleted number is %d\n",del);
            }
            break;
        case 3:
            printf("DISPLAY :\n");
            l.display();
            break;
        case 4:
            printf("SEARCH : \n");
            printf("Enter the data to search: ");
            scanf("%d",&data);
            l.search(data);
            break;
        case 5:
            printf("EXITING CODE!!!");
            break;
        default:
            printf("INVALID CHOICE!!!!!\n");
        }
    }while(ch!=5);
}

void list::insert(int data,int pos){
    struct node *temp = head;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = data;
    newnode -> next = NULL;
    if (pos == 1){
        newnode -> next = NULL;
        head = newnode;
        return;
    }
    else{
        for (int i=1; i<pos-1 && temp != NULL; i++){
            temp = temp -> next;
        }
        if (temp == NULL){
            printf("The position is out of bounds!!\n");
            return;
        }
        else{
            newnode -> next = temp -> next;
            temp -> next = newnode;
            return;
        }
    }
}

int list::dele(int pos){
    int d;
    struct node *temp = head;
    if (head == NULL){
        printf("The list is empty!!!\n");
        return 0;
    }
    else if (pos == 1){
        d = head -> data;
        head = head -> next;
        return d;
    }
    else{
        for (int i=1; i < pos-1 && temp != NULL; i++){
            temp = temp -> next;
        }
        if (temp == NULL||temp -> next == NULL){
            printf("The postion is out of bounds!!!\n");
            return 0;
        }
        else{
            d=temp->next->data;
            temp -> next = temp -> next -> next;
            return d;
        }
    }
}

void list::display(){
    struct node *temp = head;
    if (head == NULL){
        printf("The list is empty!!!\n");
        return;
    }
    else{
        while(temp != NULL){
            printf("%d ",temp -> data);
            temp = temp -> next;
        }
        printf("NULL\n");
        return;
    }
}

void list::search(int data){
    struct node *temp = head;
    int p = 0;
    if (head == NULL){
        printf("The list is empty!!!\n");
        return;
    }
    else{
        while(temp != NULL){
            p+=1;
            if (temp -> data == data){
                printf("The data found at position %d\n",p);
                return;
            }
            temp = temp -> next;
        }
        printf("The data is not found!!!!\n");
        return;
    }
}
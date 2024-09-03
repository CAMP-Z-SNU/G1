#include <stdio.h>
#include <stdlib.h>

class list{
    struct Node{
        int data;
        struct Node* next;
    };
    struct Node* head;
    public:
        list(){
            head = NULL;
        }
        void insertAtPos(int position, int data);
        void deleteAtPos(int position);
        void searchNode(int data);
        void printList();
};

int main(){
    list L;
    int choice, position, data;
    while(choice!=5){
        printf("enter \n1.insertion at a postion\n2.deletion at a position");
        printf("\n3.search a Node\n4.print list\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("\nenter the position at which data to be inserted: ");
                scanf("%d",&position);
                printf("\nenter data to be inserted: ");
                scanf("%d",&data);
                L.insertAtPos(position, data);
                break;
            case 2:
                printf("\nenter the position at which data to be deleted: ");
                scanf("%d",&position);
                L.deleteAtPos(position);
                break;
            case 3:
                printf("\nenter data to be searched: ");
                scanf("%d",data);
                L.searchNode(data);
                break;
            case 4:
                L.printList();
                break;
            default:
                printf("Invalid choice");
        }
    }
    return 0;
}

void list::insertAtPos(int position, int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node*));
    newnode->data=data;
    newnode->next=NULL;
    if(position==1){
        newnode->next=head;
        head = newnode;
    }
    else{
        struct Node* temp = head;
        for(int i=0;i<position-1;i++){
            temp=temp->next;
        }
        if(temp!=NULL){
           newnode->next = temp->next;
            temp->next = newnode;
        } else {
            printf("Position is out of boundry\n");
            free(newnode); 
        }
    }

}

void list::deleteAtPos(int position){
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    if (position == 1) {
        head = head->next;
        free(temp);
    } else {
        struct Node* prev = NULL;
        for (int i = 1; i < position && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Position out of bounds\n");
        } else {
            prev->next = temp->next;
            free(temp);
        }
    }
}

void list::searchNode(int data){
    struct Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            printf("\nPresent\n");
            return;
        }
        temp = temp->next;
    }
    printf("Not found\n");
}

void list::printList(){
    if (head == NULL) {
        printf("\nList is empty\n");
    } else {
        struct Node* temp = head;
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
#include<stdio.h>
#include<stdlib.h>
//declaring a clas//
class list{
    struct Node{
    int val;
    struct Node* next;
    
};
//making members public//
public:
    struct Node* head=NULL;
    struct Node* create(int val);
    void insert(int pos,int val);
    void deletenode(int pos);
    void search(int val);
    void print();
};

//functon to create a node//
struct list::Node* list::create(int val){
    struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
    new_node->data=val;
    new_node->next=NULL;
    return new_node;
}
//to insert at a specified position//
void list::insert(struct Node *head,int pos,int val){
    int pos;
    printf("Enter the position:");
    scanf("%d",&pos);
    
    struct Node* temp=head;
    if(pos==1){
        new_node->next=head;
        return new_node;
    }
    for(int i=1;i<pos-1;i++){
        struct Node* new_node=create(val);
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;
    return new_node;

}
//to delete node of specific position//
int list::deletenode(struct Node* head,int pos){
    struct Node* temp=head;
    for(int i=1;i<pos-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    temp->next=temp->next->next;
    free(temp);
}
//to search node//
void list::search(struct Node* head,int val){
    struct Node* temp=head;
    int val;
    printf("enter value to search:");
    scanf("%d",&val);
    while(temp!=NULL){
        if(temp->data==val){
            printf("VALUE FOUND");
        }
        else{
            printf("VALUE NOT FOUND");
        }
    }
 }

//to display linked list//
 void list::display(struct Node* head){
    struct Node* temp=head;
    while(temp!=NULL){
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
 }
 //main function//
int main(){
    printf("1-INSERT\n 2-DELETE \n 3-DISPLAY \n 4-SEARCH \n 5-PRINT\n");
    int ch;
    printf("Enter your choice:");
    scanf("%d",&ch);
    int element1;int element2;int element3;int element4;
        
        printf("create a list first");
        printf("\n");
        printf("enter 1st element:");
        scanf("%d",&element1);
        struct Node* head=create(element1);
        printf("enter 2nd element:");
        scanf("%d",&element2);
        head->next=create(element2);
        printf("enter 3rd element:");
        scanf("%d",&element3);
        head->next->next=create(element3);
        printf("enter 4th element:");
        scanf("%d",&element4);
        head->next->next->next=create(element4);
    switch(choice){
        case 1:
            head=insert(head,int val,int pos);
            break;
        case 2:
            delete(head,int pos);
            break;
        case 3:
            search(head,int val);
            break;
        case 4:
            display(head);
            break;
        default:

        

    }
}
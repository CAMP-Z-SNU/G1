#include<stdio.h>
#include<stdlib.h>
class list{
    struct Node{
        int val;
        struct Node* next;
        struct Node* prev;
    };
struct Node* head;
public:
    list()
{
    head=NULL;
}
void insertbeg(int);
void insertend(int);
void insertpos(int,int);
void deletebeg();
void deleteend();
void deletepos(int);
void search(int);
void display();
void pointermode(list &L)
};

void list::create(int val){
    struct Node* new_node=(struct Node)malloc(sizeof(struct Node));
    new_node->prev=NULL;
    new_node->data=val;
    new_node->next=NULL;
    return new_node;
}

void list::insertbeg(int val){
    struct Node* new_node=create(val);
    if(head==NULL){
        new_node->next=NULL;
        head=new_node;
        return;
    }
    new_node->next=head;
    head->prev=new_node;
    head=new_node;
}

void list::insertend(int num){
    struct Node* new_node=create(val);
    if(head==NULL){
        head=new_node;
        new_node->next=NULL;
    }
    strucy Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
        
    }
    temp->next=new_node;
    new_node->prev=temp;
    new_node->next=NULL;
}

void list::insertpos(int pos,int val){
    int pos;int i;
    printf("Enter a position to enter:");
    scanf("%d",&pos);
    struct Node* new_node=create(val);
    strucy Node* temp=head;
    struct Node* temp2;
    pos=pos-1;
    for(int i=1;i<pos &&temp!=NULL;i++){
        temp=temp->next;
    }
    temp2=temp->next;
    temp->next=new_node;
    new_node->prev=temp;
    new_node->next=temp2;
    temp2->prev=new_node;
    
}

void list::deletebeg(){
    if(head==NULL){
        printf("LIST IS EMPTY");
    }
    else{
        head=head->next;
        head->prev=NULL;
        return;
    }
}

void list::deleteend(){
    if(head==NULL){
        printf("LIST IS EMPTY");
    }
    struct Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=NULL;
    temp->next->prev=NULL;
    return;
}

void list::deletepos(int pos){
    struct Node* temp=head;
    if(temp==NULL){
        printf("LIST IS EMPTY")
    }
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    if(temp->prev!=NULL){
        temp->next=new_node;
        new_node->prev=temp;
        new_node->next=temp->next->next;
        temp->next->next->prev=new_node;
        return;
    }


}

void list::search(int val){
    struct Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        temp=temp->next;
    }
    if(temp->data==val){
        printf("Element found");
    }

}

void list::display(){
    struct Node* curr=head;
    while(curr!=NULL && curr->next!=NULL){
        printf(curr->data);
        curr=curr->next;
    }
}

void list::pointermode(list &L){ 
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


int main()
{
    list l1;
    int choice,data,pos,pos1,data1,data2,data3,data4,data5;val;
    while(1)
    {
        printf("\n1.Insert Begining\n2.Insert Position\n3.Insert End\n");
        printf("4.Delete Begining\n5.Delete Position\n6.Delete End\n");
        printf("7.Display\n8.Search\n9.Pointer Mode\n10.Exit\n");
        printf("Enter a choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the data to be inserted:");
                scanf("%d",&data);
                l1.insertbeg(data);
                break;
            case 2:
                printf("Enter the data to be inserted:");
                scanf("%d",&data1);
                l1.insertend(data1);
                break;
            case 3:
                printf("Enter the data to be inserted:");
                scanf("%d",&data2);
                printf("Enter the pos to be inserted:");
                scanf("%d",&pos);
                l1.insertpos(pos,data2);
                break;
            case 4:
                l1.deletebeg();
                break;
            case 5:
                l1.deleteend();
                break;
            case 6:
                l1.deletepos();
                break;
            case 8:
                printf("Enter the data to be searched:");
                scanf("%d",&data3);
                l1.search(data3)
                break;
            case 7:
                l1.Display();
                break;
            case 9:
                l1.pointermode(l1);
            default:
                printf("\nInvalid Choice. Try Again!");
        }
    }
}
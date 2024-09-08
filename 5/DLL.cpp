#include<stdio.h>
#include<stdlib.h>
class dll{
    struct node{
        int data;
        struct node *prev;
        struct node *next;
    }*head;
    public:
    dll(){

         head=NULL;
    }
    void InsertionPos(int,int);
    void Search(int);
    void Display();
    void DeleteNum(int,int);
    void PointerNode(dll &l1);
};
int main(){
    dll l1;
    int data,choice;
    while(1){
        printf("\n1.Insertion at position\n2.Display.\n3.Search.\n4.Delete a number.\n");
        printf("5.temporary pointer node.\n6.Exit.\n");
        printf("Enter the choice:");
        scanf("%d",&choice);
        switch(choice){
            case 1:{
                int pos;
                printf("Enter the position to be inserted:");
                scanf("%d",&pos);
                printf("Enter the data to be inserted:");
                scanf("%d",&data);
                l1.InsertionPos(pos,data);
                break;
            }
            case 2:{
                l1.Display();
                break;
            }
            case 3:{
                int num;
                printf("Enter the number to be searched:");
                scanf("%d",&num);
                l1.Search(num);
                break;
            }
            case 4:{
                int val,num;
                printf("Enter either a zero or one:");
                scanf("%d",&val);
            if(val==0 || val==1){
                printf("Enter the number to deleted:");
                scanf("%d",&num);
                l1.DeleteNum(num,val);
                break;}
            else{
                printf("Enter the correct value.");
                return 0;
            }
            break;
            }
            case 5:{
                printf("\nEntering Pointer node.\n");
                l1.PointerNode(l1);
                break;
            }
            case 6:{
                printf("Exiting the program.\n");
                return 0;
            }
            default:
                printf("Invalid choice. Please try again.");
                return 0;  
        }
    }
}
void dll::InsertionPos(int pos,int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(pos==1){
        if(head==NULL){
            head=newnode;
            return;
        }
        else{
            head->prev=newnode;
            newnode->next=head;
            head=newnode;
            return;
        }
    }
    else {
        struct node *temp=head;
        struct node *temp2;
        pos--;
        while( pos!=1 && temp ){
            temp=temp->next;
            pos--;
        }
 
         if(  (temp == nullptr)){
            printf("Position is out of the bound.\n");
            return;
        }
        if(temp->next==NULL){
            temp->next=newnode;
            newnode->prev=temp;
            return;
        }
       
        else{
        temp2=temp->next;
        temp->next=newnode;
        newnode->prev=temp;
        newnode->next=temp2;
        temp2->prev=newnode;
        }
    }
}
void dll::Display()
{
    struct node *temp=head;
    if(head==NULL){
        printf("The list is empty.\n");
        return;
    }
    while(temp->next!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }printf("%d",temp->data);
}
void dll::Search(int num){
    struct node *temp=head;
    int k=1;
    int count=0;
    if(head==NULL){
        printf("The list is empty.\n");
        return;
    }
    while(temp!=NULL){
        if(temp->data==num){
            printf("The element %d is found at index %d.\n",num,count);
            temp=temp->next;
            count++;
            k=0;
        }
        else{
            temp=temp->next;
            count++;
        }
    }
    if(k==1){
        printf("The element is not present in the list.");
        return;
    }
}
void dll::DeleteNum(int num,int val)
{
    struct node *temp=head;
    if(head==NULL){
        printf("The list is empty.");
        return;
    }
    if(temp->next==NULL&&temp->prev==NULL){
         if(temp->data==num){
            free(head);
            head=NULL;
            return;
         }
        else{
           printf("The element is not present in the linked list.\n");
           return;
        }
     }  
    if(val==0){
        while(temp!=NULL&&temp->data!=num){
            temp=temp->next;
        }
          if(temp==NULL){
            printf("The element is not present in the linked list.\n");
            return;
        }
        if(temp->data==num&&temp->prev==NULL){
            head=temp->next;
            head->prev=NULL;
            temp->next=NULL;
            free(temp);
            temp=NULL;
            return;
        }
        if(temp->data==num&&temp->next!=NULL){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            temp->prev=NULL;
            temp->next=NULL;
            free(temp);
            temp=NULL;
            printf("The element %d is deleted from the linked list.",num);
            return;
        }
        if(temp->data==num&&temp->next==NULL){
            temp->prev->next=NULL;
            temp->prev=NULL;
            free(temp);
            temp=NULL;
            printf("The element %d is deleted from the linked list.",num);
            return;
        }

    }
    else{
        struct node *temp2;
        int k = 0, count = 0;

        while (temp != NULL) {

            while (temp != NULL && temp->data != num) {
                temp = temp->next;
                count++;
                }
            if(temp!=NULL && temp->data==num && temp->prev==NULL){
                head=temp->next;
                if(head!=NULL){
                head->prev=NULL;}
                temp2=temp;
                temp=temp->next;
                  free(temp2);
                temp2=NULL;
                printf("The element %d is deleted from the index %d in the linked list.\n", num, count);
                count++;
                k=1;
            }

            else if (temp != NULL && temp->data == num && temp->next != NULL) {
                 temp2 = temp->next;
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                temp->prev = NULL;
                temp->next = NULL;
                free(temp);
                temp = temp2;
                printf("The element %d is deleted from the index %d in the linked list.\n", num, count);
                k = 1;
                count++;
                }
            else if (temp != NULL && temp->data == num && temp->next == NULL) {
                 temp->prev->next = NULL;
                temp->prev = NULL;
                free(temp);
                temp = NULL;
                printf("The element %d is deleted from the index %d in the linked list.\n", num, count);
                k = 1;
                } 
            else {
                 break;
                }
        }
        if (k == 0) {
            printf("The element is not present in the linked list.\n");
            return;
        }
    }
}
void dll::PointerNode(dll &l1)
{
    int ch;
    struct node *ptr=head;
    printf("\nYou are at the head currently.\n");
    while(1){

        if(ptr == NULL){
            printf("\nList is empty .\n");
            return;
        }
        
        printf("\nEnter:\n1 to  left shift.\n2 to Right shift.\n3 to delete current node.\n4 to modify current node.\n5 to exit pointer mode.\n");
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch(ch) {
             case 1:
                if(ptr->prev == NULL){
                    printf("Already at the leftmost node . cannot move further.\n");
                }else{
                    ptr = ptr->prev;
                    printf("Moved left. Current data: %d\n", ptr->data);
                }
                break;
            case 2:
                if(ptr->next == NULL){
                    printf("Already at the rightmost node . Cannot move further.\n");
                }else{
                    ptr = ptr->next;
                    printf("Moved right. Current data: %d\n", ptr->data);
                }
                break;
            case 3:
                struct node*temp;
                if(ptr==head){
                    if(ptr->next==NULL){
                        free(head);
                        head=NULL;
                        
                    }
                    else{
                        temp=head;
                        head=temp->next;
                        head->prev=NULL;
                        temp->next=NULL;
                        free(temp);
                        temp=NULL;
                        
                    }
                
                } 
                if(ptr->next==NULL){
                        temp=ptr;
                        temp->prev->next=NULL;
                        ptr=temp->prev;
                        temp->prev=NULL;
                        
                        free(temp);
                        temp=NULL;

                }
                else {

                
                temp=ptr;
                temp->prev->next=temp->next;
                temp->next->prev=temp->prev;
                ptr=temp->next;
                temp->prev=NULL;
                temp->next=NULL;
                free(temp);
                temp=NULL;
                }
                l1.Display();
                break;
            case 4:  
                int newData;
                printf("Enter new data: ");
                scanf("%d", &newData);
                ptr->data = newData;
                l1.Display();
                break;
            case 5:
                printf("Exiting pointer mode...\n");
                return ;
            default:
                printf("Invalid input. Try again.\n");
                return;
        }
       
    }

}
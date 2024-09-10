#include <stdio.h>
#include <stdlib.h>

class beg {
    struct node {
        int data;
        struct node *prev, *next;
    } *head;

public:
    beg() { head = NULL; }

    void InsertionPos(int, int);
    void Search(int);
    void Display();
    void DeleteNum(int, int);
    void PointerNode(beg &l1);
};

int main() {
    beg l1;
    int data, choice;

    while (1) {
        printf("\n1. Insertion at position\n2. Display\n3. Search\n4. Delete a number\n");
        printf("5. Pointer node\n6. Exit\nEnter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int pos;
                printf("Enter the position: ");
                scanf("%d", &pos);
                printf("Enter the data: ");
                scanf("%d", &data);
                l1.InsertionPos(pos, data);
                break;
            }
            case 2:
                l1.Display();
                break;
            case 3: {
                int num;
                printf("Enter the number to search: ");
                scanf("%d", &num);
                l1.Search(num);
                break;
            }
            case 4: {
                int val, num;
                printf("Enter 0 or 1 for deletion: ");
                scanf("%d", &val);
                if (val == 0 || val == 1) {
                    printf("Enter the number to delete: ");
                    scanf("%d", &num);
                    l1.DeleteNum(num, val);
                } else {
                    printf("Enter a valid value.\n");
                }
                break;
            }
            case 5:
                printf("Pointer mode\n");
                l1.PointerNode(l1);
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Exiting...\n");
                return 0;
        }
    }
}

void beg::InsertionPos(int pos, int data) {
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->prev = newnode->next = NULL;

    if (pos == 1) {
        if (head == NULL) {
            head = newnode;
        } else {
            newnode->next = head;
            head->prev = newnode;
            head = newnode;
        }
        return;
    }

    node *temp = head;
    while (--pos > 1 && temp) temp = temp->next;

    if (temp == NULL) {
        printf("Position out of bounds.\n");
        free(newnode);
        return;
    }

    newnode->next = temp->next;
    if (temp->next) temp->next->prev = newnode;
    temp->next = newnode;
    newnode->prev = temp;
}

void beg::Display() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    for (node *temp = head; temp != NULL; temp = temp->next)
        printf("%d ", temp->data);
    printf("\n");
}

void beg::Search(int num) {
    node *temp = head;
    int index = 0, found = 0;

    while (temp) {
        if (temp->data == num) {
            printf("Element %d found at index %d.\n", num, index);
            found = 1;
        }
        temp = temp->next;
        index++;
    }

    if (!found) printf("Element not found.\n");
}

void beg::DeleteNum(int num, int val) {
    node *temp = head;

    while (temp) {
        if (temp->data == num) {
            if (temp == head) {
                head = temp->next;
                if (head) head->prev = NULL;
            } else {
                if (temp->prev) temp->prev->next = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
            }
            node *toDelete = temp;
            temp = temp->next;
            free(toDelete);

            printf("Deleted element %d\n", num);
            if (val == 0) break;  // Delete first occurrence if val == 0
        } else {
            temp = temp->next;
        }
    }

    if (temp == NULL) printf("Element not found in the list.\n");
}

void beg::PointerNode(beg &l1) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    node *ptr = head;
    int choice;

    while (1) {
        printf("\n1. Left shift\n2. Right shift\n3. Delete current node\n4. Modify current node\n5. Exit pointer mode\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (ptr->prev) {
                    ptr = ptr->prev;
                    printf("Moved left. Current data: %d\n", ptr->data);
                } else {
                    printf("Already at the leftmost node.\n");
                }
                break;
            case 2:
                if (ptr->next) {
                    ptr = ptr->next;
                    printf("Moved right. Current data: %d\n", ptr->data);
                } else {
                    printf("Already at the rightmost node.\n");
                }
                break;
            case 3:
                if (ptr == head) {
                    if (head->next == NULL) {
                        free(head);
                        head = NULL;
                    } else {
                        head = ptr->next;
                        head->prev = NULL;
                        free(ptr);
                    }
                } else {
                    node *temp = ptr;
                    if (ptr->next) ptr->next->prev = ptr->prev;
                    ptr->prev->next = ptr->next;
                    ptr = ptr->next ? ptr->next : ptr->prev;
                    free(temp);
                }
                l1.Display();
                break;
            case 4: {
                int newData;
                printf("Enter new data: ");
                scanf("%d", &newData);
                ptr->data = newData;
                l1.Display();
                break;
            }
            case 5:
                printf("Exiting pointer mode.\n");
                return;
            default:
                printf("Invalid input.\n");
        }
    }
}

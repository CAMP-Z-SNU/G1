#include <stdio.h>

void forloop(int num);
int recursion(int num);

int main() {
    int num, choice;
    do {
        printf("Enter num for printing Fibonacci series: ");
        scanf("%d", &num);
        printf("Enter \n1 for loop method\n2 for recursion method\n3 for exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                forloop(num);
                break;
            case 2:
                for (int i = 0; i < num; i++) {
                    printf("%d ", recursion(i));
                }
                printf("\n");
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!!\n");
        }
    } while (choice != 3);
    
    return 0;
}

void forloop(int num) {
    int term1 = 0, term2 = 1, nextTerm;
    printf("%d ", term1);
    for (int i = 1; i < num; ++i) {
        printf("%d ", term2);
        nextTerm = term1 + term2;
        term1 = term2;
        term2 = nextTerm;
    }
    printf("\n");
}

int recursion(int num) {
    if (num <= 1){
        return num;
    }
    return recursion(num - 1) + recursion(num - 2);
}

#include<stdio.h>

int current, previous, fibonacci=0;
void iterativeMethod(int num){
    if (num < 2){
        printf("%d ", num);
        return;
    }
    else{
        previous = 0;
        current = 1;
        for (int i=2; i<=num; i++){
            fibonacci = previous + current;
            previous = current;
            current = fibonacci;
        }
        printf("%d ", fibonacci);
        return;
    }
}

int recursiveMethod(int n, int memory[]){
    if (n < 2){
        return n;
    }
    if (memory[n] != -1){
        return memory[n];
    }
    memory[n] = recursiveMethod(n-1, memory) + recursiveMethod(n-2, memory);
    return memory[n];
}

int main(){
    int n, choice, result;
    int memory[100];
    for (int i = 0; i < 100; i++) memory[i] = -1; // Initialize the array

    do{
        printf("Enter the value of n: ");
        scanf("%d", &n);
        printf("MAIN MENU:\n");
        printf("1. Iterative Method\n2. Recursive Method\n3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("Iterative Method:\n");
                for (int i=0; i<n+1; i++){
                    iterativeMethod(i);
                }
                printf("\n");
                break;
            case 2:
                printf("Recursive Method:\n");
                for (int i=0; i<n+1; i++){
                    result = recursiveMethod(i, memory);
                    printf("%d ", result);
                }
                printf("\n");
                break;
            case 3:
                printf("Exiting the program!\n");
                break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
    } while (choice != 3);
    
    return 0;
}

#include<stdio.h>
int currValue, prevValue, fibValue=0;
int main(){
    int number, selection, fibResult;
    int cacheArray[100];
    for (int i = 0; i < 100; i++) cacheArray[i] = -1; // Initialize the array

    do{
        printf("Enter the value of n: ");
        scanf("%d", &number);
        printf("MAIN MENU:\n");
        printf("1. Iterative Method\n2. Recursive Method\n3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &selection);
        switch (selection){
            case 1:
                printf("Iterative Method:\n");
                for (int i=0; i<number+1; i++){
                    iterativeFibonacci(i);
                }
                printf("\n");
                break;
            case 2:
                printf("Recursive Method:\n");
                for (int i=0; i<number+1; i++){
                    fibResult = recursiveFibonacci(i, cacheArray);
                    printf("%d ", fibResult);
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
    } while (selection != 3);

    return 0;
}


void iterativeFibonacci(int count){
    if (count < 2){
        printf("%d ", count);
        return;
    }
    else{
        prevValue = 0;
        currValue = 1;
        for (int i=2; i<=count; i++){
            fibValue = prevValue + currValue;
            prevValue = currValue;
            currValue = fibValue;
        }
        printf("%d ", fibValue);
        return;
    }
}

int recursiveFibonacci(int index, int cache[]){
    if (index < 2){
        return index;
    }
    if (cache[index] != -1){
        return cache[index];
    }
    cache[index] = recursiveFibonacci(index-1, cache) + recursiveFibonacci(index-2, cache);
    return cache[index];
}
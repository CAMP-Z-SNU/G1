
#include <stdio.h>

int fibo(int n, int arr[]) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    if (arr[n] != -1) 
        return arr[n];

   
    arr[n] = fibo(n - 1, arr) + fibo(n - 2, arr);
    return arr[n];
}

void printFib(int n)
{
    if (n < 1) {
        printf("Invalid number of terms\n");
        return;
    }

    int later = 1;
    int prev = 0;

    for (int i = 1; i <= n; i++) {
        if (i > 2) {
            int next = later + prev;
            prev = later;
            later = next;
            printf("%d ", next);
        }

        if (i == 1) {
            printf("%d ", prev);
        }
        if (i == 2) {
            printf("%d ", later);
        }
    }
}

int main()
{
    int n, choice;
    int arr[100];
    for (int i = 0; i < 100; i++) {
        arr[i] = -1;
    }

    printf("1. Fibonacci using loop method.\n2. Fibonacci using Recursion method (with Memoization).\n3. Exit the program.\n");
    printf("Enter the choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            printf("Enter the number of elements in the list: ");
            scanf("%d", &n);
            printFib(n);
            break;
        }
        case 2: {
            printf("Enter the number of terms: ");
            scanf("%d", &n);
            printf("Fibonacci Series: ");
            for (int i = 0; i < n; i++) {
                printf("%d ", fibo(i, arr));
            }
            break;
        }
        case 3: {
            printf("Exiting the program.");
            break;
        }
        default: {
            printf("Enter the correct choice.");
        }
    }
    return 0;
}


#include <stdio.h>

int fibo(int n) {
   if(n == 0)
      return 0;
   else if(n == 1)
      return 1;
   else
      return (fibo(n-1) + fibo(n-2));
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

    int n,choice;
    printf("1.Fibanocci using loop method.\n2. Fibanocci using Recurssion method.\n3.Exit the program.\n");
    printf("Enter the choice:");
    scanf("%d",&choice);
    switch(choice) {
        case 1:{
        printf("Enter the number of elements should be in the list:");
        scanf("%d",&n);
        printFib(n);
         break;
         }
        case 2:{
         int n;
          printf("Enter the number of terms\n");
          scanf("%d", &n);
          printf("Fibonacci Series: ");
          for (int i = 0; i < n; i++) {
            printf("%d ", fibo(i));
            }
         break;}
        case 3:{
         printf("Exiting the program.");
         break;}
        default :{
         printf("Enter the correct choice.");}
    }
    return 0;
}


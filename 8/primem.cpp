#include <stdio.h>
#include<stdlib.h>
int main() {
    int num, i;
    int prime = 1; 

    printf("Enter a number: ");
    scanf("%d", &num);

    for (i = 2; i <= num /2; i++) {  
        if (num % i == 0) {  
            prime = 0;   
            break;         
        }
    }
    if (prime)
        printf("The  number %d is a prime number.\n", num);
    else
        printf("The  number %d is not a prime number.\n", num);

    return 0;
}

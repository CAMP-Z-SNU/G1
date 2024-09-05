#include <stdio.h>
int main() {
    int n, i;
    int prime = 1; 

    printf("Enter a number to check if it's prime or not: ");
    scanf("%d", &n);

    for (i = 2; i <= n / 2; i++) {  
        if (n % i == 0) {  
            prime = 0;   
            break;         
        }
    }
    if (prime)
        printf("The given number %d is a prime number.\n", n);
    else
        printf("The given number %d is not a prime number.\n", n);

    return 0;
}

#include<stdio.h>
#include <math.h>
void CheckPrime(int);
int main() {
    int num;
    printf("Enter the number to be verified:");
    scanf("%d",&num);
    if(num<=1) {
        printf("It is not a prime number.");
    }
    else if(num==2 || num==3){
        printf("The given number is a prime number.");
    }
    else if(num%2==0 || num%3==0) {
        printf("It is not a prime number.");
    }
    else {
        CheckPrime(num);
    }  
    return 0;
}
void CheckPrime(int num) {
    for(int i=5;i<=sqrt(num);i=i+6){
            if(num%i==0 || num%(i+2)==0) {
                printf("It is not a prime number");
                return;
            }
    }     printf("It is a prime number.");
}
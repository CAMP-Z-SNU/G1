#include <stdio.h>

// write a program to find if a number is prime or not

bool prime(int num);

int main(){
    int num;
    printf("enter a number to check prime: ");
    scanf("%d",&num);
    if(prime(num)){
        printf("%d is a prime number",num);
    }
    else{
        printf("%d is not a prime",num);
    }
    return 0;
}

bool prime(int num){
    int count = 0;
    if(num<=1){
        return 0;
    }
    else{
        for(int i=1;i<=num;i++){
            if(num%i==0){
                count++;
            }
    }
        if(count>2){
            return 0;
        }
        else{
            return 1;
        }
    }
}

/*
Difficulty rating 1/100
*/
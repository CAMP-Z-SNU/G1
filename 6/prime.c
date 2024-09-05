#include<stdio.h>

int main(){
    int prime=1;
    int num;
    printf("Enter a number :");
    scanf("%d",&num);
    if (num<=1){
        printf("Not a prime number.");
    }

    for (int i=2;i<num;i++){
        if (num%i == 0){
            prime=0;
            break;
        }
    }
    if(prime==0){
        printf("It is a prime number");
        
    }
    else{
        printf("It is not a prime number");
        
    }
    return 0;
}
        


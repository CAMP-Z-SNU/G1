#include<stdio.h>

int main(){
    int num;
    int c=0;
    printf("Enter the number to verify: ");
    scanf("%d",&num);
    if (num <= 1){
        printf("%d is neither a prime number nor a composite number!!!",num);
    }
    else{
        for (int i=1;i<num;i++){
            if (num%i == 0){
            c+=1;
            }
        }
        if (c>1){
            printf("%d is not a prime number!!",num);
        }
        else{
            printf("%d is a prime number!!",num);
        }
    }
    return 0;
}
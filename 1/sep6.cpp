#include <stdio.h>
#include <math.h>

int main(){
    int num,squareRoot;
    printf("enter a number to check prime: ");
    scanf("%d",&num);
    if(num<0){
        printf("ener a positive number");
    }
    else{
        squareRoot = sqrt(num);
        if(num<5){
            if(num==2||num==3){
                printf("prime number");
                return 0;
            }
            else{
                printf("not prime");
            }
        }
        else{
            for(int i=0;i<squareRoot;i++){
                if((6*i+1)==num||(6*i-1)==num){
                    printf("prime number");
                return 0;
                }
            }
            printf("not prime");
        }
    }
    return 0;
}
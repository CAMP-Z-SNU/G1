#include <stdio.h>
#include <math.h>

int main(){
    int num,srt;
    printf("Enter the number : ");
    scanf("%d",&num);
    if (num < 0){
        printf("Number should be a positive number!!!!");
        return 0;
    }
    else{
        srt = sqrt(num);
        if (num < 5){
            if (num == 2 || num == 3){
                printf("%d is a prime number.",num);
                return 0;
            }
            else{
                printf("%d is not a prime number.",num);
                return 0;
            }
        }
        else{
            for (int i=0;i<sqrt(num);i++){
                if (6*i+1 == num || 6*i-1 == num){
                    printf("%d is a prime number.",num);
                    return 0;
                }
            }
            printf("%d is not a prime number.",num);
            return 0;
        }
    }
}
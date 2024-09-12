#include <stdio.h>

int main(){
    int a = 0;
    int b = 1;
    int n;
    printf("Enter the value of n : ");
    scanf("%d", &n);
    if(n == 1){
        printf("%d", a);
    }
    else if(n == 2){
        printf("%d || %d || ", a,b);
    }
    else{
        printf("%d || %d ||", a, b);
        int temp = a;
        a += b;
        b = temp;
        temp = a;
        a += b;
        b = temp;
        for(int i=2; i<n; i++){
            printf(" %d || ", a);
            temp = a;
            a += b;
            b = temp;
        }
    }
}

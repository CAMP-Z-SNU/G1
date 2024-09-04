#include<stdio.h>

int cur,prev,fib=0;
void method1(int num){
    if (num < 2){
        printf("The number %d in the fibonacci series is %d\n",num,num);
        return;
    }
    else{
        prev = 0;
        cur = 1;
        for (int i=2;i<=num;i++){
            fib = prev + cur;
            prev = cur;
            cur = fib;
        }
        printf("The number %d in the fibonacci series is %d\n",num,fib);
        return;
    }
}

int method2(int fib){
    if (fib < 2){
        return fib;
    }
    return method2(fib-1) + method2(fib-2);
}

int main(){
    int n,ch,fib;
    do{
        printf("Enter the value of n: ");
        scanf("%d",&n);
        printf("MAIN MENU:\n");
        printf("1.METHOD 1\n2.METHOD 2\n3.EXIT\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch (ch){
            case 1:
                printf("METHOD 1:\n");
                method1(n);
                break;
            case 2:
                printf("METHOD 2:\n");
                fib = method2(n);
                printf("The number %d in the fibonnaci series is %d\n",n,fib);
                break;
            case 3:
                printf("EXITING CODE!!!!");
                break;
            default:
                printf("INVALID CHOICE!!!");
                break;
        }
    }while(ch!=3);
    return 0;
}

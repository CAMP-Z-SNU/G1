#include<stdio.h>

int cur,prev,fib=0;
void method1(int num){
    if (num < 2){
        printf("%d ",num);
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
        printf("%d ",fib);
        return;
    }
}

int method2(int fib,int a[]){
    if (fib < 2){
        return fib;
    }
    if (a[fib != -1]){
        return a[fib];
    }
    a[fib]= method2(fib-1,a) + method2(fib-2,a);
    return a[fib];
}

int main(){
    int n,ch,fib;
    int a[100] = {-1};
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
                for (int i=0;i<n+1;i++){
                    method1(i);
                }
                printf("\n");
                break;
            case 2:
                printf("METHOD 2:\n");
                for (int i=0;i<n+1;i++){
                    fib = method2(i,a);
                    printf("%d ",fib);
                }
                printf("\n");
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

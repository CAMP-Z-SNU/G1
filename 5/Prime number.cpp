include<stdio.h>
int Prime(int n);
int main) {
    int num,val;
    printf("Enter the number to be verified:");
    scanf("%d",&num);
    val=Prime(num);
    if(val==1){
        printf("The number %d is a prime number.",num);
        
    }
    else{
        printf("The given number is not a prime number.");
    }
}(
int Prime(int n) {
    if(n==1 || n==0) {
        printf("It is not a prime number.");

    }else{
    for(int i=2;i<n;i++) {
        if(n%i==0) {
            return 0;
        }else{
            return 1;
        }
    }}
}
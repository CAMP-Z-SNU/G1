#include <stdio.h>
int fibonacci(int num)
{
    int a = 0, b = 1, c, i;
    if (num == 0)
        return a;
    for (i = 2; i <= num; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}
int fib(int n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}
int main()
{
    int n;
    printf("Enter a number");
    scanf("%d",&n);
    printf("%d", fib(n));
    printf("%d",fib(n));
    getchar();
    return 0;
}

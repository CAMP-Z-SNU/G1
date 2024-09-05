#include <stdio.h>
int main() {
    int a,b;
    b=1;
    printf("Enter a number: ");
    scanf("%d", &a);

    if (a < 2) {
        printf("%d is not a prime number", a);
    } else {
        for (int i = 2; i < a; i++) {
            if (a % i == 0) {
                b = 0;
            
            }
        }

        if (b=1) {
            printf("%d is a prime number",a);
        } else {
            printf("%d is not a prime number",a);
        }
    }

    return 0;
}

#include <stdio.h>
void fibonacci(int n) {
    int x,y,z;
    x=0;
    z=0;
    y=1;
    int i=0;
    printf("%d %d ",x,y);
    while(i<(n-2)){
        z=x+y;
        printf("%d ",z);
        x=y;
        y=z;
        i++;
    }
}
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int main(void) {
    char option;
    int n1, n2;
    int count;
    scanf("%d", &count);
    for (int i = 0; i < count; i++) {
        scanf(" %c", &option);

        if (option == 'F') {
            scanf("%d", &n1);
            fibonacci(n1);
            printf("\n");
        } else if (option == 'G') {
            scanf("%d %d", &n1, &n2);
            printf("%d\n",gcd(n1, n2));
        } else {
            printf("Invalid option. Please enter 'F' or 'G'.\n");
        }
    }

    return 0;
}

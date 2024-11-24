#include <stdio.h>
#include <stdlib.h>

int* selfDivisibleNumbers(int left, int right, int* count) {
    int* result = malloc(sizeof(int) * (right - left + 1));
    *count = 0;

    for (int i = left; i <= right; i++) {
        int isSelfDivisible = 1; 
        int num = i;

        while (num > 0) {
            int digit = num % 10;
            if (digit == 0 || i % digit != 0) { 
                isSelfDivisible = 0; 
                break; 
            }
            num /= 10; 
        }

        if (isSelfDivisible) {
            result[*count] = i; 
            (*count)++; 
        }
    }

    return result; 
}

int main(void) {
    int left, right;
    printf("Left : ");
    scanf("%d", &left);
    printf("Right : ");
    scanf("%d", &right);

    int count;
    int* selfDivisibleNumbersArray = selfDivisibleNumbers(left, right, &count);

    for (int i = 0; i < count; i++) {
        printf("%d ", selfDivisibleNumbersArray[i]); 
    }
    printf("\n");

    free(selfDivisibleNumbersArray); 
    return 0;
}

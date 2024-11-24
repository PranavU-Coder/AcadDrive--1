#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isMultipleOfN(char *num, int N) {
    long long int val = atoll(num);
    return val % N == 0;
}

void findLeastNumber(int N) {
    char queue[100000][20]; 
    int front = 0, rear = 0;
    
    strcpy(queue[rear++], "9");
    
    while (front < rear) {
        char current[20];
        strcpy(current, queue[front++]);
        if (isMultipleOfN(current, N)) {
            printf("%s\n", current);
            return;
        }
        char nextNumber[20];
        strcpy(nextNumber, current);
        strcat(nextNumber, "0");
        strcpy(queue[rear++], nextNumber);
        strcpy(nextNumber, current);
        strcat(nextNumber, "9");
        strcpy(queue[rear++], nextNumber);
    }
}

int main(void) {
    int T;
    scanf("%d",&T);
    while(T--){
        int N;
        scanf("%d", &N);
    
         if (N <= 0) {
             printf("Please enter a positive integer greater than 0\n");
             return 1;
    }
    findLeastNumber(N);
   }
  return 0;
}

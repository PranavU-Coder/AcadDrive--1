#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void extractNumbers(const char *str) {
    int length = strlen(str);
    char numberBuffer[20]; 
    int index = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(str[i])) {
            numberBuffer[index++] = str[i]; 
        } else {
            if (index > 0) {
                numberBuffer[index] = '\0'; 
                printf("%s ", numberBuffer); 
                index = 0; 
            }
        }
    }
    if (index > 0) {
        numberBuffer[index] = '\0';
        printf("%s ", numberBuffer);
    }
    printf("\n");
}

int main(void) {
    char input[100];
    fgets(input, sizeof(input), stdin); 
    input[strcspn(input, "\n")] = 0; 
    extractNumbers(input); 
    return 0;
}

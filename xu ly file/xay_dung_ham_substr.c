#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* substr(char* s1, int offset, int number) {
    char* result;
    result = (char*)malloc((number + 1) * sizeof(char));
    if (result == NULL) {
        printf("Khong the cap phat bo nho\n");
        return NULL;
    }
    int len = strlen(s1);
    int j = 0;
    if (offset + number > len) {
        for (int i = offset; i < len; i++) {
            result[j++] = s1[i];
        }
    } else {
        for (int i = offset; i < offset + number; i++) {
            result[j++] = s1[i];
        }
    }
    result[j] = '\0';
    return result;
}

int main() {
    char s1[] = "hello cac ban toi";
    printf("%s", substr(s1, 6,20));
    return 0;
}

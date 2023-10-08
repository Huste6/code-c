#include <stdio.h>

int main() {
    FILE *f;
    char s[] = "Lap trinh c co ban";
    char s1[50];
    f = fopen("C:\\Users\\pc\\Documents\\code c\\vd.txt", "w+");
    fwrite(s, sizeof(s), 1, f);
    fseek(f, SEEK_SET, 0);
    fread(s1, sizeof(s1), 1, f);
    printf("%s", s1);
    fclose(f);
    return 0;
}

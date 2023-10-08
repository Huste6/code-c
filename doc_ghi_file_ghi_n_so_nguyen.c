#include <stdio.h>
#include <conio.h>
#define MAX 5

int main() {
    FILE *f;
    int ia[MAX], ib[MAX], i;
    for (i = 0; i < MAX; i++) {
        printf("Nhap vao 1 so: ");
        scanf("%d", &ia[i]);
    }
    f = fopen("C:\\Users\\pc\\Documents\\code c\\bai1.dat", "wb");
    if (f == NULL) {
        printf("Khong the mo file");
        return 1;
    }
    fwrite(ia, sizeof(ia), 1, f);
    fclose(f);
    f = fopen("C:\\Users\\pc\\Documents\\code c\\bai1.dat", "rb");
    fread(ib, sizeof(ib), 1, f);
    for (i = 0; i < MAX; i++) {
        printf("%d\t", ib[i]);
    }
    fclose(f);
    return 0;
}

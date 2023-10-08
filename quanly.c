#include <stdio.h>
#include <stdlib.h>
#define MAX 50
struct nhanvien {
    int manv;
    char hoten[30];
};
void input(struct nhanvien[], int);
void output(struct nhanvien[], int);
struct nhanvien newnv() {
    struct nhanvien snv;
    char ctam[10];
    printf("ma nhan vien: ");
    fgets(ctam, 10, stdin);
    snv.manv = atoi(ctam);
    printf("ho ten: ");
    fgets(snv.hoten, 30, stdin);
    return snv;
}

void input(struct nhanvien snv[], int in) {
    for(int i = 0; i < in; i++) {
        printf("nhap vao nhan vien thu %d: \n", i + 1);
        snv[i] = newnv();
    }
}
void output(struct nhanvien snv[], int in) {
    for(int i = 0; i < in; i++)
        printf("%5d %s\n", snv[i].manv, snv[i].hoten);
}
int main(void) {
    struct nhanvien snv[MAX];
    char ctam[10];
    int in;
    printf("nhap vao so nhan vien: ");
    gets(ctam);
    in = atoi(ctam);
    input(snv, in);
    output(snv, in);
    return 0;
}

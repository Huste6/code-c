#include<stdio.h>
#include<stdlib.h>
#define MAX_LEN 10
struct DSSinhVien{
    int no;
    int mssv;
    char name[200];
    int phoneNumber;
    double diem;
};
typedef struct DSSinhVien dssv;
int main(){
    dssv *a;
    FILE*in,*out;
    int n;
    in = fopen("dssv.txt", "r");
    if (in == NULL) {
        printf("File not found!\n");
        return 1;
    }
    out = fopen("bangdiem1.txt", "w");
    if (out == NULL) {
        printf("Error opening output file\n");
        return 1;
    }
    a=(dssv*)malloc(MAX_LEN*sizeof(dssv));
    if(a==NULL){
        printf("khong the cap phat bo nho");
        return 1;
    }
    char str[1000];
    int m=0;
    while(fgets(str,sizeof(str),in)!=NULL){
        str[strlen(str)-1]='\0';
        //tach thong tin
        int stt=0;
        char*token=strtok(str," ");
        while(token!=NULL){
            ++stt;
            if(stt==1){
                a[m].no=atof(token);
            }else if(stt==2){
                a[m].mssv=atof(token);
            }else if(stt==3){
                strcpy(a[m].name,token);
            }else{
                a[m].phoneNumber=atof(token);
            }
            token=strtok(NULL," ");
        }
        ++m;
    }
    for (int i = 0; i < MAX_LEN; i++) {
        printf("Nhap diem cua sinh vien %s: ", a[i].name);
        scanf("%lf", &a[i].diem);
    }
    for (int i = 0; i < MAX_LEN; i++) {
        fprintf(out, "%d %d %s %d %.2lf\n", a[i].no, a[i].mssv, a[i].name, a[i].phoneNumber, a[i].diem);
    }
    printf("Nhap so luong sinh vien can bo sung: ");
    scanf("%d", &n);
    a = (dssv*)realloc(a, (MAX_LEN + n) * sizeof(dssv));
    if (a == NULL) {
        printf("Khong the cap phat bo nho dong!\n");
        return 1;
    }
    for (int i = MAX_LEN; i < MAX_LEN + n; i++) {
        printf("Nhap thong tin sinh vien %d: ", i + 1);
        scanf("%d %d %s %d %lf", &a[i].no, &a[i].mssv, a[i].name, &a[i].phoneNumber, &a[i].diem);
        fprintf(out, "%d %d %s %d %.2lf\n", a[i].no, a[i].mssv, a[i].name, a[i].phoneNumber, a[i].diem);
    }
    fclose(in);
    fclose(out);
    free(a);
    return 0;
}

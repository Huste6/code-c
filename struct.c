#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct Hocsinh{
	char ma[100];
    char ten[100];
    double diem;
};

typedef struct Hocsinh sv;

sv nhap1(){
    sv a;
    printf("Nhap ten: ");
    fgets(a.ten, 100, stdin);
    printf("Nhap diem: ");
    scanf("%lf", &a.diem);
    fflush(stdin);
    return a;
}

void nhap2(sv *x){
	printf("Nhap ma sinh vien:");
	gets(x->ma);
    printf("Nhap ten: ");
    fgets(x->ten, 100, stdin);
    printf("Nhap diem: ");
    scanf("%lf", &x->diem);
    fflush(stdin);
}
void in(sv a){
    printf("%s %s %.2lf\n",a.ma ,a.ten, a.diem);
}
void timkiem(sv a[],int n,char m[100]){
	for(int i=0;i<n;i++){
		if(strcmp(m, a[i].ma) == 0){
			in(a[i]);
			return;
		}
	}
	printf("Khong tim thay sinh vien");
}
void timkiem2(sv a[],int n){
	float res=0;
	int pos;
	for(int i=0;i<n;i++){
		if(a[i].diem > res){
			res=a[i].diem;
			pos=i;
		}
	}
	in(a[pos]);
}
void sapxep(sv a[],int n){
	for(int i=0;i<n;i++){
		int max_index=i;
		for(int j=i+1;j<n;j++){
			if(a[j].diem > a[max_index].diem) max_index=j;
		}
		sv tmp=a[i];
		a[i]=a[max_index];
		a[max_index]=tmp;
	}
}
int cmp(const void *a,const void *b){
	sv *x=(sv*)a;
	sv *y=(sv*)b;
	if(x->diem>y->diem) return -1;
	else return 1;
}
int main(){
    sv a[1000];
    int n;
    printf("Nhap so luong hoc sinh: ");
    scanf("%d", &n);
    fflush(stdin);
    for(int i=0; i<n; i++){
        nhap2(&a[i]);
    }
    for(int i=0; i<n; i++){
        in(a[i]);
    }
    char m[100];
    printf("Nhap ma sinh vien can tim kiem: ");
    gets(m);
    timkiem(a,n,m);
    printf("\n");
    printf("Sinh vien co diem cao nhat: ");
    timkiem2(a,n);
    //sapxep(a,n); o(n^2)
    qsort(a,n,sizeof(sv),cmp);
    qsort()
    printf("Sap xep sinh vien theo diem co thu tu giam dan: ");
    for(int i=0; i<n; i++){
        in(a[i]);
    }
    
    return 0;
}


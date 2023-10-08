#include<stdio.h>
#include<string.h>

#define MAX 100

typedef struct {
    char hoten[30];
    int diem[5];
} KetQuaThiDau;

KetQuaThiDau vdv[MAX];

void nhap(KetQuaThiDau vdv[], int n) {
	int i;
    for ( i = 0; i < n; i++) {
        printf("Nhap ten vdv [%d]: ", i + 1);
        fgets(vdv[i].hoten, sizeof(vdv[i].hoten), stdin);
    }
}

void thiDau(KetQuaThiDau vdv[], int n) {
	int i,j;
    for ( j = 0; j < 5; j++) {
        printf("Luot thu dau thu %d:\n", j + 1);
        for ( i = 0; i < n; i++) {
            printf("Van dong vien %d dat duoc: ", i + 1);
            scanf("%d", &vdv[i].diem[j]);
            while (vdv[i].diem[j] < 0 || vdv[i].diem[j] > 10) {
                printf("Diem so khong hop le, moi nhap lai: ");
                scanf("%d", &vdv[i].diem[j]);
            }
        }
    }
    printf("\n%-10s %-5s %-5s %-5s %-5s %-5s\n","ho va ten","Luot 1","Luot 2","Luot 3","Luot 4","Luot 5");
    for( i=0;i<n;i++){
        printf("%-10s ",vdv[i].hoten);
        for( j=0;j<5;j++){
            printf("%-5d ",vdv[i].diem[j]);
        }
        printf("\n");
    }
}
void Ranking(KetQuaThiDau vdv[], int n){
    int sum[5];
    int max, max1, max2;
    KetQuaThiDau K[3];
    int i,j;
    for( i = 0; i < n; i++){
        sum[i] = 0;
        for( j = 0; j < 5; j++){
            sum[i] += vdv[i].diem[j];
        }
    }

    max = sum[0], max1 = 0, max2 = 0;
    for( i = 0; i < n; i++){
        if(max < sum[i]) max = sum[i];
    }
    for( i = 0; i < n; i++){
        if(max1 < sum[i] && sum[i] < max) max1 = sum[i];
    }
    for( i = 0; i < n; i++){
        if(max2 < sum[i] && sum[i] < max1) max2 = sum[i];
    }

    for( i = 0; i < n; i++){
        if(sum[i] == max) K[0] = vdv[i];
        if(sum[i] == max1) K[1] = vdv[i];
        if(sum[i] == max2) K[2] = vdv[i];
    }
    
    printf("\n%-20s %-5s %-5s\n","ho va ten","Xep hang","Diem");
    printf("%-20s %-5s %-5d\n",K[0].hoten,"GOLD",max);
    printf("%-20s %-5s %-5d\n",K[1].hoten,"Silver",max1);
    printf("%-20s %-5s %-5d\n",K[2].hoten,"Bronze",max2);
}
void superadc(KetQuaThiDau vdv[], int n){
    printf("Super Ad Carry:\n");
    int i,j;
    for( i = 0; i < n; i++){
        for( j = 0; j <= 4; j++){
            if(vdv[i].diem[j] == 10 && vdv[i].diem[j+1] == 10 && vdv[i].diem[j+2] == 10){
                printf("%-30s\n", vdv[i].hoten);
                break;
            }
        }
    }
}
int main() {
    int m = 0, n = 0;
    while (m != 5) {
        printf("\nMenu\n1.Dang ki VDV thi dau\n2.Thi dau\n3.Ranking\n4.Super Ad Carry\n5.Thoat\n");
        scanf("%d", &m);

        switch (m) {
            case 1:
                printf("Nhap so van dong vien: ");
                scanf("%d", &n);
                getchar();
                while (n <= 0 || n > MAX) {
                    printf("So luong khong hop le, moi nhap lai: ");
                    scanf("%d", &n);
                }
                nhap(vdv, n);
                break;
            case 2:
                thiDau(vdv, n);
                break;
            case 3:
                Ranking(vdv,n);
                break;
            case 4:
                superadc(vdv,n);
                break;
            case 5:
                break;
            default:
                printf("Vui long nhap lai: \n");
        }
    }

    return 0;
}


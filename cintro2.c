#include<stdio.h>
#include<string.h>
#define max 500
#define MAX 10

typedef struct Restaurant{
    char name[30];
    char description[max];
    float rating;
    char address[100];
} eat;

void Nhap(eat K[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("Nhap ten nha hang [%d]:",i+1);
        fflush(stdin);
        fgets(K[i].name,30,stdin);
        printf("Nhap mo ta nha hang [%d]:",i+1);
        fflush(stdin);
        fgets(K[i].description,max,stdin);
        printf("Nhap rating nha hang [%d]:",i+1);
        scanf("%f",&K[i].rating);
        while(K[i].rating<0||K[i].rating>5){
            printf("Moi nhap lai rating nha hang[%d]:",i+1);
            scanf("%f",&K[i].rating);
        }
        printf("Nhap dia chi nha hang [%d]:",i+1);
        fflush(stdin);
        fgets(K[i].address,100,stdin);
    }
}

void Nhapthem(eat K[],int n,int j){
    int i;
    for(i=0;i<j;i++){
        printf("Nhap ten nha hang [%d]:",i+n);
        fflush(stdin);
        fgets(K[i+n-1].name,30,stdin);
        printf("Nhap mo ta nha hang [%d]:",i+n);
        fflush(stdin);
        fgets(K[i+n-1].description,max,stdin);
        printf("Nhap rating nha hang [%d]:",i+n);
        scanf("%f",&K[i+n-1].rating);
        while(K[i+n-1].rating<0||K[i+n-1].rating>5){
            printf("Moi nhap lai rating nha hang[%d]:",i+n);
            scanf("%f",&K[i+n-1].rating);
        }
        printf("Nhap dia chi nha hang [%d]:",i+n);
        fflush(stdin);
        fgets(K[i+n-1].address,100,stdin);
    }
}

void Inthongtin1(eat K[],int i){
    printf("Nha hang [%d]\n",i+1);
    printf("Name: %s\n",K[i].name);
    printf("Description: %s\n",K[i].description);
    printf("Rating: %3.1f\n",K[i].rating);
    printf("Address: %s\n",K[i].address);
}

void Timkiem(eat K[],int n){
    char name1[30];
    printf("Nhap ten cua hang muon tim kiem: ");
    fflush(stdin);
    fgets(name1,30,stdin);
    int i;
    int k=0;
    strlwr(name1);
    for(i=0;i<n;i++){
        char temp[30];
        strcpy(temp, K[i].name);
        strlwr(temp);
        if(strcmp(name1,temp)==0){
            Inthongtin1(K,i);
            break;
        }
    }
}
void Timkiemtheomota(eat K[],int n){
    char str[max];
    printf("Nhap ten mon an tim kiem: ");
    scanf("%s",str);
    strlwr(str);
    int i;
    for(i=0;i<n;i++){
    	char temp[30];
    	strcpy(temp,K[i].description);
    	strlwr(temp);
        char *ptr=strstr(temp,str);
        if(ptr!=NULL){
            Inthongtin1(K,i);
        }

    }
}
void ranking(eat*K,int n){
	eat K3[50],a;
	int i,j;
	for(i=0;i<n;i++){
		K3[i]=K[i];
	}
	for(j=n-1;j>=0;j--)
	{
		for(i=0;i<j;i++)
		{
			if(K3[i].rating<K3[i+1].rating)
			{
				a=K3[i];
				K3[i]=K3[i+1];
				K3[i+1]=a;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		Inthongtin1(K3,i);
	}
}

int main(){
    int m=0;
    int n=0,j=0;
    eat K[MAX];
    int i;
    while(m!=6){
        printf("Menu\n1.Nhap thong tin nha hang.\n2.In ra thong tin nha hang.\n3.Tim kiem nha hang theo ten.\n4.Tim kiem nha hang theo mo ta.\n5.Sap xep thu hang nha hang.\n6.Thoat\n");
        scanf("%d",&m);
        switch(m){
            case 1:
                if(n==0){
                    printf("Nhap so nha hang muon in thong tin: ");
                    scanf("%d",&n);
                    while(n<=0){
                        printf("Vui long nhap lai so nha hang muon in thong tin: ");
                        scanf("%d",&n);
                    }
                    Nhap(K,n);
                }else{
                    printf("Nhap so nha hang muon nhap them: ");
                    scanf("%d",&j);
                    while(j<=0){
                        printf("Vui long nhap lai so nha hang muon in them thong tin: ");
                        scanf("%d",&j);
                    }
                    n+=j;
                    Nhapthem(K,n,j);
                }
                break;
            case 2:
                for(i=0;i<n;i++){
                    Inthongtin1(K,i);
                }
                break;
            case 3:
                Timkiem(K,n);
                break;
            case 4:
                Timkiemtheomota(K,n);
                break;
            case 5:
                ranking(K,n);
                break;
            case 6:
                break;
            default: printf("Nhap lai di!");
        }
    }
}


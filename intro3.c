#include<stdio.h>
#include<string.h>
#include<strings.h>
#define des 500
typedef struct Restaurant
{
	char Name[30];
	char description[des];
	float rating;
	char add[100];
}eat;
void nhap(eat*K,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Moi nhap ten nha hang [%d]:\n",i+1);
		fflush(stdin);
		fgets(K[i].Name,30,stdin);
		printf("Nhap mo ta nha hang [%d]:\n",i+1);
		fgets(K[i].description,des,stdin);
		printf("Nhap rating nha hang [%d]:\n",i+1);
		scanf("%f",&K[i].rating);
		while(K[i].rating<0||K[i].rating>5)
		{
		printf("moi nhap lai rating nha hang [%d]:\n",i+1);
		scanf("%f",&K[i].rating);
		}
		printf("Nhap dia chi nha hang [%d]:\n",i+1);
		fflush(stdin);
		fgets(K[i].add,100,stdin);
	}
	
}
void nhapthem(eat*K,int n,int j)
{
	int i;
	for(i=n-j;i<n;i++)
	{
		printf("Moi nhap ten nha hang [%d]:\n",i+1);
		fflush(stdin);
		fgets(K[i].Name,30,stdin);
		printf("Nhap mo ta nha hang [%d]:\n",i+1);
		gets(K[i].description);
		printf("Nhap rating nha hang [%d]:\n",i+1);
		scanf("%f",&K[i].rating);
		while(K[i].rating<0||K[i].rating>5)
		{
		printf("moi nhap lai rating nha hang [%d]:\n",i+1);
		scanf("%f",&K[i].rating);
		}
		printf("Nhap dia chi nha hang [%d]:\n",i+1);
		fflush(stdin);
		fgets(K[i].add,100,stdin);
	}
	
}

void inra(eat*K,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Nha hang %d\nName: %sDescription: \n%sRating: %.1f\nAddress: %s\n",i+1,K[i].Name,K[i].description,K[i].rating,K[i].add);
		printf("\n\n");
	}
}
/*void timkiemtheoten(eat*K,int n)
{
	int i,j,k=0;
	int dem;
	char ten[30];
	/*eat K2[50];
	for(i=0;i<n;i++)
	{
		K2[i]=K[i];
	}*
	printf("Nhap ten nha hang can tim :\n");
	fflush(stdin);
	gets(ten);
	for(i=0;i<n;i++)
	{
	dem=0;	
	for(j=0;j<strlen(K[i].Name);j++)
	{
		if(K[i].Name[j]==ten[j]||K[i].Name[j]+32==ten[j]|K[i].Name[j]-32==ten[j])
		{
			dem++;
	
		}
	}
	if(dem==strlen(K[i].Name)-1)
	{	
	printf("Nha hang %d\nName: %sDescription: \n%sRating: %.1f\nAddress: %s\n",i+1,K[i].Name,K[i].description,K[i].rating,K[i].add);
	k--;
    }
    k++;
	}
	if(k==n)
	{
		printf("Khong tim thay nha hang ban can \n");
	}	
}*/ 
int timkiemtheoten2(eat*K,int n)
{
	int i,j;
	int k=0;
	char timkiem[30];
	printf("Nhap ten nha hang can tim :\n");
	fflush(stdin);
	fgets(timkiem,30,stdin);
	for(i=0;i<n;i++)
	{
		
		if(strcasecmp(K[i].Name,timkiem)==0)
		{
		printf("Nha hang %d\nName: %sDescription: \n%sRating: %.1f\nAddress: %s\n",i+1,K[i].Name,K[i].description,K[i].rating,K[i].add);
	    k--;	
		}
		k++;	
	}
	
	if(k==n)
	{
		printf("Khong tim thay nha hang ban can \n");
	}	
	
}

void timkiemtheomota2(eat*K,int n)
{
   int i,j,dem;
   char search[des],search1[des];
	printf("Nhap mo ta can tim :\n");
	fflush(stdin);
	gets(search);
	for(i=0;i<n;i++)
	{
	strcpy(search1,K[i].description);
	strlwr(search1);
	strlwr(search);
	if(strstr(search1,search)!=NULL)
	{
		printf("Nha hang %d\nName: %sDescription: %sRating: %.1f\nAddress: %s\n",i+1,K[i].Name,K[i].description,K[i].rating,K[i].add);	
	}

    }
}

void ranking(eat*K,int n)
{
	eat K3[50],a;
	int i,j;
	for(i=0;i<n;i++)
	{
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
		printf("Nha hang %d\nName: %sDescription: %sRating: %.1f\nAddress: %s\n",i+1,K3[i].Name,K3[i].description,K3[i].rating,K3[i].add);
		printf("\n\n");
	}
	
}
int main()
{
	int m,n=0,j=0;
	eat K[50];
	while(m!=6)
	{
		printf("Menu\n1.Nhap thong tin nha hang.\n2.In ra thong tin nha hang.\n3.Tim kiem nha hang theo ten.\n4.Tim kiem nha hang theo mo ta.\n5.Sap xep thu hang nha hang.\n6.Thoat\n");
		scanf("%d",&m);
		switch(m)
		{
			case 1: 
			if(n==0)
			{
				printf("Nhap so nha hang muon in thong tin:\n");
				scanf("%d",&n);
				while(n<=0)
				{
				printf("Ban da nhap sai, moi nhap lai so nha hang muon in thong tin:\n");
				scanf("%d",&n);
				}
				nhap(K,n);
			}
			else
			{
				printf("Nhap so nha hang muon nhap theo :\n");
				scanf("%d",&j);
				while(n<=0)
				{
				printf("Ban da nhap sai, moi nhap lai so nha hang muon in thong tin:\n");
				scanf("%d",&n);
			    }
			    n+=j;
				nhapthem(K,n,j);
			}
			break;
			case 2:
			inra(K,n);
			break;
			case 3:
			timkiemtheoten2(K,n);
			break;
			case 4:
			timkiemtheomota2(K,n);
			break;
			case 5:
			ranking(K,n);
			break;
			case 6:
			printf("Goodbye!......");
			break;
			default : printf("Error!Enter again !\n");
		}
	}
}


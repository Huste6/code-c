#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define qa 5
typedef struct qt
{
char cauhoi[120] ;
char pa1[30];
char pa2[30];
char pa3[30];
int dapan;
}qt_type ;
void nhap(qt_type*K,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("Moi ban nhap cau hoi %d:\n",i+1);
		fflush(stdin);
		gets(K[i].cauhoi);
		printf("Dap an 1 :_");
		gets(K[i].pa1);
		printf("Dap an 2 :_");
		gets(K[i].pa2);
		printf("Dap an 3 :_");
		gets(K[i].pa3);
		printf("dap an dung :\n");
		scanf("%d",&K[i].dapan);
		while(K[i].dapan<1||K[i].dapan>3)
		{
		printf("nhap lai dap an dung :\n");
		scanf("%d",&K[i].dapan);
		}
	}
}
void inra(qt_type*K,int n)
{
	int a;
	printf("Moi ban nhap cau hoi muon in ra man hinh :\n");
	scanf("%d",&a);
	while(a<1||a>5)
	{
	printf("Ko hop le ! Moi ban nhap lai so hieu cau hoi muon in ra man hinh :\n");
	scanf("%d",&a);
	}
	printf("%s\n",K[a-1].cauhoi);
	printf("1.%-30s2.%-30s3.%-30s",K[a-1].pa1,K[a-1].pa2,K[a-1].pa3);
}
void daodapan(qt_type*K,int n)
{
	int j,change;
	qt_type a;
	printf("Moi ban nhap cau hoi muon dao dap an\n");
	scanf("%d",&j);
	while(j<1||j>5)
	{
	printf("Lua chon ko hop le ! Moi ban nhap lai cau hoi muon dao dap an :\n");
	scanf("%d",&j);	
	}
	printf("Moi ban nhap dap an muon dao :\n");
	scanf("%d",&change);
	while(change<1||change>3||change==K[j-1].dapan)
	{
	printf("Lua chon ko hop le ! Moi ban nhap lai dap an muon dao :\n");
	scanf("%d",&change);	
	}
	
	switch(K[j-1].dapan)
	{
		case 1:
		if(change==2)
		{
			strcpy(a.pa1,K[j-1].pa1);
			strcpy(K[j-1].pa1,K[j-1].pa2);
			strcpy(K[j-1].pa2,a.pa1);
		}
		else
		{
			strcpy(a.pa1,K[j-1].pa1);
			strcpy(K[j-1].pa1,K[j-1].pa3);
			strcpy(K[j-1].pa3,a.pa1);
		}
		K[j-1].dapan=change;
		break;
		case 2:
		if(change==1)
		{
			strcpy(a.pa1,K[j-1].pa2);
			strcpy(K[j-1].pa2,K[j-1].pa1);
			strcpy(K[j-1].pa1,a.pa1);
		}
		else
		{
			strcpy(a.pa1,K[j-1].pa2);
			strcpy(K[j-1].pa2,K[j-1].pa3);
			strcpy(K[j-1].pa3,a.pa1);
		}
		K[j-1].dapan=change;
		break;
		default:
		{
		if(change==1)
		{
			strcpy(a.pa1,K[j-1].pa3);
			strcpy(K[j-1].pa3,K[j-1].pa1);
			strcpy(K[j-1].pa1,a.pa1);
		}
		else
		{
			strcpy(a.pa1,K[j-1].pa3);
			strcpy(K[j-1].pa3,K[j-1].pa2);
			strcpy(K[j-1].pa2,a.pa1);
		}
		K[j-1].dapan=change;	
		}
	}
	printf("%s\n",K[j-1].cauhoi);
	printf("1.%-30s2.%-30s3.%-30s",K[j-1].pa1,K[j-1].pa2,K[j-1].pa3);	
}
void gameplay(qt_type*K,int n)
{
	int i,j,x=0;
	int ch[3],kotae[3];
	char ten[30];
	for(i=0;i<3;i++)
	{
		x=0;
		printf("Moi nhap ten nguoi choi %d :_",i+1);
		fflush(stdin);    gets(ten);
		printf("Moi chon 3 cau hoi muon thi :\n");
		for(j=0;j<3;j++)
		{
			scanf("%d",&ch[j]);
			while(ch[j]<1||ch[j]>5||ch[j]==ch[j-1]||ch[j]==ch[j-2])
			{
				printf("Cau hoi da chon ko hop le, moi ban chon lai !\n");
				scanf("%d",&ch[j]);
			}
		}
		for(j=0;j<3;j++)
		{
			printf("%s\n",K[ch[j]-1].cauhoi);
	        printf("1.%-30s2.%-30s3.%-30s",K[ch[j]-1].pa1,K[ch[j]-1].pa2,K[ch[j]-1].pa3);
			printf("\nCau tra loi cua ban la :__");
			scanf("%d",&kotae[j]);
		while (kotae[j]<1||kotae[j]>3)
	    {
	    printf("Lua chon ko hop le ! Moi ban nhap lai dap an :\n");
	    scanf("%d",&kotae[j]);	
	    }
	    }
	    printf("Nguoi choi :%s\n",ten);
	    for(j=0;j<3;j++)
		{
		if(x==0)
		{
			printf("%-10s%-15s%-10s%-5s\n","Cau hoi","P.a lua chon","P.a dung","diem");
			x=1;
		}
		{
		if(K[ch[j]-1].dapan==kotae[j])
		printf("%-10d%-15d%-10d%-5d\n",ch[j],kotae[j],K[ch[j]-1].dapan,1);
		else printf("%-10d%-15d%-10d%-5d\n",ch[j],kotae[j],K[ch[j]-1].dapan,0);
		}
		}
	
	}
}
int main()
{
	int m,n=5;
	qt_type K[qa];
	while(m!=5)
	{
		printf("\nMenu\n1.Tao cau hoi\n2.In cau hoi\n3.Dao dap an\n4.Choi game\n5.Thoat\n");
		scanf("%d",&m);
		switch(m)
		{
			case 1:
			nhap(K,n);
			break;
			case 2:
			inra(K,n);
			break;
			case 3:
			daodapan(K,n);
			break;
			case 4:
			gameplay(K,n);
			break;
			case 5: printf("Goodbye !____");
			break;
			default : printf("Please enter again !\n");
		}
	}
}


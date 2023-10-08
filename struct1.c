#include<stdio.h>
#include<string.h>
typedef struct cars{
	int id;
	char name[30];
	int age;
	int yrs;
}Car;

int main(){
	int n;
	scanf("%d",&n);
	Car K[n];
	int sum=0,sum1=0;
	int i;
	for(i=0;i<n;i++){
		scanf("%d%s%d%d",&K[i].id,K[i].name,&K[i].age,&K[i].yrs);
		sum+=K[i].age;
		sum1+=K[i].yrs;
	}
	/*if(sum/sum1==0){
		printf("1\n");
	}else printf("0\n");*/
	/*int x,dem=0;scanf("%d",&x);
	for(int i=0;i<n;i++){
		if(K[i].yrs<=x) dem++;
	}
	printf("%d",dem);*/
	
}

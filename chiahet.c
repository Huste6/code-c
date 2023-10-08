#include<stdio.h>
int main(){
	int n;
	scanf("%d",n);
	int i;
	for(i=100;i<999;i++){
		if(i%n==0) printf("%d ",i);
	}
	return 0;
}

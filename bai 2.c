#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Hanghoa{
	char id[5];
	int sanpham;
};
int kt(char a[], char b[]){
    int c=strlen(a),cnt=0;
    for(int i=0;i<strlen(a);i++){
        if(a[i]==b[i]) cnt++;
    }
    if (cnt==c) return 1;
    else return 0;
}
int main(){
	struct Hanghoa goods[100];
	int i,j=0,N,sum=0
	while(1){
		scanf("%s", goods[j].id);
		if(strlen(goods[j].id)==2 ) break;
		scanf("%d", &goods[j].sanpham);
		j++;
	}
	if(j==0) {
		printf("0") ;
		return 0 ;
	}
	scanf("%d", &N);
	int ham[N];
	char choice[5][N];
	for(i=0;i<N;i++){
		scanf("%s %d", choice[i], &ham[i]);
		for(int j=0;j<j;j++){
			if(kt(choice[i],goods[j].id)==1) sum+=ham[i]*goods[j].sanpham;
		}      
	}
	printf("%d", sum);
}

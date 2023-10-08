#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int main(){
	int n;
	scanf("%d",&n);
	getchar();
	while(n>0){
		char c[1000];
		gets(c);
		int cnt=0;
		int i;
		for(i=0;i<strlen(c);i++){
			if(c[i]==' ' && c[i+1]!=' '){
				cnt++;
			}
		}
		printf("%d\n",cnt);
		n--;
	}
}

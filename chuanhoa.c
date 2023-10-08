#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
	int n;
	int i;
	scanf("%d",&n);
	getchar();
	while(n--){
		char c[1000];
		gets(c);
		strlwr(c);
		char a[10][100];
		int n=0;
		char *token=strtok(c," ");
		while(token!=NULL){
			strcpy(a[n++],token);
			token=strtok(NULL," ");
		}
		printf("%s",a[n-1]);
		for(i==0;i<n-1;i++){
			printf("%c",a[i][0]);
		}
		printf("@sis.hust.edu.vn");
		printf("\n");
	}	
}

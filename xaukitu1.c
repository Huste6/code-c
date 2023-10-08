#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char c[1000];
	gets(c);
	int cnt[256]={0};
	int i;
	for(i=0;i<strlen(c);i++){
		cnt[((int)c[i])]++;
	}
	for(i=0;i<256;i++){
		if(cnt[i]!=0){
			printf("%c %d\n",i,cnt[i]);
		}
	}
}

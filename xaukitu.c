#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	char c[100];
	scanf("%s",c);
	int cnt[26]={0};
	int i;
	for(i=0;i<strlen(c);i++){
		cnt[c[i]-'a']++;
	}
	for(i=0;i<25;i++){
		if(cnt[i]!=0){
			printf("%c %d\n",i+'a',cnt[i]);
		}
	}
}

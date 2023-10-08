#include<stdio.h>
#include<string.h>

int cmp(const void *a,const void *b){
	char *x=(char*)a;
	char *y=(char*)b;
	if(strcmp(x,y)<0) return -1;
	else return 1;
}
int main(){
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
	int b[10] = {0};
	int i,j;
	qsort(a,n,sizeof(a[0]),cmp);
	for(i=0;i<n;i++){
		if(b[i]==0){
			int cnt=1;
			for(j=i+1;j<n;j++){
				if(strcmp(a[i],a[j])==0){
					cnt++;
					b[j]=1;
				}
			}
			printf("%s %d\n",a[i],cnt);
		}
	}
}

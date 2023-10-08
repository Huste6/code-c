#include<stdio.h>
int main(){
	FILE *out=fopen("hello.txt","w");
	if(out==NULL){
		perror("khong the mo tep.\n");
		return 1;
	}
	fprintf(out,"hello world");
	fclose(out);
	return 0;
}

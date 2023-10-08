#include<stdio.h>

#define MAX 50
void charReadWrite(FILE*fin,FILE*fout){
	int c;
	while((c=fgetc(fin))!=EOF){
		fputc(c,fout);
		putchar(c);
	}
}

/*ham chuyen in hoa thanh in thuong va in thuong thanh in hoa*/
void Chuyenchu(FILE*fin,FILE*fout){
	int c;
	rewind(fin); 
	while((c=fgetc(fin))!=EOF){
		if(islower(c)) c=toupper(c);
		else if(isupper(c)) c=tolower(c);
		fputc(c,fout);
		putchar(c);
	}
}
void LineReadWrite(FILE*fin,FILE*fout){
	char buff[MAX];int cnt=0;
	while(fgets(buff,MAX,fin)!=NULL){
		cnt++;printf("%d. %s",cnt,buff);
	}
}
int main(){
	FILE*fin,*fout;
	fin=fopen("C:\\Users\\pc\\Documents\\code c\\xu ly file\\lab1.txt","r");
	fout=fopen("C:\\Users\\pc\\Documents\\code c\\xu ly file\\lab1a.txt","w");
	if(fin==NULL){
		printf("khong the mo!!");
		return 1;
	}else if(fout==NULL){
		printf("khong the mo!!");
		return 1;
	}else{
		LineReadWrite(fin,fout);
		fclose(fin);
		fclose(fout);
	}
	return 0;
}

#include<stdio.h>
#define MAX 50
void charReadWrite(FILE*fin,FILE*fout){
    int c;
    while((c=fgetc(fin))!=EOF){
        fputc(c,fout);
        putchar(c);
    }
}

/* chèn thêm 1 d?u cách ? m?i dòng */
void chendaucach(FILE*fin,FILE*fout){
    int c;
    rewind(fin);
    while((c=fgetc(fin))!=EOF){
        fputc(c,fout);
        if(c=='\n') fputc('\n',fout);
    }
}
void LineReadWrite(FILE*fin,FILE*fout){
	char buff[MAX];int cnt=0;
	while(fgets(buff,MAX,fin)!=NULL){
		cnt++;printf("%d. %s",cnt,buff);
	}
}
/* hàm chuy?n in hoa thành in thu?ng và in thu?ng thành in hoa */
void Chuyenchu(FILE*fin,FILE*fout){
    int c;
    rewind(fin); /* d?t con tr? l?i d?u t?p tin */
    while((c=fgetc(fin))!=EOF){
        if(islower(c)) c=toupper(c);
        else if(isupper(c)) c=tolower(c);
        fputc(c,fout);
        putchar(c);
    }
}

int main(){
    FILE*fin,*fout;
    fin=fopen("C:\\Users\\pc\\Documents\\code c\\xu ly file\\lab1.txt","r");
    fout=fopen("C:\\Users\\pc\\Documents\\code c\\xu ly file\\lab1a.txt","w");
    if(fin==NULL){
        printf("Khong the mo file lab1.txt!!");
        return 1;
    }else if(fout==NULL){
        printf("Khong the mo file lab1a.txt!!");
        return 1;
    }else{
        /*chendaucach(fin,fout);*/
        LineReadWrite(fin,fout);
        fclose(fin);
        fclose(fout);
    }
````/*fout=fopen("C:\\Users\\pc\\Documents\\code c\\xu ly file\\lab1a.txt","r");
    if(fout==NULL){
        printf("Khong the mo file lab1a.txt!!");
        return 1;
    }else{
        char s[100];
        while(fgets(s,sizeof(s),fout)!=NULL){
            printf("%s",s);
        }
        fclose(fout);
    }*/

    return 0;
}

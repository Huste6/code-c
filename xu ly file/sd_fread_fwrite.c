#include<stdio.h>
void readwrite(FILE*in,FILE*out){
    int num;
    char buff[100];
    while(!feof(in)){
        num=fread(buff,sizeof(char),100,in);
        buff[num*sizeof(char)]='\0';
        printf("%s",buff);
        fwrite(buff,sizeof(char),num,out);
    }
}

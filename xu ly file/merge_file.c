#include<stdio.h>
#define MAX_LEN 500
void LineMerge(FILE*f1,FILE*f2,FILE*f3){
    int len;
    char buff1[MAX_LEN],buff2[MAX_LEN];
    while(fgets(buff1,MAX_LEN,f1)!=NULL && fgets(buff2,MAX_LEN,f2)!=NULL){
        fputs(buff1,f3);
        fputs(buff2,f3);
    }
    if(buff1!=NULL) fputc(buff1,f3);
    while(fgets(buff1,MAX_LEN,f1)!=NULL){
        fputs(buff1,f3);
    }
    while(fgets(buff2,MAX_LEN,f2)!=NULL){
        fputs(buff2,f3);
    }
}

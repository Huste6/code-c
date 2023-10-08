#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    FILE*in;
    in=fopen("C:\\Users\\pc\\Documents\\code c\\xu ly file\\hocsinh.txt","r+");
    if(in==NULL){
        printf("FILE not found!\n");
    }else{
        FILE*out;
        out=fopen("hocsinh_out.txt","w");
        char name[200],diem[200];
        while(fgets(name,200,in)!=NULL){
            name[strlen(name)-1]='\0';
            double t,l,h;
            fscanf(in,"%lf %lf %lf",&t,&l,&h);
            fgetc(in);
            double tb=(t+l+h)/3;
            fprintf(out,"%s %.1lf",name,tb);
            if(tb>=9) fprintf(out,"XUAT SAC\n");
            else if(tb>=8) fprintf(out,"GIOI\n");
            else if(tb>=6.5) fprintf(out,"KHA\n");
            else printf(out,"YEU");
        }
        fclose(in);fclose(out);
    }
}

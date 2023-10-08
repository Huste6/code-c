#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>
int prime1(int x){
    if(x<2) return 0;
    for(int i=2;i<=sqrt(x);i++){
        if(x%i==0) return 0;
    }
    return 1;
}
int main(){
    FILE*in;
    in=fopen("number.txt","r");
    if(in==NULL){
        printf("FILE not found!\n");
    }else{
        FILE*out;
        out=fopen("prime.txt","w");
        int n,dem=0;
        while(fscanf(in,"%d",&n)!=-1){
            if(prime1(n)){
                ++dem;
                fprintf(out,"%d ",n);
            }
            if(dem%10==0){
                fprintf(out,"\n");
            }
        }
        fclose(in);fclose(out);
    }
    return 0;
}

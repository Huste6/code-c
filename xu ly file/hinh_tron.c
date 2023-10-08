#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct Circle{
    double x;
    double y;
    double radius;
};
typedef struct Circle circle;
int checkInsertsection(circle c1,circle c2){
    double x1=abs(c1.x-c2.x);
    double y1=abs(c1.y-c2.y);
    double kc=sqrt(pow(x1,2)+pow(y1,2));
    if(kc<=c1.radius+c2.radius){
        return 1;
    }else{
        return 0;
    }
}
int max(int a,int b){
    return a>b;
}
int main(){
    int n;
    printf("Nhap so luong hinh tron: ");
    scanf("%d",&n);
    circle*circles=(circle*)malloc(n*sizeof(circle));
    for(int i=0;i<n;i++){
        printf("Nhap thong tin cho hinh tron th %d:\n",i+1);
        printf("Nhap toa do tam (x,y): ");
        scanf("%f %f",&circles[i].x,&circles[i].y);
        printf("Nhap ban kinh: ");
        scanf("%f",&circles[i].radius);
        printf("\n");
    }
    printf("Thong tin ve cac hinh tron\n");
    for(int i=0;i<n;i++){
        printf("hinh thu %d\n",i+1);
        printf("toa do tam (x,y): %f %f\n",circles[i].x,circles[i].y);
        printf("ban kinh: %f\n",circles[i].radius);
    }
    int maxht1=0,maxht2=-1;
    int index=0,maxindex=-1;
    for(int i=0;i<n;i++){
        index=i;
        for(int j=0;j<n;j++){
            if(i!=j && checkInsertsection(circles[i],circles[j])){
                maxht1++;
            }
        }
        if(maxht2<maxht1){
            maxht2=maxht1;
            maxindex=i;
        }
        maxht1=0;
    }
    if(maxindex!=-1){
        printf("hinh thu %d la hinh giao voi nhieu duong tron nhat\n",maxindex+1);
        printf("toa do tam (x,y): %f %f\n",circles[maxindex].x,circles[maxindex].y);
        printf("ban kinh: %f\n",circles[maxindex].radius);
    }
    free(circles);
    return 0;
}

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double avgAge(int *a, int N){ 
	int sum = 0;
	int i;
	for( i =0 ; i <N ;i++){
		sum+=a[i];
	}
    return (double)sum/N;
	
}
double avgH(double *h, int N){
    int i;
    double sum4=0;
		for( i =0 ; i < N ; i++){
		sum4 += h[i];
	}
	double c= (double)sum4/N;
	if( 1.7 < c && c < 1.8 ) printf("1\n");
	if(  c < 1.7 ) printf("0\n");
	if( c >= 1.8 ) printf("2\n");
    return 0;
}
double avgW(double *w, int N){
	int i;
	double sum1=0;
		for(i =0 ; i <N ;i++){
	
		sum1+=w[i];
	}
	 double av_w=(double)sum1/N;
	 return av_w;
}
double avgBMI(double *h, double *w, int N){
	int i;
	double sum2=0;
	for(i =0 ; i <N ;i++){
	
		sum2+=(double)(w[i]/(h[i]*h[i]));
	}
	return (double)sum2/N;
}
double avgS(int *s, int N){
	int i;
	double sum3=0;
	for(i =0 ; i <N ;i++){
		sum3+=s[i];
	}
	return (double)sum3/N;
}
void split(int* a, int* t1, int *t2, int N, int M){
	int i;
	for(i=0;i<M;i++){
	    t1[i]=i;
	}
	for(i=M;i<2*M;i++){
		if((i-M) < N/2 && i<N) t2[i-M]=i;
		else t2[i-M]=-1;
	}
}
void sapxep(int *a,int n){
	int i;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(a[i]>a[j]){
				int tmp=a[i];
				a[i]=a[j];
				a[j]=tmp;
			}
		}
	}
}
int main(){
      int N,a[51]={0},s[51]={0};
      double w[51]={0};
      double h[51]={0};
	  scanf("%d", &N);
	  while( 0 > N || N > 50 ) {
	  printf("0\n");
	  printf("Yeu cau nhap lai :\n");
	  scanf("%d", &N);
 }  
      printf("1\n");
      int i;
      for(i=0;i<N;i++){
      	scanf("%d", &a[i]);
	  }
	  if(avgAge(a,N) < 27 ) printf("1\n");
	  else printf("0\n");
	  
	   for(i=0;i<N;i++){
      	scanf("%lf", &h[i]);
	  }
	  avgH(h,N);
	  for(i=0;i<N;i++){
      	scanf("%lf", &w[i]);
	  }
	  double k=avgBMI(h,w,N);
	  if( 18 <= k && k <= 24 ) printf("1\n");
	  else printf("0\n");
	  // cau e 
	  for(i=0;i<N;i++){
      	scanf("%d", &s[i]);
	  }
	  if(avgS(s,N)>7) printf("1\n");
	  else printf("0\n");
	  //cau f
	  int M;
	  scanf("%d", &M);
	  if( M > N/2) printf("0\n");
	  else printf("1\n");
	  // cau g
	  int t1[M],t2[M],cnt=0;
	  split(a,t1,t2,N,M);
	  for(i=0;i<M;i++){
	  	if(t2[i]!=-1) cnt++;
	  }
	  printf("%d\n", cnt);
	  //final
	  sapxep(s,N);
	  int sum1=0;
	  for(i=N-1;i>)
}

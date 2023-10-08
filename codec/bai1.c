#include<stdio.h>

int main()
{
	double x;
	scanf("%lf",&x);
	if(x>=0 && x<3) printf("muc thap");
	else if(x>=3 && x<6) printf("muc trung binh");
	else if(x>=6 && x<8) printf("muc cao");
	else if(x>=8 && x<=11) printf("muc rat cao");
	else printf("muc nguy hiem");
	return 0;
}

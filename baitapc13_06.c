#include <stdio.h>
#include <stdlib.h>

int check_vang(int n, int p[], int c) { 
    int vang_max = c * 50 / 100;
    int cnt = 0;
    int i;
    for ( i = 0; i < n; i++) {
        if (c - p[i] >= vang_max) { 
            cnt++;
        }
    }
    return cnt;
}
void dieuchuyen(int n, int p[],int k){
	int a[n];
	int i;
	for(i=0;i<n;i++){
    	a[i]=p[i]-k;
	}
	int min=a[0];
	int tmp;
	for(i=0;i<n;i++){
		if(min>a[i]){
			min=a[i];
			tmp=i;
		}
	}
	printf("phong nhan nguoi nhieu nhat: %d\n",tmp);
}
void sapxep (int a[], int n)
{
	int tmp;
	int i,j;
	int b[n];
	int c[n];
	for(i=0;i<n;i++) b[i]=a[i];
	for (i=0;i<n-1;i++){
		for (j = i+1; j < n; j++){
			if (a[i] > a [j]) {
				tmp=a[i];
				a[i]=a[j];
				a[j]= tmp;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i]==b[j]){
				c[i]=j;
				b[j]=0;
				break; 
			}
		}
	}
	
	for(i=0;i<n;i++){
		printf("%d ",c[i]);
	}
}	
void sapxep1 (int a[], int n)
{
	int tmp;
	int i,j;
	int b[n];
	int c[n];
	for(i=0;i<n;i++) b[i]=a[i];
	for (i=0;i<n-1;i++){
		for (j = i+1; j < n; j++){
			if (a[i] < a [j]) {
				tmp=a[i];
				a[i]=a[j];
				a[j]= tmp;
			}
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i]==b[j]){
				c[i]=j;
				b[j]=0;
				break; 
			}
		}
	}
	
	for(i=0;i<n;i++){
		printf("%d ",c[i]);
	}
}
int main() {
    int n;
    printf("Enter the number of exam rooms: ");
    scanf("%d", &n);
    while (n < 2 || n > 30) {
        printf("Invalid input. Enter the number of exam rooms (2-30): ");
        scanf("%d", &n);
    }
    
    int p[n];
    int sum_ts = 0;
    int i;
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i]);
        sum_ts += p[i];
    }
    printf("Total number of students: %d\n", sum_ts);
    
    int m[n]; 
    int sum_m = 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &m[i]);
        sum_m += m[i];
    }
    printf("Total number of male students: %d\n", sum_m);
    
    int c;
    printf("Enter the number of absent students: ");
    scanf("%d", &c);
    printf("Number of rooms with more than 50%% absent students: %d\n", check_vang(n, p, c));
    // cau e
    int tb = sum_ts/n;
    printf("nguong toi thieu thi sinh: %d\n",tb+1);
    //cau f
    dieuchuyen(n,p,tb+1);
    //cau g
    int g=sum_ts/c;
    int k=sum_ts-g*c;
    if(k!=0) printf("%d\n",n-g-1);
    else printf("%d\n",n-g);
    //cau h
    sapxep(m,n);
    printf("\n"); 
    //cau i
    int d[n]; 
	for(i=0;i<n;i++){
		d[i]=c-p[i]; 
	} 
	sapxep1(d,n); 
    return 0;
}

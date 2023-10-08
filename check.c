#include<stdio.h>
#include<stdlib.h>
void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Hoán d?i hai ph?n t?
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
int check(int a[],int x){
	bubbleSort(a,x);
	int i;
	for(i=1;i<=x;i++){
		if(a[i-1]!=i) return 0;
	}
	return 1;
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		int x;
		scanf("%d",&x);
		int a[x],i;
		for(i=0;i<x;i++){
			scanf("%d",&a[i]);
		}
		if(check(a,x)==1) printf("1\n");
		else printf("0\n");
	}
}

/*tim kiem 1 tu trong 1 xau:
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello World";
    char word[] = "World";

    char *ptr = strstr(str, word);

    if (ptr != NULL) {
        printf("1");
    }
    else {
        printf("0");
    }
    return 0;
}
*/
/*sap xep tang dan
#include<stdio.h>
#include <stdlib.h>
int compar(const void *p1, const void *p2) {
     return (*(int*)p1 - *(int*)p2);
}
int main() {
     int arr[] = {5, 2, 8, 1, 3};
     int n = sizeof(arr) / sizeof(arr[0]);

     qsort(arr, n, sizeof(int), compar);

     for (int i = 0; i < n; i++) {
         printf("%d ", arr[i]);
     }

     return 0;
}
*/
/*sap xep noi bot
#include <stdio.h>
void bubbleSort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}
int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(array) / sizeof(array[0]);
    printf("Mang truoc khi sap xep: \n");
    printArray(array, size);
    bubbleSort(array, size);  
    printf("Mang sau khi sap xep: \n");
    printArray(array, size); 
    return 0;
}
*/
/*dao xau ky tu
#include<stdio.h>
#include<string.h>
void reversestring(char *str){
	if(str == NULL) return;
	int length=strlen(str);
	char temp;
	for(int i=0;i<length/2;i++){
		temp=str[i];
		str[i]=str[length-1-i];
		str[length-1-i]=str[i];
	}
}
char s[20];
	fflush(stdin);
	fgets(s,20,stdin);
	strrev(s);
	printf("%s",s);
int main(){
	char str[100];
	scanf("%s",str);
	reversestring(str);
	printf("%s",str);
	return 0;
}
*/
/* ham struct
#include<stdio.h>
#define des 100
typedef struct Restaurant
{
	char Name[30];
	char description[des];
	float rating;
	char add[100];
}eat;
void inra1(eat *k){
	printf("Ten nha hang: %s",k->Name);
	printf("Mo ta: %s",k->description);
	printf("Rating: %f\n",k->rating);
	printf("address: %s",k->add);
}
int main(){
	char str[30];
	eat K;
	printf("Ten nha hang: ");
	fflush(stdin);
	fgets(K.Name,30,stdin);
	printf("Mo ta: ");
	fflush(stdin);
	fgets(K.description,100,stdin);
	printf("Rating: ");
	scanf("%f",&K.rating);
	printf("address: ");
	fflush(stdin);
	fgets(K.add,100,stdin);
	inra1(&K);
	while(m!=6)
	{
		printf("Menu\n1.Nhap thong tin nha hang.\n2.In ra thong tin nha hang.\n3.Tim kiem nha hang theo ten.\n4.Tim kiem nha hang theo mo ta.\n5.Sap xep thu hang nha hang.\n6.Thoat\n");
		scanf("%d",&m);
		switch(m)
		{
			case 1: 
}*/
/*tach xau ki tu strtok
#include<stdio.h>
#include<string.h>
int main(){
	char c[1000];
	fgets(c,1000,stdin);
	char *token=strtok(c," ");
	while(token!=NULL){
		printf("%s\n",token);
		token=strtok(NULL," ");
	}
}*/
//
#include<stdio.h>
#include<string.h>
int main(){
	char c[1000],d[100];
	scanf("%s",d);
	fflush(stdin);
	fgets(c,1000,stdin);
	char *token=strtok(c," ");
	char a[20][50];int n=0;
	while(token!=NULL){
		if(strcmp(token,d)!=0){
			strcpy(a[n],token);
			n++;
		}
		token=strtok(NULL," ");
	}
	for(int i=0;i<n;i++){
		printf("%s ",a[i]);
		if(i!=n-1) printf(" ");
	}
}

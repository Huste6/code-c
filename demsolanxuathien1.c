#include <stdio.h>
#define MAX 1000000
int a[MAX], count[MAX];
int main() {
    int n;
    int i;
    scanf("%d", &n);
    for ( i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        count[a[i]]++;
    }
    for ( i = 0; i < n; i++) {
        if (count[i] > 0) {
            printf("%d xuat hien %d lan\n", i, count[i]);
        }
    }
    return 0;
}


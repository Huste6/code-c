#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *in;
    in = fopen("out.txt", "w");
    if (in == NULL) {
        printf("File not found!\n");
        return 1;
    } else {
        int n,m, sum = 0, val;
        printf("So luong dong: ");
        scanf("%d",&m);
        while(m--){
            int *p;
            printf("Enter the size of the list: ");
            scanf("%d", &n);

            p = (int *) malloc(n * sizeof(int));

            printf("Enter a list of %d numbers: ", n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &val);
                p[i] = val;
                sum += val;
            }

            for (int i = n - 1; i >= 0; i--) {
                fprintf(in, "%d ", p[i]);
            }

            fprintf(in, "%d \n", sum);
            free(p);
        }
        fclose(in);
    }
    return 0;
}

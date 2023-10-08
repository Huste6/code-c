#include <stdio.h>

float chenhlechgia(int n) {
    int mucdau, mucmoi;
    float tiendiencu = 0, tiendienmoi = 0;
    float giacu[6] = {1.728, 1.786, 2.074, 2.612, 2.919, 3.015};
    float giamoi[5] = {1.728, 2.074, 2.612, 3.111, 3.457};
    int canduoi[6] = {0, 51, 101, 201, 301, 401};
    int canduoimoi[5] = {0, 101, 201, 401, 701};

    if (n >= 0 && n <= 50) {
        mucdau = 1;
        mucmoi = 1;
    } else if (n >= 51 && n <= 100) {
        mucdau = 2;
        mucmoi = 1;
    } else if (n >= 101 && n <= 200) {
        mucdau = 3;
        mucmoi = 2;
    } else if (n >= 201 && n <= 300) {
        mucdau = 4;
        mucmoi = 3;
    } else if (n >= 301 && n <= 400) {
        mucdau = 5;
        mucmoi = 3;
    } else if (n >= 401 && n <= 700) {
        mucdau = 6;
        mucmoi = 4;
    } else {
        mucdau = 6;
        mucmoi = 5;
    }

    tiendiencu = (n - canduoi[mucdau-1]+1) * giacu[mucdau-1];
    tiendienmoi = (n - canduoimoi[mucmoi-1]+1) * giamoi[mucmoi-1];

    while (mucdau > 0 && mucmoi > 0) {
        tiendiencu += 50 * giacu[mucdau - 1 - 1];
        tiendienmoi += 100 * giamoi[mucmoi - 1 - 1];
        mucdau--;
        mucmoi--;
    }
    return tiendienmoi - tiendiencu;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%.2f\n", chenhlechgia(n));
    return 0;
}


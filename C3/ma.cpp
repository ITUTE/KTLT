#include<stdio.h>
#include <stdlib.h>
#define MAX 8
 
int A[MAX][MAX] = { 0 };//Kh?i t?o m?ng gi� tr? 0
int X[8] = { -2,-2,-1,-1, 1, 1, 2, 2};
int Y[8] = { -1, 1,-2, 2,-2, 2,-1, 1};
int dem = 0;//S? bu?c di
int n;
 
void xuat() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%2d ", A[i][j]);
        printf("\n");
    }
    printf("\n");
}
 
void diChuyen(int x, int y) {
    ++dem;//Tang gi� tr? bu?c di
    A[x][y] = dem;//��nh d?u d� di
    for (int i = 0; i < 8; i++)    {
        //Ki?m tra xem m� d� di h?t b�n c? chua
        if (dem == n * n) {
            xuat();
            exit(0);
        }
        //N?u chua di h?t b�n c? th� t?o bu?c di m?i
        int u = x + X[i];//t?o m?t v? tr� x m?i
        int v = y + Y[i];//t?o m?t v?i tr� y m?i
        //N?u h?p l? th� ti?n h�nh di chuy?n
        if (u >= 0 && u < n&&v >= 0 && v < n&& A[u][v] == 0)
            diChuyen(u, v);
    }
    //N?u kh�ng t�m du?c bu?c di th� ta ph?i tr? l?i c�c gi� tr? ban d?u
    --dem;
    A[x][y] = 0;
}
int main() {
    scanf("%d",&n);
    int a=0,b=0;
    diChuyen(a, b);
    
}


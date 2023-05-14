// Tuan06_CL2_MineSweeper.cpp : Defines the entry point for the console application.
// H? v� t�n: Nguy?n V�n A
// MSSV: 15110001
// Ch��ng tr?nh 1: Tr? ch�i MINESWEEPER

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <time.h>

#define MAX 20

//Khai b�o h�m
//2. In ma tr?n (k�ch th�?c dxc)
void inmt(int a[][MAX], int d, int c);
//H�m ph�t sinh s? ng?u nhi�n t? 0 �?n n-1
int random(int n)
{
	int a = rand();
	return a%n;
}
//H�m �?t nh?ng qu? m?n v�o v? tr� ng?u nhi�n trong b?i m?n
void datmin(int a[][MAX], int n, int somin);
//H�m t�nh to�n gi� tr? c�c � c?n l?i trong b?i m?n
void tinhsomin(int a[][MAX], int n);
//6.Vi?t h�m t?m v? tr� c?a � xung quanh c� nhi?u m?n nh?t
//tr? v? s? m?n nhi?u nh?t
//c�c tham s? d v� c l�u d?ng,c?t c?a � t?m ��?c
int timmax(int a[][MAX], int n, int &d, int &c);
//7*.Vi?t h�m t?m v�ng kxk c� �t m?n nh?t (k cho tr�?c)
int timmin(int a[][MAX], int n, int k, int &d, int &c);
//8**.Vi?t h�m cho bi?t v�ng ch?a nh?ng s? 0 li?n k? l?n
//nh?t g?m bao nhi�u �.
int timvung0(int a[][MAX], int n);

int main()
{
	int a[MAX][MAX];		//"b?i m?n"
	int n;					//k�ch th�?c
	int somin;				//s? m?n

	srand(time(NULL));
	//nh?p k�ch th�?c (>=5 v� <=MAX)
	do {
		cout << "Nhap kich thuoc (tu 5 den " <<MAX <<"):";
		cin >> n;
	} while (n<5 || n>MAX);
	//nh?p s? m?n (<=1/4 s? �)
	do {
		cout << "Nhap kich thuoc (tu 1 den " << n*n/4 << "):";
		cin >> somin;
	} while (somin<1 || somin>n*n/4);
	datmin(a, n, somin);
	tinhsomin(a, n);
	inmt(a, n, n);
	//t?m v�ng c� �t m?n nh?t
	int d, c;
	int m = timmin(a, n, 4, d, c);
	cout << m << endl << "(" << d << "," << c << ")" << endl;
	cout << timvung0(a, n) << endl;
    return 0;
}

//2. In ma tr?n (k�ch th�?c dxc)
void inmt(int a[][MAX], int d, int c)
{
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < c; j++) {
			cout.width(5);		//gi�ng th?ng c?t
			cout << a[i][j];
		}
		cout << endl;			//h?t 1 d?ng c?a ma tr?n
	}
}

//H�m �?t nh?ng qu? m?n v�o v? tr� ng?u nhi�n trong b?i m?n
void datmin(int a[][MAX], int n, int somin)
{
	int i, j;
	//kh?i g�n
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			a[i][j] = 0;
	//�?t m?n
	while (somin > 0) {
		i = random(n);
		j = random(n);
		if (a[i][j] == 0) {
			a[i][j] = -1;
			somin--;
		}
	}
}

//H�m t�nh to�n gi� tr? c�c � c?n l?i trong b?i m?n
void tinhsomin(int a[][MAX], int n)
{
	int i, j, k, l, dem;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (a[i][j] == 0)			//ch? x�t nh?ng � ko c� m?n
			{
				dem = 0;
				for (k = i - 1; k <= i + 1; k++)
					for (l = j - 1; l <= j + 1; l++)
						if (k >= 0 && k < n && l >= 0 && l < n &&
							(k != i || l != j) && a[k][l] == -1)
							dem++;
				a[i][j] = dem;		//l�u l?i s? m?n xung quanh
			}
}

//6.Vi?t h�m t?m v? tr� c?a � xung quanh c� nhi?u m?n nh?t
//tr? v? s? m?n nhi?u nh?t
//c�c tham s? d v� c l�u d?ng,c?t c?a � t?m ��?c
int timmax(int a[][MAX], int n, int &d, int &c)
{
	int max = a[0][0];
	d = c = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (max < a[i][j]) {
				max = a[i][j];
				d = i;
				c = j;
			}
	return max;
}
//7*.Vi?t h�m t?m v�ng kxk c� �t m?n nh?t (k cho tr�?c)
int timmin(int a[][MAX], int n, int k, int &d, int &c) {
	int i, j, dem, l, m;
	int min = k*k;
	d = c = 0;						//c?p nh?t l?i sau
	if (k<0 || k>n) return -1;		//l?i, ko h?p l?
	for (i = 0; i <= n - k; i++)	//duy?t t?t c? c�c kh?i kxk
		for (j = 0; j <= n - k; j++)
		{
			//b?t �?u �?m s? m?n trong v�ng kxk, g�c tr�i tr�n (i,j)
			dem = 0;
			for (l = 0; l < k; l++)
				for (m = 0; m < k; m++)
					if (a[i + l][j + m] == -1) dem++;
			if (dem < min) {
				min = dem;
				d = i;
				c = j;
			}
		}
	return min;
}
//8**.Vi?t h�m cho bi?t v�ng ch?a nh?ng s? 0 li?n k? l?n
//nh?t g?m bao nhi�u �.
//B? t�c: H�m �? quy d�ng �? loang tr�n ma tr?n
int dem0(int a[][MAX], int n, int d, int c) {
	int plus = 0;
	int count = 0;
	if (a[d][c] == 0) {
		plus = 1;
		a[d][c] = -2;
	}
	//x�t 8 � xung quanh � (d,c)
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++)
			if (a[d + i][c + j] == 0)		//n?u l� s? 0 th? g?i �? quy �? loang
				count = dem0(a, n, d + i, c + j);
	return count + plus;
}

int timvung0(int a[][MAX], int n)
{
	int max = 0;
	int temp = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (a[i][j] == 0)
				temp = dem0(a, n, i, j);
			if (max < temp) max = temp;
		}
	return max;
}

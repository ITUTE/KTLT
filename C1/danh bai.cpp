// Tuan03_CL2_CardGame.cpp : Defines the entry point for the console application.
// Ch��ng tr?nh c�i �?t tr? ch�i b�i c�o (�?m n�t)

#include "stdafx.h"
#include <time.h>
#include <iostream>
using namespace std;

#define MAX 52

//Khai b�o c?u tr�c 1 l� b�i
typedef struct LABAI {
	int nuoc;		//1: c�, 2: r�, 3: chu?n, 4: b�ch
	int nut;		//1 --> 13: 11 = J, 12 = Q, 13 = K
};

//Bi?n to�n c?c
LABAI bobai[52];

//Khai b�o c�c h�m x? l?
//1. T?o b? b�i t�y g?m 52 l�
void taobobai(LABAI bobai[52]);
//2. X�o tr?n th? t? trong b? b�i (ng?u nhi�n)
void xaobai(LABAI bobai[52]);
//3. Chia b�i cho n ng�?i ch�i, m?i ng�?i c?m k l� b�i
void chiabai(LABAI bobai[52], LABAI vanbai[MAX][MAX], int n, int k);
//4. �?m n�t b�i c�o: tr? v? s? n�t
//0 = b�, 10 = ba t�y, 1-9 = s? n�t
int demnut(LABAI b1, LABAI b2, LABAI b3);
//5. X�c �?nh ng�?i ch�i th?ng cu?c?
//Tr? v? s? l�?ng ng�?i th?ng cu?c, stt c?a nh?ng ng�?i th?ng, s? n�t cao nh?t
int kiemtrathang(LABAI vanbai[MAX][MAX], int n, int thang[], int &sonut);
//6. In b? b�i ra m�n h?nh �? quan s�t
void inbobai(LABAI bobai[52]);
//7. In th�ng tin 1 l� b�i ra m�n h?nh
void inlabai(LABAI b);

int main()
{
	srand(time(NULL));
	taobobai(bobai);
	xaobai(bobai);
	inbobai(bobai);
    return 0;
}

//�?nh ngh?a h�m
//1. T?o b? b�i t�y g?m 52 l�
void taobobai(LABAI bobai[52])
{
	int i = 0;		//s? th? t? t?ng l� trong b? b�i
	for (int nt = 1; nt <= 13; nt++)
		for (int nc = 1; nc <= 4; nc++)
		{
			bobai[i].nut = nt;
			bobai[i].nuoc = nc;
			i++;
		}
}
//2. X�o tr?n th? t? trong b? b�i (ng?u nhi�n)
//H�m t?o 1 s? nguy�n ng?u nhi�n c� gi� tr? t? 0 �?n n-1
int random(int n)
{
	if (!n) return 0;		//ch?ng l?i
	return rand() % n;
}

void xaobai(LABAI bobai[52])
{
	int solan = 20 + random(33);		//x�o t?i thi?u 20 l?n, t?i �a 52 l?n
	for (int i = 0; i < solan; i++)
	{
		int vt1 = random(52);			//l?y 2 v? tr� ng?u nhi�n
		int vt2 = random(52);
		LABAI t = bobai[vt1];
		bobai[vt1] = bobai[vt2];
		bobai[vt2] = t;
	}
}

//6. In b? b�i ra m�n h?nh �? quan s�t
void inbobai(LABAI bobai[52])
{
	for (int i = 0; i < 52; i++) {
		inlabai(bobai[i]);
		cout << endl;
	}
}

//7. In l� b�i
void inlabai(LABAI b)
{
	char s[5][10] = { "","co","ro","chuon","bich" };	//m?ng g?m 5 chu?i
	char t[3] = { 'J', 'Q', 'K' };
	if (b.nut == 1)
		cout << "A " << s[b.nuoc];
	else if (b.nut <= 10)
		cout << b.nut << " " << s[b.nuoc];
	else
		cout << t[b.nut-11] << " " << s[b.nuoc];
}



// Tuan08_CL2_QuayLui.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX 6
//Ki?u d? li?u bi?u di?n 1 v? tr� trong ma tr?n
//g?m 2 th�nh ph?n (d?ng,c?t)
struct POS {
	int row, col;
};

//C�c bi?n to�n c?c
//Ma tr?n �?u v�o
int a[MAX][MAX] = {
	{ 1,0,1,1,0,0 },
	{ 0,1,0,1,0,0 },
	{ 0,1,0,1,1,0 },
	{ 1,0,0,0,1,1 },
	{ 0,1,1,1,0,0 },
	{ 1,0,0,0,1,1 },
};
//M?ng �? ��nh d?u nh?ng � �? duy?t qua r?i (tr�nh l?p)
int mark[MAX][MAX];
//C?p c?a ma tr?n
int n = 6;

POS kq[100];		//m?ng l�u ��?ng �i hi?n t?i
POS minpath[100];	//l�u ��?ng �i ng?n nh?t
int nk = 0;			//�? d�i ��?ng �i hi?n t?i
int minn = n*n;		//�? d�i ��?ng �i ng?n nh?t

//M?t s? h�m x? l?
//1. Ki?m tra xem �? �?n ��ch hay ch�a
int check(POS cur, int dir) {
	switch (dir) {
	case 0:	if (cur.col == 0) return 1; break;//left
	case 1:	if (!cur.row) return 1; break;//top
	case 2:	if (cur.col == n - 1) return 1; break;//right
	case 3:	if (cur.row == n - 1) return 1; break;//bottom
	}
	return 0;
}
//2. Kh?i t?o to�n b? m?ng mark b?ng 0
void initmark() {
	for (int i = 0; i<n; i++)
		for (int j = 0; j<n; j++)
			mark[i][j] = 0;
}

//3. Gi?i thu?t �? quy v� quay lui �? t?m ��?ng �i
void findpath2(POS cur, int dir)
{
	if (check(cur, dir)) //�? �i ��?c �?n ��ch th? in kq
	{
		cout << "Tim duoc duong di:\n";
		for (int i = 0; i<nk; i++)
			cout << "(" << kq[i].row << "," << kq[i].col << ")-->";
		cout << "end\n";
		//1. L�u l?i ��?ng �i ng?n nh?t
		//if (nk<minn) {
		//	minn = nk;
		//	//memcpy(minpath,kq,nk*sizeof(POS));
		//	for (int i=0; i<nk; i++)
		//		minpath[i] = kq[i];
		//}
	}
	//Th? 8 � xung quanh � �ang �?ng, xem c� �i ��?c ti?p ko
	for (int i = 1; i >= -1; i--)
		for (int j = 1; j >= -1; j--)
			if ((i || j) && cur.row + i >= 0 && cur.row + i<n
				&& cur.col + j >= 0 && cur.col + j<n) {
				POS p;						//l�u � ti?p theo c� th? �i
				p.row = cur.row + i;
				p.col = cur.col + j;
				if (a[p.row][p.col] == a[cur.row][cur.col] &&
					!mark[p.row][p.col]) {	//ch�a �i v� �i ��?c
					mark[p.row][p.col] = 1; //��nh d?u l� �? �i qua
					kq[nk++] = p;
					findpath2(p, dir);		//�? quy �? ti?p t?c t?m ��?ng
					nk--;					//quay lui, h?y ��?ng �i th?
					mark[p.row][p.col] = 0; //h?y ��nh d?u
				}
			}
}

int main()
{
	initmark();		//kh?i t?o ma tr?n ��nh d?u
					
	POS start;		//v? tr� xu?t ph�t (� 2,2)
	start.row = 2;
	start.col = 2;
	mark[start.row][start.col] = 1;	//��nh d?u �? duy?t
	kq[nk++] = start;
	findpath2(start, 1);	//l�n c?nh tr�n c?a ma tr?n
    return 0;
}



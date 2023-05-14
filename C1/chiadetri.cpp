// Buoi13_CL1_ChiaDeTri.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#define MAX 100

//VD1. T?m ki?m nh? ph�n tr�n m?ng c� th? t?
//C�ch 1: s? d?ng �? quy
int BinarySearch1(int a[], int x, int left, int right)
{
	if (left > right) return -1;		//ko t?m th?y khi k.gian r?ng
	int mid = (left + right) / 2;		//t?m trung �i?m c?a k.gian
	if (x == a[mid]) return mid;		//t?m th?y --> k?t lu?n
	if (x < a[mid]) 
		return BinarySearch1(a, x, left, mid - 1);
	return BinarySearch1(a, x, mid + 1, right);
}
//C�ch 2: kh�ng d�ng �? quy --> d�ng v?ng l?p
int BinarySearch2(int a[], int n, int x)
{
	int left = 0, right = n - 1;		//bi?n c?c b?
	while (left <= right)				//k.gian t?m ki?m c?n �t nh?t 1 p.t?
	{
		int mid = (left + right) / 2;	//t�nh trung �i?m
		if (x == a[mid]) return mid;	//t?m th?y
		else if (x < a[mid]) right = mid - 1;	//co bi�n ph?i
		else left = mid + 1;					//co bi�n tr�i
	}
	return -1;							//ko t?m th?y
}

//VD2: S?p x?p tr?n (MergeSort)
//2.1 T�ch m?ng (a,n) th�nh 2 m?ng con (T1, n1) v� (T2, n2)
void tachmang(int a[], int n, int T1[], int &n1, int T2[], int &n2)
{
	n1 = n / 2;
	n2 = n - n1;
	for (int i = 0; i < n1; i++)
		T1[i] = a[i];
	for (int i = 0; i < n2; i++)
		T2[i] = a[n1+i];
}

//2.2 Tr?n 2 m?ng (T1, n1) v� (T2, n2) t�ng d?n th�nh (a, n) t�ng d?n
void tronmang(int T1[], int n1, int T2[], int n2, int a[], int &n)
{
	n = n1 + n2;
	int i = 0, j = 0, k = 0;		//i ch?y tr�n T1, j tr�n T2, k tr�n a
	while (i < n1 && j < n2)		//c? 2 m?ng con �?u c?n ph?n t?
	{
		if (T1[i] < T2[j]) a[k++] = T1[i++];
		else a[k++] = T2[j++];
	}
	while (i < n1) a[k++] = T1[i++];//�? ph?n c?n l?i c?a T1 v�o a (n?u c�)
	while (j < n2) a[k++] = T2[j++];//�? ph?n c?n l?i c?a T2 v�o a (n?u c�)
}

//2.3 S?p x?p tr?n
void MergeSort(int a[], int n)
{
	int *T1, *T2, n1, n2;
	T1 = new int[n / 2 + 1];
	T2 = new int[n / 2 + 1];
	//B1. t�ch
	tachmang(a, n, T1, n1, T2, n2);
	//B2. s?p
	if (n1 > 1) MergeSort(T1, n1);		//s?p ph?n 1 n?u c?n thi?t
	if (n2 > 1) MergeSort(T2, n2);		//s?p ph?n 2 n?u c?n thi?t
	//B3. tr?n
	tronmang(T1, n1, T2, n2, a, n);
	delete T1;
	delete T2;
}

//VD3: PartionSort (QuickSort)
void PartitionSort(int a[], int n)
{
	//Khai b�o
	int *P1, *P2, *P3, n1 = 0, n2 = 0, n3 = 0;
	P1 = new int[n];
	P2 = new int[n];
	P3 = new int[n];
	int pivot = a[n / 2];
	//B1. t�ch
	for (int i = 0; i < n; i++)
		if (a[i] < pivot) P1[n1++] = a[i];		//b? v�o P1
		else if (a[i] == pivot) P2[n2++] = a[i];
		else P3[n3++] = a[i];
	//B2. s?p P1 v� P3 n?u c?n thi?t
	if (n1 > 1) PartitionSort(P1, n1);
	if (n3 > 1) PartitionSort(P3, n3);
	//B3. n?i - gh�p
	int k = 0;			//ch?y tr�n a
	for (int i = 0; i < n1; i++) a[k++] = P1[i];
	for (int i = 0; i < n2; i++) a[k++] = P2[i];
	for (int i = 0; i < n3; i++) a[k++] = P3[i];
	delete P1; delete P2; delete P3;
	//tham kh?o th�m c�ch d�ng h�m qsort() c?a C/C++
	//tham kh?o th�m c�ch d�ng h�m bsearch() c?a C/C++
}

//VD4: t?m �?c chung l?n nh?t b?ng pp gi?m �? tr? (�? quy)
int uscln1(int a, int b)
{
	if (a == 0 && b == 0) return 0;			//l?i
	if (a == 0) return b;
	if (b == 0) return a;					//�?c bi?t
	if (a == b) return a;					//suy bi?n
	if (a > b) return uscln1(a - b, b);
	return uscln1(a, b - a);
}

int uscln2(int a, int b)
{
	if (a == 0 && b == 0) return 0;			//l?i
	if (a == 0) return b;
	if (b == 0) return a;					//�?c bi?t
	return uscln2(b, a%b);
}
//VD5: s?p x?p ch�n (InsertionSort)
//h�m ph?: ch�n s? x v�o m?ng c� th? t? sao cho m?ng k?t qu? v?n c� th? t?
void insert(int a[], int &n, int x)
{
	int i = n - 1;				//xu?t ph�t t? cu?i m?ng
	while (i >= 0 && a[i] > x)	//v?a t?m s? <=x �?u ti�n t? b�n ph?i sang
		a[i + 1] = a[i--];		//v?a d?i nh?ng s? >x ra sau
	a[i + 1] = x;				//ch�n x v�o sau v? tr� t?m th?y/d?ng l?i
	n++;
}

void InsertionSort(int a[], int n)
{
	int n1 = n - 1;							//k�ch th�?c c?a m?ng con ph�a tr�?c
	if (n1 > 1) InsertionSort(a, n1);		//s?p ph?n �?u cho c� th? t?
	insert(a, n1, a[n - 1]);				//ch�n p.t? cu?i v�o m?ng con ph�a tr�?c
}

//BT �p d?ng: t?m nh? ph�n tr�n ma tr?n
//H�m tr? v? true n?u t?m th?y, ng�?c l?i tr? v? false
//(i, j) l�u v? tr� t?m th?y x, n?u ko th?y th? i=-1 v� j=-1
bool BSearchMatrix(int a[][MAX], int d, int c, int x, int &i, int &j)
{
	int left = 0, right = d*c - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (x == a[mid / c][mid%c]) {		//t?m th?y
			i = mid / c;
			j = mid%c;
			return true;
		}
		else if (x < a[mid / c][mid%c]) right = mid - 1;
		else left = mid + 1;
	}
	//ko th?y
	i = j = -1;
	return false;
}

int main()
{
	//int a[20] = { 1,2,4,6,7,9,15,22,30,50 };
	//int n = 10, x = 2;
	//int k = BinarySearch1(a, x, 0, n - 1);		//t?m trong to�n b? m?ng
	//cout << k << endl;
	//k = BinarySearch2(a,n,x);					//t?m trong to�n b? m?ng
	//cout << k << endl;

	int a[20] = { 9,2,6,4,3,1,7,5,8 };
	int n = 9;
	MergeSort(a, n);
	for (int i = 0; i < n; i++)
		cout << a[i] << "  ";
	cout << endl;

    return 0;
}



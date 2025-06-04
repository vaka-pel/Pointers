#include<iostream>
using namespace std;
//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl; // вывад переменной "а" на экран
	cout << &a << endl; // взятие адреса переменной "а" прямо при выводе
	cout << pa << endl; // вывод адреса переменной "а" хранящегося в указателе "ра"
	cout << *pa << endl; // разименование указателя "ра" и вывод на экран значения по адресу; 

	int* pb;
	int b = 3;
	pb = &b;
	cout << pb << endl;
	cout << *pb << endl;


	// int - "int"
	// *int - указатель на "int"


/*
& - оператор взятия адреса
* - оператор разименования
*/
#endif POINTERS BASICS

	const int n = 5;
	int arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

}
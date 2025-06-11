#include<iostream>
using namespace std;


void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* Insert(int arr[], int& n, const int value, const int index);
int* Erase(int arr[], int& n, const int index);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int** push_row_back(int** arr, int& rows, const int cols);
void push_col_back(int** arr, const int rows, int& cols);


//#define DYNAMIC_MEMORY1
#define DYNAMIC_MEMORY2
void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = Insert(arr, n, value, index);
	Print(arr, n);

	arr = Erase(arr, n, index);
	Print(arr, n);


	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	delete[] arr;
	// Memory leak - утечка памяти.
}

#endif  DYNAMIC_MEMORY1

int rows;
int cols;
cout << "Введите количество строк: "; cin >> rows;
cout << "Введите количество элементов строки: "; cin >> cols;
// Создаем массив указателей
int** arr = new int* [rows];
//выделяем память под строки
for (int i = 0; i < rows; i++)
{
	arr[i] = new int[cols];
}

FillRand(arr, rows, cols);
Print(arr, rows, cols);

arr = push_row_back(arr, rows, cols);
FillRand(arr[rows - 1], cols, 100, 1000);
Print(arr, rows, cols);

push_col_back(arr, rows, cols);
for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand() % 1000;
Print(arr, rows, cols);


//сначала удаляем строки двумерного массива
for (int i = 0; i < rows; i++)
{
	delete[] arr[i];
}
// толко теперь можно удалить массив
delete[] arr;
}
void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;	//Через арифметику указателей и оператор разыменования
	}
}
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}

	}
}
void Print(int arr[], const int n)
{
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";		//Через оператор индексирования (Subscript operator)
	}
	cout << endl;
}

void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

}
int* push_back(int arr[], int& n, const int value)
{
	//  Создаем буферный массив нужного размера
	int* buffer = new int[n + 1];

	// копируем все элементы из исходного массива в буферный
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	// удаляем исходный мвссив
	delete[] arr;

	// подменяем адрес исходного массива
	arr = buffer;
	buffer = nullptr; // nullptr - указатель на ноль

	// далее в массиве arr появляется элемент, в который можно сохранить добавляемое значение
	arr[n] = value;

	//после добавления элемента в массив, количество его элементов увеличивается на 1
	n++;

	//Mission complete - значение добавлено
	return arr;
}
int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;

	buffer[0] = value;

	n++;
	return buffer;

}
int* Insert(int arr[], int& n, const int value, const int index)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
		buffer[i < index ? i : i + 1] = arr[i];
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}
int* Erase(int arr[], int& n, const int index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
		buffer[i] = arr [i < index ? i : i + 1];
	delete[] arr;
	
	return buffer;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
int** push_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];

	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];

	}
	delete[] arr;


	buffer[rows] = new int[cols] {};

	rows++;
	return buffer;
}
void push_col_back(int** arr, const int rows, int& cols)
{
	for(int i = 0; i < rows; i++)
	{
	int* buffer = new int[cols + 1] {};
	for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
	delete[] arr[i];
	arr[i] = buffer;
	}


cols++;
}
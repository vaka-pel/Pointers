#include<iostream>
using namespace std;

template<typename T> T** Allocate(const int rows, const int cols);
template<typename T> void Clear(T**& arr, const int rows, const int cols);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
template<typename T> void Print(T arr[], const int n);
template<typename T> void Print(T** arr, const int rows, const int cols);

template<typename T> T* push_back(T arr[], int& n, const T value);
template<typename T> T* push_front(T arr[], int& n, const T value);

template<typename T> T* pop_back(T arr[], int& n);
template<typename T> T* pop_front(T arr[], int& n);

template<typename T> T* insert(T arr[], int& n, const T value, const int index);
template<typename T> T* erase(T arr[], int& n, const int index);


template<typename T> T** push_row_back(T** arr, int& rows, const int cols);
template<typename T> T** push_row_front(T** arr, int& rows, const int cols);
template<typename T> T** insert_row(T** arr, int& rows, const int cols, const int index);
template<typename T> T** pop_row_back(T** arr, int& rows, const int cols);
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols);
template<typename T> T** erase_row(T** arr, int& rows, const int cols, const int index);

template<typename T> void push_col_back(T** arr, const int rows, int& cols);
template<typename T> void push_col_front(T** arr, const int rows, int& cols);
template<typename T> void insert_col(T** arr, const int rows, int& cols, const int index );
template<typename T> void pop_col_back(T** arr, const int rows, int& cols);
template<typename T> void pop_col_front(T** arr, const int rows, int& cols);
template<typename T> void erase_col(T** arr, const int rows, int& cols, const int index );



//#define DYNAMIC_MEMORY1
#define DYNAMIC_MEMORY2

#define DATATYPE double
typedef double DataType;


void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	DataType* arr = new DataType[n];

	FillRand(arr, n);
	Print(arr, n);

	DataType value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

    cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

    arr = pop_back(arr, n);
	Print(arr, n);

    arr = pop_front(arr, n);
	Print(arr, n);

	
	// Insert - добавляет значение раздвигая под него массив
	int index;
    cout << "Введите индекс добавляемого элемента: "; cin >> index;
    cout << "Введите значение добавляемого элемента: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);
    
	// Erase - удаляет значение (элемент) массива по индексу
    cout << "Введите индекс удаляемого элемента: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	
	delete[] arr;
	// Memory leak - утечка памяти.
}

#endif  DYNAMIC_MEMORY1
#ifdef DYNAMIC_MEMORY2
int rows;
int cols;
cout << "Введите количество строк: "; cin >> rows;
cout << "Введите количество элементов строки: "; cin >> cols;


int** arr = Allocate<int>(rows, cols);
/*int** arr = new int* [rows];// Создаем массив указателей

for (int i = 0; i < rows; i++)//выделяем память под строки
{
	arr[i] = new int[cols];
}*/

FillRand(arr, rows, cols);
Print(arr, rows, cols);

arr = push_row_back(arr, rows, cols);
FillRand(arr[rows - 1], cols, 100, 1000);
Print(arr, rows, cols);

arr = push_row_front(arr, rows, cols);
Print(arr, rows, cols);


int index;
cout << "Введите индекс добавляемого значения: "; cin >> index;
arr = insert_row(arr, rows, cols, index);
Print(arr,rows, cols); 

arr = pop_row_back(arr, rows, cols);
Print(arr,rows, cols); 

arr = pop_row_front(arr, rows, cols);
Print(arr,rows, cols); 

cout << "Введите индекс удаляемого значения: "; cin >> index;
arr = erase_row(arr, rows, cols, index);
Print(arr,rows, cols); 


push_col_back(arr, rows, cols);
for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand() % 1000;
Print(arr, rows, cols);

push_col_front(arr, rows, cols);
for (int i = 0; i < rows; i++)arr[i][0] = rand() % 10;
Print(arr, rows, cols);

insert_col(arr, rows, cols, index);
for (int i = 0; i < rows; i++)arr[i][index] = rand() % 1000;
Print(arr, rows, cols);

pop_col_back(arr, rows, cols);
Print(arr, rows, cols);

pop_col_front(arr, rows, cols);
Print(arr, rows, cols);

cout << "Введите индекс удаляемого значения: "; cin >> index;
erase_col(arr, rows, cols, index);
Print(arr, rows, cols);

//Allocate(rows, cols);
Clear(arr, rows, cols);


}


#endif  DYNAMIC_MEMORY2





template<typename T> T** Allocate(const int rows, const int cols)
{
	T** buffer = new T* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new T[cols];
	}
	return buffer;
}

template<typename T> void Clear(T**& arr, const int rows, const int cols)
{
	//сначала удаляем строки двумерного массива
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	// толко теперь можно удалить массив
	delete[] arr;

	arr = nullptr;
}



void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;	//Через арифметику указателей и оператор разыменования
	}
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;	//Через арифметику указателей и оператор разыменования
		arr[i] /= 100;
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
void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = double(rand() % (maxRand - minRand) + minRand) / 100;
		}

	}
}
template<typename T> void Print(T arr[], const int n)
{
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";		//Через оператор индексирования (Subscript operator)
	}
	cout << endl;
}

template<typename T> void Print(T** arr, const int rows, const int cols)
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
template<typename T> T* push_back(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];//  Создаем буферный массив нужного размера
	for (int i = 0; i < n; i++)// копируем все элементы из исходного массива в буферный
	{
		buffer[i] = arr[i];
	}
	delete[] arr;// удаляем исходный мвссив
	arr = buffer;// подменяем адрес исходного массива
	buffer = nullptr; // nullptr - указатель на ноль
	arr[n] = value;// далее в массиве arr появляется элемент, в который можно сохранить добавляемое значение
	n++;//после добавления элемента в массив, количество его элементов увеличивается на 1
	return arr;//Mission complete - значение добавлено
}
template<typename T> T* push_front(T arr[], int& n, const T value)
{
	T* buffer = new T[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;

	buffer[0] = value;

	n++;
	return buffer;

}
template<typename T> T* insert(T arr[], int& n, const T value, const int index)
{
	T* buffer = new T[n + 1]{};
	for (int i = 0; i < n; i++)buffer[i < index ? i : i + 1] = arr[i];
	delete[] arr;
	buffer[index] = value;
	n++;
	return buffer;
}
template<typename T> T* erase(T arr[], int& n, const int index)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
		buffer[i] = arr [i < index ? i : i + 1];
	delete[] arr;
	
	return buffer;
}
template<typename T> T* pop_back(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T> T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}
template<typename T> T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];

	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new T[cols] {};
	rows++;
	return buffer;
}
template<typename T> T** push_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows + 1];

	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new T[cols] {};
	rows++;
	return buffer;
}
template<typename T> T** insert_row(T** arr, int& rows, const int cols, const int index)
{
	T** buffer = new T* [rows + 1] {};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[index] = new T[cols] {};
	rows++;
	return buffer;

}
template<typename T> T** pop_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < rows - 1; i++)buffer[i] = arr[i];
	delete[] arr;
	rows--;
	return buffer;
}
template<typename T> T** pop_row_front(T** arr, int& rows, const int cols)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < rows - 1; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	rows--;
	return buffer;
}
template<typename T> T** erase_row(T** arr, int& rows, const int cols, int index)
{
	T** buffer = new T* [rows - 1];
	for (int i = 0; i < rows - 1; i++) i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[] arr;
	rows--;
	return buffer;
}


template<typename T> void push_col_back(T** arr, const int rows, int& cols)
{
	for(int i = 0; i < rows; i++)
	{
	T* buffer = new T[cols + 1] {};
	for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
	delete[] arr[i];
	arr[i] = buffer;
	}
 cols++;
}
template<typename T> void push_col_front(T** arr, const int rows, int& cols)
{
	for(int i = 0; i < rows; i++)
	{
	T* buffer = new T[cols + 1] {};
	for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
	delete[] arr[i];
	arr[i] = buffer;
	}
 cols++;
}
template<typename T> void pop_col_back(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1] {};
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;

}
template<typename T> void pop_col_front(T** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols - 1] {};
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}

	--cols;

}
template<typename T> void insert_col(T** arr, int rows, int& cols, int index)
{
	if (index == 0) push_col_front(arr, rows, cols);
	else if (index == cols) push_col_back(arr, rows, cols);
	else
	{
		for (int i = 0; i < rows; i++)
		{
			T* buffer = new T[cols + 1] {};
			for (int j = 0; j < cols; j++)
			{
				//if (j < index) buffer[j] = arr[i][j];
				//else buffer[j + 1] = arr[i][j];
				buffer[j < index ? j : j + 1] = arr[i][j];
			}
			delete[] arr[i];
			arr[i] = buffer;
		}
		cols++;
	}

}
template<typename T> void erase_col(T** arr, int rows, int& cols, int index)
{
	if (index == 0) pop_col_front(arr, rows, cols);
	else if (index == cols - 1) pop_col_back(arr, rows, cols);
	else
	{
		for (int i = 0; i < rows; ++i)
		{
			T* buffer = new T[cols - 1] {};
			for (int j = 0; j < cols - 1; ++j)
			{
				if (j < index) buffer[j] = arr[i][j];
				else buffer[j] = arr[i][j + 1];
			}
			delete[] arr[i];
			arr[i] = buffer;
		}
		cols--;
	}
}

#include<iostream>
using namespace std;

int** Allocate(const int rows, const int cols);
void Clear(int**& arr, const int rows, const int cols);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int* Insert(int arr[], int& n, const int value, const int index);
int* Erase(int arr[], int& n, const int index);


int** push_row_back(int** arr, int& rows, const int cols);
int** push_row_front(int** arr, int& rows, const int cols);
int** Insert_row(int** arr, int& rows, const int cols, const int index);
int** pop_row_back(int** arr, int& rows, const int cols);
int** pop_row_front(int** arr, int& rows, const int cols);
int** erase_row(int** arr, int& rows, const int cols, const int index);

void push_col_back(int** arr, const int rows, int& cols);
void push_col_front(int** arr, const int rows, int& cols);
void Insert_col(int** arr, const int rows, int& cols, const int index );
void pop_col_back(int** arr, const int rows, int& cols);
void pop_col_front(int** arr, const int rows, int& cols);
void erase_col(int** arr, const int rows, int& cols, const int index );




//#define DYNAMIC_MEMORY1
#define DYNAMIC_MEMORY2
void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY1
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

    cout << "������� ����������� ��������: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

    arr = pop_back(arr, n);
	Print(arr, n);

    arr = pop_front(arr, n);
	Print(arr, n);

	
	// Insert - ��������� �������� ��������� ��� ���� ������
	int index;
    cout << "������� ������ ������������ ��������: "; cin >> index;
    cout << "������� �������� ������������ ��������: "; cin >> value;
	arr = insert(arr, n, value, index);
	Print(arr, n);
    
	// Erase - ������� �������� (�������) ������� �� �������
    cout << "������� ������ ���������� ��������: "; cin >> index;
	arr = erase(arr, n, index);
	Print(arr, n);

	
	delete[] arr;
	// Memory leak - ������ ������.
}

#endif  DYNAMIC_MEMORY1
#ifdef DYNAMIC_MEMORY2
int rows;
int cols;
cout << "������� ���������� �����: "; cin >> rows;
cout << "������� ���������� ��������� ������: "; cin >> cols;

int** arr = new int* [rows];// ������� ������ ����������

for (int i = 0; i < rows; i++)//�������� ������ ��� ������
{
	arr[i] = new int[cols];
}







FillRand(arr, rows, cols);
Print(arr, rows, cols);

arr = push_row_back(arr, rows, cols);
FillRand(arr[rows - 1], cols, 100, 1000);
Print(arr, rows, cols);

arr = push_row_front(arr, rows, cols);
Print(arr, rows, cols);


int index;
cout << "������� ������ ������������ ��������: "; cin >> index;
arr = Insert_row(arr, rows, cols, index);
Print(arr,rows, cols); 

arr = pop_row_back(arr, rows, cols);
Print(arr,rows, cols); 

arr = pop_row_front(arr, rows, cols);
Print(arr,rows, cols); 

cout << "������� ������ ���������� ��������: "; cin >> index;
arr = erase_row(arr, rows, cols, index);
Print(arr,rows, cols); 


push_col_back(arr, rows, cols);
for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand() % 1000;
Print(arr, rows, cols);

push_col_front(arr, rows, cols);
for (int i = 0; i < rows; i++)arr[i][0] = rand() % 10;
Print(arr, rows, cols);

Insert_col(arr, rows, cols, index);
for (int i = 0; i < rows; i++)arr[i][index] = rand() % 1000;
Print(arr, rows, cols);

pop_col_back(arr, rows, cols);
Print(arr, rows, cols);

pop_col_front(arr, rows, cols);
Print(arr, rows, cols);

cout << "������� ������ ���������� ��������: "; cin >> index;
erase_col(arr, rows, cols, index);
Print(arr, rows, cols);

//Allocate(rows, cols);
Clear(arr, rows, cols);


}


#endif  DYNAMIC_MEMORY2





int** Allocate(const int rows, const int cols)
{
	int** buffer = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols];
	}
	return buffer;
}

void Clear(int**& arr, const int rows, const int cols)
{
	//������� ������� ������ ���������� �������
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	// ����� ������ ����� ������� ������
	delete[] arr;

	arr = nullptr;
}



void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;	//����� ���������� ���������� � �������� �������������
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
		cout << arr[i] << "\t";		//����� �������� �������������� (Subscript operator)
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
	int* buffer = new int[n + 1];//  ������� �������� ������ ������� �������
	for (int i = 0; i < n; i++)// �������� ��� �������� �� ��������� ������� � ��������
	{
		buffer[i] = arr[i];
	}
	delete[] arr;// ������� �������� ������
	arr = buffer;// ��������� ����� ��������� �������
	buffer = nullptr; // nullptr - ��������� �� ����
	arr[n] = value;// ����� � ������� arr ���������� �������, � ������� ����� ��������� ����������� ��������
	n++;//����� ���������� �������� � ������, ���������� ��� ��������� ������������� �� 1
	return arr;//Mission complete - �������� ���������
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
	int* buffer = new int[n + 1]{};
	for (int i = 0; i < n; i++)buffer[i < index ? i : i + 1] = arr[i];
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

	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new int[cols] {};
	rows++;
	return buffer;
}
int** push_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows + 1];

	for (int i = 0; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[0] = new int[cols] {};
	rows++;
	return buffer;
}
int** Insert_row(int** arr, int& rows, const int cols, const int index)
{
	int** buffer = new int* [rows + 1] {};
	for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < rows; i++)buffer[i + 1] = arr[i];
	delete[] arr;
	buffer[index] = new int[cols] {};
	rows++;
	return buffer;

}
int** pop_row_back(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)buffer[i] = arr[i];
	delete[] arr;
	rows--;
	return buffer;
}
int** pop_row_front(int** arr, int& rows, const int cols)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	rows--;
	return buffer;
}
int** erase_row(int** arr, int& rows, const int cols, int index)
{
	int** buffer = new int* [rows - 1];
	for (int i = 0; i < rows - 1; i++) i < index ? buffer[i] = arr[i] : buffer[i] = arr[i + 1];
	delete[] arr;
	rows--;
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
void push_col_front(int** arr, const int rows, int& cols)
{
	for(int i = 0; i < rows; i++)
	{
	int* buffer = new int[cols + 1] {};
	for (int j = 0; j < cols; j++)buffer[j + 1] = arr[i][j];
	delete[] arr[i];
	arr[i] = buffer;
	}
 cols++;
}
void pop_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	--cols;

}
void pop_col_front(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		int* buffer = new int[cols - 1] {};
		for (int j = 0; j < cols - 1; j++) buffer[j] = arr[i][j + 1];
		delete[] arr[i];
		arr[i] = buffer;
	}

	--cols;

}
void Insert_col(int** arr, int rows, int& cols, int index)
{
	if (index == 0) push_col_front(arr, rows, cols);
	else if (index == cols) push_col_back(arr, rows, cols);
	else
	{
		for (int i = 0; i < rows; i++)
		{
			int* buffer = new int[cols + 1] {};
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
void erase_col(int** arr, int rows, int& cols, int index)
{
	if (index == 0) pop_col_front(arr, rows, cols);
	else if (index == cols - 1) pop_col_back(arr, rows, cols);
	else
	{
		for (int i = 0; i < rows; ++i)
		{
			int* buffer = new int[cols - 1] {};
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

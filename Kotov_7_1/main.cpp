#include <iostream>
#include <string>
using namespace std;

bool is_palindrom(int n)
{
	string str = to_string(n);
	int len = str.length();
	for (int i = 0; i < len / 2; i++)
	{
		if (str[i] != str[len - 1 - i])
		{
			return false;
		}
	}
	return true;
}

void analyze_array(int arr[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (!is_palindrom(arr[i]))
		{
			cout << "Элемент массива " << arr[i] << " на позиции " << i << " не полиндром!\n";
		}
	}
	cout << "Больше нет элементов массива, которые являются полиндромами: \n";
}

void reverse_array(int arr[], int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		swap(arr[i], arr[n - i - 1]);
	}
}

int main()
{
	setlocale(LC_ALL, "russian");

	cout << "Выполнил Котов А.А. УМЛ-112\n";
	cout << "Программа для работы с массивом\n";

	int arr[] = {101, 121, 622, 332, 444};
	int size = sizeof(arr) / sizeof(int);

	cout << "Исходный массив: \n";
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
	
	analyze_array(arr, size);

	cout << "Обратный массив: \n";
	reverse_array(arr, size);

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";

	system("pause");
}

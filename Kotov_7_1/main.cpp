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

void enter_mass(int* array, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << "Введите число: \n";
		cin >> array[i];
	}
}

void show_mass(int* array, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout << array[i] << " ";
	}
	cout << "\n";
}

double average(int* array, int count)
{
	double sum = 0;
	for (int i = 0; i < count; i++)
	{
		sum += array[i];
	}
	return sum / count;
}

int* add_element(int* array, int count)
{
	int* dest = new int[count + 1];
	for (int i = 0; i < count; i++)
	{
		dest[i] = array[i];
	}
	dest[count] = average(array, count);
	delete[] array;
	return dest;
}

int main()
{
	setlocale(LC_ALL, "russian");
	cout << "Выполнил Котов А.А. УМЛ-112\n";
	cout << "Программа для работы с массивом\n";

	int size = 5;
	int* arr = new int[size]{101, 121, 622, 332, 444};

	cout << "Исходный массив: \n";
	show_mass(arr, size);

	analyze_array(arr, size);

	cout << "Обратный массив: \n";
	reverse_array(arr, size);

	show_mass(arr, size);

	cout << "Введите новый размер массива: ";
	arr = new int[size];
	cin >> size;

	enter_mass(arr, size);

	cout << "Элементы введенного массива\n";

	show_mass(arr, size);

	cout << "Среднее арифметическое массива равно\n";

	cout << average(arr, size) << "\n";

	arr = add_element(arr, size);

	size++;

	cout << "Массив с добавленным элементом\n";

	show_mass(arr, size);

	delete[] arr;

	system("pause");
}

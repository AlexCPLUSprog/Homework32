#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct route {
	int num = 0;
	string type;
	string start;
	string finish;	
};


// Задача 1
template <typename T>
void Matrix(T*& arr, int rows, int cols) {
	arr = new T[rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}
}

// Задача 2
void change(string& str, char& ch1, char& ch2) {
    replace(str.begin(), str.end(), ch1, ch2);
    cout << str; 
}

// Задача 3
void show_route(route& R) {
	cout << "Номер маршрута: " << R.num << endl;
	cout << "Вид транспорта: " << R.type << endl;
	cout << "Начальная остановка: " << R.start << endl;
	cout << "Конечная остановка: " << R.finish << endl;
	cout << endl;
}

void input_route(route& R) {
	cout << "Введите номер транспорта: ";
	cin >> R.num;
	cout << "Введите тип транспорта: ";
	cin >> R.type;
	cout << "Введите остановку начала маршрута: ";
	cin >> R.start;
	cout << "Введите конечную остановку: ";
	cin >> R.finish;
}

int sum_route(route& R, int num, int fare) {
	int sum = 0;
	cout << "Стоимость проезда " << num << " человек составила: \n";
	return sum = num * fare;
}


int main() {
	setlocale(LC_ALL, "ru");
	int n,m;

	// Задание 1
	cout << "Задача 1.\n";    
	int** arr1 = nullptr;
	cout << "Введите длину строки массива: \n";
	cin >> n;
	cout << "Введите длину столбца массива: \n";
	cin >> m;
	Matrix(arr1, n, m);
	srand(time(NULL));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr1[i][j] = rand() % 30;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr1[i][j] << "\t";
		}
		cout << "\n";
	}
	for (int i = 0; i < n; i++) 
		delete[] arr1[i];	
	delete[] arr1;

    // Задание 2
    cout << "Задача 2.\n";
    string str = "Hello World";
    char ch1 = 'l', ch2 = 'o';
    change(str, ch1, ch2);
	cout << "\n\n";

	// Задание 3
	cout << "Задача 3\n";
	const int fare = 32;
	route Bus{ 27, "автобус", "ЖБИ", "СТЦ Мега" };
	route Tram{ 19, "трамвай", "Волгоградская","Машиностроителей" };
	route Trol{ 35, "троллейбус", "Крауля", "Ботаническая" };
	show_route(Bus);
	cout << "Введите количество человек: \n";
	cin >> n;
	cout << sum_route(Bus, n, fare) << "\n\n";
	show_route(Tram);
	cout << "Введите количество человек: \n";
	cin >> n;
	cout << sum_route(Tram, n, fare) << "\n\n";
	show_route(Trol);
	cout << "Введите количество человек: \n";
	cin >> n;
	cout << sum_route(Trol, n, fare) << "\n\n";


	return 0;
}
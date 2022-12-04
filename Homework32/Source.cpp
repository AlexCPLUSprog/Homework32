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


// ������ 1
template <typename T>
void Matrix(T*& arr, int rows, int cols) {
	arr = new T[rows];
	for (int i = 0; i < rows; i++) {
		arr[i] = new int[cols];
	}
}

// ������ 2
void change(string& str, char& ch1, char& ch2) {
    replace(str.begin(), str.end(), ch1, ch2);
    cout << str; 
}

// ������ 3
void show_route(route& R) {
	cout << "����� ��������: " << R.num << endl;
	cout << "��� ����������: " << R.type << endl;
	cout << "��������� ���������: " << R.start << endl;
	cout << "�������� ���������: " << R.finish << endl;
	cout << endl;
}

void input_route(route& R) {
	cout << "������� ����� ����������: ";
	cin >> R.num;
	cout << "������� ��� ����������: ";
	cin >> R.type;
	cout << "������� ��������� ������ ��������: ";
	cin >> R.start;
	cout << "������� �������� ���������: ";
	cin >> R.finish;
}

int sum_route(route& R, int num, int fare) {
	int sum = 0;
	cout << "��������� ������� " << num << " ������� ���������: \n";
	return sum = num * fare;
}


int main() {
	setlocale(LC_ALL, "ru");
	int n,m;

	// ������� 1
	cout << "������ 1.\n";    
	int** arr1 = nullptr;
	cout << "������� ����� ������ �������: \n";
	cin >> n;
	cout << "������� ����� ������� �������: \n";
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

    // ������� 2
    cout << "������ 2.\n";
    string str = "Hello World";
    char ch1 = 'l', ch2 = 'o';
    change(str, ch1, ch2);
	cout << "\n\n";

	// ������� 3
	cout << "������ 3\n";
	const int fare = 32;
	route Bus{ 27, "�������", "���", "��� ����" };
	route Tram{ 19, "�������", "�������������","����������������" };
	route Trol{ 35, "����������", "������", "������������" };
	show_route(Bus);
	cout << "������� ���������� �������: \n";
	cin >> n;
	cout << sum_route(Bus, n, fare) << "\n\n";
	show_route(Tram);
	cout << "������� ���������� �������: \n";
	cin >> n;
	cout << sum_route(Tram, n, fare) << "\n\n";
	show_route(Trol);
	cout << "������� ���������� �������: \n";
	cin >> n;
	cout << sum_route(Trol, n, fare) << "\n\n";


	return 0;
}
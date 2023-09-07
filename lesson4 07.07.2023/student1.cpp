#include <iostream>

using namespace std;

/* добавить:
	   * поле емайл(char*)
	   * конструктор  с 3я параметрами
	   * методы аксессоры
	   * удаление выделенной динамической памяти в деструкторе.
 */

class Student {
	char* name;
	int age;
	char* email;

public:
	Student() {
		cout << "Constructor by default" << endl;

		name = nullptr;
		age = 0;
		email = nullptr;
	}
	Student(const char* n, int a) {
		name = new char[strlen(n) + 1]; // Выделяем память при создание объекта
		strcpy_s(name, strlen(n) + 1, n);
		age = a;

		cout << "Constructor by 2 params" << endl;
	}
	Student(const char* n, int a, const char* e) {
		name = new char[strlen(n) + 1]; // Выделяем память при создание объекта
		strcpy_s(name, strlen(n) + 1, n);

		age = a;

		email = new char(strlen(e) + 1);
		strcpy_s(email, strlen(e) + 1, e);

		cout << "Constructor by 3 params" << endl;
	}
	void Input() {
		char buff[50];

		cout << "Enter name: ";
		cin >> buff;

		if (name != nullptr) {
			cout << "Delete name -> " << name << "." << endl;

			delete[] name;
		}

		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);

		cout << "Enter age: ";
		cin >> age;
	}
	void FullInput() {
		char buff[50];

		cout << "Enter name: ";
		cin >> buff;

		if (name != nullptr) {
			cout << "Delete name -> " << name << "." << endl;

			delete[] name;
		}

		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);		

		cout << "Enter age: ";
		cin >> age;

		cout << "Enter email: ";
		cin >> buff;

		if (email != nullptr) {
			cout << "Delete email -> " << email << "." << endl;

			delete[] email;
		}

		email = new char[strlen(buff) + 1];
		strcpy_s(email, strlen(buff) + 1, buff);
	}
	void Print() {
		cout << "Name: " << name << ", age: " << age << endl;
	}
	void FullPrint() {
		cout << "Name: " << name << ", age: " << age << "\nEmail: " << email << endl;
	}
	~Student() {
		delete[] name; // Явно освобождаем память при уничтожении объекта
		delete[] email;

		cout << "Destructor" << endl;
	}
};

int main() {
	Student obj1;
	Student obj2("Oleg", 20, "test@gmail.com");
	obj2.FullPrint();

	obj2.FullInput();
	obj2.FullPrint();


	/*
	obj1.Input();
	obj1.Print();
	*/

	/*
	Student a;
	Student b("Oleg", 20);

	b.Print();
	*/

	return 0;
}
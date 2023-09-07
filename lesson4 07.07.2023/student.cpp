#include<iostream>
using namespace std;

/* Добавить:
	   * поле емайл(char*)
	   * конструктор  с 3я параметрами
	   * методы аксессоры
	   * удаление выделенной динамической памяти в деструкторе.
*/

class Student
{
	char* name;
	char* email;
	int age;
public:
	Student()
	{
		cout << "Constructor by def.\n";
		name = nullptr;
		email = nullptr;
		age = 0;
	}
	Student(const char* n, int a, const char* e)
	{
		name = new char[strlen(n) + 1]; // выделяем память при создани  объекта !!
		strcpy_s(name, strlen(n) + 1, n);
		email = new char[strlen(e) + 1];
		strcpy_s(email, strlen(e) + 1, e);
		age = a;
		cout << "Constructor 3 params\n";
	}
	Student(const char* n, int a)
	{
		name = new char[strlen(n) + 1]; // выделяем память при создани  объекта !!
		strcpy_s(name, strlen(n) + 1, n);
		age = a;
		cout << "Constructor 2 params\n";
	}
	void Input()
	{
		char buff[20];
		cout << "Enter name: ";
		cin >> buff;
		if (name != nullptr)
		{
			cout << "Delete -> " << name << "." << endl;
			delete[]name;
		}
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);

		cout << "Enter age: ";
		cin >> age;
	}

	void FullInput() {
		char buff[20];
		cout << "Enter name: ";
		cin >> buff;
		if (name != nullptr)
		{
			cout << "Delete -> " << name << "." << endl;
			delete[]name;
		}
		name = new char[strlen(buff) + 1];
		strcpy_s(name, strlen(buff) + 1, buff);

		cout << "Enter age: ";
		cin >> age;

		cout << "Enter email: ";
		cin >> buff;

		if (email != nullptr)
		{
			cout << "Delete -> " << name << "." << endl;
			delete[]email;
		}

		email = new char[strlen(buff) + 1];
		strcpy_s(email, strlen(buff) + 1, buff);
	}

	void Print()
	{
		cout << "Name: " << name << "\tAge: " << age << endl;
	}
	void FullPrint() {
		cout << "Name: " << name << "\nAge: " << age << "\nemail: " << email << endl;
	}
	~Student()
	{
		delete[] name; // явно освобождаем память при уничтожении объекта !!!!
		delete[] email;
		cout << "Destructor\n";
	}
};

int main() {
	system("chcp 1251");

	Student obj1("Oleg", 20);
	obj1.Print();

	Student obj2("Nikolay", 20, "email@gmail.com");
	obj2.FullPrint();

	obj2.FullInput();
	obj2.FullPrint();
}
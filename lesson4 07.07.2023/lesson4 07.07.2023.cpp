#include <iostream>

using namespace std;

class Point {
private:
	int x;
	int y;

public:
	Point() { // Конструктор без параметров будет по умолчанию
		cout << "Constructor by default" << endl;
		x = y = 0;
	}

	Point(int a, int b) { // Конструктор с параметром
		cout << "Constructor by 2 params" << endl;
		x = a;
		y = b;
	}

	Point(int a) { // Конструктор с параметром
		cout << "Constructor by 1 params" << endl;
		x = y = a;
	}

	~Point() {
		cout << "Destructor" << endl;
	}


	void Init(int a, int b) {
		x = a;
		y = b;
	}

	void Print() {
		cout << "X: " << x << " Y: " << y << endl;
	}
};

int main() {
	Point obj1; // Выозов конструктора по умолчанию!
	obj1.Print();

	obj1.Init(15, 20);
	obj1.Print();


	Point obj2(100, 200); // Выозов конструктора с параметрами
	obj2.Print();

	obj2.Init(5, 8);
	obj2.Print();


	Point obj3(5);
	obj3.Print();

   return 0;
}

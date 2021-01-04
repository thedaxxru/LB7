#include <iostream>;
#include <iomanip>;

using namespace std;

template <class T>

class Equation {

public:
	T a, b, c, d;

	Equation(T _a, T _b, T _c) {

		a = _a;
		b = _b;
		c = _c;
	}
	Equation(const Equation& equation) //копирующий конструктор
	{	
		a = equation.a;
		b = equation.b;
		c = equation.c;
	}
	void print() {
		cout << a << "x^2";
		if (b < 0) {
			cout << b << "x";

		}
		else {
			cout << "+" << b << "x";

		}

		if (c < 0) {

			cout << c;

		}
		else {

			cout << "+" << c;

		}
		cout << endl;
	}
	void operator*=(T x) {
		a *= x;
		b *= x;
		c *= x;
	}
	Equation<T> operator-(T x) {
		Equation<T> result(a - x, b - x, c - x);
		return result;
	}

	T Disc() {


		return (b * b - 4 * a * c);
	}

	T* getX() {


		return getX(Disc());
	}
	int getResultCount() {
		T d = Disc();
		if (d == 0) {
			return 1;
		}
		else if (d>0) {
			return 2;
		}
		else {
			return 0;
		}
	}
	T* getX(T d) {
		if (d < 0) {
			return NULL;
		}
		if (a != 0) {
			if (d == 0) {
				return ValueToMass(-b / (2 * a));
			}
			else {
				T x1 = ((-b + sqrt(d)) / (2 * a));
				T x2 = ((-b - sqrt(d)) / (2 * a));

				T* result = new T[2];
				result[0] = x1;
				result[1] = x2;
				return result;
			}
		}
		else if (b != 0) {
			ValueToMass(-c / b);
		}
		else {
			return NULL;
		}


	}
	void printResult() {
		T* result = getX();
		int size = getResultCount();
		if (size == 0) {
			cout << "NO RESULT!" << endl;
		}
		else if (size == 1) {
			cout << "x = " << result[0] << endl;
		}
		else if (size == 2) {
			cout << "x1 = " << result[0] << endl;
			cout << "x2 = " << result[1] << endl;
		}
	}
private:
	T* ValueToMass(T v) {
		T* result = new T[1];
		result[0] = v;
		return result;
	}
};
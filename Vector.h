#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

class Vector
{
	int n;
	double* a;
public:
	Vector()
	{
		int n = 0;
		a = nullptr;
	}
	Vector(double* a, int n)//конструктор 
	{
		this->n = n;
		this->a = new double[n];
		for (int i = 0; i < n; i++)
		{
			this->a[i] = a[i];
		}
	}
	Vector(const  Vector& V)//копирование 
	{
		n = V.n;
		a = new double[n];
		for (int i; i < n; i++)
		{
			a[i] = V.a[i];
		}
	}
	Vector(Vector&& V)//перемещение
	{
		a = V.a;
		n = V.n;
		V.a = nullptr;
		V.n = 0;
	}
	/*void FileWrite(ofstream foutt) const //запись результата в файл
	{
		for (int i = 0; i < n; i++)
		{
			foutt << a[i] << " ";
		}
		foutt << endl;
	}*/
	/*void create() //создание вектора на безе массива 
	{
		vector <double> A;
		A.reserve(n);
		for (int i = 0; i < n; i++)
		{
			A[i] = a[i];
		}
	}*/
	// V бинарная операция + (сложение векторов) определяется как компонентная ф-я класса V
	friend Vector& operator +(double* x, Vector& v2);
	Vector& operator =(Vector& v2)
	{
		n = v2.n;
		if (a != nullptr) delete[]a;
		a = new double[n];
		for (int i = 0; i < n; i++)a[i] = v2.a[i];
		return *this;
	}
	~Vector() // деструктор
	{
		if (a!= nullptr) delete[] a;
	}
	friend ostream& operator <<(ostream& out, Vector& R2);
	friend istream& operator >>(istream& in, Vector& R2);
};

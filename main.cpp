#include "Vector.h"
ostream& operator<<(ostream& out, Vector& R2)
{
	for (int i = 0; i < R2.n; i++)
	{
		out << R2.a[i];
	}
	return out;
}
istream& operator >> (istream& in, Vector& R2)
{
	for (int i = 0; i < R2.n; i++)
	{
		in >> R2.a[i];
	}
	return in;
}
Vector& operator +(double* x, Vector& v2)//v2-исходный массив в классе, x-просто массив из файла
{

	/*vector<double> rez;//создаем вектор явл-ся результатом работы всей проги
	//const unsigned int N = v2.n;//узнаем размерность массива из файла
	rez.reserve(2 * v2.n);//предполагается что вектор и массив одинаковой размерности */
	double* p = new double[2*v2.n];
	for (int i = 0; i < v2.n; i++)
	{
		p[i] = x[i];
	}
	for (int i = v2.n; i < (2 * v2.n); i++)
	{
		p[i] = v2.a[i - v2.n];
	}
	Vector* rez = new Vector(p,(2* v2.n));
	return *rez;
}
int main()
{
	ifstream fint ("input.txt");//чтение
	if (!fint)
	{
		cout << endl << "Error, file not found" << endl;
		system("pause");
		return 1;
	} 
	double* w1 = new double[5];
	double* w2 = new double[5];
	for (int i = 0; i < 5; i++)
	{
		fint >> w1[i];
	}
	string str;
	getline(fint, str);
	for (int j=0; j < 5; j++)
	{
		fint >> w2[j];
	}
	Vector V2(w2, 5);//тот самый массив который вектор ))))
	Vector Rez;
	Rez = w1 + V2;
	fint.close();
	ofstream foutt("output.txt");
	foutt << Rez;
	foutt.close();
}

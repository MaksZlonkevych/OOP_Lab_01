#include <iostream>
#include <conio.h>
#include<cstdlib>
using namespace std;
// 20v
class Drobu {
private:
	int x1, y1, x2, y2;
public:
	Drobu(int a, int b, int e, int f)
	{
		x1 = a;
		y1 = b;
		x2 = e;
		y2 = f;
	}

	float summ(float c, float d, float k)
	{
		return (c + d) / k;
	}

	float difference(float c, float d, float k)
	{
		return (c - d) / k;
	}

	float product(float x1, float y1, float x2, float y2)
	{
		return ((x1 / y1)*(x2 / y2));
	}

	float quotient(float x1, float y1, float x2, float y2)
	{
		return ((x1 / y1) / (x2 / y2));
	}
};
void count()
{
	system("chcp 1251");
	int a, b, e, f;
	cout << "Введіть чисельник першого дробу: ";
	cin >> a;
	cout << endl;
	cout << "Введіть знаменник першого дробу: ";
	cin >> b;
	cout << endl;

	cout << "Введіть чисельник другого дробу: ";
	cin >> e;
	cout << endl;
	cout << "Введіть знаменник другого дробу: ";
	cin >> f;
	Drobu A(a, b, e, f);
	cout << endl;
	int c = 0;
	int s1, s2;
	for (int i = 1; c != 1; i++)
	{
		if ((i%b == 0) && (i%f == 0))
		{
			c = 1;
			s1 = a * (i / b);
			s2 = e * (i / f);
			cout << "\nПерший дріб: " << a << "/" << b << "\n";
			cout << "\nДругий дріб: " << e << "/" << f << "\n";
			cout << "\nНайменший спільний знаменник = " << i << endl;
			cout << "\nСума дробів = (" << s1 << "+" << s2 << ")/" << i << " = " << A.summ(s1, s2, i) << endl;
			cout << "\nРізниця дробів = (" << s1 << "-" << s2 << ")/" << i << " = " << A.difference(s1, s2, i) << endl;
		}
	}

	cout << "\nДобуток дробів = " << A.product(a, b, e, f) << endl;
	cout << "\nДілення дробів = " << A.quotient(a, b, e, f) << endl;
	system("pause");

}

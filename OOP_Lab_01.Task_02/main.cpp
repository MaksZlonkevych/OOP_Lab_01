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
	cout << "������ ��������� ������� �����: ";
	cin >> a;
	cout << endl;
	cout << "������ ��������� ������� �����: ";
	cin >> b;
	cout << endl;

	cout << "������ ��������� ������� �����: ";
	cin >> e;
	cout << endl;
	cout << "������ ��������� ������� �����: ";
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
			cout << "\n������ ���: " << a << "/" << b << "\n";
			cout << "\n������ ���: " << e << "/" << f << "\n";
			cout << "\n��������� ������� ��������� = " << i << endl;
			cout << "\n���� ����� = (" << s1 << "+" << s2 << ")/" << i << " = " << A.summ(s1, s2, i) << endl;
			cout << "\nг����� ����� = (" << s1 << "-" << s2 << ")/" << i << " = " << A.difference(s1, s2, i) << endl;
		}
	}

	cout << "\n������� ����� = " << A.product(a, b, e, f) << endl;
	cout << "\nĳ����� ����� = " << A.quotient(a, b, e, f) << endl;
	system("pause");

}

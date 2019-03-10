#include <iostream>
#define max_kst 100
using namespace std;
//7v
class spusok {
private:
	double array[max_kst];
	int kst = 0;

public:
	spusok()
	{		//оголошення констуруктора.
		for (int i = 0; i < max_kst; i++)
			array[i] = 0;
	}

	spusok(int a)
	{		//перегружаємо конструктор
		for (int i = 0; i < a && i < max_kst; i++)
			array[i] = rand() % 50;
		if (kst < a) kst = a - 1;
	}

	~spusok() {

	}
	void get_to_end_or_start(int, double);
	void vulych(int);
	void sort();
	void put_from_start();
	void put_from_end();
	void getall(void);

};

void spusok::get_to_end_or_start(int par, double new_el)
{
	double *p = array + kst;
	if (par == 0)
	{
		int i = 0;
		p = array + kst;
		while (p != array - 1) {
			*(p + 1) = *p;
			p--;
		}
		*array = new_el;
		kst++;
	}
	else
	{
		if (par == 1)
		{
			*(p + 1) = new_el;
			kst++;
		}
		else cout << "Введено неправильну літеру" << endl;
	}
}
void spusok::getall(void) {
	int i;
	for (i = 0; i < max_kst; i++) {
		cin >> array[i];
		if (cin.fail()) break;
	}
	cin.clear();
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	kst = i - 1;
}

void spusok::put_from_start(void) {
	for (int i = 0; i <= kst; i++) cout << array[i] << " ";
	cout << endl;
}

void spusok::put_from_end() {
	double *p = array + kst + 1;
	while (p-- != array) {
		cout << *p << " ";

	}
	cout << endl;
}

void spusok::vulych(int numb)
{
	double *p = array + numb;
	while ((p - array) != (kst + 1)) {
		*p = *(p + 1);
		p++;
	}
	cout << "Масив без елемента:" << endl;
	for (int i = 0; i < kst; i++) cout << array[i] << " ";
	cout << endl;
}

void spusok::sort() {

	for (int j = 0; j < kst - 1; j++) {
		for (int i = 0; i < kst - 1; i++) {
			if (*(array + i) > *(array + i + 1)) { // перевірка, якщо так, то міняти місцями 
				double tmp = *(array + i);
				*(array + i) = *(array + i + 1);
				*(array + i + 1)
					= tmp;
			}
		}
	}

}


int main() {
	system("chcp 1251");
	int i = 0, a = 0;
	double b;
	cout << "Введіть кількість елементів першого масиву дійсних чисел, яку потрібно заповнити випадковими числами: " << endl;
	cin >> a;
	spusok obj(a);
	spusok obj2;
	cout << "Введіть елементи другого масиву дійсних чисел, кінець введення довіль-ний нечисловий символ:" << endl;
	obj2.getall();
	obj.sort();
	obj2.sort();
	cout << endl << "Звичайне та реверсивне виведення елементів масиву першого об'є-кта:" << endl;
	obj.put_from_start();
	obj.put_from_end();
	cout << endl << "Звичайне та реверсивне виведення елементів масиву другого об'єк-та:" << endl;
	obj2.put_from_start();
	obj2.put_from_end();
	cout << "Введіть номер елемента масиву першого об'єкта, який потрібно вилучити:" << endl;
	cin >> a;
	obj.vulych(a);
	cout << "Введіть 0, якщо потрібно додати елемент на початок масиву чи 1, якщо у кінець:";
	cin >> a;
	cout << "Введіть новий елемент:";
	cin >> b;
	obj2.get_to_end_or_start(a, b);
	cout << "Готовий масив:";
	obj2.put_from_start();

	system("pause");
	return 0;
}

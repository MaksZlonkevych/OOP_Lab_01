#include <iostream>

#define max_kst 100

using namespace std;

//7v

class spusok {

private:

	double *array;

	int kst = 0;


public:

	spusok()

	{  //îãîëîøåííÿ êîíñòóðóêòîðà.

		for (int i = 0; i < this->kst; i++)

			array[i] = 0;

	}


	spusok(int a)

	{  //ïåðåãðóæàºìî êîíñòðóêòîð
		this->kst = a;

		this->array = new double[this->kst];
		for (int i = 0; i < a; i++)

			array[i] = rand() % 50;
		if (kst < a) kst = a - 1;

	}


	~spusok() {
		delete array;
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

		else cout << "Ââåäåíî íåïðàâèëüíó ë³òåðó" << endl;

	}

}

void spusok::getall(void) {

	int i;

	for (i = 0; i < this->kst; i++) {

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

	cout << "Ìàñèâ áåç åëåìåíòà:" << endl;

	for (int i = 0; i < kst; i++) cout << array[i] << " ";

	cout << endl;

}


void spusok::sort() {


	for (int j = 0; j < kst - 1; j++) {

		for (int i = 0; i < kst - 1; i++) {

			if (*(array + i) > *(array + i + 1)) { // ïåðåâ³ðêà, ÿêùî òàê, òî ì³íÿòè ì³ñöÿìè 

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

	cout << "Ââåä³òü ê³ëüê³ñòü åëåìåíò³â ïåðøîãî ìàñèâó ä³éñíèõ ÷èñåë, ÿêó ïîòð³áíî çàïîâíèòè âèïàäêîâèìè ÷èñëàìè: " << endl;

	cin >> a;

	spusok obj(a);

	spusok obj2;

	cout << "Ââåä³òü åëåìåíòè äðóãîãî ìàñèâó ä³éñíèõ ÷èñåë, ê³íåöü ââåäåííÿ äîâ³ëü-íèé íå÷èñëîâèé ñèìâîë:" << endl;

	obj2.getall();

	obj.sort();

	obj2.sort();

	cout << endl << "Çâè÷àéíå òà ðåâåðñèâíå âèâåäåííÿ åëåìåíò³â ìàñèâó ïåðøîãî îá'º-êòà:" << endl;

	obj.put_from_start();

	obj.put_from_end();

	cout << endl << "Çâè÷àéíå òà ðåâåðñèâíå âèâåäåííÿ åëåìåíò³â ìàñèâó äðóãîãî îá'ºê-òà:" << endl;

	obj2.put_from_start();

	obj2.put_from_end();

	cout << "Ââåä³òü íîìåð åëåìåíòà ìàñèâó ïåðøîãî îá'ºêòà, ÿêèé ïîòð³áíî âèëó÷èòè:" << endl;

	cin >> a;

	obj.vulych(a);

	cout << "Ââåä³òü 0, ÿêùî ïîòð³áíî äîäàòè åëåìåíò íà ïî÷àòîê ìàñèâó ÷è 1, ÿêùî ó ê³íåöü:";

	cin >> a;

	cout << "Ââåä³òü íîâèé åëåìåíò:";

	cin >> b;

	obj2.get_to_end_or_start(a, b);

	cout << "Ãîòîâèé ìàñèâ:";

	obj2.put_from_start();


	system("pause");

	return 0;

}
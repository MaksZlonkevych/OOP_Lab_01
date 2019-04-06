#include<iostream>
#include"Rectangle.hpp"
using namespace std;
int main()

{
	//Rectangle r(1, 17);
	//cout << r;//cout.operator<<(r)  (ostream)
	//r.output();

	int value;
	int length = 0;
	
	cout << "amount of rectangles:\t";
	cin >> length;

	try
	{
		Rectangle* array=nullptr;
		array = new Rectangle[length];
		for (size_t i = 0; i < length; i++)
		{
			cout << "rectangle [" << i + 1 << "]:" << endl;
			cin >> array[i];
			//array[i].set_width_height(w, h);
		}
		cout << "before change:" << endl;
		for (size_t i = 0; i < length; i++)
			cout << array[i];
			//array[i].output();

		cout << "value for change:\t";
		cin >> value;
		for (size_t i = 0; i < length; i++)
			array[i]-=value;

		cout << "after change:" << endl;
		for (size_t i = 0; i < length; i++)
			cout << array[i];
			//array[i].output();

		sort_asc(array, length);
		cout << "after sorting by ascending:" << endl;
		for (size_t i = 0; i < length; i++)
			cout << array[i];
			//array[i].output();

		sort_desc(array, length);
		cout << "after sorting by descending:" << endl;
		for (size_t i = 0; i < length; i++)
			cout << array[i];
			//array[i].output();

		delete[]array;
	}
	catch (const char* msg)
	{
		cout << msg << endl;
	}
	catch (exception e)
	{
		cout << e.what();
	}
	system("pause>>void");
	return 0;
}


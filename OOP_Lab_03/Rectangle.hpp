#pragma once
#include<iostream>
using namespace std;
class Rectangle
{
	//data
private:	
	int width;//
	int height;//



	//methods
			//constructors (ctor)
public:
	//
	Rectangle();
	//
	Rectangle(int w, int h);

//mutators(set)
	//
	void set_width(int w);
	void set_height(int h);
	void set_width_height(int w, int h);

//inspectors
	int get_width() const;
	int get_height() const;

// other methods
	void output() const;
	int square() const;
	int perimeter() const;

// operators overload
	bool operator<(const Rectangle& rectangle);
	bool operator>(const Rectangle& rectangle);
	bool operator<=(const Rectangle& rectangle);
	bool operator>=(const Rectangle& rectangle);
	bool operator!=(const Rectangle& rectangle);
	bool operator==(const Rectangle& rectangle);
	Rectangle& operator-=(int n);

};

//overload << and >>
ostream& operator<<(ostream& out, const Rectangle& rectangle);
istream& operator >> (istream& in, Rectangle& rectangle);

// sorting
void sort_asc(Rectangle* array, int length);
void sort_desc(Rectangle* array, int length);

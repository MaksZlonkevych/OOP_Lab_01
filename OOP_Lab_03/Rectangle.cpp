#include"Rectangle.hpp"

Rectangle::Rectangle()
 {
	 cout << "ctor without params" << endl;
	 width = 0;
	 height = 0;
 }

Rectangle::Rectangle(int w, int h)
{
	cout << "ctor with params" << endl;

	set_width(w);
	set_height(h);
}

void Rectangle::set_width(int w)
{
	if (w<0)
	{
		width = 0;
		throw exception("incorrect number");
	}
	width = w;
}

void Rectangle::set_height(int h)
{
	if (h<0)
	{
		height = 0;
		throw exception("incorrect number");
	}
	height = h;
}

void Rectangle::set_width_height(int w, int h)
{
	set_width(w);
	set_height(h);
}

int Rectangle::get_width() const
{
	return width;
}

int Rectangle::get_height() const
{
	return height;
}

void Rectangle::output() const
{
	cout << "width = " << width << " ; " << "height = " << height << endl;
}

int Rectangle::square() const
{
	
	return width*height;
}

int Rectangle::perimeter() const
{
	return 2 * width + 2 * height;
}

bool Rectangle::operator<(const Rectangle& rectangle)// reference
{
	/*if (square() < rectangle.square())
		return true;
	else
		return false;*/
	return square() < rectangle.square();
}

bool Rectangle::operator>(const Rectangle & rectangle)
{
	return square() > rectangle.square();
}

bool Rectangle::operator<=(const Rectangle & rectangle)
{
	return square() <= rectangle.square();
}

bool Rectangle::operator>=(const Rectangle & rectangle)
{
	return square() >= rectangle.square();
}

bool Rectangle::operator!=(const Rectangle & rectangle)
{
	return square() != rectangle.square();
}

bool Rectangle::operator==(const Rectangle & rectangle)
{
	return square() == rectangle.square();
}

Rectangle& Rectangle::operator-=(int n)
{
	set_width_height(width - n, height - n);
	return *this;
}

ostream & operator<<(ostream & out, const Rectangle & rectangle)
{
	out << "width = " << rectangle.get_width() << " ; " << "height = " << rectangle.get_height() << endl;
	return out;
}

istream & operator >> (istream & in, Rectangle & rectangle)
{
	int w, h;
	cout << "width:\t";
	in >> w;
	cout << "height:\t";
	in >> h;
	rectangle.set_width_height(w, h);
	return in;
}

void sort_asc(Rectangle * array, int length)
{
	int min;
	for (size_t i = 0; i < length; i++)
	{
		min = i;
		for (size_t j = i+1; j < length; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (i != min)
			swap(array[i], array[min]);
	}
}

void sort_desc(Rectangle * array, int length)
{
	int max;
	for (size_t i = 0; i < length; i++)
	{
		max = i;
		for (size_t j = i + 1; j < length; j++)
		{
			if (array[j] > array[max])
				max = j;
		}
		if (i != max)
			swap(array[i], array[max]);
	}
}

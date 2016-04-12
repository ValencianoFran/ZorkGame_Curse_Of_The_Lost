#define _CRT_SECURE_NO_WARNINGS
#ifndef _STRING__
#define _STRING__
#include <string.h>


class String
{
private:

	char* my_string = "";
	unsigned int max_size = strlen(my_string) + 1;

public:

	//CONSTRUCTOR
	String(const char* str)
	{
		int size = strlen(str) + 1;
		my_string = new char[size];
		max_size = size;
		strcpy_s(my_string, size, str);
	}

	//COPY CONSTRUCTOR
	String(const String& other)
	{
		int size = strlen(other.my_string) + 1;
		my_string = new char[size];
		max_size = size;
		strcpy_s(my_string, size, other.my_string);
	}

	//STRING LONGITUDE
	unsigned int lenght() const
	{
		return max_size;
	}

	//RETURN STRING
	const char* c_str() const
	{
		return my_string;
	}

	//IS STRING EMPTY?
	bool empty() const
	{
		return strlen(my_string) == 0;
	}

	//== OPERATOR
	const bool operator==(String other) const
	{
		return	(strcmp(my_string, other.my_string) == 0);
	}

	//= OPERATOR
	void operator=(const String& other)
	{
		int size = strlen(other.my_string) + 1;
		if (other.lenght() > max_size)
		{
			delete[] my_string;
			my_string = new char[size];
			max_size = size;
		}
		strcpy_s(my_string, max_size, other.my_string);
	}

	//OPERATOR +=
	void operator+=(const String& other)
	{
		char* temp = nullptr;
		int size = other.lenght() + max_size;
		temp = new char[max_size];
		strcpy_s(temp, max_size, my_string);

		if (max_size < size)
		{
			delete[] my_string;
			my_string = new char[size];
			max_size = size;
		}

		strcpy_s(my_string, size, temp);
		strcat_s(my_string, size, other.my_string);
		delete[] temp;
	}

	//+ OPERADOR
	String operator+(const String& other)
	{
		String new_str("New String");
		int size = strlen(my_string) + strlen(other.my_string) + 1;
		new_str.my_string = new char[size];
		strcpy_s(new_str.my_string, size, other.my_string);
		strcpy_s(new_str.my_string, size, other.my_string);
		return new_str;
	}

	//DESTRUCTOR
	~String()
	{
		delete[] my_string;
	}
};




#endif
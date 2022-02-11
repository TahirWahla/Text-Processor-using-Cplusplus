#include "MyString.h"
int MyString::wordcount = 0;

MyString::MyString(const char* word) :english(0), puntation(0)
{
	
	count = 0;
	arr = nullptr;

		wordcount++;
}
MyString::MyString(const MyString& obj) :english(obj.english), puntation(obj.puntation)
{
	count = obj.count;
	arr = new MyChar[count];
	for (int i = 0; i < count; i++)
	{
		arr[i] = obj[i];
	}
}
MyString::~MyString()
{
	if (arr!=nullptr)
	{
		delete[] arr;
		arr = nullptr;
	}
	wordcount--;
}
//operators
MyChar& MyString::operator[](const int index)
{
	return arr[index];
}

MyChar& MyString::operator[](const int index)const 
{
	return arr[index];
}
MyString& MyString::operator=(const MyString& obj)
{
	english = obj.english;
	puntation = obj.puntation;
	if (this != &obj)
	{
		if (arr)
		{
			delete[] arr;
		}
		count = obj.count;
		arr = new MyChar[count];
		for (int i = 0; i <count; i++)
		{
			arr[i] = obj[i];
		}
	}
	return *this;
}
int MyString::getwordcount()
{
	return wordcount;
}
int MyString::getEnglish()
{
	return english;
}
int MyString::getPuntation()
{
	return puntation;
}
MyString MyString::operator+(const MyString& obj)
{
	MyString temp;
	temp.english = english + obj.english;
	temp.puntation = puntation + obj.puntation;
	temp.count = count + obj.count;
	temp.arr = new MyChar[temp.count];
	int i=0,j=0;
	for (i = 0; i < count; i++)
	{
		temp[i] = arr[i];
	}
	for (i; i <temp.count; i++)
	{
		temp[i] = obj[j];
		j++;
	}

	return temp;
}

//getter

int MyString::getcount()
{
	return count;
}






MyString MyString::operator+()
{
	for (int i = 0; i < count; i++)
	{
		arr[i].uppercase();
	}
	return *this;
}
MyString MyString::operator-()
{

	for (int i = 0; i < count; i++)
	{
		arr[i].lowercase();
	}
	return *this;
}

void MyString::operator*(int a)
{
	for (int i = 0; i < count; i++)
	{
		arr[i] * a;
	}
}
void MyString::operator%(int a)
{
	for (int i = 0; i < count; i++)
	{
		arr[i] % a;
	}
}

void MyString::dataForHuffman(char*& a, int*& b, int& siz)
{
	for (int i = 0; i < count; i++)
	{
		arr[i].dataForHuffman(a, b, siz);
	}
}


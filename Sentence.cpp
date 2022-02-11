#include "Sentence.h"
int Sentence::sentenceCount = 0;
void clear(char* arr, int length);

Sentence::Sentence(const Sentence& obj)
{
	count = obj.count;
	arr = new MyString[count];
	for (int i = 0; i < count; i++)
	{
		arr[i] = obj[i];
	}
}

Sentence::~Sentence()
{
	if (arr!=nullptr)
	{
		delete[]arr;
		arr = nullptr;
	}
	sentenceCount--;
}

Sentence::Sentence(const char* word) :count(0)
{
		arr = nullptr;
		count = 0;
	sentenceCount++;
}


void Sentence::getcount(int length)
{
	ofstream fout;
	fout.open("frequency.txt", ios::app);
		fout << "Words in sentence " << length << " : " << count << endl;
		for (int i = 0; i < count; i++)
		{
			fout << "Charater in word " << i + 1 <<" of sentence "<<length << " : " << arr[i].getcount() << endl;
		}
	fout.close();
}


int Sentence::getSentenceCount()
{
	return sentenceCount;
}
int Sentence::getEnglish()
{
	int a = 0;
	for (int i = 0; i < count; i++)
	{
		a += arr[i].getEnglish();
	}
	return a;
}
int Sentence::getPuntation()
{
	int a = 0;
	for (int i = 0; i < count; i++)
	{
		a += arr[i].getPuntation();
	}
	return a;
}
void Sentence::dataForHuffman(char*& a, int*& b, int& siz)
{
	for (int i = 0; i < count; i++)
	{
		arr[i].dataForHuffman(a, b, siz);
	}
}

Sentence& Sentence::operator=(const Sentence& obj)
{
	count = obj.count;
	if (arr)
	{
		delete[] arr;
	}
	arr = new MyString[obj.count];
	for (int i = 0; i < count; i++)
	{
		arr[i] = obj[i];
	}
	return *this;
}

MyString& Sentence::operator[](const int index)
{
	if (index<count)
	{
		return arr[index];
	}
	else
	{
		return arr[0];
	}
}
MyString& Sentence::operator[](const int index)const
{
	if (index < count)
	{
		return arr[index];
	}
	else
	{
		return arr[0];
	}
}

Sentence Sentence::operator+()
{
	for (int i = 0; i < count; i++)
	{
		+arr[i];
	}
	return *this;
}
Sentence Sentence::operator-()
{
	for (int i = 0; i < count; i++)
	{
		-arr[i];
	}
	return *this;
}
void Sentence::operator*(int a)
{
	for (int i = 0; i < count; i++)
	{
		arr[i] * a;
	}
}
void Sentence::operator%(int a)
{
	for (int i = 0; i < count; i++)
	{
		arr[i] % a;
	}
}

void clear(char* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = '\0';
	}
}

Sentence Sentence::operator+(const Sentence& obj)
{
	Sentence temp;
	temp.count = count + obj.count;
	temp.arr = new MyString[temp.count];
	int i = 0, j = 0;
	for (i = 0; i < count; i++)
	{
		temp[i] = arr[i];
	}
	for (i; i < temp.count; i++)
	{
		temp[i] = obj[j];
		j++;
	}

	return temp;
}
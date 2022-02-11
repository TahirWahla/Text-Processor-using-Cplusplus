#include"MyString.h"

class Sentence
{
	MyString* arr;
	static int sentenceCount;
	int count;

public:
	Sentence(const char *word=nullptr);
	~Sentence();
	Sentence(const Sentence& obj);

	static int getSentenceCount();
	void getcount(int length);
	int getEnglish();
	int getPuntation();
	void dataForHuffman(char*& a, int*& b, int& siz);

	Sentence& operator=(const Sentence& obj);
	MyString& operator[](const int index);
	MyString& operator[](const int index)const;
	Sentence operator+();
	Sentence operator-();
	Sentence operator+(const Sentence& obj);
	void operator*(int a);
	void operator%(int a);
	//getter



	friend ostream& operator<<(ostream& out, const Sentence& obj)
	{

		for (int i = 0; i < obj.count; i++)
		{
			out << obj[i] << " ";
		}
		return out;
	}

	friend bool operator==(const Sentence& obj, const Sentence& obj2)
	{
		if (obj.count == obj2.count)
		{
			for (int i = 0; i < obj.count; i++)
			{
				if (obj[i]!=obj2[i])
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}

	friend bool operator!=(const Sentence& obj, const Sentence& obj2)
	{
		if (obj.count == obj2.count)
		{
			for (int i = 0; i < obj.count; i++)
			{
				if (obj[i] != obj2[i])
				{
					return true;
				}
			}
			return false;
		}
		return true;
	}
	friend ifstream& operator>>(ifstream& in, Sentence& obj)
	{
		ifstream file;
		bool exit = false;
		int words = MyString::getwordcount();

		file.open("test.txt");
		char a[100];
		for (int i = 0; i < words; i++)
		{
			file >> a;
		}
			
		while (!file.eof())
		{
			file >> a;
			obj.count++;
			for (int i = 0; a[i] != '\0'; i++)
			{
				if (a[i] == '.')
				{
					exit = true;
				}
				else
				{
					exit = false;
				}
			}
			if (exit==true)
			{
				break;
			}
		}
		file.close();
		file.open("test.txt");
		if (obj.arr!=nullptr)
		{
			delete[]obj.arr;
		}
		for (int i = 0; i < words; i++)
		{
			file >> a;
		}
		obj.arr = new MyString[obj.count];
		for (int i = 0; i < obj.count; i++)
		{
			file >> a;
			in >> obj[i];
		}
		file.close();
		return in;
	}
	friend ofstream& operator<<(ofstream& out, Sentence& obj)
	{
		for (int i = 0; i < obj.count; i++)
		{
			out << obj[i]<<" ";
		}
		return out;
	}
};


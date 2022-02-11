
#include"MyChar.h"
class MyString
{
	int count;
	static int wordcount;
	int english;
	int puntation;
	MyChar* arr;
public:
	MyString(const char *word=nullptr);
	MyString(const MyString &obj);
	~MyString();
	//operators
	MyChar& operator[](const int index);
	MyChar& operator[](const int index)const;
	MyString& operator=(const MyString& obj);
	MyString operator+(const MyString& obj);
	MyString operator+();
	MyString operator-();
	void operator*(int a);
	void operator%(int a);
	void dataForHuffman(char*& a, int*& b, int& siz);



	//setter
	//getter
	int getcount();
	static int getwordcount();
	int getEnglish();
	int getPuntation();
	friend istream& operator>>(istream& in, MyString& obj)
	{
		//cout << "Working" << endl;
		char* temp = new char[1000];
		in >> temp;
		int length = 0;
		while (temp[length]!='\0')
		{
			length++;
		}
		delete[] obj.arr;
		obj.count = length;
		obj.arr = new MyChar[length];
		for (int i = 0; i < length; i++)
		{
			obj[i] = temp[i];
			if (obj.arr[i].getchar() >= 'a' && obj.arr[i].getchar() <= 'z' || obj.arr[i].getchar() >= 'A' && obj.arr[i].getchar() <= 'Z')
		{
			obj.english++;
		}
		else
		{
			obj.puntation++;
		}
		}
		delete[] temp;
		return in;
	}
	friend ostream& operator<<(ostream& out, const MyString& obj)
	{
		for (int i = 0; i < obj.count; i++)
		{
			out << obj.arr[i];
		}
		return out;
	}

	friend bool operator==(const MyString& obj, const MyString& obj2)
	{
		if (obj.count ==obj2.count)
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
	
	friend bool operator!=(const MyString& obj, const MyString& obj2)
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


};


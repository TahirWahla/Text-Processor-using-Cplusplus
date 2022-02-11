#include "MyChar.h"
int MyChar::charcount = 0;


														//friend
ifstream& operator>>(ifstream& in, MyChar& obj)
{
	char a;
	in >> a;
	obj.setchar(a);
	return in;
}

ofstream& operator<<(ofstream& out, MyChar& obj)
{
	out << obj.getchar();
	return out;
}


bool operator==(MyChar& obj, MyChar& obj2)
{
		if (obj.getchar() == obj2.getchar())
		{
			return true;
		}
		else
		{
			return false;
		}
}
bool operator!=(MyChar& obj, MyChar& obj2)
{
	if (obj.getchar() != obj2.getchar())
	{
		return true;
	}
	else
	{
		return false;
	}
}

													//constructor
MyChar::MyChar(const char  ch)
{
	c = ch;
	charcount++;
}
MyChar::~MyChar()
{
	charcount--;
}

//setter
void MyChar::setchar(const char a)
{
	c = a;
}

//getter
char MyChar::
getchar()const
{
	return c;
}

int MyChar::getcount()
{
	return charcount;
}

//functions

void MyChar::lowercase()
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
	}
}
void MyChar::uppercase()
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
	}
}

void MyChar::dataForHuffman(char*& a,int*&b,int &siz)
{
	bool check = 0;
	if (siz==0)
	{
		a = new char[siz + 1];
		b = new int[siz + 1];
		a[siz] = c;
		b[siz] = 1;
		siz++;
	}
	else
	{
		for (int i = 0; i < siz; i++)
		{
			if (a[i]==c)
			{
				b[i]++;
				check = true;
				break;
			}
		}
		if (check==false)
		{
			char* temp = new char[siz + 1];
			int* temp1 = new int[siz + 1];
			for (int i = 0; i < siz; i++)
			{
				temp[i] = a[i];
				temp1[i] = b[i];
			}
			temp[siz] = c;
			temp1[siz] = 1;
			delete[] a;
			delete[]b;
			a = temp;
			b = temp1;
	siz++;
		}

	}
}

MyChar& MyChar::operator=(const MyChar& obj)
{
	c = obj.c;
	return* this;
}

void MyChar::operator*(int a)
{
	for (int i = 0; i < a; i++)
	{
		if (c>='a'&& c<='z')
		{
		if (c=='z')
		{
			c = 'a';
		}else
			c++;
		}

		if (c >= 'A' && c <= 'Z')
		{
		if (c == 'Z')
		{
			c = 'A';
		}else
			c++;
		}
	}
}
void MyChar::operator%(int a)
{
	for (int i = 0; i < a; i++)
	{
		if (c >= 'a' && c <= 'z')
		{
			if (c == 'a')
			{
				c = 'z';
			}
			else
				c--;
		}

		if (c >= 'A' && c <= 'Z')
		{
			if (c == 'A')
			{
				c = 'Z';
			}
			else
				c--;
		}
	}
}
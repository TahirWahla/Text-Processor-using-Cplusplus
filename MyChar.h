#pragma once
#include<iostream>
#include<fstream>
using namespace std;
class MyChar
{
	char c;
	static int charcount;
	
public :
	MyChar(char  c = 0);
	~MyChar();

	//setter
	void setchar(char a);

	//getter
	char getchar()const;
	static int getcount();
	//functions
	void lowercase();
	void uppercase();
	void dataForHuffman(char*& a,int *&b,int &siz);

	MyChar& operator=(const MyChar& obj);
	void operator*(int a);
	void operator%(int a);
	//friend
	friend bool operator==(MyChar& obj1, MyChar& obj2);
	friend bool operator!=(MyChar& obj1, MyChar& obj2);
	friend ifstream& operator>>(ifstream& in, MyChar& obj);
	friend ofstream& operator<<(ofstream& out, MyChar& obj);
	friend istream& operator>>(istream& in, MyChar& obj)
	{
		in >> obj.c;
		return in;
	}
	friend ostream& operator<<(ostream& out, const MyChar& obj)
	{
		out << obj.c;
		return out;
	}
};


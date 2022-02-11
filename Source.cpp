#include "Paragraph.h"
#include<fstream>
void display(MyString& obj)
{
	cout << obj << endl;
	cout << "Size of the string : ";
	cout << obj.getcount();
	cout << endl;
}
int main()
{
	int* frequency = nullptr;
	char* data = nullptr;
	int siz = 0;
	ifstream fin;
	ofstream fout,out;
	fout.open("output.txt");
	out.open("frequency.txt",ios::trunc);
	fin.open("test.txt");
	if (!fin.is_open())
	{
		return 0;
	}
	
	/*Paragraph a;
	fin >> a;
	Paragraph b(a);
	cout << b << endl;
	cout << a << endl;

	out << "Paragraph Number : " << 1 << endl;
	a.getcount();
	cout << "English : " << a.getEnglish() << endl;
	cout << "Puntation : " << a.getPuntation() << endl;
	cout << "English : " << b.getEnglish() << endl;
	cout << "Puntation : " << b.getPuntation() << endl;*/

	//Paragraph a;
	//fin >> a;
	//a * 25;
	//fout<<a;
	//cout << a << endl;
	//a % 25;
	//cout << a << endl;

	//Paragraph a;
	/*fin >> a;
	Paragraph b(a);
	a.dataForHuffman(data, frequency, siz);
	b.dataForHuffman(data, frequency, siz);
	cout << a << endl;
	a.getcount();
	cout << endl;

	int count=0;
	for (int i = 0; i < siz; i++)
	{
		count += frequency[i];
		cout << data[i] << " " << frequency[i] << endl;
	}
	cout << count << endl;;
	cout<<MyChar::getcount();*/


	//Paragraph a,b;
	//fin >> a;

	//cout << a.getEnglish() << endl;

	//b = a;
	////Paragraph c = a + b;
	//cout << c << endl;
	//cout << c.getPuntation() << endl;
	//cout << c.getEnglish() << endl;
	Paragraph a;
	fin >> a;
	cout << a << endl;
	cout << "English : " << a.getEnglish() << endl;
	cout << "Puntation : " << a.getPuntation() << endl;
	a * 2;
	cout << a << endl;
	a % 2;
	cout << a << endl;
	
	
	a.dataForHuffman(data,frequency,siz);
	for (int i = 0; i < siz; i++)
	{
		cout << data[i] << " " << frequency[i] << endl;
	}
	
	a.getcount();
	
	Paragraph c(a);
	if (c==a)
	{
		cout << "c equal to a" << endl;
	}

	if (c!=a)
	{
		cout << "c not equal to a" << endl;
	}


	out.close();
	fin.close();
	fout.close();
}

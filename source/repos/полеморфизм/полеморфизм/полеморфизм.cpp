#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
using namespace std;


class Student
{
	string name;
	int a;
public :
	Student(){}
	Student(string name_, int a_) :name(name_), a(a_)
	{}
	~Student(){}
	virtual void names()
	{
		cout << "\nВведите полное имя:";
		cin >> name;
		cout << "\nВведите факультет:";
		cin >> a;
		while (cin.get() != '\n') {}
	}
	virtual void shows()
	{
		cout << "\n" << name << "\n" << a ;
	}
};

class Graduate : public Student
{	
	string name;
	int b;
public: 
	Graduate(){}
	Graduate(string name_, int b_) :name(name_), b(b_)
	{}
	void names()
	{
		cout << "\nВведите полное имя:";
		cin >> name;
		cout << "\nВведите год выпуска:";
		cin >> b;
		while (cin.get() != '\n') {}
	}
	void shows()
	{
		cout << "\n" << name << "\n" << b ;
	}
};

class Undergraduate : public Student
{
	string name;
	int c;
public:
	Undergraduate(){}
	Undergraduate(string name_, int c_): name(name_), c(c_){}
	void names() 
	{
		cout << "\nВведите полное имя:";
		cin >> name;
		cout << "\nВведите курс:";
		cin >> c;
		while (cin.get() != '\n') {}
	}
	void shows()
	{
		cout << "\n" << name << "\n" << c ;
	}
};

int menu()
{
	int c;
	cout << "\n-----Меню-----"
		<< "\n-----1) Добавить студента"
		<< "\n-----2) Добавить выпускика"
		<< "\n-----3) Добавить старшекурсника"
		<< "\n-----4) Вывод всех данных"
		<< "\n-----5)Выход";
	do
	{
		c = _getch();

	} while (!(c >= '1' && c <= '6'));
	return c;
}

int main()
{
	const int student = 3;
	setlocale(0, "rus");
	Student* coll[student];
	coll[0] = new Student;
	coll[1] = new Graduate;
	coll[2] = new Undergraduate;
	
	for (int i = 0; i < student; i++)
	{
		coll[i]->shows();
	}

	
	delete coll[0];
	delete coll[1];
	delete coll[2];


	/*Student** p = new Student * [1];
	Graduate** g = new Graduate * [1];
	Undergraduate** u = new Undergraduate * [1];
	p[0] = new Student[5];
	g[1] = new Graduate[5];
	u[2] = new Undergraduate[5];
	Student* st;
	Graduate* gr;
	Undergraduate* un;
	int a = 0;
	int b = 0;
	int c = 0;

	while (1)
	{
		switch (menu())
		{
		case '1':
		{
			st = &p[0][a];
			st->names();
			a++;
			break;
		}
		case '2':
		{
			gr = &g[1][b];
			gr->names();
			b++;
			break;
		}
		case '3':
		{
			un = &u[2][c];
			un->names();
			c++;
			break;
		}
		case '4':
		{
			if (a)
			{
				for (int i = 0; i < a; i++)
				{
					st = &p[0][i];
					st->shows();
				}
			}
			if (b)
			{
				for (int i = 0; i < b; i++)
				{
					gr = &g[0][i];
					gr->shows();
				}
			}
			if (c)
			{
				for (int i = 0; i < c; i++)
				{
					un = &u[0][i];
					un->shows();
				}
			}
			break;
		}
		case '5':
			return 0;
			break;
		}
	}*/

	system("pause");
	return 0;
	
}
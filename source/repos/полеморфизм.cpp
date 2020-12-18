#include <iostream>
#include <iomanip>
#include <conio.h>
#include <string>
using namespace std;


class Student
{
protected:
	string name;
	string a;
public :
	Student(){}
	Student(string name_, string a_) :name(name_), a(a_)
	{}
	~Student(){}
	
	virtual void shows()
	{
		cout <<"Имя: " << name << "\n"<<"Факультет: " << a ;
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
	virtual void shows()
	{
		cout << "\nИмя: " << name << "\nГод выпуска: " << b ;
	}

};

class Undergraduate : public Student
{
	string name;
	int c;
public:
	Undergraduate(){}
	Undergraduate(string name_, int c_): name(name_), c(c_){}
	virtual void shows()
	{
		cout << "\nИмя: " << name << "\nКурс:" << c ;
	}
};

int main()
{
	const int student = 3;
	setlocale(0, "rus");
	Student* coll[student];
	coll[0] = new Student("Ivan", "fcad");
	coll[1] = new Graduate("Ivan",2020);
	coll[2] = new Undergraduate("Ivan", 3);
	coll[0]->shows();
	coll[1]->shows();
	coll[2]->shows();
		
	delete coll[0];
	delete coll[1];
	delete coll[2];

	system("pause");
	return 0;
	
}
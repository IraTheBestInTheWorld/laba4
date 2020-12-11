#include <iostream>
#include <conio.h>

using namespace std;

class pramougol
{
private :
	int a, b, squar, perim;
public:
	void get()
	{
		while (true)
		{
			cout << "-----------------" << endl;
			cout << "Введите сторону a " << endl;
			cin >> a;
			cout << "Ведите сторону b " << endl;

			cin >> b;
			if (cin.get() == '\n') break;
			else 
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::infinity(), '\n');//< ::max()
				cout << "Будьте внимательнее! Неккоректный ввод!\n";
			}
			
		}
	}
	void square()
	{
		squar = a * b;
	}
	void show_square()
	{
		cout << "Площадь = " << squar;
	}
	void perimetr()
	{
		perim = (a + b) * 2;
	}
	void show_perimetr()
	{
		cout << "Периметр = " << perim;
	}
};

void Menu()
{
	cout << "\nМеню" << endl;
	cout << "\nВыберите действие:";
	cout << "\n1-Площадь прямоугольника";
	cout << "\n2-Периметр прямоугольника" << endl;
}

int main()
{
	setlocale(0, "rus");
	pramougol on;
	int menu;
	on.get();
	Menu();
	menu = _getch();

	switch (menu)
	{
	case '1':
		on.square();
		on.show_square(); break;
	case '2':
		on.perimetr();
		on.show_perimetr(); break;
	}
	cout << endl;

	system("pause");
	return 0;
}
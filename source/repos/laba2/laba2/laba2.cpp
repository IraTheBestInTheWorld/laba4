#include <iostream>
#include "String.h"
using namespace std;

class String
{
public:
	String();
	String(const char* str);
	String(const String& string); // конструктор копии 
	String(String&& string);
	~String();
	//Консольный Ввод и Вывод
	int size();
	char* getString();
	String operator+(const String& string);
	bool operator>(const String& string);
	friend ostream& operator<<(ostream& out, const String& string);
	friend istream& operator>>(istream& in, String& string);

private:
	char* str;
	int length;
};



int main()
{
	setlocale(0, "rus");
	String str, str2;
	int deistv;
	cout << "----------------------";
	cout << "\nВведите первую сторку" << "\n-> ";
	cin >> str2;
	cout << "\nВаша строка" << "\n->";
	cout << str2;
	cout << "\nВведите вторую строку" << "\n-> ";
	cin >> str;
	cout << "\nВаша строка" << "\n->";
	cout << str;

	while (1) {
		cout << "\n" << "Выберите действие:\n";
		cout << "\n1. Сравнение";
		cout << "\n2. Сложение (+)";
		cout << "\n3. Выход";
		cout << "\n->";
		cin >> deistv;
		if (deistv == 1)
		{
			if (str > str2)
				cout << "\nПервая строка больше";
			else
			{
				cout << "\nВторая строка больше";
			}
		}

		if (deistv == 2)
		{
			cout << "\nРезультат = ";
			cout << str + str2;
		}

		if (deistv == 3)
		{
			system("PAUSE");
			return 0;
		}
	}

}

String::String()
{
	this->str = nullptr;
	this->length = 0;
}

String::String(const char* str)
{
	this->length = strlen(str);
	this->str = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
	{
		this->str[i] = str[i];
	}
	this->str[this->length] = '\0';
}

String::String(const String& string)
{
	this->length = string.length;
	this->str = new char[this->length + 1];
	for (int i = 0; i < this->length; i++)
	{
		this->str[i] = string.str[i];
	}
	this->str[this->length] = '\0';
}

String::String(String&& string)
{
	this->length = string.length;
	this->str = string.str;
	string.str = nullptr;
}

String::~String()
{
	delete[]this->str;
	this->length = 0;
}

int String::size()
{
	return length;
}

char* String::getString()
{
	return this->str;
}

String String::operator+(const String& string)
{
	String summaryString;
	summaryString.length = this->length + string.length;
	summaryString.str = new char[summaryString.length + 1];
	int i = 0;
	for (; i < this->length; i++)
	{
		summaryString.str[i] = this->str[i];
	}
	for (int j = 0; j < string.length; j++, i++)
	{
		summaryString.str[i] = string.str[j];
	}
	summaryString.str[summaryString.length] = '\0';
	return summaryString;
}

bool String::operator>(const String& string)
{
	for (int i = 0; string.str[i] != '\0' || this->str[i] != '\0'; i++)
	{
		if (static_cast<int>(this->str[i]) < static_cast<int>(string.str[i]))
		{
			return true;
		}
		else if (static_cast<int>(this->str[i]) == static_cast<int>(string.str[i]))
		{
			continue;
		}

		return false;
	}
	return false;
}

ostream& operator<<(ostream& out, const String& string)
{
	out << string.str;
	return out;
}

char* getRememberForString(char* str, int& size_of_str, char symbol)
{
	char* temp = new char[++size_of_str];
	for (int i = 0; i < size_of_str - 1; i++)
	{
		temp[i] = str[i];
	}
	delete[]str;
	str = temp;
	str[size_of_str - 1] = symbol;
	return str;
}

istream& operator>>(istream& in, String& string)
{
	char* input_data = nullptr;
	delete string.str;
	int size_of_str = 0;
	char symbol;
	while (true) {
		if ((symbol = in.get()) != '\n')
		{
			input_data = getRememberForString(input_data, size_of_str, symbol);
		}
		else
		{
			input_data = getRememberForString(input_data, size_of_str, '\0');
			break;
		}
	}
	string.str = input_data;
	string.length = size_of_str - 1;
	return in;
}
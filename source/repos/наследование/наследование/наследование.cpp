#include <iostream>
#include <conio.h>
using namespace std;

class Learner
{
public:
    Learner() {};
    Learner(string name_, size_t birth_) : name(name_), birth(birth_)
    {}
    void getInf()
    {
        cout << "\nВведите полное имя:";
        cin >> name;
        cout << "\nВведите дату рождения:";
        cin >> birth;
        while(cin.get()!='\n'){}
    }
    void show()
    {
        cout << name << birth;
    }
    ~Learner(){}
private:
    string name;
    size_t birth;
};

class School : public Learner
{
public :
    School(){}
    School(string name_, size_t birth_, size_t classsch_): Learner (name_, birth_), classsch(classsch_)
    {}
    void getInfSchool()
    {
        getInf();
        cout << "\nВведите класс:";
        cin >> classsch;
    }
    void showSchool()
    {
        cout << "\nШкольники:" << &Learner::show << "\nКласс:" << classsch;
    }
    ~School(){}
private:
    size_t classsch;
};

class Student : public Learner
{
public:
    Student(){}
    Student (string name_, size_t birth_, size_t course_) : Learner(name_, birth_), course(course_)
    {}
    void getInfoStudent()
    {
        getInf();
        cout << "\nВведите курс:";
        cin >> course;
    }
    void showStudent()
    {
        cout << "\nСтуденты:" << &Learner::show << "\nКурс:" << course;
    }
    ~Student(){}
private:
    size_t course;
};

int menu()
{
    int c;
    cout << "\n-----Меню-----"
        << "\n-----1) Добавить студента"
        << "\n-----2) Добавить школьника"
        << "\n-----3) Вывод всех данных"
        << "\n-----4) Выход";
    do
    {
        c = _getch();

    } while (!(c>='1'&& c<='5'));
    return c;
}

int main()
{
    setlocale(LC_ALL, "rus");
    Student** s = new Student*[1];
    School** c = new School * [1];
    s[1] = new Student[5];
    c[0] = new School[5];
    Student* st;
    School* sc;
    int a = 0;
    int b = 0;

    while (1)
    {
        switch (menu())
        {
        case '1':
        {
            st = &s[1][a];
            st->getInfoStudent();
            a++;
            break;
        }
        case'2':
        {
            sc = &c[0][b];
            sc->getInfSchool();
            b++;
            break;
        }
        case '3':
        {
            if (a)
            {
                for (int i = 0; i < a; i++)
                {
                    st = &s[1][i];
                    st->showStudent();
                }
            }
            if (b)
            {
                for (int i = 0; i < b; i++)
                {
                    sc = &c[0][i];
                    sc->showSchool();
                }
            }
            break;
        }
        case '4':
            return 0;
            break;
        }
    }
    return 0;
}


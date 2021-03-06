// Task.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;
/*
class Base
{
public:
	Base()
		: j(0)
	{

	}

	void Print(int i)
	{
		cout << "enter: " << i << "\n";
	}

	virtual void DoSomeThing()
	{
		cout << "Base do something\n";
	}
private:
	int j = 0;
};
*/
/*пример переопределения
*/
/*class Child : public Base
{
public:
	Child()
		: i(0)
	{

	}

	void Print(int i)
	{
		cout << "Derived print " << i << "\n";
	}

	void DoSomeThing() override
	{
		cout << "something\n";
	}
private:
	int i = 0;
};
*/



struct Person
{
	Person()
	{}



	Person(const Person& otherObj)
	{
		m_name = otherObj.m_name;
	}
private:
	string m_name;
};


struct Student : Person
{


	Student()
	{}

	Student(const Student & otherStudent)
		: Person(otherStudent)
		, m_speciality(otherStudent.m_speciality)
	{
	}
private:
	string m_speciality;
};

int main()
{

	/*Student s;
	Person &p = s;
	cout << s.name() << "\n";//Student::name()
	cout << p.name() << "\n"; //Person::name()
    */
	//Person p;
	
	//создать конструктор копирования с наследованием

	Student s;
	s.m_name = "Name"s;
	s.m_speciality = "Teacher"s;


	Student newStudent(s);
	cout << "name: " << newStudent.m_name << "  " << " spec: " << newStudent.m_speciality << "\n";

	Person newPerson(s);

	cout << newPerson.m_name << "\n";

	Person p;
	p.m_name = "Anton"s;

	Person newPerson2(p);

	cout << newPerson2.m_name << "\n";


	return 0;
}

/*
	
*/
#include <iostream>
#include <set>
#include <string>

using namespace std;

struct Person {
	string name;
	int age;
	Person(string n, int a) : name(n), age(a) {} 
};

ostream& operator << (ostream &os, const Person& p)
{
	os << p.name;
	return os;
}

bool operator < (Person a, Person b)
{
	if (a.age > b.age)
		return true;
	else if (a.age < b.age)
		return false;
	else
	{
		if ((a.name).compare(b.name) < 0)
			return true;
		else
			return false;
	}
	
}

int main ()
{
	string name;
	int age;
	set<Person> ppl;
	
	while (cin >> name >> age)
	{
		Person temp (name,age);
		ppl.insert(temp);
	}
	for (set<Person>::iterator it=ppl.begin();it!=ppl.end();++it)
	{
		cout << *it << endl;
	}
}

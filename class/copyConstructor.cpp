#include<iostream>
#include<cstring>

using namespace std;

class Person {

	char name[30];
	int age;

	public :
		Person(){
			cout<<"생성자1 실행\n";
		}

		Person(const char * _name, int _age) : age(_age)
		{
			strcpy(this->name, name);
			cout<<"생성자2 실행\n";
		}

		Person(const Person &copy) : age(copy.age)
		{
			strcpy(this->name, copy.name);
			cout<<"복사 생성자 실행\n";
		}
		
}; //Person

int main(){

	Person p1("name", 20);
	Person p2=p1;


	return 0;
}

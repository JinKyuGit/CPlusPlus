#include<iostream>
#include<cstring>

using namespace std;


class Person {

	char * name;
	int age;

	public :
		Person(){
			name=NULL;
			age=0;
		}
		Person(const char * _name, int _age) : age(_age) {

			int len=strlen(_name)+1;
			name=new char[len];
			strcpy(this->name, _name);
		}

		~Person(){
			delete []name;
		}
		//대입연산자
		Person& operator=(const Person& p){
			
			delete []name; //메모리 누수 방지
			int len=strlen(p.name)+1;
			name=new char[len];
			strcpy(name, p.name);
			this->age=p.age;
			return *this;
		}

		void Show(){
			cout<<name<<", "<<age<<endl;
		}
}; // Person


int main(){

	Person p1;
	Person p2("Lee", 19);
	
	p1=p2;

	p1.Show();
	



	return 0;
}

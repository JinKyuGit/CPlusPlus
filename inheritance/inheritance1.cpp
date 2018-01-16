#include<iostream>
#include<cstring>

using namespace std;

class Person {

	char * name;
	int age;

	public :
	Person(const char * _name, int _age) : age(_age)
	{
		int len=strlen(_name);
		this->name=new char[len];
		strncpy(this->name, _name, len);
		cout<<"Person 생성자 실행.\n";
	}

	~Person(){
		delete []this->name;
		cout<<"Person 소멸자 실행.\n";
	}

	void GetUp(){
		cout<<"하암~ \n";
	}

	void Eat(){
		cout<<"냠냠 \n";
	}

	void Sleep(){
		cout<<"쿨쿨 \n";
	}

	void ShowInfo(){
		cout<<"name : "<<this->name<<endl;	
		cout<<"age : "<<this->age<<endl;
	}

	void Test(){
		cout<<"Person의 Test() 실행.\n";
	}
}; // Person

//Person 상속.
class Student : public Person {
				//Person 클래스의 private를 제외한
				//멤버들을 public으로 지정하여 상속.
	char * school;

	public :
		Student(const char * _name, int _age, const char * _school)
			: Person(_name, _age)
		{
				int len=strlen(_school);
				this->school=new char[len];
				strncpy(this->school, _school, len);
				cout<<"Student 생성자 실행.\n";
		}
		
		~Student(){
			delete []this->school;
			cout<<"Student 소멸자 실행.\n";
		}

		void StudentInfo(){
			ShowInfo();
			//부모에게 상속받은 함수를 통해
			//부모 클래스의 멤버변수 접근.
			cout<<"school : "<<this->school<<endl;
			//Person의 멤버변수는 private 이므로 직접 사용 불가.
		}
		void Test(){
			cout<<"Student의 Test() 실행.\n";
		}
}; // Student


int main(){
	
	const char * school="양명고";
	Student st("이진규", 30, school);
	st.GetUp();
	st.Eat();
	st.Sleep();
	st.StudentInfo();
	st.Test();

	Person p=st;
	p.Test();

	Person * p1=new Student("test", 10, "school");
	p1->Test();
	p1=new Person("person", 11);
	p1->Test();
	return 0;
}


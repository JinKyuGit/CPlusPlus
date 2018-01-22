#include<iostream>
#include<cstring>

using namespace std;

//대입연산자 활용.

class Test 
{
	int num;
	char * name;

	public :
		Test(int _num, const char * _name) : num(_num)  {
			
			name=new char[strlen(_name)+1];
			strcpy(this->name, _name); 
		}
		void ShowData(){
			cout<<"name : "<<this->name<<endl;
			cout<<"num : "<<this->num<<endl;
		}
		
		void SetNum(int num){
			this->num=num;
		}

		void SetName(const char * _name){
			
			strcpy(this->name, _name);
		}

		
		//대입 연산자 정의
		/*
		Test2& operator=(const Test2& ref){
			
			this->num=ref.num;
			copy(this.name, ref.name);
			return *this;
		}
		*/


}; //Test


class Test2 {

	int num;
	char * name;

	public :
		Test2(int _num, const char * _name) : num(_num) {
				
				this->name=new char[strlen(_name)+1];
				strcpy(this->name, _name);

			}

		void ShowData(){
			cout<<"name : "<<this->name<<endl;
			cout<<"num : "<<this->num<<endl;
		}
		
		void SetNum(int num){
			this->num=num;
		}

		void SetName(const char * _name){
			
			strcpy(this->name, _name);
		}
		
		//대입 연산자
		Test2& operator=(const Test2& ref){
			this->num=ref.num;
			
			delete []this->name;
			this->name=new char[(strlen(ref.name))+1];
			strcpy(this->name, ref.name);
			return *this;
		}


}; //Test2



int main(){

		cout<<"디폴트 대입연산자 사용시.\n";
		Test t1(4, "name1");
		Test t2=t1;
		cout<<"  t1 데이터 변경 전\n";
	
		cout<<" == t1 ==\n";
		t1.ShowData();
		cout<<" == t2 ==\n";
		t2.ShowData();

		cout<<"  t1 데이터 변경 후\n";
		t1.SetNum(5);
		t1.SetName("name2");
	
		cout<<" == t1 ==\n";
		t1.ShowData();
		cout<<" == t2 ==\n";
	    t2.ShowData();
		//t2가 t1을 복사한 별개의 객체이나
		//디폴트 대입 생성자를 이용하여 얇은 복사를
		//진행하였으므로, t1의 char * 값이 변하면
		//t2의 값도 변함.
		
		cout<<"\n\n ==================== \n\n";

		cout<<"대입 연산자 직접 정의.\n";
	
		Test2 t3(1, "name1");
		Test2 t4(2, "name2");

		t3=t4;

		cout<<" == t3 ==\n";
		t3.ShowData();
		cout<<" == t4 ==\n";
		t4.ShowData();

		cout<<" t4 값 변경.\n";
		t4.SetNum(3);
		t4.SetName("name3");

		cout<<" == t3 ==\n";
		t3.ShowData();
		cout<<" == t4 ==\n";
		t4.ShowData();


	return 0;
}

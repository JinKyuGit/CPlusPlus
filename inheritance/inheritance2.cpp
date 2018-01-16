#include<iostream>
#include<cstring>

using namespace std;


class Shape {

	int x;
	int y;

	public :
	Shape() {
		cout<<"Shape 생성자 실행\n";
	}
	Shape(int _x, int _y) : x(_x), y(_y){ }
	
	//가상 소멸자.
	//가상 소멸자를 사용하지 않으면
	//부모 클래스 포인터로 자식 클래스 이용하는 경우  ex)Person * p1
	//소멸시 부모 소멸자가 바인딩됨.
	//즉, 자식 소멸자의 바인딩을 위해
	//소멸자를 상속받도록 부모 소멸자를 가상화.
 	virtual ~Shape(){
			cout<<"Shape 소멸자 실행\n";
		}

	virtual void Draw() = 0;
	//순수 가상함수
	//순수 가상함수 선언시 객체 생성 불가능(상속만 가능)
	//virtual void Draw(){} > 일반 가상함수.
	
}; //Shape

class Rectangle : public Shape {

	
	public :
		Rectangle(){
		cout<<"Rectacgle 생성자 실행\n";
		}
		Rectangle(int _x, int _y) : Shape(_x, _y) { }
		~Rectangle(){
			cout<<"Rectangle 소멸자 실행\n";
		}
		void Draw(){
			cout<<"Draw Rectangle\n";
		}

}; //Rectangle

class Circle : public Shape {

	public :
		Circle(){
		cout<<"Circle 생성자 실행\n";
		}
		Circle(int _x, int _y) : Shape(_x, _y){ }
		void Draw(){
			cout<<"Draw Circle\n";
		}
		~Circle(){
			cout<<"Circle 소멸자 실행\n";
		}

}; // Circle


int main(){

	//다형성 - 객체의 타입이 다른 경우 동일한 메세지가 전달되더라도
	//다르게 동작하는 것.


	//생성시에는 부모 -> 자식
	//소멸시에는 자식 -> 부모 
	Shape * s1=new Circle;
	Shape * s2=new Rectangle;

	//Shape s3; 순수 가상함수 선언으로 인해 에러.
	s1->Draw();
	s2->Draw();

	delete s1;
	delete s2;
	return 0;
}

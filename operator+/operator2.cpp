#include<iostream>

using namespace std;


class Point {

	int x;
	int y;

	public :
		Point(int _x=0, int _y=0) : x(_x), y(_y) { }
		
		void ShowPoint(const char * name){
			cout<<" == "<<name<<" ==\n";
			cout<<" x : "<<x<<" y : "<<y<<endl;
		}

		Point(const Point & copy)
			: x(copy.x), y(copy.y){
				cout<<"복사 생성자\n";
			}
		
		//매개변수가 없으면 전위증가&감소
		//매개변수 int인 경우 후위증가&감소
		const Point operator++(int){
		
			Point p(this->x, this->y);
			
			this->x+=1;
			this->y+=1;
		
			return p;
			//const 선언으로 인해
			//반환되는 임시객체는 const형.
		}

		Point& operator++(){
			this->x+=1;
			this->y+=1;
		

			return *this;
		}

		Point operator+(const Point & copy){
			int a=this->x+copy.x;
			int b=this->y+copy.y;

			Point p(a, b);
			return p;
		}
}; //Point
int main(){

	Point p1(1, 1);
	Point p2(10, 10);

//	Point p3=(p1++)++; 컴파일 에러.
//	후위 증가로 반환된 임시객체는 const 객체이므로
//	값의 변환이 불가능해짐.
//	c++의 연산특성을 적용한 것.
	
	cout<<"p3 생성\n";
//	Point p3=(p2++); 복사 생성자 실행 안됨.
	Point p3=(p2++);
	
	cout<<"p4 생성\n";
	Point p4=(++p2);	
	++p2;
	
	p1.ShowPoint("p1");
	p2.ShowPoint("p2");
	p3.ShowPoint("p3");
	p4.ShowPoint("p4");
	return 0;
}

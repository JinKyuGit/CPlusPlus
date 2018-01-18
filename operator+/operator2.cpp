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
		
		//매개변수가 없으면 전위증가&감소
		//매개변수 int인 경우 후위증가&감소
		const Point operator++(int){
		
			const Point p(this->x, this->y);
			
			this->x+=1;
			this->y+=1;
		
			return p;
		}

		Point& operator++(){
			this->x+=1;
			this->y+=1;

			return *this;
			//클래스 내에서 this는
			//해당 객체의 포인터를 의미함.
			//즉 *this는 해당 객체의 레퍼런스임.
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
	p1.ShowPoint("p1");
	p2.ShowPoint("p2");


//	Point p3=(p1++)++; 컴파일 에러.
//	후위 증가로 반환된 임시객체는 const 객체이므로
//	값의 변환이 불가능해짐.
//	c++의 연산특성을 적용한 것.
	Point p3=(p2++);
	p3++;
	Point p4=++(++p2);	
	p3.ShowPoint("p3");
	p4.ShowPoint("p4");
	p1.ShowPoint("p1");
	p2.ShowPoint("p2");


	return 0;
}

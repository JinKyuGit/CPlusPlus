#include<iostream>


using namespace std;



class Point {

	int x;
	int y;

	public :
		Point(int _x=0, int _y=0) : x(_x), y(_y) {
			cout<<"기본 생성자 실행.\n";
		}

		~Point(){
			cout<<"소멸자 실행.\n";
		}

		Point(const Point &copy) : x(copy.x),y(copy.y) {
			cout<<"복사 생성자 실행.\n";
		}

		void ShowPoint(const char * name){
			cout<<" == "<<name<<" ==\n";
			cout<<"x : "<<x<<" y : "<<y<<endl;
		}

		/*
		Point operator++(){
			
			this->x+=1;
			this->y+=1;

			Point p(this->x, this->y);
			return p;
		}
		*/
		//이렇게 하는 경우
		//++(++객체)연산시
		//++(+1된 객체의 복사본)이 오므로
		//원래 객체는 +1만된다.
		//제대로된 결과를 얻으려면.

		Point& operator++(){
			this->x+=1;
			this->y+=1;
			
			return *this;
		}

		//참조형으로 리턴할 수 없는 것은
		//함수내의 지역객체(p)는
		//함수가 끝남과 동시에 소멸되기 때문.
		//그렇다고 *this를 반환하게 되면
		//전위증가가 되어버림.
		Point operator++(int){
		
			Point p(*this);  //복사 생성자 실행.
			//Point p(x, y); //기본 생성자 실행.
			this->x+=1;
			this->y+=1;

			return p;
		}

}; //Point


int main(){

	Point p1(1, 1);
	
//	Point p2=p1;
	
	Point p3=++(++p1);
	
	Point p4=p3++;
	
	p1.ShowPoint("p1");
	cout<<"p1 : "<<&p1<<endl;
	p3.ShowPoint("p3");
	cout<<"p3 : "<<&p3<<endl;
	p4.ShowPoint("p4");
	cout<<"p4 : "<<&p4<<endl;

	return 0;
}

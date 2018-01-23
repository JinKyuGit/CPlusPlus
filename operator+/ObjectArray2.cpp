#include<iostream>
#include<cstdlib>


using namespace std;


class Point {
	
	int x;
	int y;

	public :
		Point(int _x=0, int _y=0) : x(_x), y(_y) {
			cout<<"기초생성자 실행\n";
		}
		
		friend ostream& operator<<(ostream& os, Point& p);
		
		Point(const Point& copy) : x(copy.x), y(copy.y) {
			cout<<"복사생성자 실행\n";
		}

		Point& operator=(const Point& ref){
			cout<<"대입연산자 실행\n";
			x=ref.x;
			y=ref.y;
			return *this;
		}
}; //Point

ostream& operator<<(ostream& os, Point &p){

	os<<"[ x : "<<p.x<<" y : "<<p.y<<" ]"<<endl;
	return os;
}

class PointArray {
	
	Point * arr;
	int numOfPoint;

	public :
		PointArray(int _numOfPoint) : numOfPoint(_numOfPoint) {
			arr=new Point[_numOfPoint];
		}

		~PointArray(){
			delete []arr;
		}

		Point& operator[](int idx){
			
			if(idx < 0 || idx >= numOfPoint){
				cout<<"Exception : Out of Bounds\n";
				exit(1);
			}

			return arr[idx];
		}

		int GetLen(){
			return numOfPoint;
		}

}; //PointArray


int main(){
	
	
	PointArray arr(1);
	cout<<" == PointArray 선언 ==\n";
	int len=arr.GetLen();
	
	int i;
	for(i=0; i<len; i++){
		arr[i]=Point(i*2, i*3); //대입연산자 이용.
	}
	cout<<" == arr[i]=Point(i, i) 실행 == \n";
	for(i=0; i<len; i++){
		cout<<arr[i];
	}
	cout<<" == 출력 ==\n";


	return 0;
}

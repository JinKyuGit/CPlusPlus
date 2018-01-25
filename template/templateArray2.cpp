#include<iostream>
#include<cstdlib>
using namespace std;

//템플릿을 이용하여
//배열처럼 다룰 수 있는 객체 만들기.

class Point{

	int x;
	int y;
	
	public :
		Point(int _x=0, int _y=0) : x(_x), y(_y) { }
		Point& operator= (const Point& p){
			this->x=p.x;
			this->y=p.y;

			return *this;
		}

		friend ostream& operator<< (ostream& os, const Point& p);

}; //Point

ostream& operator<< (ostream& os, const Point& p){

	os<<"["<<p.x<<", "<<p.y<<"]"<<endl;
	return os;
}

template <class T>
class Array {

	T * arr;
	int bounds;

	public :
		Array(int n);
		T& operator[](int idx);		
		~Array();		
}; //Array

template <class T>
Array<T>:: Array(int n){
	arr=new T[n];
	bounds=n;
}

template <class T>
Array<T>:: ~Array(){
	delete []arr;
}

template <class T>
T& Array<T>:: operator[](int idx){

	if(idx < 0 || idx >= bounds){
		cout<<"Exception : out of bounds\n";
		exit(1);
	}

	return arr[idx];
}


int main(){
	
	Array<int> arr1(5);
	Array<Point> arr2(5);
	Array<Point *> arr3(5);

	int i;
	for(i=0; i<5; i++){
		arr1[i]=i;
		arr2[i]=Point(i+1, i+2);
		arr3[i]=new Point(i*2, i*3);
	}

	for(i=0; i<5; i++){
		cout<<arr1[i];	
		cout<<arr2[i];
		cout<<*(arr3[i]);
	}

	cout<<endl;
	

	return 0;
}

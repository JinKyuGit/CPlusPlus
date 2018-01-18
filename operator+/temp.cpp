#include<iostream>


using namespace std;



int main(){

	int num=10;

	++(++num); 
	--(--num);
//	(num++)++; 컴파일 에러.
//	(num--)--; 컴파일 에러
// 이유는 잘 모르겠다.
// 아마도 후위증가한 값을 다시 후위증가한다는 것의
// 의미가 모호해서 그런듯??
// (num++)++;
// (num와 동일 - 연산후 ++)++;
// 의미 모호
	return 0;
}

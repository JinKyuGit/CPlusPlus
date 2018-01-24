#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;


class String {
	
	private :

		char * str;
		int len;

	public :
		
		String();
		String(const char * _str);
		String(const String& s);
		~String();
		int GetLen();
		String& operator= (const String& s);
		String operator+ (const String& s);
		String& operator+= (const String& s);
		int operator== (const String& s);
		friend ostream& operator<< (ostream& os, const String& s);
		friend istream& operator>> (istream& is, String& s);
};//String

int main(){

	String str1="hello";
	String str2=" world";
	
	String str3=str1+str2;

	cout<<str3;
	cout<<endl;

	String str4;
	cout<<"입력 : ";
	cin>>str4;

	cout<<"입력한 문자 : ";
	cout<<str4;
	cout<<endl;



	return 0;
}
//기본생성자
String:: String(){
	str=NULL;
	len=0;
}
//매개변수 생성자.  문자열
String:: String(const char * _str){
	
	len=strlen(_str)+1;
	str=new char[len];
	strcpy(str, _str);
}

//복사 생성자
String:: String(const String& s) : len(s.len) {

	if(NULL != str){
		delete []str;
	}

	str=new char[len];
	strcpy(str, s.str);
}

//소멸자
String:: ~String(){
	delete []str;
}

//대입 연산자 오버로딩.
String& String:: operator= (const String& s){
	
	len=s.len;
	delete []str;

	str=new char[len];
	strcpy(str, s.str);
	return *this;
}

//+ 연산자 오버로딩
//두개의 스트링을 합쳐 하나의 새로운 객체이므로
//반환형은 String
String String:: operator+ (const String& s){
	
	int length=this->len + s.len;
	char * temp=new char[length];

	//객체 문자열 앞에 복사
	//매개변수 문자열 뒤에 덧붙이기.
	strcpy(temp, str);
	strcat(temp, s.str);
	
	String ss(temp);
	delete []temp;

	return ss;
}

//+= 연산자 오버로딩
//기존 객체에 더하는 것이므로 반환형은 레퍼런스
String& String:: operator+= (const String& s){
	
	len+=s.len;
	char * temp=new char[len];
	strcpy(temp, str);
	strcat(temp, s.str);

	delete []str;
	str=new char[len];
	strcpy(str, temp);
	
	delete[] temp;
	return *this;

}

//동등비교 연산자
//같으면 0 틀리면 1
int String:: operator== (const String& s){
	
	if(strcmp(this->str, s.str) == 0){
			return 0;
	}else  {
			return 1;
	}

}

//출력
ostream& operator<< (ostream& os, const String& s){
	
	os<<s.str;
	return os;
}

int String:: GetLen(){

	return this->len;
}


//입력
istream& operator>> (istream& is, String& s){
	
	int len=s.GetLen();
	char * temp=new char[len];
	is>>temp;
	//문자열 매개변수 생성자 및 복사생성자 사용.
	s=String(temp);
	delete []temp;
	return is;
}

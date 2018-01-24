#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

//string 클래스의 기능 만들어보기.
//1. 문자열을 인자로 전달받는 생성자 정의
//2. 생성자, 소멸자, 복사생성자, 대입연산자 정의
//3. 문자열 결합 + 연산자 오버로딩
//4. 문자열 덧붙이는 += 연산자 오버로딩
//5. 내용비교 == 연산자 오버로딩
//6. 콘솔입출력이 가능한 << >>연산자 오버로딩

class String {

	char * str;
	int len;
	
	public :
		String(){
			str=NULL;
			len=0;
		}

		String(const char * _str){
			
			this->len=strlen(_str)+1;
			this->str=new char[len];
			strcpy(str, _str);
		}

		String(const String& s) : len(s.len) {
			
			this->str=new char[len];
			strcpy(str, s.str);

		}

		~String(){
			delete []str;
		}
		
		String operator+ (const String& s){
			
			this->len+=s.len;
			char * temp=new char[this->len];
			strcpy(temp, this->str);
			strcat(temp, s.str);
			
			String str(temp);
			delete []temp;

			return str;
		}

		String& operator+= (const String& s){
			
			this->len+=len+s.len;
			char * temp=new char[len];
			
			strcpy(temp, this->str);
			strcat(temp, s.str);

			delete []str;
			str=new char[len];
			strcpy(str, temp);
			
			delete []temp;
			return *this;
		}

		String operator= (const String& s){
			
			if(NULL != str){
				delete []str;
			}

			len=s.len;
			str=new char[len];
			strcpy(str, s.str);
			return *this;
		}

		bool operator== (const String& s){
			
			if(strcmp(str, s.str) == 0){
				return true;
			}else {
				return false;
			}
			
		}

		friend ostream& operator<< (ostream& os, const String& s);
		friend istream& operator>> (istream& is, String& s);

}; //String

ostream& operator<< (ostream& os, const String& s){
	
	os<<s.str;
	return os;
}

istream& operator>> (istream& is, String& s){

	char ch[100];
	is>>ch;
	s=String(ch);
	return is;

}



int main(){

	String str1="야호";

	cout<<str1;
	cout<<endl;
	
	String str2="후후";

	String str3=str1+str2;

	cout<<str3;
	cout<<endl;

	bool flag=str1==str2;

	cout<<flag;
	cout<<endl;

	return 0;
}


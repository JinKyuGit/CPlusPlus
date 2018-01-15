#include<iostream>


int main(){

	char name[100];
	char lang[100];

	std::cout<<"이름은 ? : ";
	std::cin>>name;

	std::cout<<"좋아하는 언어는? : ";
	std::cin>>lang;

	std::cout<<"당신의 이름은 "<<name<<std::endl;
	std::cout<<"좋아하는 언어는 "<<lang<<std::endl;

	return 0;
}

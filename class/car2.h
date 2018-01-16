#ifndef __CAR2_H__
#define __CAR2_H__


//필요한 변수
//1. 시동 유무
//2. 시속
//3. 연료

//필요한 기능
//1. 시동
//2. 가속
//3. 감속
//4. 상태확인
//5. 충전.

class Car {

	private :
		bool flag;
		int speed;
		int fuel;
	public :
		Car(int _speed,int _fuel)
			: speed(_speed), fuel(_fuel)
		{
			this->flag=false;
		}
		
		void Show();
		void StartUp();
		void Accel();
		void Break();
		void Charge(int charge);
		void Stop();
};

#endif

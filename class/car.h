#ifndef __CAR_H__
#define __CAR_H__

class Car {

	int speed;
	int fuel;

	public :
		Car(){
			this->speed=0;
			this->fuel=100;
		}

		void Show();
		void Accel();
		void Break();


};

#endif

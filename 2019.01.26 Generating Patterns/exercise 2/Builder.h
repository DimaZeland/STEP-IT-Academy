#pragma once
#include<iostream>
#include<string>

class Car {
public:
	void Start() { std::cout << "The car started to ride\n"; }
	void Stop() { std::cout << "The car stopped\n"; }
	void Left(int angle) { std::cout << "The car turn left in " << angle << " degress\n"; }
	void Right(int angle) { std::cout << "The car turn right in " << angle << " degress\n"; }
};

class CarConsole abstract{
public:
	virtual void Start() abstract;
	virtual void Stop() abstract;
	virtual void Rotate(int angle)  abstract;
};

class Driver: public CarConsole{
protected: 
	Car bmw;
public:
	void Start() override final{ bmw.Start(); };
	void Stop() override final { bmw.Stop(); };
	void Rotate(int angle) override final { 
		if (angle > 0)
			bmw.Right(angle);
		else
			bmw.Left(-angle); 
	};
};
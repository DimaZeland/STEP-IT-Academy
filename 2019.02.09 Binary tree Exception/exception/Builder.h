#include <iostream>
#include<string>

class Auto {
protected:
	std::string number = "";
	float maxSpeed = 100;
	float currentSpeed = 0;
public:
	Auto(std::string num = "", float maxSp = 100, float currentSp = 0){
		SetNumber(num);
		SetMaxSpeed(maxSp);
		SetCurrentSpeed(currentSp);
	}
	inline std::string GetNumber() const { return number; }
	inline float GetMaxSpeed() const { return maxSpeed; }
	inline float GetCurrentSpeed() const { return currentSpeed; }

	inline void SetNumber(std::string num) {
		if (num.size() != 8)
			throw InvalidNumber(num);
		number = num;
	}

	inline void SetMaxSpeed(float Sp) {
		if (Sp > 360)
			throw WrongMaxSpeed(Sp);
		maxSpeed = Sp;
	}

	inline void SetCurrentSpeed(float Sp) {
		if (Sp > maxSpeed)
			throw WrongSpeed(Sp);
		currentSpeed = Sp;
	}

	inline void CurrentSpeedIncrease(float Sp = 5) {
		if (currentSpeed + Sp > maxSpeed)
			throw WrongSpeed(Sp + currentSpeed);
		currentSpeed += Sp;
	}

	inline void CurrentSpeedDecrease(float Sp = 5) { currentSpeed -= Sp; }

	class WrongSpeed :public std::exception {
	private:
		float Speed;
	public:
		WrongSpeed(float Sp) : Speed(Sp) {}
		void what() { std::cout << '\n' << Speed << " - Exceeding the maximum speed!\n"; }
	};

	class WrongMaxSpeed :public std::exception {
	private:
		float Speed;
	public:
		WrongMaxSpeed(float Sp) : Speed(Sp) {}
		void what() { std::cout << '\n' << Speed << " - Setting a maximum speed of more than 360!\n"; }
	};

	class InvalidNumber :public std::exception {
	private:
		std::string number;
	public:
		InvalidNumber(std::string num) : number(num) {}
		void what() { std::cout << '\n' << number << " - Car number is not in the correct format!\n"; }
	};
};
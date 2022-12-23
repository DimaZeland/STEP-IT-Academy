#include<iostream>

template<typename T>
struct result{
	T minimum, maximum;
//	result(T min, T max) : minimum<min>, maximum<max>{}
};
template <typename T>
result<T> max_min(const std::initializer_list<T> &list){
	result<T> xX{1000000, -1};

	for (auto x : list) {
		if (x < xX.minimum)
			xX.minimum = x;
		if (x > xX.maximum)
			xX.maximum = x;
	}
	return xX;
}


int main(){
	std::initializer_list<int> one{ 1,2,3,4,5,-1 };
	result<int> truues = max_min(one);
	std::cout << "min: " << truues.minimum << ", max: " << truues.maximum << std::endl;
	
	system("pause");
	return 0;
}
#pragma once
#include<iostream>

template <typename T>
class Vector{
private:
	T * buffer = nullptr;
	size_t size = 0;
	size_t capacity = 0;
public:
	Vector(size_t size);
	Vector(size_t size, T value);
	Vector();
	Vector(const Vector<T>&);
	~Vector();
	void reserve(size_t newCapacity);
	void resize(size_t newSize, const T & value = T());
	inline void pushBack(const T &elem){ resize(size + 1, elem);}
	void print()const;
	size_t getCapacity() const;
	size_t getSize() const;
	size_t Capacity();
	size_t Size();
	bool empty(); 
	void SetValue(size_t index, T value);
	T operator[](size_t index) { if (index < size) return buffer[index]; else return T(); }
	void pushback(const T& elem);
	void popback();
	T& front();
	T& back();
	bool insert(size_t index, T value);
	bool erase(size_t index);
	void clear();
	void print();
	Vector& operator=(const Vector&);
	friend std::ostream& operator<<(std::ostream& os, const Vector<T>&);
	friend std::istream& operator>>(std::istream& is, Vector<T>&);
};

template<typename T>
Vector<T>::Vector(size_t size) {
	this->size = size;
	capacity = size * 2;
	buffer = new T[capacity]{ T() };
}

template<typename T>
Vector<T>::Vector(size_t size, T value) {
	this->size = size;
	capacity = size * 2;
	buffer = new T[capacity];
	for (int i = 0; i < size; ++i)
		buffer[i] = value;
}

template<typename T>
Vector<T>::Vector() {
	this->size = 0;
	capacity = 0;
	buffer = nullptr;
}

template<typename T>
Vector<T>::Vector(const Vector<T>& v) {
	this->size(v.size);
	this->capacity(v.capacity);
	this->buffer = new T[size];
	for (int i = 0; i < size; ++size)
		buffer[i] = v.buffer[i];
	return *this;
}

template<typename T>
Vector<T>::~Vector() {
	delete[] buffer; 
	buffer = nullptr;
}

template <typename T>
void
Vector<T>::reserve(size_t newCapacity) {
	if (newCapacity <= capacity)
		return;
	T * result = new T[newCapacity]{};
	for (int i = 0; i < size; ++i)
		result[i] = buffer[i];

	delete[] buffer;
	buffer = result;
	capacity = newCapacity;
}

template <typename T>
void
Vector<T>::resize(size_t newSize, const T & value) {
	if (newSize > capacity)
		reserve(newSize * 2);// 10 [][][][][] [][][]
	for (size_t i = size; i < newSize; ++i)
		buffer[i] = value;
	size = newSize;
}

template <typename T>
void
Vector<T>::print()const {
	cout << "Your vector is :\n";
	for (int i = 0; i < size; ++i)
		cout << buffer[i] << "\t";
	cout << endl;
}

template<typename T>
size_t
Vector<T>::getCapacity() const {
	return capacity;
}

template<typename T>
size_t Vector<T>::getSize() const {
	return size;
}

template<typename T>
size_t
Vector<T>::Capacity() {
	return capacity;
}

template<typename T>
size_t
Vector<T>::Size() {
	return size;
}

template<typename T>
bool
Vector<T>::empty(){
	return 0 == size;
}

template<typename T>
void
Vector<T>::SetValue(size_t index, T value) {
	buffer[index] = value;
}

template<typename T>
void
Vector<T>::pushback(const T & elem) {
	if (capacity - size)
		buffer[size++] = elem;
	else {
		capacity = size * 2;
		buffer[size++] = elem;
	}
}

template<typename T>
void
Vector<T>::popback() {
	if (size)
		buffer[--size] = T();
}

template<typename T>
T &
Vector<T>::front() {
	T static errorFront = 0;
	if (0 == size)
		return errorFront;
	return buffer[0];
}

template<typename T>
T &
Vector<T>::back() {
	T static errorBack = 0;
	if (0 == size)
		return errorBack;
	return buffer[size - 1];
}

template<typename T>
bool
Vector<T>::insert(size_t index, T value) {
	if (index > size - 1)
		return false;
	else {
		++size;
		for (int i = size - 1; i > index; --i)
			buffer[i] = buffer[i - 1];
		buffer[index] = value;
		return true;
	}
}

template<typename T>
bool
Vector<T>::erase(size_t index) {
	if (index > size - 1)
		return false;
	else {
		for (int i = index; i < size - 1; ++i)
			buffer[i] = buffer[i + 1];
		buffer[--size] = T();
		return true;
	}
}
template<typename T>
void
Vector<T>::clear() {
	while (--size > 0)
		buffer[size] = T();
	buffer[size] = T();
}

template<typename T>
void
Vector<T>::print() {
	for (int i = 0; i < size; ++i)
		std::cout << i << ": " << buffer[i] << std::endl;
}

template<typename T>
Vector<T>&
Vector<T>::operator=(const Vector & v) {
	if (this == &v)
		return *this;
	delete[] buffer;

	size = v.size;
	capacity = v.capacity;
	if (size) {
		buffer = new T[size];
		for (int i = 0; i < size; ++i)
			buffer[i] = v.buffer[i];
	}
	return *this;
}

template<typename T>
std::ostream&
operator<<(std::ostream & os, const Vector<T>& v) {
	for (int i = 0; i < v.size; ++i)
		os << i << ": " << v.buffer[i] << std::endl;
	return os;
}

template<typename T>
std::istream&
operator>>(std::istream & is, Vector<T>& v) {
	T buf = T();
	for (int i = 0; i < v.size; ++i) {
		std::cout << "\nEnter a value of [" << i << "] element: ";
		is >> v.buffer[i];
	}
	return is;
}
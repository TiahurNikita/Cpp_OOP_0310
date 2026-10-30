#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <string>
#include <ostream>
#include <iostream>
#include <format>
#include <cstring>

template<typename T>
class Vector2_t {
private:
	T x;
	T y;
	char* name;
public:
	T get_x() const { return x; }
	T get_y() const { return y; }
	void set_x(T x) { this->x = x; }
	void set_y(T y) { this->y = y; }
	char* get_name() const { return name; }
	void set_name(char* name) { this->name = name; }

	std::string to_string() const;

	Vector2_t();
	Vector2_t(T x);
	Vector2_t(T x, T y);
	Vector2_t(T x, T y, char* name);

	Vector2_t(const Vector2_t<T>& other);
	Vector2_t(Vector2_t<T>&& other) noexcept;

	Vector2_t<T>& operator =(const Vector2_t<T>& other);
	Vector2_t<T>& operator =(Vector2_t<T>&& other) noexcept;

	~Vector2_t();

	Vector2_t<T> operator +(const Vector2_t<T>& other) const;
	Vector2_t<T> operator -(const Vector2_t<T>& other) const;

	void operator += (const Vector2_t<T>& other);
	void operator += (T n);

	void operator -= (const Vector2_t<T>& other);
	void operator -= (T n);

	Vector2_t<T> operator -() const;

	T operator *(const Vector2_t<T>& other) const;

	Vector2_t<T> operator *(T n) const;
	Vector2_t<T> operator /(T n) const;
};

template<typename T>
Vector2_t<T>::Vector2_t() {
	x = T(0);
	y = T(0);
	name = NULL;
}

template<typename T>
Vector2_t<T>::Vector2_t(T x) {
	this->x = x;
	y = T(0);
	name = NULL;
}

template<typename T>
Vector2_t<T>::Vector2_t(T x, T y) : x{ x }, y{ y } {
	name = NULL;
}

template<typename T>
Vector2_t<T>::Vector2_t(T x, T y, char* name) : x{ x }, y{ y }, name{ name } {
}

template<typename T>
Vector2_t<T>::Vector2_t(const Vector2_t<T>& other) {
	this->x = other.x;
	this->y = other.y;
	if (other.name != NULL) {
		size_t len = strlen(other.name) + 1;
		this->name = new char[len];
		strcpy(this->name, other.name);
		std::cout << "Copy constructor: copy from " << (void*)other.name << " to " << (void*)(this->name) << std::endl;
	}
	else this->name = NULL;
}

template<typename T>
Vector2_t<T>::Vector2_t(Vector2_t<T>&& other) noexcept {
	this->x = other.x;
	this->y = other.y;
	this->name = other.name;
	other.name = NULL;
	std::cout << "Move constructor: take from " << (void*)this->name << std::endl;
}

template<typename T>
Vector2_t<T>::~Vector2_t() {
	if (name != NULL) {
		delete[] name;
	}
}

template<typename T>
std::string Vector2_t<T>::to_string() const {
	if (name != NULL) return std::format("{}: ({}; {})", name, x, y);
	else return std::format("({}; {})", x, y);
}

template<typename T>
Vector2_t<T> Vector2_t<T>::operator +(const Vector2_t<T>& other) const {
	char* new_name = NULL;
	if (this->name != NULL && other.name != NULL) {
		size_t len1 = strlen(this->name);
		size_t len = len1 + strlen(other.name) + 2;
		new_name = new char[len];
		strcpy(new_name, this->name);
		strcpy(new_name + len1, "+");
		strcpy(new_name + len1 + 1, other.name);
	}
	return Vector2_t<T>(this->x + other.x, this->y + other.y, new_name);
}
template<typename T>
Vector2_t<T> Vector2_t<T>::operator -(const Vector2_t<T>& other) const {
	char* new_name = NULL;
	if (this->name != NULL && other.name != NULL) {
		size_t len1 = strlen(this->name);
		size_t len = len1 + strlen(other.name) + 2;
		new_name = new char[len];
		strcpy(new_name, this->name);
		strcpy(new_name + len1, "-");
		strcpy(new_name + len1 + 1, other.name);
	}
	return Vector2_t<T>(this->x - other.x, this->y - other.y, new_name);
}

template<typename T>
Vector2_t<T>& Vector2_t<T>::operator =(const Vector2_t<T>& other) {
	this->x = other.x;
	this->y = other.y;

	if (other.name != NULL) {
		size_t len = strlen(other.name) + 1;
		this->name = new char[len];
		strcpy(this->name, other.name);
		std::cout << "Copy assignment: copy from " << (void*)other.name << " to "
			<< (void*)(this->name) << std::endl;
	}
	else {
		this->name = NULL;
	}
	return *this;
}

template<typename T>
Vector2_t<T>& Vector2_t<T>::operator =(Vector2_t<T>&& other) noexcept {
	this->x = other.x;
	this->y = other.y;
	this->name = other.name;
	other.name = NULL;
	std::cout << "Move assigment: take from " << (void*)this->name << std::endl;
	return *this;
}
template<typename T>
Vector2_t<T> Vector2_t<T>::operator -() const {
	char* new_name = NULL;
	if (this->name != NULL) {
		size_t len = strlen(this->name) + 2;
		new_name = new char[len];
		strcpy(new_name, "-");
		strcpy(new_name + 1, this->name);
	}
	return Vector2_t<T>(-this->x, -this->y, new_name);
}

template<typename T>
std::ostream& operator <<(std::ostream& out, const Vector2_t<T>& v) {
	out << v.to_string();
	return out;
}

template<typename T>
Vector2_t<T> Vector2_t<T>::operator *(T n) const {
	char* new_name = NULL;
	if (this->name != NULL) {
		size_t len = strlen(this->name) + 1;
		new_name = new char[len];
		strcpy(new_name, this->name);
	}
	return Vector2_t<T>(this->x * n, this->y * n, new_name);
}

template<typename T>
Vector2_t<T> Vector2_t<T>::operator /(T n) const {
	char* new_name = NULL;
	if (this->name != NULL) {
		size_t len = strlen(this->name) + 1;
		new_name = new char[len];
		strcpy(new_name, this->name);
	}
	return Vector2_t<T>(this->x / n, this->y / n, new_name);
}

template<typename T>
void Vector2_t<T>::operator += (const Vector2_t<T>& other) {
	this->x += other.x;
	this->y += other.y;
}

template<typename T>
void Vector2_t<T>::operator += (T n) {
	this->x += n;
	this->y += n;
}

template<typename T>
void Vector2_t<T>::operator -= (const Vector2_t<T>& other) {
	this->x -= other.x;
	this->y -= other.y;
}

template<typename T>
void Vector2_t<T>::operator -= (T n) {
	this->x -= n;
	this->y -= n;
}

template<typename T>
T Vector2_t<T>::operator *(const Vector2_t<T>& other) const {
	return this->x * other.x + this->y * other.y;
}
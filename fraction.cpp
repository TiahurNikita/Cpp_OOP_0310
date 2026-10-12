#define _CRT_SECURE_NO_WARNINGS
#include "fraction.h"
#include <iostream>
#include <format>

fraction_t::fraction_t() {
	numerator = 0;
	denominator = 1;
	name = NULL;
}

fraction_t::fraction_t(int n) {
	numerator = n;
	denominator = 1;
	name = NULL;
}

fraction_t::fraction_t(int numerator, int denominator):
	numerator{ numerator }, denominator{ denominator }
{
	name = NULL;
}

fraction_t::fraction_t(int numerator, int denominator, char* name) :
	numerator{ numerator }, denominator{ denominator }, name{name}
{
}

fraction_t::fraction_t(fraction_t& other) {
	//this->name = other.name - 2 покажчик на 1 і те ж ім'я (для полів-покажчиків)
	//деструктор 1 об'єкта видалить дані й для іншого, що спричинить помилку
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	if (other.name != NULL) {
		size_t len = strlen(other.name) + 1;
		this->name = new char[len];
		strcpy(this->name, other.name);
		std::cout << "Copy constructor: copy from " 
			<< (void*)other.name << " to " << (void*)(this->name) << std::endl;
	}
	else this->name = NULL;
}

fraction_t::fraction_t(fraction_t&& other) noexcept{
	/* Конструктор перенесення (move constructor) викликається тоді,
	* коли інший об'єкт (other) підлягає знищеннюю, наприклад, коли він
	* передається як результат роботи функції
	* 
	* Конструктор перенесення може "забрати" ресурс іншого об'єкта
	* замість того, щоб створювати копію. Але, щоб знищення не запустилось
	* автоматично, слід поміняти ресурс іншого об'єкту на NULL
	*/
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	this->name = other.name;
	other.name = NULL;
	std::cout << "Move constructor: take from " << (void*)this->name << std::endl;
}

fraction_t fraction_t::operator +(const fraction_t& other) {
	char* new_name = NULL;
	if (this->name != NULL && other.name != NULL) {
		size_t len1 = strlen(this->name);
		size_t len = len1 + strlen(other.name) + 2;
		new_name = new char[len];
		strcpy(new_name, this->name);
		strcpy(new_name + len1, "+");
		strcpy(new_name + len1 + 1, other.name);
	}
	int num, den, gcd_n_d;
	num = this->numerator * other.denominator + other.numerator * this->denominator;
	den = this->denominator * other.denominator;
	//gcd_n_d = gcd(num, den);
	//num /= gcd_n_d;
	//den /= gcd_n_d;
	return fraction_t(num, den, new_name);
}

fraction_t fraction_t::operator -(const fraction_t& other) {
	char* new_name = NULL;
	if (this->name != NULL && other.name != NULL) {
		size_t len1 = strlen(this->name);
		size_t len = len1 + strlen(other.name) + 2;
		new_name = new char[len];
		strcpy(new_name, this->name);
		strcpy(new_name + len1, "-");
		strcpy(new_name + len1 + 1, other.name);
	}
	int num, den, gcd_n_d;
	num = this->numerator * other.denominator - other.numerator * this->denominator;
	den = this->denominator * other.denominator;
	//gcd_n_d = gcd(num, den);
	//num /= gcd_n_d;
	//den /= gcd_n_d;
	return fraction_t(num, den, new_name);
}

/*
Поєднання конструктора копіювання та відповідного оператора "="
називають "семантикою копіювання"
*/
fraction_t& fraction_t::operator =(const fraction_t& other) {
	this->numerator = other.numerator;
	this->denominator = other.denominator;
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

fraction_t& fraction_t::operator =(fraction_t&& other) noexcept {
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	this->name = other.name;
	other.name = NULL;
	std::cout << "Move assigment: take from " << (void*)this->name << std::endl;
	return *this;
}

char* fraction_t::get_name() const {
	return name;
}

void fraction_t::set_name(char* name) {
	this->name = name;
}

int fraction_t::get_numerator() const {
	return numerator;
}

int fraction_t::get_denominator() const {
	return denominator;
}

void fraction_t::set_numerator(int numerator) {
	this->numerator = numerator;
	/* this - покажчик на об'єкт, неявний параметр, шо
	передається у нестатичні методи класу */
}

void fraction_t::set_denominator(int denominator) {
	this->denominator = denominator;
}

std::string fraction_t::to_string() const {
	return std::format("({0}/{1}) {2}", numerator, denominator, (name==NULL ? "":name));
}

fraction_t::~fraction_t() {
	if (name != NULL) {
		delete[] name;
	}
}

fraction_t operator *(const fraction_t& f1, const fraction_t& f2) {
	char* new_name = NULL;
	if (f1.name != NULL && f2.name != NULL) {
		size_t len1 = strlen(f1.name);
		size_t len = len1 + strlen(f2.name) + 2;
		new_name = new char[len];
		strcpy(new_name, f1.name);
		strcpy(new_name + len1, "*");
		strcpy(new_name + len1 + 1, f2.name);
	}
	int num, den, gcd_n_d;
	num = f1.numerator * f2.numerator; // Дружні функції мають доступ до 
	den = f1.denominator * f2.denominator; // приватних полів об'єкту
	//gcd_n_d = gcd(num, den);
	//num /= gcd_n_d;
	//den /= gcd_n_d;
	return fraction_t(num, den, new_name);
}

fraction_t operator /(const fraction_t& f1, const fraction_t& f2) {
	char* new_name = NULL;
	if (f1.get_name() != NULL && f2.get_name() != NULL) {
		size_t len1 = strlen(f1.get_name());
		size_t len = len1 + strlen(f2.get_name()) + 2;
		new_name = new char[len];
		strcpy(new_name, f1.get_name());
		strcpy(new_name + len1, "/");
		strcpy(new_name + len1 + 1, f2.get_name());
	}
	int num, den, gcd_n_d;
	num = f1.get_numerator() * f2.get_denominator(); //Недружні функції мають доступ
	den = f1.get_denominator() * f2.get_numerator(); //лише до аксесорів
	//gcd_n_d = gcd(num, den);
	//num /= gcd_n_d;
	//den /= gcd_n_d;
	return fraction_t(num, den, new_name);
}

std::ostream& operator <<(std::ostream& out, const fraction_t& f) {
	out << f.to_string();
	return out;
}

fraction_t operator -(const fraction_t& f) { // A = -B
	char* new_name = NULL;
	if (f.get_name() != NULL) {
		size_t len = strlen(f.get_name()) + 2;
		new_name = new char[len];
		strcpy(new_name, "-");
		strcpy(new_name+1, f.get_name());
	}
	return fraction_t(-f.get_numerator(), f.get_denominator(), new_name);
}

void fraction_t::operator += (const fraction_t& other) {
	/*char* new_name = NULL;
	if (this->name != NULL && other.name != NULL) {
		size_t len1 = strlen(this->name);
		size_t len = len1 + strlen(other.name) + 2;
		new_name = new char[len];
		strcpy(new_name, this->name);
		strcpy(new_name + len1, "+");
		strcpy(new_name + len1 + 1, other.name);
	}*/
	int num, den, gcd_n_d;
	this->numerator = this->numerator * other.denominator + other.numerator * this->denominator;
	this->denominator = this->denominator * other.denominator;
	reduce();
	//this->name = new_name;
}

void fraction_t::operator += (int n) {
	this->numerator += n * this->denominator;
	reduce();
}

int fraction_t::gcd(int a, int b) {
	if (a < 0) a = -a;
	if (b < 0) b = -b;
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

void fraction_t::reduce() {
	int g = gcd(numerator, denominator);
	if(g!=1){
		numerator /= g;
		denominator /= g;
	}
}

/*
Правила опису класів:
При описі класів необхідно обов'язково включити до списку:
- конструктор за замовчуванням
- конструктор копіювання
- конструктор перенесення
- оператор = копіювання
- оператор = перенесення
- деструктор
~ інколи додають параметризований конструктор
*/
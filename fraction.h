#pragma once
#include <string>
#include <ostream>

class fraction_t {			// клас - тип даних, тому є традиція додавати "_t"
private:					// склад класу поділяється за "видимістю" на декілька категорій
	int numerator;			// поле - "змінна" в середині класу
	int denominator;		// набір полів називають "характеристиками" класу
	char* name;
	int gcd(int a, int b);
	void reduce();
public:						// За рекомендаціями ООП поля мають бути приватними,
	int get_numerator() const;	// а для доступу до них створюють методи ("функції"), що називаються
	int get_denominator() const;  // аксесорами (які поділяють на геттери і сеттери)
	void set_numerator(int); // набір методів класу також називають "поведінкою"
	void set_denominator(int);
	char* get_name() const;
	void set_name(char* name);
	std::string to_string() const;

	fraction_t();			// конструктор
	fraction_t(int);
	fraction_t(int, int);
	fraction_t(int, int, char*);

	fraction_t(fraction_t&); // конструктор копіювання
	fraction_t(fraction_t&&) noexcept; // конструктор переносу (move cinstructor)

	~fraction_t(); // детруктор - знищення об'єкту

	static fraction_t decil() {
		fraction_t d(1, 10, new char[] {"Decil"});
		return d;
	}

	// оператори C++ надає можливість перевантажувати оператори з автоматичним
	// включенням наших об'єктів до арифметичних та інших виразів на кшталт A+B
	// Перевантаження - через ключеве слово "operator", для пришвидшення роботи
	// другий аргумент (other) передається за посиланням (&) для унеможливлення
	// його змін додається const
	fraction_t operator +(const fraction_t& other);
	fraction_t operator -(const fraction_t& other);
	// Особливу роль грають оператори присвоєння (=)
	// Вони також поділяються на оператори копіювання та перенесення
	fraction_t& operator =(const fraction_t& other); //copy
	fraction_t& operator =(fraction_t&& other) noexcept; //move

	void operator += (const fraction_t& other);
	void operator += (int n);

	// "Дружні методи"
	// зовнішні функції, яким дозволено доступ до приватних членів об'єктів
	friend fraction_t operator *(const fraction_t& f1, const fraction_t& f2);
};
// Оператори можуть бути оголошенні поза класом
// традиція: зовні описаються оператори, що не змінюють об'єкти (*, / тощо)
// в середині класу - ті, що змінюють (+=, = тощо)
fraction_t operator *(const fraction_t& f1, const fraction_t& f2);
fraction_t operator /(const fraction_t& f1, const fraction_t& f2);

fraction_t operator -(const fraction_t& f);
// а також деякі оператори, що в якості 1 параметра отримують не даний об'єкт
std::ostream& operator <<(std::ostream& out, const fraction_t& f);
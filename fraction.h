#pragma once
#include <string>

class fraction_t {			// клас - тип даних, тому є традиція додавати "_t"
private:					// склад класу поділяється за "видимістю" на декілька категорій
	int numerator;			// поле - "змінна" в середині класу
	int denominator;		// набір полів називають "характеристиками" класу
	char* name;
public:						// За рекомендаціями ООП поля мають бути приватними,
	int get_numerator();	// а для доступу до них створюють методи ("функції"), що називаються
	int get_denominator();  // аксесорами (які поділяють на геттери і сеттери)
	void set_numerator(int); // набір методів класу також називають "поведінкою"
	void set_denominator(int);
	char* get_name();
	void set_name(char* name);
	std::string to_string();

	fraction_t();			// конструктор
	fraction_t(int);
	fraction_t(int, int);
	fraction_t(int, int, char*);

	fraction_t(fraction_t&); // конструктор копіювання
	//fraction_t(fraction_t&&); // конструктор переносу (move cinstructor)

	~fraction_t(); // детруктор - знищення об'єкту
};
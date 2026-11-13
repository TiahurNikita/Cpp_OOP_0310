#pragma once
#include <string>
// інша традиція іменування - CamelCase
// імена змінних, полів та методів - lowerCamelCase
// перша літера маленька, далі у поєднанні - великі
// імена класів  - CapitalCamelCase - 1 літера велика

class Product {
private:
	std::string name;
	double price;
public:
	std::string getName() const;
	Product* setName(std::string);
	double getPrice() const;
	Product* setPrice(double);

	virtual std::string toString() const = 0;

	Product() {}
	Product(const Product& other) : name{ other.name }, price { other.price } {}
	Product(Product&& other) noexcept : name{ other.name }, price{ other.price } {}
	~Product() {}
};
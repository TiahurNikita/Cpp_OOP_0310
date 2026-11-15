#pragma once
#include "Product.h"

class Periphery : public Product {
private:
	std::string connection;
public:
	std::string getConnection() const;
	Periphery* setConnection(std::string);

	Periphery() {}
	Periphery(const Periphery& other) : connection{ other.connection } {}
	Periphery(Periphery&& other) noexcept : connection{ other.connection } {}
	~Periphery(){}
};

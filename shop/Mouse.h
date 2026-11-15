#pragma once
#include "Periphery.h"

class Mouse : public Periphery {
private:
	unsigned int dpi;
public:
	unsigned int getDPI() const;
	Mouse* setDPI(unsigned int);
	std::string toString() const override;

	Mouse() : dpi{ 1000 } {}
	Mouse(const Mouse& other) : dpi{ other.dpi } {}
	Mouse(Mouse&& other) noexcept : dpi{ other.dpi } {}
	~Mouse() {}
};
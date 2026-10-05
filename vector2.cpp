#include "vector2.h"
#include <iostream>
#include <format>

vector2_t::vector2_t() {
	x = 0.0f;
	y = 0.0f;
	name = NULL;
}

vector2_t::vector2_t(float x) {
	this->x = x;
	y = 0.0f;
	name = NULL;
}

vector2_t::vector2_t(float x, float y) :
	x{ x }, y{ y }
{
	name = NULL;
}

vector2_t::vector2_t(float x, float y, char* name) :
	x{ x }, y{ y }, name{ name }
{
}

vector2_t::vector2_t(vector2_t& other) {
	this->x = other.x;
	this->y = other.y;
	if (other.name != NULL) {
		size_t len = strnlen_s(other.name, 100) + 1;
		this->name = new char[len];
		strcpy_s(this->name, len, other.name);
		std::cout << "Copy constructor: copy from " << (void*)other.name << " to " << (void*)(this->name) << std::endl;
	}
	else this->name = NULL;
}

float vector2_t::get_x() {
	return x;
}

float vector2_t::get_y() {
	return y;
}

void vector2_t::set_x(float x) {
	this->x = x;
}

void vector2_t::set_y(float y) {
	this->y = y;
}

char* vector2_t::get_name() {
	return name;
}

void vector2_t::set_name(char* name) {
	this->name = name;
}

std::string vector2_t::to_string() {
	if(name != NULL) return std::format("{}: ({}; {})", name, x, y);
	else return std::format("({}; {})", x, y);
}

vector2_t::~vector2_t() {
	if (name != NULL) {
		delete[] name;
	}
}
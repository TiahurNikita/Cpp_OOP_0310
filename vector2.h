#pragma once
#include <string>

class vector2_t {
private:
	float x;
	float y;
	char* name;
public:
	float get_x();
	float get_y();
	void set_x(float);
	void set_y(float);
	char* get_name();
	void set_name(char* name);
	std::string to_string();

	vector2_t();
	vector2_t(float);
	vector2_t(float, float);
	vector2_t(float, float, char*);

	vector2_t(vector2_t&);
	vector2_t(vector2_t&&) noexcept;

	~vector2_t();

	static vector2_t vec0() {
		vector2_t vec0(0, 0, new char[] {"0-Vector"});
		return vec0;
	}

	vector2_t operator +(const vector2_t& other);
	vector2_t operator -(const vector2_t& other);

	vector2_t& operator =(const vector2_t& other);
	vector2_t& operator =(vector2_t&& other) noexcept;
};
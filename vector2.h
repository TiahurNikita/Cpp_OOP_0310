#pragma once
#include <string>
#include <ostream>

class vector2_t {
private:
	float x;
	float y;
	char* name;
public:
	float get_x() const;
	float get_y() const;
	void set_x(float);
	void set_y(float);
	char* get_name() const;
	void set_name(char* name);
	std::string to_string() const;

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

	void operator += (const vector2_t& other);
	void operator += (float n);

	void operator -= (const vector2_t& other);
	void operator -= (float n);

	friend float operator *(const vector2_t& v1, const vector2_t& v2);
};

float operator *(const vector2_t& v1, const vector2_t& v2);

vector2_t operator *(const vector2_t& v, float n);
vector2_t operator /(const vector2_t& v, float n);

vector2_t operator -(const vector2_t& v);
std::ostream& operator <<(std::ostream& out, const vector2_t& v);
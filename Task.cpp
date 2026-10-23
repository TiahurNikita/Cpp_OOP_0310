#include "intro.h"
#include <iostream>
#include "vector2.h"
#include "basics.h"
#include "autos_basic.h"
int main() {
	//intro();
	/*vector2_t vec1;
	vector2_t* vec2 = new vector2_t;
	std::cout << vec1.to_string() << std::endl
		<< vec2->to_string() << std::endl;

	vector2_t vec3(5.3f);
	vector2_t* vec4 = new vector2_t(4.5, -8.7, new char[] {"Vec4"});
	std::cout << vec3.to_string() << std::endl
		<< vec4->to_string() << std::endl;
	vector2_t vec5(-3.4f, 2.3f, new char[] {"Normal"});
	vector2_t* vec6 = new vector2_t(vec5);
	std::cout << vec5.to_string() << std::endl
		<< vec6->to_string() << std::endl;
	vector2_t v = std::move(vector2_t::vec0());
	std::cout << v.to_string() << std::endl;

	std::cout << "-----------------" << std::endl;
	vector2_t f;
	std::cout << f.to_string() << std::endl;
	f = v;
	std::cout << f.to_string() << std::endl;
	std::cout << "-----------------" << std::endl;
	f = f + vec5;
	std::cout << f.to_string() << std::endl;
	f = f - *vec4;
	std::cout << f.to_string() << std::endl;
	std::cout << -f << std::endl;
	std::cout << "-----------------" << std::endl;
	vec5 += *vec4;
	std::cout << vec5 << std::endl;
	std::cout << vec5*5 << std::endl;
	vec5 -= vec3;
	std::cout << vec5/2 << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << vec5*vec3 << std::endl;

	delete vec2;
	delete vec4;
	delete vec6;*/
	//basics();
	autos_basic();
	return 0;
}

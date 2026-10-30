#include "vector_task.h"
#include "vector2.h"

void vector_task() {
	Vector2_t<int> vec1(100);
	Vector2_t<float>* vec2 = new Vector2_t<float>;

	std::cout << vec1.to_string() << std::endl
		<< vec2->to_string() << std::endl;

	Vector2_t<double> vec3(4.6);
	Vector2_t<float>* vec4 = new Vector2_t<float>(-8.9f, 123.4f, new char[]{"Vec4"});

	std::cout << vec3.to_string() << std::endl
		<< vec4->to_string() << std::endl;

	Vector2_t<float> vec5(-4.9f, 7.5f, new char[] {"Normal"});
	Vector2_t<float>* vec6 = new Vector2_t<float>(vec5);

	std::cout << vec5.to_string() << std::endl
		<< vec6->to_string() << std::endl;
	Vector2_t<int> v = std::move(vec1);
	std::cout << v.to_string() << std::endl;

	std::cout << "-----------------" << std::endl;
	Vector2_t<int> f;
	std::cout << f.to_string() << std::endl;
	f = v;
	std::cout << f.to_string() << std::endl;

	std::cout << "-----------------" << std::endl;
	Vector2_t<float> t;
	t = vec5 + *vec4;
	std::cout << t.to_string() << std::endl;
	t = t - *vec4;
	std::cout << t.to_string() << std::endl;
	std::cout << -t << std::endl;

	std::cout << "-----------------" << std::endl;
	vec5 += *vec4;
	std::cout << vec5 << std::endl;
	std::cout << vec5 * 5.0f << std::endl;
	Vector2_t<double> a(12.8, -17.8, new char[] {"A-Vec"});
	std::cout << a / 2.0 << std::endl;

	std::cout << "-----------------" << std::endl;
	Vector2_t<int> mult1(8, 2);
	Vector2_t<int> mult2(1, 9);
	std::cout << mult1 * mult2 << std::endl;

	delete vec2;
	delete vec4;
	delete vec6;
}
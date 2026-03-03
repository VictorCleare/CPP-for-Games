#include <iostream>

int main() {

	double d = 42.99;

	float f = static_cast<float>(d);

	int i = static_cast<int>(f);

	char c = static_cast<char>(i);

	bool b = static_cast<bool>(c);

	std::cout << "Double: " << d << std::endl;
	std::cout << "Float: " << f << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Char: " << c << std::endl;
	std::cout << "Bool: " << b << std::endl;

	return 0;
}
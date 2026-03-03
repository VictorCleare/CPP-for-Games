#include <iostream>

int main() {

	float num1;
	char sign;
	float num2;
	float result;

	std::cout << "*** SIMPLE CALCULATOR ***" << std::endl << std::endl;
	std::cout << "Please input your first value" << std::endl;
	std::cin >> num1;

	while (std::cin.fail()) {

		std::cout << "ERROR: I expected a number." << std::endl;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> num1;
	}

	std::cout << "Please input your operator ( + - / * )" << std::endl;
	std::cin >> sign;

	while (sign != '+' && sign != '-' && sign != '/' && sign != '*') {

		std::cout << "ERROR: Please input a valid operator ( + - / * )." << std::endl;

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> sign;
	}


	std::cout << "Please input your second value" << std::endl;
	std::cin >> num2;

	while (std::cin.fail() || (num2 == 0 && sign == '/')) {
		if (num2 == 0 && sign == '/') {
			std::cout << "ERROR: I cannot divide by 0" << std::endl;
			num2 = 1;
		}
		else if (std::cin.fail()) {
			std::cout << "ERROR: I expected a number." << std::endl;
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> num2;
	}

	if (sign == '+') {
		result = num1 + num2;
	} 
	else if (sign == '-') {
		result = num1 - num2;
	} 
	else if (sign == '/') {
		result = num1 / num2;
	} 
	else if (sign == '*') {
		result = num1 * num2;
	}
	else {
		std::cout << "ERROR: Could not compute." << std::endl;
	}
	
	std::cout << num1 << " " << sign << " " << num2 << " = " << result << std::endl;

	std::cout << "Press [Enter] to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();




	return 0;
}
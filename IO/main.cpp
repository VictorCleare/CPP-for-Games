#include <iostream>
#include <string>
#include <limits>

int main() {

	std::string name;
	int age;

	std::cout << "Hello, what is your name?" << std::endl;
	std::cin >> name;

	std::cout << "And, how old are you?" << std::endl;
	std::cin >> age;

	while (std::cin.fail() || age < 0) {
		if (age < 0) {
			std::cout << "ERROR: I doubt you're that young." << std::endl;
			age = 0;
		}
		else if (std::cin.fail()) {
			std::cout << "ERROR: I expected a number." << std::endl;
		}
		
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> age;
	}

	if (age < 25) {
		std::cout << "Hello, " << name;
		std::cout << ".  You are only " << age << " years old." << std::endl;
	} else if (age < 50) {
		std::cout << "Hello, " << name;
		std::cout << ".  You are already " << age << " years old." << std::endl;
	}
	else if (age >= 50) {
		std::cout << "Hello, " << name;
		std::cout << ".  You are very wise for your age." << std::endl;
	}


	std::cout << "Press [Enter] to continue..." << std::endl;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();

	return 0;
}
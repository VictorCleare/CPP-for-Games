#include <fstream>
#include <iostream>

struct highscore {
	char name[4];
	uint32_t score;
};

int main() {

	// Write ascii files.
	{
		std::ofstream highscores("highscores.txt");
		if (!highscores) {
			std::cerr << "ERROR: Could not open file for writing." << std::endl;
			return 1;
		}
		highscores << "VIC " << 2014 << std::endl;
		highscores << "TOM " << 2012 << std::endl;
		highscores << "LUC " << 2009 << std::endl;
		highscores << "DAN " << 2018 << std::endl;
		highscores << "SUZ " << 2000 << std::endl;

		if (highscores.bad()) {
			std::cerr << "ERROR: An error occurred while writing to file." << std::endl;
			return 1;
		}

		highscores.close();
	}


	// Append to ascii files.
	{
		std::ofstream highscores("highscores.txt", std::ios::app);
		if (!highscores) {
			std::cerr << "ERROR: Could not open file for appending." << std::endl;
			return 1;
		}

		highscores << "ERY " << 1977 << std::endl;

		if (highscores.bad()) {
			std::cerr << "ERROR: An error occurred while writing to file." << std::endl;
			return 1;
		}

		highscores.close();

	}


	// Read ascii files.
	{
		std::ifstream highscores("highscores.txt");
		if (!highscores) {
			std::cerr << "ERROR: Failed to open file." << std::endl;
			return 1;
		}

		char name[4];
		int score;

		while (highscores >> name >> score) {
			std::cout << name << " " << score << std::endl;
		}

		if (highscores.bad()) {
			std::cerr << "ERROR: Reading the file." << std::endl;
			return 1;
		}

		highscores.close();
	}

	std::cout << std::endl;


	// Writing binary files
	{
		std::ofstream highscores("highscores.bin", std::ios::binary);

		if (!highscores) {
			std::cerr << "ERROR: Could not open binary file for writing." << std::endl;
			return 1;
		}

		highscore scores[] = {
			{"VIC", 2014},
			{"TOM", 2012},
			{"LUC", 2009},
			{"DAN", 2018},
			{"SUZ", 2000}
		};

		auto numScores = std::size(scores);

		highscores.write(reinterpret_cast<const char*>(&numScores), sizeof(numScores));

		highscores.write(reinterpret_cast<const char*>(scores), numScores * sizeof(highscore));

		if (highscores.bad()) {
			std::cerr << "ERROR: Failed to write to binary file." << std::endl;
			return 1;
		}

		highscores.close();
	}


	// Reading from binary files.
	{
		std::ifstream highscores("highscores.bin", std::ios::binary);
		if (!highscores) {
			std::cerr << "ERROR: Could not open binary file for reading." << std::endl;
			return 1;
		}

		size_t numEntries;
		highscores.read(reinterpret_cast<char*>(&numEntries), sizeof(numEntries));

		highscore* scores = new highscore[numEntries];

		highscores.read(reinterpret_cast<char*>(scores), numEntries * sizeof(highscore));

		if (highscores.bad()) {
			std::cerr << "ERROR: Failed to read binary file." << std::endl;
			return 1;
		}

		for (int i = 0; i < numEntries; i++) {
			std::cout << scores[i].name << " " << scores[i].score << std::endl;
		}

		delete[] scores;


		highscores.close();

	}

	return 0;
}
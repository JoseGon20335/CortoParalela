//generadorDeNumeros.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <number_of_elements>" << std::endl;
        return 1;
    }

        int n = std::stoi(argv[1]); // Obtener el número de elementos desde el argumento
        
    srand(static_cast<unsigned int>(time(nullptr)));

    std::ofstream outputFile("input.csv");

    for (int i = 0; i < n; i++) {
        int num = rand() % 1000;
        outputFile << num << ",";
    }

    outputFile.close();

    std::ifstream inputFile("input.csv");
    std::vector<int> numbers;

    int num;
    while (inputFile >> num) {
        numbers.push_back(num);
    }

    return 0;
}

//quicksortSecuencial.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>

std::vector<int> quicksort(const std::vector<int>& arr) {
    if (arr.size() <= 1)
        return arr;

    int pivot = arr[arr.size() / 2];
    std::vector<int> left, right, sorted;

    for (int element : arr) {
        if (element < pivot)
            left.push_back(element);
        else if (element > pivot)
            right.push_back(element);
    }

    std::vector<int> sorted_left = quicksort(left);
    std::vector<int> sorted_right = quicksort(right);

    sorted.insert(sorted.end(), sorted_left.begin(), sorted_left.end());
    sorted.push_back(pivot);
    sorted.insert(sorted.end(), sorted_right.begin(), sorted_right.end());

    return sorted;
}

int main() {
    std::ifstream inputFile("input.csv");
    std::ofstream outputFile("sorted_output_secuencial.csv");
    
    if (!inputFile.is_open()) {
        std::cerr << "Could not open input file." << std::endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        std::cerr << "Could not open output file." << std::endl;
        return 1;
    }

    std::vector<int> numbers;

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string token;
        while (std::getline(iss, token, ',')) {
            int num = std::stoi(token);
            numbers.push_back(num);
        }
    }

    int* array = new int[numbers.size()];
    std::copy(numbers.begin(), numbers.end(), array);
    
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "SIze1: " << numbers.size();
    // Sorting the array
    numbers = quicksort(numbers);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Time taken by quicksort: " << duration.count() << " seconds" << std::endl;

    for (size_t i = 0; i < numbers.size(); i++) {
        outputFile << numbers[i] << ",";
    }

    delete[] array;
    inputFile.close();
    outputFile.close();

    return 0;
}
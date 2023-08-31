#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <omp.h>

std::vector<int> quicksort(std::vector<int> arr, int left, int right) {
    if (left >= right)
        return std::vector<int>();

    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);  // Swap using std::swap
            i++;
            j--;
        }
    }

    std::vector<int> sorted;
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            std::vector<int> leftSorted = quicksort(arr, left, j);
            sorted.insert(sorted.end(), leftSorted.begin(), leftSorted.end());
        }

        #pragma omp section
        {
            std::vector<int> rightSorted = quicksort(arr, i, right);
            sorted.insert(sorted.end(), rightSorted.begin(), rightSorted.end());
        }
    }

    sorted.push_back(pivot);
    return sorted;
}

int main() {
    std::ifstream inputFile("input.csv");
    std::ofstream outputFile("sorted_output_paralela.csv");

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

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<int> sortedNumbers;
    #pragma omp parallel
    {
        #pragma omp single nowait
        sortedNumbers = quicksort(numbers, 0, numbers.size() - 1);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Time taken by parallel quicksort: " << duration.count() << " seconds" << std::endl;
    
    for (size_t i = 0; i < sortedNumbers.size(); i++) {
        outputFile << sortedNumbers[i] << ",";
    }
    
    inputFile.close();
    outputFile.close();

    return 0;
}
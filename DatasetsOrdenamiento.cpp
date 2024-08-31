#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void saveToFile(const std::string& filename, const std::vector<int>& data) {
    std::ofstream file(filename);
    for (int num : data) {
        file << num << " ";
    }
    file.close();
}

std::vector<int> generateRandom(int size) {
    std::vector<int> data(size);
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 10000 + 1; // Numbers between 1 and 10000
    }
    return data;
}

std::vector<int> generateSemiSorted(int size) {
    std::vector<int> data = generateRandom(size);
    std::sort(data.begin(), data.begin() + size / 2); // Sort first half
    return data;
}

std::vector<int> generateReverseSorted(int size) {
    std::vector<int> data = generateRandom(size);
    std::sort(data.begin(), data.end(), std::greater<int>());
    return data;
}

int main() {
    srand(time(0)); // Seed random number generator
    std::vector<int> sizes = {100, 200, 300, 400, 500, 1000, 5000, 10000};

    for (int size : sizes) {
        auto dataRandom = generateRandom(size);
        auto dataSemiSorted = generateSemiSorted(size);
        auto dataReverseSorted = generateReverseSorted(size);

        saveToFile("random_" + std::to_string(size) + ".txt", dataRandom);
        saveToFile("semi_sorted_" + std::to_string(size) + ".txt", dataSemiSorted);
        saveToFile("reverse_sorted_" + std::to_string(size) + ".txt", dataReverseSorted);
    }

    return 0;
}

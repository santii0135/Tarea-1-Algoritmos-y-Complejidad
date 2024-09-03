#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void saveToFile(const string& folder, const string& filename, const vector<int>& data) {
    ofstream file(folder + "/" + filename, ios::out | ios::binary);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo para escribir: " << filename << endl;
        return;
    }
    size_t size = data.size();
    file.write(reinterpret_cast<char*>(&size), sizeof(size));
    file.write(reinterpret_cast<char*>(const_cast<int*>(&data[0])), size * sizeof(int));
    file.close();
}

vector<int> generateRandom(int size) {
    vector<int> data(size);
    for (int i = 0; i < size; ++i) {
        data[i] = rand() % 10000 + 1; // Numbers between 1 and 10000
    }
    return data;
}

vector<int> generateSemiSorted(int size) {
    vector<int> data = generateRandom(size);
    sort(data.begin(), data.begin() + size / 2); // Sort first half
    return data;
}

vector<int> generateReverseSorted(int size) {
    vector<int> data = generateRandom(size);
    sort(data.begin(), data.end(), greater<int>());
    return data;
}

int main() {
    srand(time(0)); // Seed random number generator
    vector<int> sizes = {100, 200, 300, 400, 500, 1000, 5000, 10000, 100000, 50000, 100000};

    for (int size : sizes) {
        auto dataRandom = generateRandom(size);
        auto dataSemiSorted = generateSemiSorted(size);
        auto dataReverseSorted = generateReverseSorted(size);

        saveToFile("random", "random_" + to_string(size) + ".bin", dataRandom);
        saveToFile("semi_ordenado", "semi_sorted_" + to_string(size) + ".bin", dataSemiSorted);
        saveToFile("ordenado", "reverse_sorted_" + to_string(size) + ".bin", dataReverseSorted);
    }

    return 0;
}

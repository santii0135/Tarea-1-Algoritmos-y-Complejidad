#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

void saveToFile(const string& carpeta, const string& archivo, const vector<int>& data) {
    ofstream file(carpeta + "/" + archivo, ios::out | ios::binary);
    if (!file.is_open()) {
        cout << "No se pudo abrir el archivo para escribir: " << archivo << endl;
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
        data[i] = rand() % 10000 + 1; // Numeros Aleatorios entre 1 y 10000
    }
    return data;
}

vector<int> generateSemiSorted(int size) {
    vector<int> data = generateRandom(size);
    sort(data.begin(), data.begin() + size / 2); // Ordena primera mitad
    return data;
}

vector<int> generateReverseSorted(int size) {
    vector<int> data = generateRandom(size);
    sort(data.begin(), data.end());
    reverse(data.begin(), data.end());
    return data;
}

int main() {
    srand(time(0));
    vector<int> sizes = {100, 500, 1000, 5000, 10000, 20000, 30000, 40000, 50000, 60000, 70000, 80000, 90000, 100000};

    for (int size : sizes) {
        auto dataRandom = generateRandom(size);
        auto dataSemiSorted = generateSemiSorted(size);
        auto dataReverseSorted = generateReverseSorted(size);

        saveToFile("random", "random_" + to_string(size) + ".bin", dataRandom);
        saveToFile("semi_sorted", "semi_sorted_" + to_string(size) + ".bin", dataSemiSorted);
        saveToFile("reverse_sorted", "reverse_sorted_" + to_string(size) + ".bin", dataReverseSorted);
    }

    return 0;
}

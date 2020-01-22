#include <fstream>
#include <iostream>
#include "FileCacheManager.h"

string FileCacheManager::getSolution(string problem) {
    string solution;
    string filename = to_string(hashFunc(problem)) + ".txt";
    fstream stream{filename, ios::in};
    if (!stream) {
        cout << "ERROR open file" << endl;
        return "";
    }
    getline(stream, solution);
    stream.close();
        return solution;
}

bool FileCacheManager::isInCache(string prob) {
    string filename = to_string(hashFunc(prob)) + ".txt";
    fstream file{filename, ios::in};
    if (file.is_open()) {
        file.close();
        return true;
    }
    return false;
}

void FileCacheManager::setSolution(string prob, string solution) {
    string filename = to_string(hashFunc(prob)) + ".txt";
    fstream file{filename, ios::out};
    if (!file) {
        cout<< "Error opening file" <<endl;
        exit(1);
    }
    file << solution;
    file << '\n';
    file.close();
}


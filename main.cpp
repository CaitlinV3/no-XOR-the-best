#include <iostream>
#include <fstream>
#include <string>
#include "encryption.h"

using namespace std;

string readFile(const string &filePath) {
    ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        throw runtime_error("Could not open file " + filePath);
    }
    string content((istreambuf_iterator<char>(inputFile)), (istreambuf_iterator<char>()));
    inputFile.close();
    return content;
}

void writeFile(const string &filePath, const string &content) {
    ofstream outputFile(filePath);
    if (!outputFile.is_open()) {
        throw runtime_error("Could not open file " + filePath);
    }
    outputFile << content;
    outputFile.close();
}

int main(int argc, char* argv[]) {
    if (argc != 5) {
        cerr << "Usage: " << argv[0] << " <encrypt/decrypt> <input file> <output file> <key>" << endl;
        return 1;
    }
    string operation = argv[1];
    string inputFilePath = argv[2];
    string outputFilePath = argv[3];
    int key = stoi(argv[4]);

    try {

        string content = readFile(inputFilePath);
        string result;

        if (operation == "encrypt") {
            result = encrypt(content, key);
        } else if (operation == "decrypt") {
            result = decrypt(content, key);
        } else {
            cerr << "Invalid operation: " << operation << endl;
            return 1;
        }

        writeFile(outputFilePath, result);
        cout << "Operation completed successfully" << endl;
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}
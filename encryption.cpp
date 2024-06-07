#include "encryption.h"

using namespace std;

string encrypt(const string &text, int key){
    string encryptedText = text;
    for (char &c : encryptedText){
        c ^= key; // XOR operation
    }
    return encryptedText;
}

string decrypt(const string &text, int key){
    return encrypt(text, key); // XOR operation is its own inverse
}
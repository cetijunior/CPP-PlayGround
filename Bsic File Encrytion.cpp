#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void encryptFile(const string& inputFilePath, const string& outputFilePath, int key) {
    ifstream inputFile(inputFilePath, ios::binary);
    ofstream outputFile(outputFilePath, ios::binary);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        ch = (ch + key) % 256; // Ensure the character remains within valid range
        outputFile.put(ch);
    }

    inputFile.close();
    outputFile.close();
}

void decryptFile(const string& inputFilePath, const string& outputFilePath, int key) {
    ifstream inputFile(inputFilePath, ios::binary);
    ofstream outputFile(outputFilePath, ios::binary);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        cerr << "Error opening files!" << endl;
        return;
    }

    char ch;
    while (inputFile.get(ch)) {
        ch = (ch - key + 256) % 256; // Ensure the character remains within valid range
        outputFile.put(ch);
    }
    inputFile.close();
    outputFile.close();
}

int main() {
    int choice;
    int key;
    string inputFilePath, outputFilePath;

    cout << "File Encryption/Decryption Program" << endl;
    cout << "1. Encrypt a file" << endl;
    cout << "2. Decrypt a file" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    cout << "Enter the encryption/Decryption key (int): ";
    cin >> key;

    cout << "Enter the input file path: ";
    cin.ignore();
    getline(cin, inputFilePath);
    
    cout << "Enter the output file path: ";
    getline(cin, outputFilePath);

    if (choice == 1) {
        encryptFile(inputFilePath, outputFilePath, key);
        cout << "File encrypted successfully." << endl;
    } else if (choice == 2) {
        decryptFile(inputFilePath, outputFilePath, key);
        cout << "File decrypted successfully." << endl;
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}

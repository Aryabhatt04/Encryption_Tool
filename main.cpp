#include <iostream>
#include <fstream>
using namespace std;

// Function to encrypt or decrypt file
void processFile(const string &inputFile, const string &outputFile, const string &key)
{
    ifstream in(inputFile, ios::binary);
    ofstream out(outputFile, ios::binary);

    if (!in.is_open() || !out.is_open())
    {
        cerr << "Error: Could not open input/output files.\n";
        return;
    }

    char buffer;
    size_t keyLength = key.length();
    size_t i = 0;

    while (in.get(buffer))
    {
        char encryptedChar = buffer ^ key[i % keyLength]; // XOR with key
        out.put(encryptedChar);
        i++;
    }

    in.close();
    out.close();

    cout << "✅ Processing completed.\n";
}

int main()
{
    string inputFile, outputFile, key;
    int choice;

    cout << "====== File Encryptor/Decryptor ======\n";
    cout << "1. Encrypt File\n";
    cout << "2. Decrypt File\n";
    cout << "Choose option (1/2): ";
    cin >> choice;
    cin.ignore();

    cout << "Enter input file path: ";
    getline(cin, inputFile);
    cout << "Enter output file path: ";
    getline(cin, outputFile);
    cout << "Enter secret key: ";
    getline(cin, key);

    processFile(inputFile, outputFile, key);
    return 0;
}

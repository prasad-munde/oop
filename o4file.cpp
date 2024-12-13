#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() 
{
    // Create and write to the output file
    ofstream outputFile("example.txt");
    if (outputFile.is_open()) 
    {
        outputFile << "Hello, World!\n";
        outputFile << "This is a C++ file handling example.\n";
        outputFile.close();
    } 
    else 
    {
        cerr << "Unable to open file for writing.\n";
        return 1;
    }

    // Open the input file and read from it
    ifstream inputFile("example.txt");
    string line;
    if (inputFile.is_open()) 
    {
        while (getline(inputFile, line)) 
        {
            cout << line << std::endl;
        }
        inputFile.close();
    } 
    else 
    {
        cerr << "Unable to open file for reading.\n";
        return 1;
    }

    return 0;
}

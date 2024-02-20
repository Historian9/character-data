#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const string fileName = "/Users/dmitriyboroda/Desktop/dev/laboratory work/character data/character data/file.txt";

int main() {
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cout << "Файла <" << fileName << "> не существует" << endl;
        return 1;
    }

    string line1, line2;
    getline(inputFile, line1);
    getline(inputFile, line2);
    
    inputFile.close();

    string fullLine = line1 + line2;

    
    
    return 0;
}


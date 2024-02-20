#include <iostream>
#include <fstream> // для работы с файлом
#include <string> // для работы со строками
#include <sstream> // для создания потока ввода из строки
#include <vector> // для создания вектора
using namespace std;

const string fileName = "/Users/dmitriyboroda/Desktop/dev/laboratory work/character data/character data/file.txt"; // путь к файлу

int main() {
    ifstream inputFile(fileName); // для чтения данных из файла

    if (!inputFile.is_open()) { // проверка на наличие файла
        cout << "Файла <" << fileName << "> не существует" << endl;
        return 1;
    }

    string line1, line2;
    
    // чтение строк из файла
    getline(inputFile, line1);
    getline(inputFile, line2);
    
    inputFile.close(); // закрытие файла

    string fullLine = line1 + " " + line2; // создание общей строки
    
    istringstream iss(fullLine); // создание потока ввода из строки
    
    vector<string> words; 
    
    // создание вектора из слов строки
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    
//    for (int i = 0; i < words.size(); i++) {
//        cout << words[i] << " ";
//    }

    
    
    return 0;
}


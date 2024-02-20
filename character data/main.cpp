#include <iostream>
#include <fstream> // для работы с файлом
#include <string> // для работы со строками
#include <sstream> // для создания потока ввода из строки
#include <vector> // для создания вектора
#include <unordered_map> // для использования хеш-таблицы
using namespace std;

const string fileName = "/Users/dmitriyboroda/Desktop/dev/laboratory work/character data/character data/file.txt"; // путь к файлу


// функция для подсчета повторений символов в слове
bool hasDuplicateLetters(const string& word){
    unordered_map<char, int> letterCount; // создания хеш-таблицы (словаря), где будут храниться буквы слова, и сколько раз они встречаются в нем
    
    for (int i = 0; i < word.size(); i++){
        letterCount[word[i]]++;
        if (letterCount[word[i]] > 1){
            return false; // найдено повторение
        }
    }
    return true; // нет повторений
}


int main() {
    string lol = "LOOOOOOOL";
    ifstream inputFile(fileName); // для чтения данных из файла

    if (!inputFile.is_open()){ // проверка на наличие файла
        cout << "Файла <" << fileName << "> не существует" << endl;
        return 1;
    }
    
    string line1, line2;
    
    // чтение строк из файла
    getline(inputFile, line1);
    
    if (line1 == ""){ // проверка на наличие элементов в файле
        cout << "Файл пустой";
        return 2;
    }
    
    getline(inputFile, line2);
    
    inputFile.close(); // закрытие файла

    string fullLine = line1 + " " + line2; // создание общей строки
    
    istringstream iss(fullLine); // создание потока ввода из строки
    
    vector<string> words; 
    
    // создание вектора из слов строки
    string word;
    while (iss >> word){
        words.push_back(word);
    }
    
    // проходимся по вектору и проверяем слова на неповторяемость элементов
    cout << "Слова, у которых все буквы различны: ";
    for (int i = 0; i < words.size(); i++){
        if (hasDuplicateLetters(words[i])){
            cout << words[i] << " ";
        }
    }
    cout << endl;

    return 0;
}


#include <iostream>
#include <fstream> // для работы с файлом
#include <string> // для работы со строками
#include <sstream> // для создания потока ввода из строки
#include <vector> // для создания вектора
#include <unordered_map> // для использования хеш-таблицы
using namespace std;
//мой путь /Users/Rava/Documents/character-data/character data/file.txt
//твой путь /Users/dmitriyboroda/Desktop/dev/laboratory work/character data/character data/file.txt
const string fileName = "/Users/dmitriyboroda/Desktop/dev/laboratory work/character data/character data/file.txt"; // путь к файлу


// функция для подсчета повторений символов в слове
bool hasDuplicateLetters(const string& word){
    unordered_map<char, int> letterCount; // создания хеш-таблицы (словаря), где будут храниться буквы слова, и сколько раз они встречаются
    
    for (int i = 0; i < word.size(); i++){
        letterCount[word[i]]++;
        if (letterCount[word[i]] > 1){
            return false; // найдено повторение
        }
    }
    return true; // нет повторений
}


int main() {
    ifstream inputFile(fileName); // для чтения данных из файла

    if (!inputFile.is_open()){ // проверка на наличие файла
        cout << "Файла <" << fileName << "> не существует" << endl;
        return 1;
    }
    
    string line1, line2;
    
    getline(inputFile, line1); // чтение первой строки из файла
    
    if (line1 == ""){ // проверка на наличие элементов в файле
        cout << "Файл пустой";
        return 2;
    }
    
    getline(inputFile, line2); // чтение второй строки из файла
    
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

    cout << "Чередование символов исходной строки через два: ";
    
    // поочередно выводим по два символа из каждой строки
    for (int i = 0; i < min(line1.size(), line2.size()) - 1; i += 2){
        cout << line1[i] << line1[i + 1] << line2[i] << line2[i + 1];
    }
    
    // если символов в строках было разное количество -> выводим оставшиеся символы
    if ((min(line1.size(), line2.size()) == line1.size()) and (line1.size() != line2.size())){
        cout << line2.substr(line1.size() - 1);
    } else if ((min(line1.size(), line2.size()) == line2.size()) and (line1.size() != line2.size())){
        cout << line1.substr(line2.size() - 1);
    }
    
    cout << endl;
    return 0;
}


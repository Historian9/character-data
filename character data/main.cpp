#include <iostream>
#include <fstream> // для работы с файлом
using namespace std;

// путь 1 - /Users/Rava/Documents/character-data/character data/file.txt
// путь 2 - /Users/dmitriyboroda/Desktop/dev/laboratory work/character data/character data/file.txt
const char* fileName = "/Users/dmitriyboroda/Desktop/dev/laboratory work/character data/character data/file.txt"; // путь к файлу


// Функция для проверки, содержатся ли только латинские буквы в строке
bool containsOnlyLatinLetters(const char* str) {
    for (int i = 0; str[i] != '\0'; ++i) {
        // Проверяем, что символ принадлежит латинскому алфавиту (буквы в верхнем и нижнем регистре)
        if ((str[i] != ' ' and (str[i] < 'A' or (str[i] > 'Z' and str[i] < 'a') or str[i] > 'z'))) {
            return false; // если символ не является латинской буквой или пробелом, возвращаем false
        }
    }
    return true; // все символы латинские
}


// Функция для подсчета повторений символов в слове
bool hasDuplicateLetters(const char* word, int length) {
    int letterCount[256] = {0}; // массив для подсчета повторений символов (ASCII)

    for (int i = 0; i < length; i++) {
        letterCount[(unsigned int)word[i]]++; // делаем из символа ASCII номер и прибавляем 1 к элементу массива с этим индексом
        if (letterCount[(unsigned int)word[i]] > 1) { // если этот элемент > 1, то этот символ уже встречался в слове
            return false; // найдено повторение
        }
    }
    return true; // нет повторений
}

int main() {
    bool outPut = false; // для проверки существования слов с неповторяющимися буками в файле
    ifstream inputFile(fileName); // для чтения данных из файла

    if (!inputFile.is_open()) { // проверка на наличие файла
        cout << "Файла <" << fileName << "> не существует" << endl;
        return 1;
    }

    char line1[256], line2[256];

    inputFile.getline(line1, sizeof(line1)); // чтение первой строки из файла

    if (line1[0] == '\0') { // проверка на наличие элементов в файле (1 строка)
        cout << "1 строка пустая" << endl;;
        return 2;
    }

    inputFile.getline(line2, sizeof(line2)); // чтение второй строки из файла

    if (line2[0] == '\0') { // проверка на наличие элементов в файле (2 строка)
        cout << "2 строка пустая" << endl;
        return 3;
    }
    
    if (!containsOnlyLatinLetters(line1)) { // проверка на наличие только латинских букв в 1 строке
            cout << "В файле содержатся нелатинские символы в первой строке" << endl;
            return 4;
        }

    if (!containsOnlyLatinLetters(line2)) { // проверка на наличие только латинских букв во 2 строке
        cout << "В файле содержатся нелатинские символы во второй строке" << endl;
        return 5;
    }
    
    inputFile.close(); // закрытие файла

    char fullLine[512]; // создание общей строки
    strcpy(fullLine, line1); // Копирование содержимого line1 в fullLine
    strcat(fullLine, " "); // Добавление пробела к fullLine
    strcat(fullLine, line2); // Добавление содержимого line2 к fullLine
    
    cout << "Слова, у которых все буквы различны: ";
    int i = 0;
    int wordStart = 0; // для обозначения первого индекса слова в строке
    int flag = 0; // флаг для переноса wordStart

    do {
        if (flag == 1 and fullLine[i] != ' ' and fullLine[i] != '\n' and fullLine[i] != '\t' and fullLine[i] != '\0') {
            wordStart = i; // индикатор начала слова
            flag = 0; // обнуляем флаг
        }

        if (fullLine[i] == ' ' or fullLine[i] == '\n' or fullLine[i] == '\t' or fullLine[i] == '\0') { // если дошли до конца слова в строке
            if (hasDuplicateLetters(fullLine + wordStart, i - wordStart)) { // проверяем слово на повторение букв
                for (int j = wordStart; j < i; j++) {
                    cout << fullLine[j]; // выводим слово из строки
                }
                cout << " ";
                outPut = true; // есть слова с неповт. буквами
            }
            flag = 1; // чтобы перенести wordStart на начало следующего слова
        }
        i++;
        
    } while (fullLine[i - 1] != '\0'); // используем do-while, чтобы мы сначала дошли до конца строки, проверили слово на повторение букв и вывели его; i - 1 используется, чтобы не выйти за пределы цикла
    
    if (outPut == false) { // если нет слов с неповт. буквами
        cout << "В файле нет слов с неповторяющимися буквами" << endl;
    }
    cout << endl;
    
    cout << "Чередование символов исходной строки через два: ";
    
    i = 0;
    int j = 0;

    // Продолжаем, пока хотя бы одна из строк не закончится
    while (line1[i] != '\0' || line2[j] != '\0') {
        // Выводим первые 2 символа из первой строки
        for (int k = 0; k < 2; k++) {
            if (line1[i] != '\0') {
                cout << line1[i];
                i++;
            }
        }
        // Выводим первые 2 символа из второй строки
        for (int k = 0; k < 2; k++) {
            if (line2[j] != '\0') {
                cout << line2[j];
                j++;
            }
        }
    }

    cout << endl;

    return 0;
}

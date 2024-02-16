#include <iostream>
#include <fstream>
using namespace std;

const string file_name = "/Users/dmitriyboroda/Desktop/dev/laboratory work/character data/character data/file.txt";

int main(){
    
    // Проверка на наличие файла
    ifstream in(file_name);
    if (!in)
    {
        cout << "Ошибка: файл " << file_name << " не существует" << endl;
        return 0;
    } // if
    
}

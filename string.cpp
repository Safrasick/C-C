#include <iostream>
#include <string>
#include <algorithm>
 
using namespace std;
 
string* extractCommentSubstrings(const string* strings, int size, int& substringCount) { // Функция для извлечения подстрок, заключенных в скобки комментария /* и */
    string* commentSubstrings = new string[size]; // Динамический массив для хранения подстрок
    substringCount = 0; // Счетчик найденных подстрок
 
    for (int i = 0; i < size; ++i) {
        size_t pos = 0;
        while ((pos = strings[i].find("/*", pos)) != string::npos) {
            size_t endPos = strings[i].find("*/", pos);
            if (endPos != string::npos) {
                commentSubstrings[substringCount++] = strings[i].substr(pos + 2, endPos - pos - 2);
                pos = endPos + 2;
            }
            else {
                break; // Не найдено закрывающей скобки, выходим из цикла
            }
        }
    }
 
    return commentSubstrings;
}
 
string findMinDigitsSubstring(const string* substrings, int size) { // Функция для поиска подстроки с минимальным числом цифр 0, 2, 4, 6, 8
    string minDigitsSubstring;
    int minDigitsCount = numeric_limits<int>::max();
 
    for (int i = 0; i < size; ++i) {
        const string& substring = substrings[i];
 
        int digitsCount = count_if(substring.begin(), substring.end(), [](char c) {
            return isdigit(c) && (c == '0' || c == '2' || c == '4' || c == '6' || c == '8');
            });
 
        if (digitsCount < minDigitsCount) {
            minDigitsCount = digitsCount;
            minDigitsSubstring = substring;
        }
    }
 
    return minDigitsSubstring;
}
 
string removeDuplicateSpaces(const string& str) { // Функция для удаления повторяющихся пробелов в строке
    string result;
    bool prevSpace = false;
    for (char c : str) {
        if (!isspace(c)) {
            result += c;
            prevSpace = false;
        }
        else {
            if (!prevSpace) {
                result += c;
            }
            prevSpace = true;
        }
    }
    return result;
}
 
string findStringWithSubstring(const string* strings, int size, const string& substring) { // Функция для поиска строки, содержащей указанную подстроку
    for (int i = 0; i < size; ++i) {
        if (strings[i].find(substring) != string::npos) {
            return strings[i];
        }
    }
    return ""; // Возвращаем пустую строку, если подстрока не найдена
}
 
int main() {
    int numberOfStrings;
    cout << "Enter number of strings: ";
    cin >> numberOfStrings;
    cin.ignore(); // Чтобы очистить буфер после ввода числа
 
    string* strings = new string[numberOfStrings];
    cout << "Enter strings:" << endl;
    for (int i = 0; i < numberOfStrings; ++i) {
        getline(cin, strings[i]);
    }
 
    // Выделение и печать подстрок, заключенных в скобки комментария /* и */
    cout << "Substrings:" << endl;
    int substringCount;
    string* substrings = extractCommentSubstrings(strings, numberOfStrings, substringCount);
    for (int i = 0; i < substringCount; ++i) {
        cout << substrings[i] << endl;
    }
    cout << endl;
 
    // Поиск подстроки с минимальным числом цифр 0, 2, 4, 6, 8
    string minDigitsSubstring = findMinDigitsSubstring(substrings, substringCount);
    if (!minDigitsSubstring.empty()) {
        cout << "Substring with minimum numbers 0 2 4 6 8: " << minDigitsSubstring << endl;
 
        // Преобразование строки, удаляя повторяющиеся пробелы
        string originalString = findStringWithSubstring(strings, numberOfStrings, minDigitsSubstring);
        string changedString = removeDuplicateSpaces(originalString);
        cout << "Changed string: " << changedString << endl;
    }
    else {
        cout << "No substrings with 0 2 4 6 8." << endl;
    }
 
    // Освобождаем выделенную память
    delete[] strings;
    delete[] substrings;
 
    return 0;
}

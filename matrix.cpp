#include <iostream>
using namespace std;
 
const int maxSize = 100;
 
void inputArray(int* arr, int size) { // Функция для ввода данных в массив
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}
 
bool isInArray(int* arr, int size, int value)
{
    for (int j = 0; j < size; j++) {
        if (value == arr[j]) {
            return true;
        }
    }
 
    return false;
}
 
int CountInArray(int* arr, int size, int value)
{
    int count = 0;
    for (int j = 0; j < size; j++) {
        if (value == arr[j]) {
            count++;
        }
    }
 
    return count;
}
 
void calculateC(int* A, int sizeA, int* B, int sizeB, int* C, int& sizeC) { // Функция для вычисления массива C
    sizeC = 0;
    for (int i = 0; i < sizeB; i++) {
        // Проверяем, есть ли элемент B[i] в массиве A
        bool found = isInArray(A, sizeA, B[i]);
 
        // Если элемента B[i] нет в массиве A и еще не добавлен в массив C, добавляем его
        if (!found) {
            if (CountInArray(B, sizeB, B[i]) == 1)
            {
                bool alreadyAdded = isInArray(C, sizeC, B[i]);
                if (!alreadyAdded) {
                    C[sizeC] = B[i];
                    ++sizeC;
                }
            }
        }
    }
}
 
void calculateC2(int* A, int sizeA, int* B, int sizeB, int* C, int& sizeC) { // Функция для вычисления массива C
    sizeC = 0;
    for (int i = 0; i < sizeB; i++) {
        // Проверяем, есть ли элемент B[i] в массиве A
        bool found = false;
 
        for (int j = 0; j < sizeA; j++) {
            if (B[i] == A[j]) {
                found = true;
                break;
            }
        }
        // Если элемента B[i] нет в массиве A и еще не добавлен в массив C, добавляем его
        if (!found) {
            bool alreadyAdded = false;
            for (int k = 0; k < sizeC; k++) {
                if (B[i] == C[k]) {
                    alreadyAdded = true;
                    break;
                }
            }
            if (!alreadyAdded) {
                C[sizeC] = B[i];
                ++sizeC;
            }
        }
    }
}
 
void outputArray(int* arr, int size) { // Функция для вывода результата
    cout << "The answer is: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
 
int main() {
    int A[maxSize], B[maxSize], C[maxSize];
    int sizeA, sizeB, sizeC;
 
    cout << "Enter size A: ";
    cin >> sizeA;
    cout << "Enter elements in array A:\n";
    inputArray(A, sizeA);
 
    cout << "Enter size B: ";
    cin >> sizeB;
    cout << "Enter elements in array B:\n";
    inputArray(B, sizeB);
 
    calculateC(A, sizeA, B, sizeB, C, sizeC);
 
    if (sizeC == 0) {
        cout << "No elements in C.\n";
    }
    else {
        outputArray(C, sizeC);
    }
 
    return 0;
}

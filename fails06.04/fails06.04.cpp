#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
string SOGL = "бвгджзйклмнпрстфхцчшщъьБВГДЖЗЙКЛМНПРСТФХЦЧШЩЪЬ";
string GLAS = "аеэиоуюяыАЕЭИОУЮБЫ";
string NUMB = "1234567890";
//Задание 1. Дано два текстовых файла. Выяснить, совпадают ли их строки. Если нет, то вывести несовпадающую
//строку из каждого файла.

void insert(FILE* a, char str[], int size)
{
    cout << "Введите строку,которую хотите записать в файл" << endl;
    gets_s(str, size);
    bool result = fputs(str, a);
    if (!result)cout << "Успешно!" << endl;
    else cout << "Файл недоступен!" << endl;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    char bufer1[256];
    char bufer2[256];
    char str1[50];
    char str2[50];
    FILE* a;
    fopen_s(&a, "D:\\dz\\FILES\\1.txt", "w+");
    FILE* b;
    fopen_s(&b, "D:\\dz\\FILES\\2.txt", "w+");
    insert(a, str1, 50);
    insert(b, str2, 50);
    fgets(bufer1, 10, a);
    fgets(bufer2, 10, b);
    bufer1[10] = 0;
    bufer2[10] = 0;
    cout << bufer1 << endl << bufer2 << endl;
    fclosea);
    fclose(b);
}

/*Дан текстовый файл.Необходимо создать
новый файл и записать в него следующую статистику по
исходному файлу :
■ Количество символов;
■ Количество строк;
■ Количество гласных букв;
■ Количество согласных букв;
■ Количество цифр*/

bool search(char ch, string arr) {
    for (size_t i = 0; i < arr.size(); i++) {
        if (ch == arr[i]) {
            return true;
        }
    }
}

int symFile() {
    int sym = 0;
    ifstream N("file.txt");
    if (!N)
    {
        exit(-1);
    }
    else
    {
        while (!N.eof())
        {
            char ch;
            N >> ch;
            sym++;
        }
    }

    return sym - 1;
}

int strFile() {
    int str = 0;
    ifstream N("file.txt");
    if (!N) {
        exit(-1);
    }
    else {
        string line;
        while (getline(N, line)) {
            str++;
        }
    }
    N.close();
    return str;
}

int glasFile() {
    int glas = 0;
    ifstream N("file.txt");
    if (!N)
    {
        exit(-1);
    }
    else
    {
        while (!N.eof())
        {
            char ch;
            N >> ch;
            if (search(ch, GLAS) == true) {
                glas++;
            }
        }
    }
    N.close();
    return glas;
}

int soglFile() {
    int sogl = 0;
    ifstream N("file.txt");
    if (!N)
    {
        exit(-1);
    }
    else
    {
        while (!N.eof())
        {
            char ch;
            N >> ch;
            if (search(ch, SOGL) == true) {
                sogl++;
            }
        }
    }
    N.close();
    return sogl;
}

int numbFile() {
    int numb = 0;
    ifstream N("file.txt");
    if (!N)
    {
        exit(-1);
    }
    else
    {
        while (!N.eof())
        {
            char ch;
            N >> ch;
            if (search(ch, NUMB) == true) {
                numb++;
            }
        }
    }
    N.close();
    return numb;
}

int main()
{
    setlocale(LC_ALL, "Russian");

    int SYM = symFile();
    int STR = strFile();
    int Glas = glasFile();
    int Sogl = soglFile();
    int Numb = numbFile();

    cout << "Символов в Файле: " << SYM << endl;
    cout << "Строк в Файле: " << STR << endl;
    cout << "Гласных в Файле: " << Glas << endl;
    cout << "Согласных в Файле: " << Sogl << endl;
    cout << "Чисел в Файле: " << Numb << endl;

    ofstream out("out.txt");
    out << "Символов в Файле: " << SYM << endl;
    out << "Строк в Файле: " << STR << endl;
    out << "Гласных в Файле: " << Glas << endl;
    out << "Согласных в Файле: " << Sogl << endl;
    out << "Чисел в Файле: " << Numb << endl;
    out.close();

    cout << endl;
    system("pause");
    return 0;
}
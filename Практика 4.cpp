#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Record {
    string name;
    string type;
    float price;
    int min_quantity;
    Date date;
};



int main () {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    Record Table[10] = {{"Папка",       "K", 4.75,  4,  {03, 07, 2022}},
                        {"Бумага",      "K", 13.90, 10, {03, 04, 2021}},
                        {"Калькулятор", "O", 1244,  3,  {04, 03, 2022}}
    };


    //создание файла txt
    string path_txt ="Taranov.txt";
    ofstream fout_txt;
    fout_txt.open(path_txt);


    //запись в файл txt
    for (int i=0;i<3;i++){
        fout_txt << Table[i].name << ' ' << Table[i].type << ' ' << Table[i].price << ' ' << Table[i].min_quantity << ' ' << Table[i].date.day << ' ' << Table[i].date.month << ' ' << Table[i].date.year << ' ' << endl;
    }
    fout_txt.close();

    //Считывание содержимого файла txt
    ifstream fin_txt;
    fin_txt.open(path_txt);
    if (!fin_txt.is_open())
    {
        cout<<"Ошибка открытия файла!";
    }
    else
    {
        //вывод содержимого файла txt
        Record read_file_txt[3];
        string s1;
        for (int i=0;i<3;i++){
            s1="";
            fin_txt >> s1;read_file_txt[i].name=s1;
            fin_txt >> s1;read_file_txt[i].type=s1;
            fin_txt >> s1;read_file_txt[i].price=stof(s1);
            fin_txt >> s1;read_file_txt[i].min_quantity=stoi(s1);
            fin_txt >> s1;read_file_txt[i].date.day=stoi(s1);
            fin_txt >> s1;read_file_txt[i].date.month=stoi(s1);
            fin_txt >> s1;read_file_txt[i].date.year=stoi(s1);
            cout << read_file_txt[i].name << ' ' << read_file_txt[i].type << ' ' << read_file_txt[i].price << ' ' << read_file_txt[i].min_quantity << ' ' << read_file_txt[i].date.day << ' ' << read_file_txt[i].date.month << ' ' << read_file_txt[i].date.year << endl;
        }
    }
    fin_txt.close();





    //создание файла bin
    string path_bin ="Taranov.bin";
    ofstream fout_bin(path_bin,ios_base::binary);

    //запись в файл bin
    for (int i=0;i<3;i++){
        fout_bin << Table[i].name << ' ' << Table[i].type << ' ' << Table[i].price << ' ' << Table[i].min_quantity << ' ' << Table[i].date.day << ' ' << Table[i].date.month << ' ' << Table[i].date.year << ' ' << endl;
    }
    fout_bin.close();

    //Считывание содержимого файла txt
    ifstream fin_bin(path_bin,ios_base::binary);
    if (!fin_bin.is_open())
    {
        cout<<"Ошибка открытия файла!";
    }
    else
    {
        //вывод содержимого файла bin
        Record read_file_bin[3];
        string s1;
        for (int i=0;i<3;i++){
            s1="";
            fin_bin >> s1;read_file_bin[i].name=s1;
            fin_bin >> s1;read_file_bin[i].type=s1;
            fin_bin >> s1;read_file_bin[i].price=stof(s1);
            fin_bin >> s1;read_file_bin[i].min_quantity=stoi(s1);
            fin_bin >> s1;read_file_bin[i].date.day=stoi(s1);
            fin_bin >> s1;read_file_bin[i].date.month=stoi(s1);
            fin_bin >> s1;read_file_bin[i].date.year=stoi(s1);
            cout << read_file_bin[i].name << ' ' << read_file_bin[i].type << ' ' << read_file_bin[i].price << ' ' << read_file_bin[i].min_quantity << ' ' << read_file_bin[i].date.day << ' ' << read_file_bin[i].date.month << ' ' << read_file_bin[i].date.year << endl;
        }
    }

    fout_txt.open(path_txt,ios_base::app);
    Record tmp={ "Рубашка_Алексея_Михайловича", "А", 666, 1, {21,07,2022}};
    fout_txt<<tmp.name<< ' ' <<tmp.type<< ' ' <<tmp.price<< ' ' <<tmp.min_quantity<< ' ' <<tmp.date.day<< ' ' <<tmp.date.year<< ' ' <<tmp.date.year;
    fout_txt.close();

    fin_txt.open(path_txt);
    int mn=31; int mn_index=10;
    int mx=0; int mx_index=0;
    Record helper[4];
    string str;
    for (int i=0;i<4;i++){
        str="";
        fin_txt >> str;helper[i].name=str;
        fin_txt >> str;helper[i].type=str;
        fin_txt >> str;helper[i].price=stof(str);
        fin_txt >> str;helper[i].min_quantity=stoi(str);
        fin_txt >> str;helper[i].date.day=stoi(str);
        fin_txt >> str;helper[i].date.month=stoi(str);
        fin_txt >> str;helper[i].date.year=stoi(str);
    }
    for(int i =0;i<4;i++)
        if (helper[i].date.day<mn) {
            mn = min(mn, helper[i].date.day);
            mn_index=i;
        }
    for(int i =0;i<4;i++)
        if (helper[i].date.day>mx) {
            mx = max(mx, helper[i].date.day);
            mx_index=i;
        }
    swap(helper[mn_index],helper[mx_index]);
    fin_txt.close();

    fout_txt.open(path_txt);
    for (int i=0;i<4;i++){
        fout_txt << helper[i].name << ' ' << helper[i].type << ' ' << helper[i].price << ' ' << helper[i].min_quantity << ' ' << helper[i].date.day << ' ' << helper[i].date.month << ' ' << helper[i].date.year << ' ' << endl;
    }
    fout_txt.close();
    return 0;
}

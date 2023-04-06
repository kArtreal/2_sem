#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Goods {
    string name;
    char type;
    float price;
    int min_quantity;
    Date date;
};

void line(){
    cout<<"|"<<string(115, '-')<<"|"<<endl;
}

int main () {
    SetConsoleOutputCP(CP_UTF8);
    Goods first, second, third;
    first = {"Папка", 'K', 4.75, 4, {03,07,2022}};
    second = {"Бумага", 'K', 13.90, 10,{03,04,2021}};
    third = {"Калькулятор", 'O', 411.00, 1,{04,03,2022}};

    string f,s,t; //удобная запись даты
    f = to_string(first.date.day)+"."+to_string(first.date.month)+"."+ to_string(first.date.year);
    s = to_string(second.date.day)+"."+to_string(second.date.month)+"."+ to_string(second.date.year);
    t = to_string(third.date.day)+"."+to_string(third.date.month)+"."+ to_string(third.date.year);

    //сортировка по значению дня
    if (first.date.day<=second.date.day)
        swap(f,s);
    if (first.date.day<=third.date.day)
        swap(f,t);
    if (second.date.day<=third.date.day)
        swap(s,t);

    line();
    cout << "|" << "Прайс-лист" << setw(106) << "|" << endl;
    line();
    cout << "|" << "Наименование товара" << setw(5) << "|" << "Тип товара" << setw(5) << "|" << "Цена за 1 шт (руб)"<< setw(5) << "|" << "Минимальное количество в партии" << setw(6) << "|" <<"Дата"<<setw(13)<<"|"<< endl;
    line();
    cout << "|" << first.name <<setw(19)<< "|" << first.type <<setw(14)<< "|" << first.price <<setw(19)<< "|" << first.min_quantity <<setw(36)<<"|"<<f<<setw(9)<<"|"<< endl;
    line();
    cout << "|" << second.name <<setw(18)<< "|" << second.type <<setw(14)<< "|" << second.price <<setw(19)<< "|" << second.min_quantity <<setw(35)<<"|"<<s<<setw(9)<<"|"<< endl;
    line();
    cout << "|" << third.name <<setw(13)<< "|" << third.type <<setw(14)<< "|" << third.price <<setw(20)<< "|" << third.min_quantity <<setw(36)<<"|"<<t<<setw(9)<<"|"<< endl;
    line();
    cout<<"|"<<"Примечание: К-канцтовары, О-оргтехника"<<setw(78)<<"|"<<endl;
    line();
}
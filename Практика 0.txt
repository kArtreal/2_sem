#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string>

using namespace std;

struct goods {
    string name;
    char type;
    float price;
    int min_quantity;
    string date;
};

void line(){
    cout<<"|"<<string(115, '-')<<"|"<<endl;
}

int main () {
    SetConsoleOutputCP(CP_UTF8);
    goods first, second, third;
    first = {"Папка", 'K', 4.75, 4,"03.07.2022"};
    second = {"Бумага", 'K', 13.90, 10,"03.04.2021"};
    third = {"Калькулятор", 'O', 411.00, 1,"04.03.2022"};
    line();
    cout << "|" << "Прайс-лист" << setw(106) << "|" << endl;
    line();
    cout << "|" << "Наименование товара" << setw(5) << "|" << "Тип товара" << setw(5) << "|" << "Цена за 1 шт (руб)"
         << setw(5) << "|" << "Минимальное количество в партии" << setw(6) << "|" <<"Дата"<<setw(13)<<"|"<< endl;
    line();
    cout << "|" << first.name <<setw(19)<< "|" << first.type <<setw(14)<< "|" << first.price <<setw(19)<< "|" << first.min_quantity <<setw(36)<<"|"<<first.date<<setw(7)<<"|"<< endl;
    line();
    cout << "|" << second.name <<setw(18)<< "|" << second.type <<setw(14)<< "|" << second.price <<setw(19)<< "|" << second.min_quantity <<setw(35)<<"|"<<second.date<<setw(7)<<"|"<< endl;
    line();
    cout << "|" << third.name <<setw(13)<< "|" << third.type <<setw(14)<< "|" << third.price <<setw(20)<< "|" << third.min_quantity <<setw(36)<<"|"<<third.date<<setw(7)<<"|"<< endl;
    line();
    cout<<"|"<<"Примечание: К-канцтовары, О-оргтехника"<<setw(78)<<"|"<<endl;
    line();
}


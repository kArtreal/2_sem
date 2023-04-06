#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

struct Record {
    string name;
    char type;
    float price;
    int min_quantity;
    Date date;
};


int main () {
    Record Table[10] = {{"Папка",       'K', 4.75,  4,  {03, 07, 2022}},
                        {"Бумага",      'K', 13.90, 10, {03, 04, 2021}},
                        {"Калькулятор", 'O', 1244,  3,  {04, 03, 2022}}
    };

    Record *a = (Record *) calloc(3, sizeof(Record));
    for (int i = 0; i < 3; i++) a[i] = Table[i];
    a=(Record*) realloc(a,10*sizeof(Record));
    Record *b = new Record[10];
    for (int i=0;i<10;i++) b[i]=a[i];
    cout << "Адрес\tЗначение A[i]->name\tАдрес\tЗначение B[i]->name" << endl;
    for(int i=0;i<10;i++){
        cout<<&a[i]<<"\t"<<a[i].name<<"\t"<<&b[i]<<"/t"<<b[i].name<<endl;
        
    }

    free(a);
    free(b);
    return 0;
}

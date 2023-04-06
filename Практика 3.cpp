#include <iostream>
#include <windows.h>
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

struct node{
    Record data;
    node* next;
};
node* myHead;
int item_counter=0;

//добавление в начало списка
void add_item (Record data){
    node* new_item=new node();
    new_item->data=data;
    if (item_counter==0)
        new_item->next=NULL;
    else
        new_item->next=myHead;
    myHead=new_item;
    item_counter++;
}

//добавление в любое место списка
void insert_item(Record data,int index){
    if(index<0 or index>=item_counter or item_counter<0)
        return;
    if (index==0)
        add_item(data);
    else{
        node* current = myHead;
        for(int i = 0;i<index-1;i++)
            current=current->next;
        node* new_item = new node();
        new_item->data=data;
        new_item->next=current->next;
        current->next=new_item;
    }
}

void edit_item(Record data, int index){
    if (index<0 or index>=item_counter or item_counter<0){
        cout<<"Индекс вне диапозона";
        return;
    }
    else {
        node *current = myHead;
        for (int i=0;i<index;i++)
            current=current->next;
        current->data=data;
    }
}

void delete_item(int index){
    if (index<0 or index>=item_counter or item_counter<0){
        cout<<"Индекс вне диапозона";
        return;
    }
    else{
        node* current=myHead;
        node* old;
        if (index=0){
            old=myHead;
            myHead=current->next;
            delete old;
            item_counter--;
        }
        else{
            int i=0;
            while(current){
                if (i=index-1){
                    old=current->next->next;
                    delete current->next;
                    current->next=old;
                    item_counter--;
                    break;
                }
                i++;
                current=current->next;
            }
        }
    }
}

void printMyList() {
    struct node* current = myHead;
    while (current) {
        cout << " " << current->data.name<<" "<< current->data.type<<" "<< current->data.price<<" "<< current->data.min_quantity<<" "<< current->data.date.day<<" "<< current->data.date.month<<" "<< current->data.date.year;
        current = current->next;
        cout << endl;
    }
    cout<<endl;

}

int main () {
    SetConsoleOutputCP(CP_UTF8);
    Record Table[10] = {{"Папка",       'K', 4.75,  4,  {03, 07, 2022}},
                        {"Бумага",      'K', 13.90, 10, {03, 04, 2021}},
                        {"Калькулятор", 'O', 1244,  3,  {04, 03, 2022}}
    };
    for (int i=0;i<3;i++) add_item(Table[i]);
    printMyList();
    delete_item(1);
    printMyList();
    add_item({"Рубашка Алексея Михайловича",       'A', 4.75,  4,  {03, 07, 2022}});
    printMyList();
    insert_item({"Костюм Вячеслава Валерьевича",       'A', 4.75,  4,  {03, 07, 2022}},2);
    printMyList();
    edit_item({"Очки Андрея Александровича",       'A', 4.75,  4,  {03, 07, 2022}},1);
    printMyList();
    return 0;
}

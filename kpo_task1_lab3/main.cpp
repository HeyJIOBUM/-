#include "class determination.h"
using namespace std;
void show(animal anima){
    cout << "Name - " << anima.getName() << endl;
    cout << "Type - " << anima.getType() << endl;
    cout << "Weight - " << anima.getAv_we() << endl;
    cout << "-----------------------------------------------------------------------" << endl;
}
animal Supername(animal& anima){
    animal temp(anima);
    temp.setName("SuperName");
    return temp;
}
int main(){
    //конструктор с параметрами
    char str[100] = "name";
    char str1[100] = "type";
    animal a(str, str1, 10);
    a.show();

    //конструктор копирования, инициализация объекта другим объектом
    animal d = a;
    d.show();

    //конструктор копирования, функция show принимает объект в качестве параметра по значению
    d.setType("Cat");
    show(d);

    //конструктор копирования, создание временного объекта как возвращаемого значения
    //после завершения функции Supername временный объект удалится
    animal c = Supername(a);
    c.show();

    //статическое размещение массива объектов в памяти
    animal b[10];
    b[0].set("Mercy", "Hourse", 15);
    b[0].show();

    //динамическое размещение массива объектов в памяти
    animal* ptr = new animal[10];
    ptr->setName("Wasya");
    ptr->show();

    //указатель на метод класса
    void (animal::*ptr_fun)();
    ptr_fun = &animal::show;
    (a.*ptr_fun)();

    //работа с объектом через объект и через указатель на объект
    animal obj, *pointer;
    pointer = &obj;
    obj.setName("James");
    pointer->setType("Dog");
    obj.setAv_we(2);
    pointer->show();

    delete[] ptr;
    return 0;
}
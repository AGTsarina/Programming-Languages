#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
const int MAX = 100; // начальная емкость 
// разработка структуры, позволяющей обеспечить работу с массивом вещественных чисел
struct Vector{
    double * data; // хранилище данных // одноменрный массив (указатель на первый байт памяти, где хранится 
    // массив)
    int size; // текущий размер 
    int capacity; // емкость = максимальное количество элементов, которые можно записать в массив 
    Vector(){ // конструктор по умолчанию
        this->capacity = MAX;
        size = 0;
        data = new double[capacity];
    }
    // деструктор - специальный метод, вызывающийся при удалении объекта из памяти
    // имя деструктора = ~Имя_структуры, параметров нет
    ~Vector(){
        delete[]data;
    }

}; 

// добавление элемента к вектору (массиву)
void Add(Vector &v, double x);
void Print(Vector &v);

int main(){
    Vector v;
    Add(v, 10.5);
    Add(v, -10.5);
    Add(v, 7.8);
    Print(v);
    return 0;
}

void Add(Vector &v, double x){
    if (v.size < v.capacity){
        v.data[v.size++] = x;
    }
    else{
        v.capacity += MAX;
        double * temp = new double[v.capacity];
        for(int i=0; i<v.size; i++){
            temp[i] = v.data[i];
        }
        delete[] v.data;
        v.data = temp;
        v.data[v.size++] = x;
    }
}

void Print(Vector &v){
    for(int i=0; i<v.size; i++){
        cout << v.data[i] << " ";
    }
    cout << endl;
}
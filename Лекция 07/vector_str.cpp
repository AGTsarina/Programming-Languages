#include <iostream>
using namespace std;
const int MAX = 10;
struct Item
{
    int key; // ключевое значение
    int value; // сколько раз ключ встречается в массиве
};

struct Vector
{
    Item *data;
    int size;
    int capacity;
    Vector(){
        data = nullptr;
        size = 0;
        capacity = 0;
    }
};

void add(Vector &v, Item &x){
    if (v.capacity == v.size){
        v.capacity+= MAX;
        Item *temp = new Item[v.capacity];
        for(int i=0; i<v.size; i++){
            temp[i] = v.data[i];
        }
        delete[] v.data;
        v.data = temp;
    }
    v.data[v.size++] = x;
}

int main(){
    int temp[]{0,0,0,1,1,1,1,1,2,2,2,3,3,3,5,5,5,5,7,7,10,10};
    int numsSize = sizeof(temp) / sizeof(int);
    int x = temp[0];
    Vector degrees;    
    int count = 1;
    Item item;
    for (int i=1; i<numsSize; i++, count++) {
        if (temp[i] != x) {           
            item.key = x;
            item.value = count;
            add(degrees, item);
            count = 0;
            x = temp[i];
        }
    }
    item.key = x;
    item.value = count;    
    add(degrees, item);
    for (int i=0; i<degrees.size; i++) {        
        cout << degrees.data[i].key << " " << degrees.data[i].value << endl;
    }

}


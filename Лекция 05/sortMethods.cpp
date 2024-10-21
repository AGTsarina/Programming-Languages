// Сортировка последовательностей с произольным доступом

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef int Type; // вводим просой пользовательский тип
typedef void (*SortMethod)(Type *, int); // вводим функциональный тип

Type* Create(int n);
// у функций сортировки массива одинаковая сигнатура:
// одинаковые типу возращаемых значений,
// одинаковые типы параметров
// = это функции одного и того же функционального типа
void BubbleSort(Type* A, int n); 
void BubbleSortOpt(Type* A, int n);
void SelectSort(Type* A, int n);
void InsertSort(Type* A, int n);
void Print(Type* A, int n);
// функция, где параметр - указатель на метод сортировки
void PrintTime(const char * name, SortMethod sort);

int main(){    
    srand(time(NULL));
    cout << (void *)SelectSort << endl;
    int n = 10;
    Type* A = Create(n);
    Print(A, n);
    BubbleSortOpt(A, n);
    Print(A, n);
    n = 10000;
    PrintTime("BubbleSort", BubbleSort);
    PrintTime("BubbleSortOpt", BubbleSortOpt);
    PrintTime("SelectSort", SelectSort);
    PrintTime("InsertSort", InsertSort);
}

void PrintTime(const char * name, SortMethod sort){
    int n = 100000;
    Type* B = Create(n);
    clock_t t1 = clock();
    sort(B, n);
    cout << "Time " << name <<": " << clock() - t1 << endl;
}

Type* Create(int n){
    Type *res = new Type[n];
    for(int i=0; i<n; i++){
        res[i] = rand() % 1000;
    }
    return res;
}
void BubbleSort(Type* A, int n){
    for(int i=1; i < n; i++){
        for(int j = n - 1; j >= i; j--){
            if (A[j] < A[j - 1]){
                Type temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
            }
        }
    }
}
void BubbleSortOpt(Type* A, int n){
    for(int i=1; i < n; i++){
        bool flag = false; // предполагаем, нет перестановок
        for(int j = n - 1; j >= i; j--){
            if (A[j] < A[j - 1]){
                Type temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                flag = true;
            }
        }
        if (!flag){ // не было перестановок
           return;
        }
    }
}

void InsertSort(Type* A, int n){
    for(int i = 1; i <n; i++){
        Type x = A[i];
        int j = i - 1;
        for(; j > -1 && A[j] > x; j--){
            A[j + 1] = A[j];
        }
        A[j + 1] = x;
    }
}

void Print(Type* A, int n){
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << endl << endl;  // cout << "\n\n";
}

void SelectSort(Type* A, int n){
    for(int i=0; i<n-1; i++){
        Type min = A[i];
        int imin = i;
        for (int j=i+1; j<n; j++){
            if (A[j] < min){
                min = A[j];
                imin = j;
            }
        }
        A[imin] = A[i];
        A[i] = min;
    }
}

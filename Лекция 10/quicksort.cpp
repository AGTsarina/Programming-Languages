
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef int Type;
typedef void (*SortMethod)(Type *, int); // вводим функциональный тип
void BubbleSort(Type* A, int n);
void QuickSort(Type* A, int n);
void PrintTime(const char * name, SortMethod sort);
int Part(Type *A, int L, int R);
void Print(Type* A, int n);
Type* Create(int n);

int main(){
    //srand(time(NULL));
    //int A[10]{7,4,3,8,2,1,0,5,6,9};
    int * A = Create(100);
    //cout << Part(A, 0, 5) << endl;
    QuickSort(A, 100);
    Print(A, 100);

    PrintTime("BubbleSort", BubbleSort);
    PrintTime("QuickSort", QuickSort);
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

void Print(Type* A, int n){
    for(int i=0; i<n; i++){
        cout << A[i] << " ";
    }
    cout << endl << endl;  // cout << "\n\n";
}

void PrintTime(const char * name, SortMethod sort){
    int n = 10000;
    Type* B = Create(n);
    clock_t t1 = clock();
    sort(B, n);
    cout << "Time " << name <<": " << clock() - t1 << endl;
}

int Part(Type *A, int L, int R){
    Type x = A[(L + R) / 2]; // опорный элемент
    int i = L, j = R;
    while(i < j){
        for(;i <=R && A[i] < x; i++);
        for(; j >= L && A[j] > x; j--);
        Type temp = A[i];
        A[i] = A[j];
        A[j] = temp;                 
    }
    return i;
}

void QuickSort(Type *A, int L, int R){
    if (R - L < 2) return;
    int k = Part(A, L, R);
    QuickSort(A, L, k);
    QuickSort(A, k + 1, R);
}

void QuickSort(Type *A, int n){
    QuickSort(A, 0, n-1);
}
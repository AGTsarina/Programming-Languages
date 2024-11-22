
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

typedef int Type;
typedef void (*SortMethod)(Type *, int); // вводим функциональный тип
void BubbleSort(Type* A, int n);
void QuickSort(Type* A, int n);
void PrintTime(const char * name, SortMethod sort);
void Part(Type *A, int L, int R, int &i, int &j);
void Print(Type* A, int n);
Type* Create(int n);

ofstream fout("output.txt");
ofstream &cout = fout;
int main(){
    
    //srand(time(NULL));
    const int n = 10;
    //int A[n] = {7,4,3,8,2,1,0,5,6,9};
    int * A = Create(n);
    //cout << Part(A, 0, 5) << endl;
    Print(A, n);
    QuickSort(A, n);
    Print(A, n);

   // PrintTime("BubbleSort", BubbleSort);
   // PrintTime("QuickSort", QuickSort);
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

void Part(Type *A, int L, int R, int &i, int &j){
    Type x = A[(L + R) / 2]; // опорный элемент
    i = L; j = R;
    while(i <= j){
        for(;i <=R && A[i] < x; i++);
        for(; j >= L && A[j] > x; j--);
        if (i <= j){
            Type temp = A[i];
            A[i] = A[j];
            A[j] = temp;    
            i++; j--;        
        }                 
    }    
}

void QuickSort(Type *A, int L, int R){
    if (R - L < 1) return;
    int i, j;
    Part(A, L, R, i, j);
     QuickSort(A, L, j);
    QuickSort(A, i, R);
}

void QuickSort(Type *A, int n){
    QuickSort(A, 0, n-1);
}

#include <iostream>
#include <fstream>
using namespace std;

const int days_in_month[]{31, 28, 31,30,31,30,31,31,30,31,30,31};

void Init(int *A, int n); // инициализация целочисленного массива
int * CreateIntArray(int n);
void Init(float *A, int n); // инициализация вещественного массива

int main(){
    int A[5];
    float B[10];
    char C[]={'a', 'b', 'c'};

    int *PA = CreateIntArray(5);
    float *PB = new float[10];
    char *PC = new char[3]{'a', 'b', 'c'};

    Init(A, 5);
    

    Init(B, 10);
    Init(PB, 10);
    
    for(int i=0; i<3; i++){
        cout << C[i] << " " << PC[i] << " ";
    }
    cout << endl;
    delete[] PA;
    delete[] PB;
    delete[] PC;
}

void Init(int *A, int n){ // инициализация целочисленного массива
    for(int i=0; i<n; i++){
        A[i] = i + 1;        
    }
}
void Init(float *A, int n){ // инициализация вещественного массива
    float value = 0.1f;
    for(int i=0; i<10; i++, value+=0.1){
        A[i] = value;        
    }
}

int * CreateIntArray(int n){
    int *res = new int[n];  // !!! нельзя int res[n];
    Init(res, n);
    return res;
}
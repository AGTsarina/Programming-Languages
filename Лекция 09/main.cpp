#include <fstream>
#include <iostream>
#include "matrix.h"

using namespace std;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n; // размерность задачи
    double ** A = GetMatrix(fin, n);
    double ** A1 = Copy(A, n);    
    Print(A, n, cout);
    double *B = GetVector(fin, n);
    double * B1 = Copy(B, n);
    double *x = Solve(A, B, n);
    Print(x, n, fout);
    if (Correct(A1, x, B1, n)){
        cout << "Yes\n";
    }
    else{cout << "No!\n";}
}
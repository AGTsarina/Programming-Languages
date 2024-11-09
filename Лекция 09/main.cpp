#include <fstream>
#include <iostream>
#include "matrix.h"

using namespace std;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n; // размерность задачи
    double ** A = GetMatrix(fin, n);
    Print(A, n, cout);
    double *B = GetVector(fin, n);
    double *x = Solve(A, B, n);
    Print(x, n, fout);
}
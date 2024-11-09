#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

// заголовки функций

double ** GetMatrix(istream &fin, int &n);
double * GetVector(istream &fin, int n);
double * Solve(double **A, double *B, int n);
void Print(double *x, int n, ostream &fout);
void Print(double **A, int n, ostream &fout);
double *Copy(double *v, int n);
double ** Copy(double **A, int n);
bool Correct(double ** A, double *x, double *B, int n);

// реализация функций matrix.cpp

double ** GetMatrix(istream &fin, int &n){
    fin >> n;
    double ** res = new double*[n];
    for(int i=0; i<n; i++){
        res[i] = GetVector(fin, n);
    }
    return res;
}
double * GetVector(istream &fin, int n){
    double *res = new double[n];
    for(int j=0; j<n; j++){
        fin >> res[j];
    }
    return res;
}
/// @brief Умножение вектора на число
/// @param v Вектор
/// @param n размер вектора
/// @param k индекс, с которого начинается умножение
/// @param value число, на которе умножаем
void Mult(double *v, int n, int k, double value){
    for(int i=k; i<n; i++){
        v[i] *= value;
    }
}

void Substraction(double *v1, double *v2, int k, int n){
    double value = v1[k];
    for(int i=k; i<n; i++){
        v1[i] -= v2[i] * value;
    }
}

double Dot(double *v1, double *v2, int k, int n){
    double res = 0.0;
    for(int i=k; i<n; i++){
        res += v1[i] * v2[i];
    }
}

double * Solve(double **A, double *B, int n){
    for(int i=0; i<n; i++){
        B[i] /= A[i][i];
        Mult(A[i], n, i, 1.0 / A[i][i]);
        for(int j=i+1; j<n; j++){
            B[j] -= B[i] * A[j][i];
            Substraction(A[j], A[i], i, n);
        }
    }
    double * x = new double [n];
    for(int i=n-1; i>-1; i--){
        x[i] = B[i] - Dot(x, A[i], i+1, n);
    }
    return x;
}
void Print(double *v, int n, ostream &fout){ 
    if (!v) return;   
    for(int j=0; j<n; j++){
        fout <<setw(4)<< v[j] << " ";
    }
    fout << endl;
}

void Print(double **A, int n, ostream &fout){       
    for(int j=0; j<n; j++){
        Print(A[j], n, fout);
    }
    fout << endl;
}

double *Copy(double *v, int n){
    double *res = new double[n];
    for(int i=0; i<n; i++){
        res[i] = v[i];
    }
    return res;
}
double ** Copy(double **A, int n){
    double ** res = new double*[n];
    for(int i=0; i<n; i++){
        res[i] = Copy(A[i], n);
    }
    return res;
}
bool Correct(double ** A, double *x, double *B, int n){
    double eps = 1.0e-10;
    for(int i=0; i<n; i++){
        if (abs(Dot(A[i], x, 0, n) - B[i])>eps){
            return false;
        }
    }
    return true;
}

double * SolveIterations(double **A, double *B, int n){
    double *x = new double[n];
    for(int i=0; i<n; i++) x[i] = 0;
    double * x1 = new double[n];
    for(int k=0; k<100; k++){
        for(int i=0; i<n; i++){
            x1[i] = (B[i] - Dot(A[i], x, 0, n))/A[i][i] +x[i]; 
        }
        double *temp = x;
        x = x1; x1 = temp;
        Print(x1, n, cout);
    }
    return x1;
}
#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

double sum(double *A, int n);

int main(){
    double A[]={1,2,3,4,5};
    double s1 = sum(A, 5);
    double s2 = sum(&A[0], 5);
    double s3 = sum(&A[1], 4);
    return 0;
}

double sum(double *A, int n){
    double s = 0;
    for(int i=0; i<n; i++){
        A[i] *= 2;
        s += A[i];
    }
    return s;
}

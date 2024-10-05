#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double Exp(double x, double eps, int &n);
double Exp(double x, double eps=1.0e-7);

int main(){
    ofstream fout("output.txt");
    double x1 = 0.5, x2 = 5.0, x3 = 10.0;
    for(double eps = 0.1; eps > 1.0e-11; eps /= 10){
        int N1, N2, N3;
        double res1 = Exp(x1, eps, N1);
        double res2 = Exp(x2, eps, N2);
        double res3 = Exp(x3, eps, N3);
        fout << eps <<"\t" << N1 << "\t" << N2 << "\t" << N3<<endl;
    }     
}

double Exp(double x, double eps, int &n){
    double X = x;
    x = abs(x);
    
    double res = 0.0;
    double sl = 1;
    for(n = 1; abs(sl) > eps ; n++){
        res += sl;
        sl *= x / n;
    }
    n--;
    if (X < 0) return 1.0/res;
    return res;
}
double Exp(double x, double eps){
    int n;
    return Exp(x, eps, n);
}
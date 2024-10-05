#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double Exp(double x, double eps, int &n);
double Exp(double x, double eps=1.0e-7);

int main(){
    ofstream fout("output.txt");
    double eps = 1.0e-5;
    for(double x = -20; x<10.05; x+=0.5){
        int N;
        double res = Exp(x, eps, N);
        fout << "e(" << fixed << setw(3) <<setprecision(2) << x << ") = " << setprecision(10) << res ;
        fout << "\treal = " << exp(x) << " ";
        fout << "\tN = " << N << endl;
    } 
    cout <<  Exp(-1.5, 1.0e-10) << endl; 
    cout <<  Exp(-2.5) << endl; 
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
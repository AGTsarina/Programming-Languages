#include <fstream>
#include <iomanip>
#include <cmath>

using namespace std;
// Задача 3.3 Функция вычисления суммы ряда
double S_Task_3_3(double eps, int &N);
// Задача 3.5 Функция вычисления суммы ряда
double S_Task_3_5(double eps, int &N);

int main(){    
    ofstream fout("output.txt");
    int N;
    for(double eps = 1.0e-2; abs(eps - 1.0e-10) > 1.0e-14; eps /= 10.0){
        double res = S_Task_3_5(eps, N);        
        fout << "Сумма ряда с точностью " << setprecision(1)<< eps << " равна " <<setprecision(25) << res << endl;
        fout << "Количество слагаемых " << N << endl << endl;
    }
}

double S_Task_3_3(double eps, int &n){
    double res = 0.0;
    double sl = 1.0;
    for(n = 1; sl > eps; n++){
        sl = (2.0 * n + 1) / ((n + 1) * (n + 1) * (n + 2) * (n + 2));        
        res += sl;
    }
    n--;
    return res;
}

double S_Task_3_5(double eps, int &n){
    double res = 0.0;
    double sl = 1.0;
    double e = exp(1.0);
    double zn = e;
    for(n = 1; sl > eps; n++){
        sl = n * n * n / zn;        
        res += sl;
        zn *= e;
    }
    n--;
    return res;
}
#include <iostream>
#include <ctime>
using namespace std;
// Рекурсивные алгоритмы

// 1. Вычисление факториала
long f(long n);
long fr(long n);

int main(){
    int n = 100000;
    cout << f(15)<< " " << fr(15) <<  endl;
    clock_t t1 = clock();
    for(int i=0; i<n; i++) f(15);
    clock_t t2 = clock();
    cout << "Test 1 " << t2 - t1 <<endl;

    t1 = clock();
    for(int i=0; i<n; i++) fr(15);
    t2 = clock();
    cout << "Test 2 " << t2 - t1 << endl;
}

long f(long n){
    long res = 1;
    for(long i=2; i<=n; i++){
        res *= i;
    }
    return res;
}
long fr(long n){
    if (n < 2) return 1;
    return n * fr(n - 1);

    // n * (n-1) * (n -2) * .... 3 * 2 * 1
}

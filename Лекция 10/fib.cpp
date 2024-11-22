#include <iostream>
#include <ctime>
using namespace std;
// Рекурсивные алгоритмы

// 2. Вычисление чисел Фибоначчи
long f(long n);
long fr(long n);

int main(){
    int n = 100000;
    int m = 15;   
    
    std::cout << f(m)<< " " << fr(m) <<  endl;
    clock_t t1 = clock();
    for(int i=0; i<n; i++) f(m);
    clock_t t2 = clock();
    std::cout << "Test 1 " << t2 - t1 <<endl;

    t1 = clock();    
    for(int i=0; i<n; i++) fr(m);
    t2 = clock();
    std::cout << "Test 2 " << t2 - t1 << endl;
}

long f(long n){
    if (n < 2) return 1;
    long f0 = 1, f1 = 1;
    for(long i=2; i<=n; i++){
        long f = f0 + f1;
        f0 = f1;
        f1 = f;        
    }
    return f1;
}
long fr(long n, long *&dict){
    if (!dict[n]){ 
        if (n < 2){
            dict[n] = 1;            
        }
        else dict[n] = fr(n - 1, dict) + fr(n - 2, dict);
    }
    return dict[n];    
}

long fr(long m){
    long * dict = new long[m + 1];
    for(int i=0; i<m + 1; i++) dict[i] = 0;
    long res = fr(m, dict);
    delete[]dict;
    return res;
}

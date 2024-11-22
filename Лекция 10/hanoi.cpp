#include <iostream>
using namespace std;

//Ханойские башни

void Move(int n, int A, int B);

int main(){
    Move(4, 3, 1);
}

void Move(int n, int A, int B){
    if (n == 1){
        cout << A << " -> " << B<< endl;
    }
    else{
        int C = 6 - A - B;
        Move(n-1, A, C);
        Move(1, A, B);
        Move(n-1, C, B);
    }
}
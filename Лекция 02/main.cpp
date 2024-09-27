#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

// определение функции (заявка)
// фукция, определяющая попадает ли точка в область
bool InArea(double x, double y);
double Random(double max);

int main(){
    ofstream fout("output.txt");
    int N = 10000; // количество точек
    int M = 0; // количество точек, попадающих в область
    for(int i=0; i<N; i++){
        double x = Random(25.0), y = Random(18.0);
        bool res = InArea(x,y);
        if (InArea(x,y)){ 
            M++; // условная конструкция
            fout <<x <<" " << y << " " << "In\n";
        }
        else{
            fout <<x <<" " << y << " " << "Out\n";
        }
        
    }
    cout << 25.0 * 18.0 * M / N << endl;
}

bool InArea(double x, double y){    
        if (y > 4 && y < 6){ // корпус
            if (y > 10 - x && y > x - 17)
                return true;
        }
        else{ // парус
            double a = -0.143, b=3.286, c = 0.571;
            if (x > 13 && y > 8 && y < a * x * x + b * x + c)
                return true;
        }
        return false;
}

double Random(double max){
    return rand() * max / RAND_MAX;
}

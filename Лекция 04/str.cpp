#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main(){
    double t = 1.2;
    int dir = 230;
    char s[]="-.12", res[10];
    
    printf("Temp = %lf, Wind dir =  %d \n", t, dir);
    sprintf(res, "-0%s", s + 1);
    cout << res << endl;
}
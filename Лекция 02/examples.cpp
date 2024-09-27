#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

// Для известной длины ребра куба определить площадь поверхности, объем и длину диагонали
double cube_volume(double side, double& area, double &diag);
void cube_param(double side, double& area, double &diag, double& volume);

int main(){
    double a = 10;
    double s, d;
    double v = cube_volume(a, s, d);
    cout << setw(7) << a << " " << v << " " << s << " " << d << endl;

    double s1, d1, v1;
    cube_param(a, s1, d1, v1);
    cout << setw(7) << a << " " << v1 << " " << s1 << " " << d1 << endl;

    v = cube_volume(2.0 * a, s, d);
    cout << setw(7) << 2.0 * a << " " << v << " " << s << " " << d << endl;    
    v = cube_volume(5.0, s, d);
    cout << setw(7) << 5.0 << " " << v << " " << s << " " << d << endl;
}

double cube_volume(double side, double& area, double &diag){
    area = side * side * 6.0;
    diag = sqrt(3.0) * side;
    return pow(side, 3.0);
}
void cube_param(double side, double& area, double &diag, double& volume){
    area = side * side * 6.0;
    diag = sqrt(3.0) * side;
    volume = pow(side, 3.0);
}

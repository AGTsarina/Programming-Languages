double f(double x, double y);
double f_pointers(double* px, double *py);
double f_ref(double &x, double &y);

const int N = 10;

int main(){
    double x = 5, y = 7;
    // оператор &  получает адрес объекта, к которому он применен
    double res_value = f(x, y);
    double res_p = f_pointers(&x, &y);
    double res_ref = f_ref(x, y);
    return 0;
}
// передача параметров по значению
double f(double x, double y){
    x *= 2;
    y *= 3;
    return x + y;
}

// передача значений по адресу
double f_pointers(double* px, double *py){
    // оператор * перед указателем извлекает значение, которое хранится по адресу в указателе
    *px *= 2;
    *py *= 3;
    return *px + *py;
}
// пекредача значений по ссылке
double f_ref(double &x, double &y){
    x *= 2;
    y *= 3;
    return x + y;
}

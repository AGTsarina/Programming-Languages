#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

#define INNER
//#undef INNER
#define N_ 100
const int N = 100;


const int days_in_month[]{31, 28, 31,30,31,30,31,31,30,31,30,31};

double * read(const char * filename, int &n);
void print(const double * T, int n, ostream &fout=cout);
double * select(double *T, int n, int m, int &nm);
double max(double *T, int n);

int main(){
    int n;    
    double* T = read("input.txt", n);    
    ofstream fout("temp.txt"), year("year.txt");
    print(T, n, fout);
    // создаем массив для хранения адресов, с которых начинается
    // запись информации за каждый месяц (тип каждого элемента - double *)
    //double * TM[12]; // статическое объявление
    double** TM = new double*[12];
    int *nm = new int[12];
    // в отдельный массив записать информацию о температуре заданного месяца m
    for(int m = 1, i = 0; m <13; m++, i++){        
        // m - порядковый номер месяца, nm - количество записей
        TM[i] = select(T, n, m, nm[i]);
        print(TM[i], nm[i], year);
        cout << "Max Temp Month[: " << m << "] " << max(TM[i], nm[i])<< endl;    
    }
    cout << "Max Temp Year: " << max(T, n)<< endl;
    delete[]T;   
#ifndef INNER
    for(int i=0; i<12; i++){
        delete[]TM[i];
    }    
#endif
    delete []nm;
    delete[]TM;
}

double * read(const char * filename, int &n){
    const int MAX = 1000; 
    int capacity = MAX, length = 0;
    double * res = new double[capacity];    
    ifstream fin(filename);
    for(;fin >> res[length]; length++){
        if (length == capacity - 1){  // массив заполнен            
            // создаем новый массив с увеличенной емкостью
            capacity += MAX;
            double * temp = new double[capacity];
            // переписываем в новый массив информацию из старого
            for(int i=0; i<length; i++){
                temp[i] = res[i];
            }
            // запоминаем, где хранится старый массив
            double * to_delete = res;
            // дальше будем работать с новым массивом
            res = temp;
            // удаляем старый массив
            delete [] to_delete;
        }
    }
    // создаем новый массив, есмкость которого соответсвует длине вспомогательного массива
    double *T = new double[length];
    for(int i=0; i<length; i++){
        T[i] = res[i];
    }
    delete[] res;
    n = length;
    return T;
}

void print(const double * T, int n, ostream &fout){
    for(int i=0; i<n; i++){
        fout <<T[i] << "\t";
    }
    fout << endl << endl;
}

double * select(double *T, int n, int m, int &nm){
    nm = days_in_month[m - 1] * 24;
    int skip = 0;
    for(int i=0; i<m - 1; i++){
        skip += days_in_month[i]; // кол-во дней, которые пропускаем
    }
    skip *= 24; // кол-во записей, кот. пропускаем
#ifndef INNER
    // 1. создаем внешний массив
    double *res = new double[nm];
    for(int i=0; i<nm; i++){
        res[i] = T[i + skip];
    }
#endif
#ifdef INNER
    // 2. внутренний массив
    double *res = T + skip; // вычисляем адрес элемента массива, стоящего за первыми skip элементами
#endif
    return res;
}

double max(double *T, int n){
    double res = T[0];
    for(int i=0; i<n; i++){
        if (T[i] > res) res = T[i];
    }
    return res;
}

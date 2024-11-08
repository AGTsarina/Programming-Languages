#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

double get_value(char *str);
double ** ReadTable(int ncols, int nrows, const char *filename);
int * GetNumWrongs(double ** data, int ncols, int nrows, double *wrong_values);
// шаблоны
template<class Type>
void Print(Type * data, int n, const char *, ostream &fout);

int main(){
    int ncols = 16, nrows = 8760;
    double ** data = ReadTable(ncols, nrows, "data.txt");
    double wrong_values[ncols]{9999, 99, 99, 99, 99, 99.9, 99.9, 99.9, 999,999,999, 99.9, 99.9, 99.9, 5, 999.9};
    string names[ncols]{"Год", "Мес", "День", "Время", "час", "V8",  "V121",  "V301", "F8", "F121", "F301", "T2", "T121",
    "T301", "R2", "Р2"};
   
    auto num_wrongs = GetNumWrongs(data, ncols, nrows, wrong_values);
    Print(names, ncols, "Titles: ", cout);
    Print(wrong_values, ncols, "Wrong Values: ", cout);
    Print(num_wrongs, ncols, "Num Wrongs: ", cout);
    
}

double get_value(char *str){
    if (str[0]=='.'){
        char res[20];
        sprintf(res, "0%s", str);
        return atof(res);
    }
    if (str[0] == '-' && str[1] == '.'){
        char res[20];
        sprintf(res, "-0%s", str + 1);
        return atof(res);
    }
    return atof(str);
}

double ** ReadTable(int ncols, int nrows, const char *filename){
    // создаем матрицу (выделяем память под столбцы)
    double ** res = new double* [ncols];
    for(int i=0; i<ncols; i++){
        res[i] = new double[nrows];
    }
    // считываем данные из файла
    ifstream fin(filename);
    for(int i=0; i<nrows; i++){
        for(int j=0; j <ncols; j++){
            char str[20];
            fin >> str;
            res[j][i] = get_value(str);
        }
    }
    return res;
}

int * GetNumWrongs(double ** data, int ncols, int nrows, double *wrong_values){
    int * res = new int[ncols];
    for(int i=0; i<ncols; i++){
        res[i] = 0;
        for(int j = 0; j<nrows; j++){
            if (data[i][j] == wrong_values[i]) res[i]++;
        }
    }
    return res;
}

template <class Type>
void Print(Type * data, int n, const char *title, ostream &fout){
    fout << title << endl;
    for(auto i=0; i<n; i++){
        fout<<setw(5) << data[i] << " ";
    }
    fout << endl;
}
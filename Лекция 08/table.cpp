#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Column{
    string header;
    double wrong_value;
    int size;
    double * data;
    int num_wrongs;
    double mean;
    double min, max;
};

struct Table
{
    int size; 
    Column * data;
};


double get_value(char *str);
Table ReadTable(int ncols, int nrows, const char *filename, string * names,
double * wrongs);
int GetNumWrongs(double * data, int nrows, double wrong_value);
double GetMean(double * data, int nrows, double wrong_value);
int* GetNumWrongs(Table &table);
double * GetMean(Table& table);
// шаблоны
template<class Type>
void Print(Type * data, int n, const char *, ostream &fout);

int main(){
    int ncols = 16, nrows = 8760;
    double wrong_values[ncols]{9999, 99, 99, 99, 99, 99.9, 99.9, 99.9, 999,999,999, 99.9, 99.9, 99.9, 5, 999.9};
    string names[ncols]{"Год", "Мес", "День", "Время", "час", "V8",  "V121",  "V301", "F8", "F121", "F301", "T2", "T121",
    "T301", "R2", "Р2"};
    Table data = ReadTable(ncols, nrows, "data.txt", names, wrong_values);   
   
    auto num_wrongs = GetNumWrongs(data);
    auto means = GetMean(data);
    Print(names, ncols, "Titles: ", cout);
    Print(wrong_values, ncols, "Wrong Values: ", cout);
    Print(num_wrongs, ncols, "Num Wrongs: ", cout);
    Print(means, ncols, "Mean Values: ", cout);
    
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

Table ReadTable(int ncols, int nrows, const char *filename, string * names,
double * wrongs){
    // создаем матрицу (выделяем память под столбцы)
    Table res;
    res.size = ncols;
    res.data = new Column[ncols];
    for(int i=0; i<ncols; i++){        
        res.data[i].data = new double[nrows];
        res.data[i].header = names[i];
        res.data[i].wrong_value = wrongs[i];
        res.data[i].size = nrows;
    }
    // считываем данные из файла
    ifstream fin(filename);
    for(int i=0; i<nrows; i++){
        for(int j=0; j <ncols; j++){
            char str[20];
            fin >> str;
            res.data[j].data[i] = get_value(str);
        }
    }
    return res;
}

int GetNumWrongs(double * data, int nrows, double wrong_value){
    int res;
    res = 0;
    for(int j = 0; j<nrows; j++){
        if (data[j] == wrong_value) res++;
    }   
    return res;
}

double GetMean(double * data, int nrows, double wrong_value){
    double res = 0.0;
    int num = 0;
    for(int j = 0; j<nrows; j++){
        if (data[j] != wrong_value) {res+=data[j]; num++; }
    }   
    return res/num;
}

int* GetNumWrongs(Table &table){
    int *res = new int[table.size];
    for(int i=0; i<table.size; i++){
        res[i] = GetNumWrongs(table.data[i].data, table.data[i].size, table.data[i].wrong_value);
        table.data[i].num_wrongs = res[i];
    }
    return res;
}
double * GetMean(Table& table){
    double *res = new double[table.size];
    for(int i=0; i<table.size; i++){
        res[i] = GetMean(table.data[i].data, table.data[i].size, table.data[i].wrong_value);
        table.data[i].mean = res[i];
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
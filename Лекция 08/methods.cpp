#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int GetNumWrongs(double * data, int nrows, double wrong_value);
double GetMean(double * data, int nrows, double wrong_value);
double get_value(char *str);

struct Column{
    // поля - система харектеристик/свойств
    string header;
    double wrong_value;
    int size;
    double * data;
    int num_wrongs;
    double mean;
    double min, max;
    // методы - внутренние функции класса, прописывающие систему действий
    // конструктор
    Column(){}
    void CreateColumn(string header, double wrong_value, int size){
        this->header = header;
        this->wrong_value = wrong_value;
        this->size = size;
        this->data = new double[size];
    }
    int getNumWrongs(){
        num_wrongs = GetNumWrongs(data, size, wrong_value);
        return num_wrongs;
    }
    double getMean(){
        mean = GetMean(data, size, wrong_value);;
        return mean;
    }
};

struct Table
{
    // поля
    int size; 
    Column * data;
    // методы
    // конструктор
    Table(int ncols, int nrows, const char *filename, string * names,
double * wrongs){    
        this->size = ncols;
        this->data = new Column[ncols];
        for(int i=0; i<ncols; i++){        
            this->data[i].CreateColumn(names[i], wrongs[i], nrows);
        }
        // считываем данные из файла
        ifstream fin(filename);
        for(int i=0; i<nrows; i++){
            for(int j=0; j <ncols; j++){
                char str[20];
                fin >> str;
                this->data[j].data[i] = get_value(str);
            }
        }
    }
    int* GetNumWrongs(){
        int *res = new int[this->size];
        for(int i=0; i<this->size; i++){
            res[i] = this->data[i].getNumWrongs();            
        }
        return res;
    }
    double * GetMean(){
        double *res = new double[size];
        for(int i=0; i<size; i++){
            res[i] = data[i].getMean();            
        }
        return res;
    }
};



// шаблоны
template<class Type>
void Print(Type * data, int n, const char *, ostream &fout);

int main(){
    int ncols = 16, nrows = 8760;
    double wrong_values[ncols]{9999, 99, 99, 99, 99, 99.9, 99.9, 99.9, 999,999,999, 99.9, 99.9, 99.9, 5, 999.9};
    string names[ncols]{"Год", "Мес", "День", "Время", "час", "V8",  "V121",  "V301", "F8", "F121", "F301", "T2", "T121",
    "T301", "R2", "Р2"};
    Table data(ncols, nrows, "data.txt", names, wrong_values);   
   
    auto num_wrongs = data.GetNumWrongs();
    auto means = data.GetMean();
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



template <class Type>
void Print(Type * data, int n, const char *title, ostream &fout){
    fout << title << endl;
    for(auto i=0; i<n; i++){
        fout<<setw(5) << data[i] << " ";
    }
    fout << endl;
}
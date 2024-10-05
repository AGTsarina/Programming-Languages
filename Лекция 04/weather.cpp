#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

double get_value(char *str);
int get_num_lines(ifstream & fin);
double * read_temperature(ifstream & fin, int n);
int length(char *str);
void save(const char *filename, double *T, int n);
// определение колиечтва отказов датчика и номер первого отказа
int num_failures(double *T, int n, int &index);
void interpolate(double *T, int n, int x1, int x2);

int main(){
    ifstream fin("BMM_2023.txt");
    // определим количество непустых строк в файле = кол-ву наблюдений
    int n = get_num_lines(fin);
    double * T = read_temperature(fin, n);
    
    int index_falure;
    cout << "Количество отказов датчика: " << num_failures(T, n, index_falure)<<endl;
    cout << "Индекс первого отказа: " << index_falure<<endl;
    cout << T[index_falure - 1] << " " << T[index_falure] << " " << T[index_falure + 4] << endl;
    interpolate(T, n, index_falure - 1, index_falure + 4);
    save("output.txt", T, n);
    return 0;    
}
void interpolate(double *T, int n, int x1, int x2){
    double T1 = T[x1], T2 = T[x2];
    double k = (T2 - T1) / (x2 - x1);
    double b = -k * x1 + T1;
    for(int i = x1 + 1; i < x2; i++){
        T[i] = k * i + b;
    }
}

int num_failures(double *T, int n, int &index){
    int res = 0;
    index = -1;
    for(int i=0; i<n; i++){
        if (T[i] > 99){
            res++;
            if (index < 0) index = i;
        }
    }
    return res;
}


void save(const char *filename, double *T, int n){
    ofstream fout(filename);
    for(int i=0; i<n; i++){
        fout << T[i] << endl;
    }
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
int get_num_lines(ifstream & fin){
    int res = 0;
    char str[200];
    while(!fin.eof()){ // покм не достигнут конец файла
        fin.getline(str, 200); // считываем строку, количество прочитанных символов не превышает 200
        if(length(str) > 1) res++;
    }
    fin.close();
    return res;
}

double * read_temperature(ifstream & fin, int n){
    fin.open("BMM_2023.txt", ios::in);
    double * res = new double[n]; // выделяем 8n байт, возвращаем указатель на начало блока
    int lskip = 11, rskip = 4;
    char temp[20];    
    int k = 0;
    fin.seekg(0, ios::beg);    
    while(fin >> temp){
        for(int i=1; i<lskip; i++){
            fin >> temp;        
        }
        fin >> temp; // читаем информацию о приземной температуре
        res[k++] = get_value(temp);        
        for(int i=0; i<rskip; i++){
            fin >> temp;        
        }
    }
    return res;
}

int length(char *str){
    int i=0;
    for(; str[i]!='\0'; i++);
    return i;
}


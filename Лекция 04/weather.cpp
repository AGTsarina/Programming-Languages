#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

double get_value(char *str);

int main(){
    ifstream fin("BMM_2023.txt");
    int lskip = 11, rskip = 4;
    char temp[20];
    double t;
    for(int i=0; i<lskip; i++){
        fin >> temp;
        cout << temp << " | ";
    }
    fin >> temp; // читаем информацию о приземной температуре
    t = get_value(temp);
    cout << endl;
}

double get_value(char *str){
    if (str[0]=='.'){
        char res[20];
        sprintf(res, "0%s", str);
        return atof(res);
    }
    // to be continued
}
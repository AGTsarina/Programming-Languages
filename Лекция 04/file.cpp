#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main(){
    ifstream fin("BMM_2023.txt");
    char *s = new char[200];
    fin.getline(s, 200);
    fin.getline(s, 200);
    fin.getline(s, 200);
    fin.seekg(0, ios::beg);
    cout << "Pos: " << fin.tellg() << endl;    
    fin.getline(s, 200);
    return 0;
}
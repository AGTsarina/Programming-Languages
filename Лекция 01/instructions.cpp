#include <iostream> // подключение библиотеки ввода / вывода
#include <fstream> // подключение библиотеки для работы с файлами

using namespace std;

int main(){    
    auto a = 10, b = 5;
    // разветвление
    if (a > b && (a % 2 == 0 || b % 2 != 0)) cout << a << endl; 
    else cout << b << endl;

    // цикл с предусловием
    while (a > 0){
        a--;
        b *= 2;
    }
    cout << a << " " << b << endl;

    // цикл с фиксированным количеством итераций
    int s = 0;
    for(int i=0; i< 10; i++ ){
        s += i;
    }
    cout << s << endl;
}


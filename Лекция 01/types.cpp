#include <iostream> // подключение библиотеки ввода / вывода
#include <fstream> // подключение библиотеки для работы с файлами

using namespace std;

int main(){    
    // знаковые целые числа
    int var_int = 100;
    short var_short = 1000;
    long var_long = 1000000000;
    char var_char = 70;
    
    // определяем размер памяти для каждого типа данных
    cout  << sizeof(int) << " "
          << sizeof(short) << " "
          << sizeof(long) << " "
          << sizeof(long long) << " "
          << sizeof(char) << endl;
    
    // исследуем адреса переменных
    int* p_var_int = &var_int;
    short* p_var_short = &var_short;
    long* p_var_long = &var_long;
    char* p_var_char = &var_char;

    cout  << p_var_int << " "
          << p_var_short << " "
          << p_var_long << " "          
          << (void *)p_var_char << endl; // static_cast<void*>(p_var_char);   // преобразование к безтиповому указателю
    
    int & A = var_int;        // адрес в памяти переменной
    char & ch = var_char;     // псевдоним/ другое имя для уже существующей переменной/объекта

    cout << A << " " << ch << endl;
}

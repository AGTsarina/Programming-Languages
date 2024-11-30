#include <fstream>
#include <iostream>
using namespace std;

// В файле дан текст
// 1. Определим количество слов тексте
// 2. Поменяем каждую первую букву слова на заглавную
// 3. Определим сколько раз в тексте встречается заданное слово
// 4. Заменить все вхождения заданного слова на другое слово

// Прочитать из файла текст в объект "текст" (char **)
char ** readFile(const char *filename, int &nlines);
int getNumWords(char *line);
void toTitle(char *line);
int getNumWords(char **text, int nlines);
int getNumWord(char *line, const char *word);
void replaceWords(char *&line, const char*toFind, const char *toReplace);
void print(char *line){for(char *p = line; *p; p++){
        cout << *p;
    }
    cout << endl;}
int main(){
    int nlines;
    char ** text = readFile("input.txt", nlines);
    toTitle(text[0]);
    print(text[0]);
    cout << endl << getNumWord(text[3], "cast")<< " "<<
    getNumWords(text, nlines) << endl;
    replaceWords(text[0], "Cast", "Casted");
    print(text[0]);
    return 0;
}

int getNumLines(ifstream &input){
    char temp[1000];
    int res = 0;
    while(input.getline(temp, 1000)){
        res++;
    }
    return res;
}

int length(const char *s){
    int res = 0;
    for(const char * p = s; *p; p++, res++);
    return res;
}
char * copy(char *to, const char *from){    
    for(; *from; from++, to++){
        *to = *from;
    }
    *to = '\0';
    return to;
}

char * readLine(ifstream &input){
    char temp[1000];
    input.getline(temp, 1000);
    char * res = new char[length(temp) + 1];
    copy(res, temp);
    return res;
}

char ** readFile(const char *filename, int &nlines){
    ifstream input(filename);
    // определяем кол-во строк в файле
    nlines = getNumLines(input);
    input.close();
    input.open(filename);
    input.seekg(0, ios::beg);
    char ** res = new char*[nlines];
    for(int i=0; i<nlines; i++){
        res[i] = readLine(input);
    }
    return res;
}

int getNumWords(char *line){
    int res = 0;
    for(char *p = line; *p;){
        // поиск начала слова
        for(;*p && *p == ' '; p++);
        // учитываем слово
        if (*p) res++;
        // ищем конец слова
        for(;*p && *p != ' '; p++);
    }
    return res;
}
int getNumWords(char **text, int nlines){
    int res = 0;
    for(int i=0; i<nlines; i++){
        res += getNumWords(text[i]);
    }
    return res;
}

bool isSeparator(char c, char *sep){
    for(char *p = sep; *p; p++){
        if (c == *p) return true;
    }
    return false;
}
bool isAlpha(char c){
    if (c >= 'a' && c <='z') return true;
    if (c >= '\240' && c <='\261') return true;
    return false;
}

void toUpper(char *c){
    if (*c >= 'a' && *c <='z'){
        *c += 'A' - 'a';
    }
    if (*c >= 'а' && *c <='я')
        *c += 'А' - 'а'; 
}

void toTitle(char *line){
    char sep[]=" ,.<>()\"";
    for(char *p = line; *p;){
        // поиск начала слова
        for(;*p && isSeparator(*p, sep); p++);
        // учитываем слово
        if (*p && isAlpha(*p)){
            toUpper(p);
        }
        // ищем конец слова
        for(;*p && !isSeparator(*p, sep); p++);
    }
}

int getNumWord(char *line, const char *word){
    int res=0;
    char sep[]="_ ,.<>()\"";
    for(char *p = line; *p;){
        // поиск начала слова
        for(;*p && isSeparator(*p, sep); p++);
        // учитываем слово
        if (*p){
            char *begin = p;
            // ищем конец слова
            bool flag = true;
            for(const char *w = word;*p && !isSeparator(*p, sep); p++, w++){
                if (!*w || *p != *w){
                    flag = false;
                }                
            }
            if (flag) res++;
            char *end = p - 1;
        }
    }
    return res;
}

void replaceWords(char *&line, const char*toFind, const char *toReplace){    
    char sep[]="_ ,.<>()\"";
    int dif = length(toReplace) - length(toFind);
    char *resline = new char[length(line) + getNumWord(line, toFind) * dif + 1];
    char *res = resline;
    for(char *p = line; *p;){
        // поиск начала слова и переписываем в новую строку символы
        for(;*p && isSeparator(*p, sep); p++, res++){
            *res = *p;
        }
        // учитываем слово
        if (*p){
            char *begin = p;
            // ищем конец слова
            bool flag = true;
            for(const char *w = toFind;*p && !isSeparator(*p, sep); p++, w++){
                if (!*w || *p != *w){
                    flag = false;
                }                
            }
            char *end = p - 1;
            if (flag){
                // слово требуется заменить
                res = copy(res, toReplace);
            }
            else{
                // слово надо оставить
                for(char * pcur = begin; pcur <= end; pcur++, res++){
                    *res = *pcur;
                }
            }
            
        }
    }
    *res = 0;
    delete[] line;
    line = resline;
}
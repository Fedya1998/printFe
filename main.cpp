#include <iostream>
#include <stdio.h>

using namespace std;

/*
void PrintValue(char c) {
    putchar(c);
}

void PrintValue(int i) {
    printf("%d", i);
}

void PrintValue(const char *msg) {
    printf("%s", msg);
}

void PrintValue(double lg) {
    printf("%lg", lg);
}

void PrintValue(void *ptr) { printf("%p", ptr); }
*/

void printFe(const char *message) {
    cout<<message;
};

template<typename T, typename... Args>
void printFe(const char *message, T val, Args ... args) {
    while (*message) {
        if (*message != '%') {
            cout<<*message;
            message++;
        } else {
            if (*(message + 1) == '%'){
                cout<<'%';
                message+=2;
                continue;
            }
            cout<<val;
            printFe(message + 1, args...);
            break;
        }
    }
}

int main() {
    printFe("I love % and % loves me%%; we love each other % times\n", "printFe", "printFe", 2365);
    return 0;
}

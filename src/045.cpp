#include <cstdio>
#include <string>
using namespace std;

inline bool is_digit(char ch) {
    if (ch >= '0' && ch <= '9') return true;
    return false;
}
bool valid(const char* str) {
    while (str != NULL && *str == ' ') ++str;
    bool neg = false;
    if (*str == '-') {
        neg = true;
        ++str;
    } else if (*str == '+') {
        neg = false;
        ++str;
    }
    bool float_flag = false, exp_flag = false;
    for (; str != NULL && *str != '\0' && *str != ' '; ++str) {
        if (*str == '.') {
            if (!float_flag) {
                float_flag = true;
            }
            else return false;
        } else if (*str == 'e') {
            if (!exp_flag) {
                exp_flag = true;
                if (*(str+1) == '-' || *(str+1) == '+') ++str;
            }
            else return false;
        } else if (!is_digit(*str)) return false;
    }
    while (str != NULL && *str != '\0' && *str == ' ') {
        ++str; 
    }
    if (*str == '\0') return true;
    else return false;
}
int main() {
    char str[1024];
    while (gets(str)) {
        if ( valid(str) ) {
            printf("true\n");
        } else {
            printf("false\n");
        }
    }
    return 0;
}

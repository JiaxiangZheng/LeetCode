#include <iostream>
#include <cstring>
using namespace std;

void prepare_alpha_table(const char* pattern, bool* is_in_pattern, int* slide_step, int alpha_size) {
    int len_pattern = strlen(pattern);
    for (int i=0; i<alpha_size; ++i) {
        is_in_pattern[i] = false; slide_step[i] = len_pattern;
    }
    for (const char* p = pattern; *p != '\0'; ++p) {
        *(is_in_pattern + *p) = true;
        *(slide_step + *p) = (len_pattern - 1) - (p - pattern);   // right most will replace the reoccurence in the left
    }
}
#define ALPHA_TABLE_SIZE 256
const char* str_match_bm(const char* str, const char* pattern, bool* is_in_pattern, int* slide_step/* , int alpha_size */) {
    int len_str = strlen(str);
    int len_pattern = strlen(pattern);
    int i = len_pattern - 1;
    while (i < len_str) {
        i += (len_pattern - 1 - j);
        int j = len_pattern - 1;
        while (pattern[j] == str[i]) {--i; --j;}
        if (j == 0) return str + i;
        if (is_in_pattern[str[i]]) {
            i += (len_pattern - j);
        } else {
            i += (0);
        }
    }
    return NULL;
}

int main() {
    const char* str = "this abcddcabckeabcdabcefgkei f";
    const char* pattern = "abcdabc";
    bool is_in[ALPHA_TABLE_SIZE]; int step[ALPHA_TABLE_SIZE];
    prepare_alpha_table(pattern, is_in, step, ALPHA_TABLE_SIZE);
//    const char* pos = str_match_bm(str, pattern, is_in, step);
//    if (pos != NULL)
//        cout << pos << endl;
//    else cout << "not in" << endl;
    return 0;
}

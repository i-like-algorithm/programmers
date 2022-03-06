#include <string>
#include <vector>
#include <string.h>

using namespace std;

string solution(string s) {
    int max = -2147483648;
    int min = 2147483647;
    int num = 0;
    char *cstr = new char[s.length() + 1];
    strcpy(cstr, s.c_str());
    
    char *p = strtok(cstr, " ");
    while (p != NULL) {
        num = atoi(p);
        if (num > max)
            max = num;
        if (num < min)
            min = num;
        p = strtok(NULL, " ");
    }
    
    delete [] cstr;
    return to_string(min) + " " + to_string(max);
}

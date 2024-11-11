#include "auxiliary_functions.h"

const bool is_numeric(const string& str) {
    size_t i = 0;
    if(str.size() > 0) {
        for(i = 0; i < str.size(); i++) {
            if(str[i] > '9' || str[i] < '0') {
                return false;
            }
        }
        return true;
    }
    return false;
}

void getLineReturnsWords(vector<string>& words, const string& line) {
    size_t i;
    string aux = "";
    for(i=0; i < line.size(); i++) {
        if(line[i] == ' ' || line[i] == '\n' || line[i] == '\0') {
            words.push_back(aux);
            aux = "";
        } else {
            aux.push_back(line[i]);
        }
    }
}

const int getStringInt(string number) {
    size_t i;
    int ans = 0;
    for(i = 0; i < number.size(); i++) {
        ans *= 10;
        ans = ans + (number[i] - '0');
    }
    return ans;
}
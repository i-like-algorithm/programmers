#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> split_token(const string &expression) {
    vector<string> result;
    int start_idx = 0;
    
    for (int i = 0; i < expression.size(); i++) {
        if (!isdigit(expression[i])) {
            result.push_back(expression.substr(start_idx, i - start_idx));
            result.push_back(string(1, expression[i]));
            start_idx = i + 1;
        }
    }
    result.push_back(expression.substr(start_idx));
    return result;
}

void recurssive(vector<string> &result, vector<string> &stack, string &token, vector<string> &expr_arr) {
    if (stack.empty()) {
        stack.push_back(token);
    }
    else {
        int idx1;
        int idx2;

        for (int k = 0; k < expr_arr.size(); k++) {
            if (expr_arr[k] == token)
                idx1 = k;
        }
        for (int k = 0; k < expr_arr.size(); k++) {
            if (expr_arr[k] == stack.back())
                idx2 = k;
        }

        if (idx2 <= idx1) {
            result.push_back(stack.back());
            stack.pop_back();
            recurssive(result, stack, token, expr_arr);
        }
        else 
            stack.push_back(token);
    }
}

long long solution(string expression) {
    long long answer = 0;
    vector<string> expr = {"+", "-", "*"};
    sort(expr.begin(), expr.end());
    vector<vector<string>> expr_arr;
    vector<string> token = split_token(expression);
    vector<string> stack;
    vector<string> result;
    vector<long long> cal;
    
    do {
        expr_arr.push_back(expr);
    } while (next_permutation(expr.begin(), expr.end()));
    
    for (int i = 0; i < expr_arr.size(); i++) {
        stack.clear();
        result.clear();
        cal.clear();
        
        for (int j = 0; j < token.size(); j++) {
            if (!(token[j] == "+" || token[j] == "-" || token[j] == "*")) {
                result.push_back(token[j]);
            }
            else
                recurssive(result, stack, token[j], expr_arr[i]);
        }

        while (!stack.empty()) {
            result.push_back(stack.back());
            stack.pop_back();
        }

        for (int i = 0; i < result.size(); i++) {
            if (!(result[i] == "+" || result[i] == "-" || result[i] == "*")) {
                cal.push_back(stoll(result[i]));
            }
            else {
                long long op1 = cal.back();
                cal.pop_back();
                long long op2 = cal.back();
                cal.pop_back();
                if (result[i] == "+")
                    cal.push_back(op2 + op1);
                else if (result[i] == "-")
                    cal.push_back(op2 - op1);
                else 
                    cal.push_back(op2 * op1);
            }
        }
        if (abs(cal[0]) > answer)
            answer = abs(cal[0]);
    }

    return answer;
}

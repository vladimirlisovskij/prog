#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

// является ли числом
bool is_num(const string& str) {
    for (auto i : str) if (!isdigit(i)) return false;
    return true;
}

bool is_bin (const string& str) {
    return str == "+" || str == "-" || str == "*" || str == "/" || str == "^";
}

// приоритет второго оператора больше чем у первого */
bool is_prior(const string& str1, const string& str2) {
    return str2 == "^" || ((str1 == "+" || str1 == "-") && (str2 == "*" || str2 == "/"));
}

// помещает символ либо в стек либо в результирующую строку
void helper (const string& tok, stack<string>& temp, string& res) {
    if (is_num(tok)) res += tok + " ";
    else if (tok == "(") temp.push(tok);
    else if (tok == ")") {
        while (!temp.empty() && temp.top() != "(") {
            res += temp.top();
            res += " ";
            temp.pop();
        }
        if (temp.empty()) cout << "wrong bracer\n";
        temp.pop();
    } else if (is_bin(tok)) {
        while (!temp.empty() && is_prior(tok, temp.top())) {
            res += temp.top() + " ";
            temp.pop();
        }
        temp.push(tok);
    } else cout << "invalid token " << tok << endl;
}

/* перевод в ОПН */
string opn (string str) {
    stack<string> temp;
    size_t  pos = 0;
    string res;
    while ((pos = str.find(' ')) != string::npos){  // получаем подстроку от начала до первого пробела
        string tok = str.substr(0, pos);
        helper(tok, temp, res);
        str.erase(0, pos + 1);
    }
    helper(str, temp, res);  // в конце строки нет пробела
    while (temp.size() > 1) {  // считываем стек в строку
        res += temp.top();
        res += " ";
        temp.pop();
    }
    res += temp.top();
    return res;
}

/* выполяет операцию */
double do_oper (stack<double>& temp, char oper) {
    double b = temp.top(); temp.pop();  // порядок считывания
    double a = temp.top(); temp.pop();
    switch (oper) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
            return a / b;
        case '^':
            return pow(a,b);
        default:
            cout << "invalid operator " << oper << endl;
            return 0;
    }
}

/* считаем */
double result (string str) {
    stack<double> temp;
    size_t pos = 0;
    while ((pos = str.find(' ')) != string::npos){
        string tok = str.substr(0, pos);
        if (is_num(tok)) temp.push(stoi(tok));
        else temp.push(do_oper(temp, tok[0]));
        str.erase(0, pos + 1);
    }
    temp.push(do_oper(temp, str[0]));
    return temp.top();
}

int main () {
    string in;
    getline(cin, in);
    cout << opn(in) << "\n";
    cout << result(opn(in)) << "\n";
    return  0;
}
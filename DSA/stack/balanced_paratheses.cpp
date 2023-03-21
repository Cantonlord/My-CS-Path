#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isPair(char open, char close) {
    if (open == '(' && close == ')')
        return true;
    else if (open == '[' && close == ']')
        return true;
    else if (open == '{' && close == '}')
        return true;
    return false;
}

bool isBalanced(string s) {
    stack<char> ss;
    for (int i = 0; i < s.size(); i++) {
        char para = s[i];
        if (para == '(' || para == '[' || para == '{')
            ss.push(para);
        if (para == ')' || para == ']' || para == '}') {
            if (ss.empty() || !isPair(ss.top(), para))
                return false;
            else 
                ss.pop();
        }
    }
    return (ss.empty()) ? true : false;
}


int main() {
    string s = "{({}}";
    isBalanced(s) ? printf("true") : printf("false");

}
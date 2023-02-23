#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool check_inversion(string s) {
    stack<char> st;

    for(char c : s) {
        if(c == '(') {
            st.push(c);
        }
        else if(c == ')') {
            if(st.empty() || st.top() != '(') {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string s;
    cout << "Digite uma sequência de parênteses: ";
    getline(cin, s);

    bool inverted = check_inversion(s);
    if(inverted) {
        cout << "A sequência está invertida!" << endl;
    }
    else {
        cout << "A sequência não está invertida." << endl;
    }

    return 0;
}

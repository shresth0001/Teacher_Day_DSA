#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
private:
    char pop(stack<char>& s) {
        char c = s.top();
        s.pop();
        return c;
    }

public:
    bool isValid(string s) {
        stack<char> st;

        for (const char c : s) {
            if (c == '(') {
                st.push(')');
            } else if (c == '{') {
                st.push('}');
            } else if (c == '[') {
                st.push(']');
            } else if (st.empty() || pop(st) != c) {
                return false;
            }
        }

        return st.empty();
    }
};

int main() {
    Solution solution;
    string testString1 = "()[]{}";
    string testString2 = "([)]";
    string testString3 = "{[]}";

    cout << "Is \"" << testString1 << "\" valid? " << (solution.isValid(testString1) ? "Yes" : "No") << endl;
    cout << "Is \"" << testString2 << "\" valid? " << (solution.isValid(testString2) ? "Yes" : "No") << endl;
    cout << "Is \"" << testString3 << "\" valid? " << (solution.isValid(testString3) ? "Yes" : "No") << endl;

    return 0;
}
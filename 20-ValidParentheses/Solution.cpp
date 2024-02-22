class Solution {
public:
    bool isValid(string s) {
        stack<char> openings;
        for (char c : s) {
            if (c == '[' || c == '{' || c == '(') openings.push(c);
            else if (c == ']' && (openings.empty() || openings.top() != '[')) return false;
            else if (c == '}' && (openings.empty() || openings.top() != '{')) return false;
            else if (c == ')' && (openings.empty() || openings.top() != '(')) return false;
            else openings.pop();
        }
        return openings.empty();
    }
};
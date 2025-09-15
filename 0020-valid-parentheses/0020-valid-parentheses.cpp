class Solution {
public:
    bool isValid(string s) {

        stack<char> stac;

        for (char c :s) {
            if (c == '(' || c == '{' || c == '[') {
                stac.push(c);
            } else {
                if (stac.empty()) {
                    return false;
                }
                char temp = stac.top();
                stac.pop();

                if (temp == '(' && c != ')' || temp == '{' && c != '}' || temp == '[' && c != ']') {
                    return false;
                }
            }
        }

        return stac.empty();        
    }
};
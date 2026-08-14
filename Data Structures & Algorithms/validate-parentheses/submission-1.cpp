class Solution {
public:
    bool isValid(string s) {
        stack<char> seen;
        for(char c:s) {
            if(c=='('||c=='{'||c=='[') {
                seen.push(c);
            }
            else{
                if(seen.empty()) {
                    return false;
                }
                if(c==')'&&seen.top()!='(') {
                    return false;
                }
                if(c=='}'&&seen.top()!='{') {
                    return false;
                }
                if(c==']'&&seen.top()!='[') {
                    return false;
                }
                seen.pop();
            }
        }
        return seen.empty();
    }
};

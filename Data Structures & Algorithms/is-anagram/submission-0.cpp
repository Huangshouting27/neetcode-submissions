class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) {
            return false;
        }
        unordered_map<char,int> counts;
        unordered_map<char,int> countt;
        for(int i=0;i<s.length();i++) {
            counts[s[i]]++;
            countt[t[i]]++;
        }
        for(auto item:counts){
            if(item.second!=countt[item.first]){
                return false;
            }
        }
        return true;
    }
};

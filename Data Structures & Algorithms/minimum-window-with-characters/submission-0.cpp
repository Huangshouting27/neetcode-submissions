class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length()<t.length()) {
            return "";
        }
        unordered_map<char,int>counts;
        unordered_map<char,int>countt;
        for(int i=0;i<t.length();i++) {
            countt[t[i]]++;
        }
        int left=0;
        int have=0;
        int need=countt.size();
        int minLen = INT_MAX;
        int start = 0;
        for(int right=0;right<s.length();right++) {
            counts[s[right]]++;
            if (countt.count(s[right]) &&counts[s[right]] == countt[s[right]]) {
                have++;
            }
            while(have==need) {
                int len = right - left + 1;
                if (len < minLen) {
                    minLen = len;
                    start = left;
                }
                if (countt.count(s[left]) &&counts[s[left]] == countt[s[left]]) {
                    have--;
                }
                counts[s[left]]--;
                left++;
            }
        }
        if (minLen == INT_MAX) {
                return "";
        }
        return s.substr(start, minLen);
    }
};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen;
        int left=0;
        int maxlen=0;
        for(int i=0;i<s.length();i++) {
            while(seen.count(s[i])) {
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[i]);
            int len = i - left + 1;
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};

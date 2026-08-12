class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int maxlen=0;
        int maxfreq=0;
        unordered_map<char,int> count;
        for(int i=0;i<s.length();i++) {
            count[s[i]]++;
            maxfreq=max(maxfreq,count[s[i]]);
            while((i-left+1)-maxfreq>k)  {
                count[s[left]]--;
                left++;
            }
            int len=i-left+1;
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};

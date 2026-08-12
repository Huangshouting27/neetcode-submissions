class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) {
            return false;
        }
        unordered_map<char,int> count1;
        unordered_map<char,int> count2;
        for(int i=0;i<s1.length();i++) {
            count1[s1[i]]++;
        }
        for(int i=0;i<s1.length();i++) {
            count2[s2[i]]++;
        }
        if(count1 == count2) {
            return true;
        }
        for(int i=s1.length();i<s2.length();i++) {
            count2[s2[i]]++;

            // 左邊移除
            char remove = s2[i - s1.length()];
            count2[remove]--;

            if(count2[remove] == 0) {
                count2.erase(remove);
            }
            if(count1==count2) {
                return true;
            }
        }
        return false;
    }
};

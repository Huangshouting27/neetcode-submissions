class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> number(nums.begin(),nums.end());
        int longest=0;
        for(int num:nums) {
            if(number.count(num-1)==0) {
                int cur=num;
                int length=1;
                while(number.count(cur+1)) {
                    cur++;
                    length++;
                }
                longest=max(length,longest);
            }
        }
        return longest;
    }
};

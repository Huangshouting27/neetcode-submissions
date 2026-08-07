class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int k=0;k<nums.size();k++) {
            if (k > 0 && nums[k] == nums[k - 1]) {
                continue;
            }
            int i=k+1;
            int j=nums.size()-1;
            while(i<j) {
                int rest=0-nums[k];
                if(nums[i]+nums[j]==rest) {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    int leftValue = nums[i];
                    int rightValue = nums[j];
                    while (i < j && nums[i] == leftValue) {
                        i++;
                    }
                    while (i < j && nums[j] == rightValue) {
                        j--;
                    }
                }
                else if(nums[i]+nums[j]<rest) {
                    i++;
                }
                else{
                    j--;
                }
            } 
        }
        return ans;
    }
};

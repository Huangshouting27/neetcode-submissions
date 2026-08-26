class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size()-1;
        while(left<=right) {
            int i=(right+left)/2;
            if(nums[i]>target) {
                right=i-1;
            }
            else if(nums[i]<target) {
                left=i+1;
            }
            else {
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> q; //存index
        for(int right=0;right<nums.size();right++) {
            while(!q.empty()&&nums[right]>nums[q.back()]) { //比新元素小的都淘汰
                q.pop_back();
            }
            q.push_back(right); //加入新元素
            int left=right-k+1;//算目前視窗的左index
            if(!q.empty()&&q.front()<left) { //若最大候選已離開視窗
                q.pop_front(); //把它刪掉
            }
            if (right >= k - 1) { //若視窗有3個元素 
                ans.push_back(nums[q.front()]);//把deque中最大的加入ans中
            }
        }
        return ans;
    }
};

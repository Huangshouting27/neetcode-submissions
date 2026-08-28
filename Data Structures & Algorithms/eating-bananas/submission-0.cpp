class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(), piles.end());
        while(left<=right) {
            int mid=(left+right)/2;
            long long time=0;
            for(int pile:piles) {
                int hour=(pile+mid-1)/mid;
                time+=hour;
            }
            if(time<=h) {
                right=mid-1;
            }
            else {
                left=mid+1;
            }
        }
        return left;
    }
};

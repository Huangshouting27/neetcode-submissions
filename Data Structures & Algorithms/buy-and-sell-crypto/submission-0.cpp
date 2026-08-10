class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m=0;
        for(int i=0;i<prices.size();i++) {
            int j=prices.size()-1;
            while(i<j){
                int profit=prices[j]-prices[i];
                m=max(m,profit);
                j--;
            }
        }
        return m;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        for(int num :nums) { //統計每個數字出現幾次並存到seen中
            seen[num]++;
        }
        vector<pair<int, int>> freq; //{數字, 出現次數} vector表示可存多組 名稱叫freq的二微陣列 方便排序
        for(auto &item:seen) {
            freq.push_back({item.first,item.second});
        }
        sort(freq.begin(), freq.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(freq[i].first);
        }
        return ans;
    }
};

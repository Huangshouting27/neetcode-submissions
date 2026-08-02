class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> seen; //分類標籤 保存這一組的所有單字
        for(int i=0;i<strs.size();i++) { //走訪所有單字
            string key = strs[i]; //key依序為act pots tops...
            sort(key.begin(), key.end()); //把key按照字母順序排列
            seen[key].push_back(strs[i]); //根據key把單字放到相對應的地方
        }
        vector<vector<string>> ans; //題目要求回傳二微陣列
        for (auto& group : seen) {
            ans.push_back(group.second);
        }
        return ans;
    }
};

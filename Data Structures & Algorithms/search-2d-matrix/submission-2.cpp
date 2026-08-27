class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i=matrix.size();
        int j=matrix[0].size();
        int left=0;
        int right=i*j-1;
        while(left<=right) {
            int index=(left+right)/2;
            int row=index/j;
            int col=index%j;
            if(matrix[row][col]<target) {
                left=index+1;
            }
            else if(matrix[row][col]>target) {
                right=index-1;
            }
            else {
                return true;
            }
        }
        return false;
    }
};

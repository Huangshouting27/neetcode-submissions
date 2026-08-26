class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int ans=0;
        for(int i=0;i<heights.size();i++) {
            if(st.empty()) {
                st.push(i);
            }
            else {
                if(heights[i]>=heights[st.top()]) {
                    st.push(i);
                }
                else {
                    while(!st.empty()&&heights[i]<heights[st.top()]) {
                        int top=st.top();
                        st.pop();
                        int width=0;
                        if(st.empty()) {
                            width=i;
                        }
                        else {
                            width=i-st.top()-1;
                        }
                        ans=max(ans,heights[top]*width);
                    }
                    st.push(i);
                }
            }
        }
        while(!st.empty()) {
            int top=st.top();
            st.pop();
            int width;
            if(st.empty()) {
                width=heights.size();
            }
            else {
                width=heights.size()-st.top()-1;
            }
            ans=max(ans,heights[top]*width);
        }
        return ans;
    }
};

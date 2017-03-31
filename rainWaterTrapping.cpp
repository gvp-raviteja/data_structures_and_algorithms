/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int i;
        int area = 0;
        if(height.size()>0){
            st.push(0);
            for( i=1;i<height.size();i++){
                if(height[st.top()]<=height[i]){
                    st.pop();
                    st.push(i);
                }
                else
                    break;
            }
            for(;i<height.size();i++){
                if(height[st.top()]>=height[i])
                    st.push(i);
                else{
                    while(!st.empty() && height[st.top()]<height[i]){
                        int a = st.top();
                        st.pop();
                        if(!st.empty())
                            area = area + abs(min(height[st.top()],height[i])-height[a]) * (i-st.top()-1);
                    }
                    st.push(i);
                }
            }
        }
        return area;
    }
};

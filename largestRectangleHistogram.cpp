/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
find the area of largest rectangle in the histogram. 
For example,
Given heights = [2,1,5,6,2,3],
return 10. 
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        pair<int,int> val;
        stack<pair<int,int>> stck;
        int max_area = 0,area,i,index;
        for(i=0;i<heights.size();i++){
            if(stck.empty() || heights[i]>stck.top().first){
                stck.push(make_pair(heights[i],i));
            }
            else if(heights[i]<stck.top().first){
                while(!stck.empty() && stck.top().first > heights[i]){
                    val = stck.top();
                    stck.pop();
                    area = val.first * (i-val.second);
                    index = val.second;
                    if(max_area < area ){
                        max_area =  area;
                    }
                }
                if(stck.empty()  || heights[i]>stck.top().first){
                    stck.push(make_pair(heights[i],index));
                }
            }
        }
        while(!stck.empty()){
            val = stck.top();
            stck.pop();
            area = val.first * (i-val.second);
            if(max_area < area ){
                max_area = area;
            }
        }
        return max_area;
    }
};

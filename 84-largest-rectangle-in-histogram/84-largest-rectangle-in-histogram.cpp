class Solution {
public:
    int largestRectangleArea(vector<int>& heights) 
    {
        heights.push_back(0);
        int maxArea=0;
        stack<int> index;
        for(int i=0;i<heights.size();i++)
        {
                while(!index.empty() and heights[index.top()]>heights[i])
                {
                    // cout<<index.top()<<endl;
                    // cout<<heights[index.top()];
                    int h=heights[index.top()];
                    index.pop();
                    int left;
                    if(index.empty())
                        left=-1;
                    else
                        left=index.top();
                    int currArea=h*(i-1-left);
                    maxArea=max(maxArea,currArea);
                }
                index.push(i);
        }
            
        return maxArea;
        
    }
};
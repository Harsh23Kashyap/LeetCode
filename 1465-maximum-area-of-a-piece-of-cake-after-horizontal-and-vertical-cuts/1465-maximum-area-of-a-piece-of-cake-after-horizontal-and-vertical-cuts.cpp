//const 
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) 
    {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long int maxh=INT_MIN;
        long int maxw=INT_MIN;
        for (int i=0;i<horizontalCuts.size()-1;i++)
        {
            maxh=max(maxh, (long)(horizontalCuts[i+1]-horizontalCuts[i]));
        }
        for (int i=0;i<verticalCuts.size()-1;i++)
        {
            maxw=max(maxw, (long)(verticalCuts[i+1]-verticalCuts[i]));
        }
        //(long)max_h * max_v %  1000000007;
        return (long)(maxh*maxw)%1000000007;

    }
};
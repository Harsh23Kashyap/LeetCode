class Solution {
public:
    int maxArea(vector<int>& height) {
        int left[height.size()];
        left[0]=height[0];
        for (int i=1;i<height.size();i++)
        {
            if(height[i]>left[i-1])
            {
                left[i]=height[i];
            }
            else
            {
                left[i]=left[i-1];
            }
        }
        int right[height.size()];
        right[height.size()-1]=height[height.size()-1];
        for (int i=height.size()-2;i>=0;i--)
        {
            if(height[i]>right[i+1])
            {
                right[i]=height[i];
            }
            else
            {
                right[i]=right[i+1];
            }
        }
        // for (int i=0;i<height.size();i++)
        // {
        //     cout<<i<<" - From left "<<left[i]<<" from right "<<right[i]<<endl;
        // }
        int lp=0,rp=height.size()-1;
        int max=0;
        while(lp<=rp)
        {
            int lh=left[lp];
            int rh=right[rp];
            int store=abs((lp-rp)*(int)min(lh,rh));
            //cout<<"Left- "<<height[lp]<<" right-"<<right[lp]<<" amt-" <<store<<endl;
            //cout<<max<<endl;
            if(store>max)
                max=store;
            if(min(lh,rh)==lh && lp<height.size())
                lp++;
            else if(min(lh,rh)==rh && rp>=0)
                rp--;
        }
        return max;
        //cout<<max;
    }
};
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) 
    {
        int n=heights.size();
        stack<int> s;
        vector<int> temp;
        
        s.push(heights[n-1]);
        temp.push_back(0);
        for(int i=n-2;i>=0;i--)
        {
            //cout<<"For "<<i<<endl;
            int count=0;
            while(!s.empty() and s.top()<heights[i])
            {
                //cout<<s.top()<<endl;
                s.pop();
                count++;
            }
            if(s.empty())
                count--;
            s.push(heights[i]);
            temp.push_back(count+1);
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};
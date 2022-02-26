class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) 
    {
        vector<int> answer;
        int days=temp.size()-1;
        stack<int> s;
        //cout<<"runs"<<endl;
        for(int i=days;i>=0;i--)
        {
            //cout<<"runs"<<i<<endl;
            if(s.empty())
            {
                //cout<<"runs"<<i<<endl;
                answer.push_back(0);
                s.push(i);
            }
            else
            {
                while(!s.empty() and temp[s.top()]<=temp[i])
                {
                    s.pop();
                }
                if(s.empty())
                    answer.push_back(0);
                else  
                    answer.push_back(s.top()-i);
                s.push(i);
            }
            
        }
        reverse(answer.begin(),answer.end());
        return answer;
        
    }
};
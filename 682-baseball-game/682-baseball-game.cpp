class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        stack<int> s;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i]=="+")
            {
                int a=s.top();
                s.pop();
                int b=s.top();
                s.push(a);
                s.push(a+b);
            }
            else if(ops[i]=="C")
                s.pop();
            else if(ops[i]=="D")
            {
                s.push(s.top()*2);
            }
            else
            {
                s.push(stoi(ops[i]));
            }
        }
        int sum=0;
        while(!s.empty())
        {
            sum+=s.top();
            s.pop();
        }
        return sum;
        
    }
};
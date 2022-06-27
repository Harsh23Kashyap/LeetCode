class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& preq) 
    {
        unordered_map<int,vector<int>> u;
        unordered_map<int,int> degree;
        for(int i=0;i<numCourses;i++)
            degree[i]=0;
        for(vector<int> p:preq)
        {
            u[p[1]].push_back(p[0]);
            degree[p[0]]++;
        }
        //queue<int> top;
        queue<int> temp;
        for(auto it:degree)
        {
            //cout<<it.first<<" "<<it.second<<endl;
            if(it.second==0)
                temp.push(it.first);
        }
        
        int cnt=0;
        while(!temp.empty())
        {
            int k=temp.front();
            //cout<<k<<endl;
            temp.pop();
            vector<int> check=u[k];
            for(int i:check)
            {
                if(--degree[i]==0)
                    temp.push(i);
            }
            cnt++;
            
        }
        //cout<<cnt<<endl;
        return cnt==numCourses;
        
        
        
        
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
         vector<vector<pair<int,int>>> vec(n+1);
        
        for(int i=0;i<times.size();i++)
        {
           int j = times[i][0];
           vec[j].push_back({times[i][1],times[i][2]}); 
        }
        
        vector<int> signal(n+1,INT_MAX);
        queue<int> q;
        q.push(k);
        signal[k] = 0;
        
        while (!q.empty()) 
        {
            int currNode = q.front(); 
            q.pop();
            
       
            for (pair<int,int> p : vec[currNode]) 
            {
                int time = p.second;
                int neighbor = p.first;
                
                int arrival = signal[currNode] + time;
                if (signal[neighbor] > arrival) 
                {
                    signal[neighbor] = arrival;
                    q.push(neighbor);
                }
            
            }
        }
        
        int maxi = 0;
        for(int i =1;i<=n;i++)
        {
            
            if(signal[i]==INT_MAX)
                return -1;
        
            maxi = max(maxi,signal[i]);
            
        }
                
        return maxi;

    }
        
    
};
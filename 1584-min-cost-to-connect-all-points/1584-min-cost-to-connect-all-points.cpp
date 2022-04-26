typedef pair<int,pair<int,int>> pi;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) 
    {
        int n=points.size();
        vector<vector<int>> adj( n , vector<int> (n, 0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                adj[i][j]=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
            }
        }
        
        
        
        vector<pair<int,int>> visited;
        
        int cost=0;
        //Prism
        int vertex=1;
        priority_queue<pi,vector<pi>, greater<pi>> pq;
        for(int i=0;i<n;i++)
            pq.push(make_pair(adj[0][i],make_pair(points[i][0],points[i][1])));
        
        // while(!pq.empty())
        // {
        //     pair<int,int> p1=pq.top().second;
        //    cout<<p1.first<<","<<p1.second<<"  -> "<<pq.top().first<<endl;
        //     pq.pop();
        // }
        visited.push_back(make_pair(points[0][0],points[0][1]));
        while(vertex!=n)
        {
            pair<int,pair<int,int>> temp;
            pair<int,int> p1;
            while(true)
            {
                temp=pq.top();
                p1=temp.second;
                int c=temp.first;
                if(find(visited.begin(),visited.end(),p1)==visited.end())
                {
                    //cout<<p1.first<<","<<p1.second<<"  -> "<<c<<endl;
                    pq.pop();
                    visited.push_back(p1);
                    cost+=c;
                    break;
                }
                else
                {
                    pq.pop();
                    
                }
            }
            int ind;
            for(ind=0;ind<n;ind++)
            {
                if(points[ind][0]==p1.first and points[ind][1]==p1.second)
                    break;
            }
            for(int i=0;i<n;i++)
                pq.push(make_pair(adj[ind][i],make_pair(points[i][0],points[i][1])));
            vertex++;
        
        }
        return cost;
        
        
        
    }
};
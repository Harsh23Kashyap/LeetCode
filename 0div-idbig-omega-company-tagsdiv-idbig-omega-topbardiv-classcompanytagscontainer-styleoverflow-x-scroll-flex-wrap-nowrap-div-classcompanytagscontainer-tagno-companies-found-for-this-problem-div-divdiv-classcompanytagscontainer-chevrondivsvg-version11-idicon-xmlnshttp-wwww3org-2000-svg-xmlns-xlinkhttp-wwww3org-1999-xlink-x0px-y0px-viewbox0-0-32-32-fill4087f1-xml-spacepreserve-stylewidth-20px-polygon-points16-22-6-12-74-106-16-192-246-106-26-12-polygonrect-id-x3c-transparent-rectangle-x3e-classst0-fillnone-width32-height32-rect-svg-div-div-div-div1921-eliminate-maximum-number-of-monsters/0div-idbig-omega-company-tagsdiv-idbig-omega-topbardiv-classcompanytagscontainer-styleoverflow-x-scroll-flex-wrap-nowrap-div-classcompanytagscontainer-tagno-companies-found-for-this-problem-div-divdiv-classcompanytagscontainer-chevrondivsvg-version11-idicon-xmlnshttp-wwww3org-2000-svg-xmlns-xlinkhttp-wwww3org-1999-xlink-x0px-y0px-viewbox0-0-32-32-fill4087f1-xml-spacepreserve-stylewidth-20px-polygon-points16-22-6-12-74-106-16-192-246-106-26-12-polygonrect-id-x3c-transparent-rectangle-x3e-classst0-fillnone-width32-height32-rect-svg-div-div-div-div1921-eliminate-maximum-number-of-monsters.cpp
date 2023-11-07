class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        vector<float> time;
        
        for(int i=0;i<dist.size();i++)
        {
            time.push_back(dist[i]*1.0/speed[i]);
        }
        int ans=0;
        sort(time.begin(),time.end());
        for(int i=0;i<time.size();i++)
        {
           if(i>=time[i])
               break;
            ans++;
        }
        
        return ans;
    }
};
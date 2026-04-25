class Solution {
public:
    vector<long long> pass(vector<vector<int>>& points,int side){
        vector<long long> single;
        for(auto it:points){
            
            if(it[1]==0)
            single.push_back(it[0]);

            else if(it[0]==side)
                single.push_back(side+it[1]);
            
            else if(it[1]==side)
                single.push_back(3ll*side-it[0]);
            
            else
                single.push_back(4ll*side-it[1]);

        }

        sort(single.begin(),single.end());
        int n=single.size();
        for(int i=0;i<n;i++)
            single.push_back(single[i]+side*4ll);

        return single;
    }

    bool can(int d,vector<long long> &single, int k, int side ){

        vector<long long> nxt(single.size());

        for(int i=0;i<single.size();i++)
            nxt[i]=lower_bound(single.begin(),single.end(),single[i]+d)-single.begin();
        

        for(int i=0;i<single.size()/2;i++){
            int c=1;
            long long curr=i;

            for(int step=1;step<k;step++){
                curr=nxt[curr];
                if(curr>=i+single.size()/2){
                    break;
                }
                c++;
            }

            if(c==k){
                long long first = single[i];
                long long last = single[curr];

                if (4ll*side - (last - first) >= d)
                    return true;
            }
        }
        return false;
    }
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> single=pass(points,side);

        long long l=0,h=4ll*side;
        int ans=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(can(m,single,k,side)){
                ans=m;
                l=m+1;
            }
            else
                h=m-1;
        }
        return ans;
    }
};
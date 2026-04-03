class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        //Great questions
        //first sort
        sort(walls.begin(),walls.end());
        unordered_set<int> uu(walls.begin(),walls.end());

        vector<pair<int,int>> rr;
        for(int i=0;i<robots.size();i++)
            rr.push_back({robots[i],distance[i]}); 

        int n=rr.size();
        //sort and add {robots,walls}
        sort(rr.begin(),rr.end());

        //now we want to find for each robot, there left and rigt range
        vector<int> left(n,0);
        vector<int> right(n,0);

        //now for each robot left is there left range or +1 or the previous robots rigt range and same with right
        for(int i=0;i<rr.size();i++){
            int ld=rr[i].first-rr[i].second;
            int rd=rr[i].first+rr[i].second;
            if(i>0)
                ld=max(ld,rr[i-1].first);
            if(i<rr.size()-1)
                rd=min(rd,rr[i+1].first);
            left[i]=ld;
            right[i]=rd;
        }


        //Now traverse;
        vector<vector<int>> dp(n, vector<int> (2,-1));
        //for robot 0 noting to its left;
        dp[0][0]= upper_bound(walls.begin(),walls.end(), rr[0].first)-lower_bound(walls.begin(),walls.end(),left[0]);
        dp[0][1]=upper_bound(walls.begin(),walls.end(), right[0])-lower_bound(walls.begin(),walls.end(),rr[0].first);

        for(int i=1;i<n;i++){

            //when we try for right, we are basically free as we will handle in next for oevrlap

            int rwalls=upper_bound(walls.begin(),walls.end(), right[i]  )-lower_bound(walls.begin(),walls.end(),rr[i].first);
            //two case prev left this right
            int rcond1=dp[i-1][0]+rwalls;
            //prev rigt this right, overlap can happen at ronbot idnex
            int overlapr=0;
            if(right[i-1]>=rr[i].first and uu.find(rr[i].first)!=uu.end())
                overlapr=1;
            int rcond2=dp[i-1][1]-overlapr+rwalls;

            dp[i][1]=max(rcond1,rcond2);

            //when we look at left /multiple cases
            //when we do left and previous is left, then  issues of overlap at robot[i-1]
            int lwalls=upper_bound(walls.begin(),walls.end(), rr[i].first)-lower_bound(walls.begin(),walls.end(),left[i]);
            int overlapl=0;
            if(left[i]<=rr[i-1].first and uu.find(rr[i-1].first)!=uu.end())
                overlapl=1;
            int lcond2=dp[i-1][0]-overlapl+lwalls;

            //second is when prev also shoots right and this robots shoots left, overlap chances
            int overlapr2=0;
            if(right[i-1]>=left[i])
           overlapr2=upper_bound(walls.begin(),walls.end(), right[i-1])-lower_bound(walls.begin(),walls.end(),left[i]);
            int lcond1=dp[i-1][1]-overlapr2+lwalls;

            dp[i][0]=max(lcond1,lcond2);

        }
        return max(dp.back()[0],dp.back()[1]);



        
    }
};
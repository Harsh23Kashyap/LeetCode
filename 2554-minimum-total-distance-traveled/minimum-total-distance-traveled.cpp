class Solution {
public:
 /*
        what i understand, it not greedy, there can be case that making the robot move t close factory is not optimal
        the reason is f we move to robot x to factory a can be scenario where two more robots wouldve been better by allocation to factory a. 

        //it is possible to repair every robot, 

        so for every robot we allocate the rbots to each place and see

        lets odo dfs


        */
    
    // int n=
    // long long pass(int i, int j,vector<int>& robot,unordered_map<int,int> u){
    //     if(i==robot.size())
    //         return 0;
        
    //     if(j==n)
    //         return -1;

    //     if(u[j]==0)
    //     j++;
        

    //     //now first is moving to the best left which is on left;
    //     auto it=u.lower_bound(i);
    //     //element found at i;
    //     // so we will choose on left max of j and left to see of some lemnets are there or not
    //     int l=max(j,)
    //     /then same way rigvht

    //     // and do max


    // }
    long long pass(int i, int j, int rc, vector<int>& robot, vector<vector<int>>& factory, vector<vector<vector<long long>>> &dp){
        if(i==robot.size())
            return 0;
        if(j==factory.size())
            return 1e15;
        

        if(dp[i][j][rc]!=-1)
            return dp[i][j][rc];

        
        //use the current j factory for our work
        long long take=1e15;
        if(rc>0)
        { 
            take=llabs(robot[i]-factory[j][0])+pass(i+1,j,rc-1,robot,factory,dp); 
        }
        //skip this factory
        long long skip=1e15;
        if(j+1<factory.size()){
             skip=pass(i,j+1,factory[j+1][1],robot,factory,dp);
        }

        return dp[i][j][rc]=min(take,skip);




    }
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        vector<vector<vector<long long>>> dp(robot.size(), vector<vector<long long>> (factory.size(),vector<long long> (robot.size()+1,-1)));

        return pass(0, 0, factory[0][1], robot, factory, dp);
    }
};
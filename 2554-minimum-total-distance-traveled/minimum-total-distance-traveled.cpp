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
   long long dp[101][101]; // constraints are small (<=100)

    long long pass(int i, int j, vector<int>& robot, vector<vector<int>>& factory) {
        if (i == robot.size()) return 0;
        if (j == factory.size()) return 1e15;

        if (dp[i][j] != -1) return dp[i][j];

        long long res = 1e15;
        long long cost = 0;

        for (int k = 0; k <= factory[j][1]; k++) {
            if (i + k > robot.size()) break;

            if (k > 0)
                cost += abs(robot[i + k - 1] - factory[j][0]);

            res = min(res, cost + pass(i + k, j + 1, robot, factory));
        }

        return dp[i][j] = res;
    }

    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        memset(dp, -1, sizeof(dp));

        return pass(0, 0, robot, factory);
    }
};
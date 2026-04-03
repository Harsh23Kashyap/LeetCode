class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance, vector<int>& walls) {
        sort(walls.begin(),walls.end());
        unordered_set<int> uu(walls.begin(),walls.end());
        vector<pair<int,int>> rr;
        for(int i=0;i<robots.size();i++)
            rr.push_back({robots[i],distance[i]});

        int n=rr.size();
        sort(rr.begin(),rr.end());

        vector<int> left(n,0);
        vector<int> right(n,0);

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

        vector<vector<int>> dp(n, vector<int> (2,-1));
        dp[0][0]= upper_bound(walls.begin(),walls.end(), rr[0].first )-lower_bound(walls.begin(),walls.end(),left[0]);
        dp[0][1]= upper_bound(walls.begin(),walls.end(), right[0] )-lower_bound(walls.begin(),walls.end(),rr[0].first);

        for(int i=1;i<n;i++)
        {
 
            int rightcount = upper_bound(walls.begin(),walls.end(), right[i])-lower_bound(walls.begin(),walls.end(),rr[i].first);

            // BUG 2: You assumed shooting right is "basically free". But if prev also shot Right, 
            // they can overlap exactly at rr[i].first. We must subtract that overlap.
            int overlapR = 0;
            if (rr[i].first <= right[i-1] and uu.find(rr[i].first)!=uu.end()) {  
                overlapR = 1;
            }
            
            // Compare [Prev Left + Right] vs [Prev Right - Overlap + Right]
            dp[i][1]=max(dp[i-1][0] + rightcount, dp[i-1][1] - overlapR + rightcount);


            // --- LEFT LOGIC ---
            // BUG 1: Removed the "+ 1" from rr[i].first + 1
            int leftcount=upper_bound(walls.begin(),walls.end(), rr[i].first)-lower_bound(walls.begin(),walls.end(),left[i]);
            
            // BUG 3: "when we do left and previous is left, then no issues" -> WRONG.
            // They both stop/start exactly at rr[i-1].first. So if there's a wall exactly there, it's double-counted.
            int overlapLL = 0;
            if (left[i] <= rr[i-1].first) { // Guard prevents negative iterator crossing
                overlapLL = upper_bound(walls.begin(),walls.end(), rr[i-1].first)-lower_bound(walls.begin(),walls.end(),left[i]);
            }
            int lcond=dp[i-1][0] - overlapLL + leftcount;

            // BUG 4: Prevent iterators crossing causing negative numbers!
            // If left[i] > right[i-1], upper_bound - lower_bound is NEGATIVE, causing you to ADD walls.
            // Also removed the "+ 1" from right[i-1] + 1
            int overlapLR = 0;
            if (left[i] <= right[i-1]) { // Guard prevents negative iterator crossing
                overlapLR=upper_bound(walls.begin(),walls.end(), right[i-1])-lower_bound(walls.begin(),walls.end(),left[i]);
            }
            int lcond2=dp[i-1][1] - overlapLR + leftcount;

            dp[i][0]=max(lcond,lcond2);
        }
        
        return max(dp.back()[0],dp.back()[1]);
    }
};
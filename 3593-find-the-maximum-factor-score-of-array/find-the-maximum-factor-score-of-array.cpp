class Solution {
public:
    long long gcd(long long a, long long b) {
        if(b==0)
        return a;

        return gcd(b,a%b);
    }

    long long maxScore(vector<int>& nums) {
        int n = nums.size();

        long long maxi = 0;
        long long fullGCD = 0, fullLCM = 1;
        for (int i = 0; i < n; i++) {
            fullGCD = gcd(fullGCD, nums[i]);
            fullLCM = fullLCM * nums[i] / gcd(fullLCM, nums[i]);
        }
        maxi = fullGCD * fullLCM;

        for (int i = 0; i < n; i++) 
        {
            long long chcf = 0, clcm = 1;
            for (int j = 0; j < n; j++) {
                if (j == i) continue;
                chcf = gcd(chcf, nums[j]);
                clcm = clcm * nums[j] / gcd(clcm, nums[j]);
            }
            maxi = max(maxi, chcf * clcm);
        }

        return maxi;
    }
};

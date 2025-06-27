class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long s1 = 0, s2 = 0;
        int z1 = 0, z2 = 0;

        for (int x : nums1) {
            if (x == 0) z1++;
            else s1 += x;
        }

        for (int x : nums2) {
            if (x == 0) z2++;
            else s2 += x;
        }

        long long min1 = s1 + z1;
        long long min2 = s2 + z2;

        if (min1 > min2 && z2 == 0) return -1;
        if (min2 > min1 && z1 == 0) return -1;

        return max(min1, min2);
    }
};

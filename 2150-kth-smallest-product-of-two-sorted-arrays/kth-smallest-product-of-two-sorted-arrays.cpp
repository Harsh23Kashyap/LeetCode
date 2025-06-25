class Solution {
public:
    long long ceilDiv(long long a, long long b) {
        if (b > 0) return (a + b - 1) / b;
        else return (a + b + 1) / b;
    }
    long long floorDiv(long long a, long long b) {
    if (b > 0) return a / b;
    else return a / b;
}

    long long count(vector<int>& nums1, vector<int>& nums2, long long k) 
    {
        long long c = 0;

        for (int it : nums1) {
            if (it == 0) {
                if (k >= 0) c += nums2.size();
                continue;
            } 

            int low = 0, high = nums2.size()-1;
            while (low <= high) {
                int mid = (low + high) / 2;
                long long prod = 1LL * it * nums2[mid];
                if (prod <= k) {
                    if (it > 0) low = mid + 1;
                    else high = mid - 1;
                } else {
                    if (it > 0) high = mid-1;
                    else low = mid + 1;
                }
            }

            c += (it > 0) ? low : (nums2.size() - low);
        }

        return c;
    }

    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        long long low = -1e10, high = 1e10;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            cout<<mid<<endl;
            if (count(nums1, nums2, mid) >= k) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};

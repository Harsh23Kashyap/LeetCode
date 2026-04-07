class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> u;

        int s = 0; // prefix sum (count of odds)
        int c = 0;

        for(int i = 0; i < nums.size(); i++) {
            int it = nums[i];
            int curr = it % 2;

            s += curr;

            // cout << "Index: " << i 
            //      << ", Num: " << it 
            //      << ", curr(odd?): " << curr 
            //      << ", prefixSum(s): " << s << "\n";

            if(s == k) {
                c++;
                // cout << "  -> s == k, increment count, c = " << c << "\n";
            }

            if(u.find(s - k) != u.end()) {
                c += u[s - k];
            //     cout << "  -> found (s-k)=" << s-k 
            //          << " in map with freq " << u[s-k] 
            //          << ", updated c = " << c << "\n";
            }

            u[s]++;
            // cout << "  -> updated map: u[" << s << "] = " << u[s] << "\n";

            // cout << "-------------------------\n";
        }

        cout << "Final count: " << c << "\n";
        return c;
    }
};
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b) {
            return a[1] > b[1];
        });
        
        int totalUnits = 0;
        
        for (auto &box : boxTypes) {
            if (truckSize == 0) break;
            
            int boxesToTake = min(box[0], truckSize);
            totalUnits += boxesToTake * box[1];
            truckSize -= boxesToTake;
        }
        
        return totalUnits;
    }
};
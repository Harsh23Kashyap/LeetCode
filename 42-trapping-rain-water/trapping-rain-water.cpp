class Solution {
public:
    int trap(vector<int>& height) {

        int n = height.size();

        int i = 0;
        int j = n - 1;

        int leftMax = 0;
        int rightMax = 0;

        int water = 0;

        while(i < j) {

            // process left side
            if(height[i] < height[j]) {

                if(height[i] >= leftMax) {
                    leftMax = height[i];
                }
                else {
                    water += leftMax - height[i];
                }

                i++;
            }

            // process right side
            else {

                if(height[j] >= rightMax) {
                    rightMax = height[j];
                }
                else {
                    water += rightMax - height[j];
                }

                j--;
            }
        }

        return water;
    }
};
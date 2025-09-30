class Solution {
    public int triangularSum(int[] nums) {
         while(true){
            if(nums.length==1)
                return nums[0]%10;
                int[] sumdp= new int[nums.length-1];
                for(int j=0;j<nums.length-1;j++){
                    sumdp[j]=(nums[j]+nums[j+1])%10;
                }
                if(sumdp.length==1){
                return sumdp[0];
                }

                nums=sumdp;
            }
            // return -1;
        }
    }

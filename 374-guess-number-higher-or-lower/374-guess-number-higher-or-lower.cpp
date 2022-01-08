/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) 
    {
        long start=1;
        long end=n;
        long mid;
        while(start<=end)
        {
            mid=(start+end)/2;
            int res= guess(mid);
                if(res==0) return mid;
            else if(res==1)start=mid+1;
            else end=mid-1;
        }
        return -1;
    }
};
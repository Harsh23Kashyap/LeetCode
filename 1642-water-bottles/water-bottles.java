class Solution {
    public int numWaterBottles(int numBottles, int numExchange) {
        int rem=0;
        int c=0;
        while(numBottles>0){
            c+=numBottles;
            int newNumBottles=(numBottles+rem)/numExchange;
            rem= (numBottles+rem)%numExchange;
            numBottles= newNumBottles;
        }
        return c;
    }
}
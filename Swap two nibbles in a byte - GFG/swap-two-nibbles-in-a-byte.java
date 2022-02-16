// { Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while(t-- > 0)
        {
            int N = Integer.parseInt(read.readLine());
            Solution ob = new Solution();
            System.out.println(ob.swapNibbles(N));
        }
    }
}// } Driver Code Ends


//User function Template for Java
class Solution{
    static int swapNibbles(int N) 
    {
        int a= (N<<4) & 240;
        int b= (N>>4) & 15;
        return a|b;
    }
}
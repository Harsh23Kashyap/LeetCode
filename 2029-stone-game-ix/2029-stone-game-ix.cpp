// class Solution {
// public:
//     bool stoneGameIX(vector<int>& stones) 
//     {
//         int sum=0;
//         if(stones.size()==1 and stones[0]%3==0)
//             return false;
//         unordered_map<int,int> u;
//         for(int i:stones)
//             u[i%3]++;
        
//         if(u.find(2)!=u.end() and u[2]--)
//             sum+=2;
//         else if(u.find(1)!=u.end() and u[1]--)
//             sum+=1;
//         else
//             return false;
//         //cout<<sum<<endl;
//         int c=1;
//         while(c!=stones.size() and sum%3!=0)
//         {
//             cout<<((c%2==0)?"Alice":"Bob");
            
//             c++;
//             int mod=sum%3;
//             if(mod==1)
//             {
//                 if(u.find(1)!=u.end() and u[1]-->0)
//                     sum+=1;
//                 else if(u.find(0)!=u.end() and u[0]-->0)
//                     sum+=0;
//                 else
//                 {
//                     if(c%2==0)
//                         return true;
//                     else 
//                         return false;
//                 }
//             }
//             else if(mod==2)
//             {
//                 if(u.find(2)!=u.end() and u[2]-->0)
//                     sum+=2;
//                 else if(u.find(0)!=u.end() and u[0]-->0)
//                     sum+=0;
//                 else
//                 {
//                     //cout<<"rns";
//                     if(c%2==0)
//                         return true;
//                     else 
//                         return false;
//                 }
//             }
//             cout<<sum<<endl;
//         }
//         if(c==stones.size())
//         {
//             if(sum%3==0 and c%2==0)
//                 return true;
//             return false;
//         }
//         if(c%2==0)
//             return true;
//         return false;
//     }
// };
class Solution
{
  public:
    bool get(vector<int> mod, int n, int k)
    {
        if (mod[k] < 1)
            return false;
        mod[k]--;
        int sum = k;
        for (int i = 1; i < n; i++)
        {
            //cout<<((i%2==0)?"Alice":"Bob");
            if (mod[1] && (sum + 1) % 3 != 0)
                mod[1]--, sum += 1;
            else if (mod[2] && (sum + 2) % 3 != 0)
                mod[2]--, sum += 2;
            else if (mod[0] > 0 && (sum) % 3 != 0)
                mod[0]--;
            else
                return i & 1;
            //cout<<sum<<endl;
        }
        return false;
    }

    bool stoneGameIX(vector<int> &v)
    {
        vector<int> mod(3);
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            mod[v[i] % 3]++;
        }
        return get(mod, n, 2) || get(mod, n, 1);
    }
};
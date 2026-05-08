class Solution {
public:

    bool isPrime(int a){

        if(a <= 1)
            return false;

        for(int i = 2; i * i <= a; i++){

            if(a % i == 0)
                return false;
        }

        return true;
    }

    int minJumps(vector<int>& nums) {
 
        unordered_map<int, bool> prime;
            unordered_map<int, vector<int>> u;

            for(int i = 0; i < nums.size(); i++){

                int x = nums[i];

                for(int d = 2; d * d <= x; d++){

                    if(x % d == 0){

                        if(isPrime(d))
                            u[d].push_back(i);

                        while(x % d == 0)
                            x /= d;
                    }
                }

                if(x > 1)
                    u[x].push_back(i);
            }

        queue<int> q;
        unordered_set<int> vis;
        unordered_set<int> usedPrime;

        q.push(0);
        vis.insert(0);

        int curr = 0;

        while(!q.empty()){

            int sz = q.size();

            while(sz--){

                int it = q.front();
                q.pop();

                if(it == nums.size() - 1)
                    return curr;

                // right
                if(it + 1 < nums.size() &&
                   vis.find(it + 1) == vis.end()){

                    q.push(it + 1);
                    vis.insert(it + 1);
                }

                // left
                if(it - 1 >= 0 &&
                   vis.find(it - 1) == vis.end()){

                    q.push(it - 1);
                    vis.insert(it - 1);
                }

                // prime jumps
                if(isPrime(nums[it]) &&
                   usedPrime.find(nums[it]) == usedPrime.end()){

                    for(auto k : u[nums[it]]){

                        if(vis.find(k) == vis.end()){

                            vis.insert(k);
                            q.push(k);
                        }
                    }

                    usedPrime.insert(nums[it]);
                }
            }

            curr++;
        }

        return -1;
    }
};
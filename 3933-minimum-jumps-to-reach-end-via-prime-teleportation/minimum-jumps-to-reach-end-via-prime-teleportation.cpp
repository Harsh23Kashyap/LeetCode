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

        int n = nums.size();

        unordered_map<int, vector<int>> mp;

        // preprocess
        for(int i = 0; i < n; i++){

            for(int d = 2; d * d <= nums[i]; d++){

                if(nums[i] % d == 0){

                    if(isPrime(d))
                        mp[d].push_back(i);

                    int other = nums[i] / d;

                    if(other != d && isPrime(other))
                        mp[other].push_back(i);
                }
            }

            if(isPrime(nums[i]))
                mp[nums[i]].push_back(i);
        }

        queue<int> q;
        vector<int> vis(n, 0);

        q.push(0);
        vis[0] = 1;

        int steps = 0;

        while(!q.empty()){

            int sz = q.size();

            while(sz--){

                int it = q.front();
                q.pop();

                if(it == n - 1)
                    return steps;

                // right
                if(it + 1 < n && !vis[it + 1]){

                    vis[it + 1] = 1;
                    q.push(it + 1);
                }

                // left
                if(it - 1 >= 0 && !vis[it - 1]){

                    vis[it - 1] = 1;
                    q.push(it - 1);
                }

                // prime teleport
                if(isPrime(nums[it])){

                    int p = nums[it];

                    for(int nxt : mp[p]){

                        if(!vis[nxt]){

                            vis[nxt] = 1;
                            q.push(nxt);
                        }
                    }

                    // IMPORTANT
                    mp[p].clear();
                }
            }

            steps++;
        }

        return -1;
    }
};
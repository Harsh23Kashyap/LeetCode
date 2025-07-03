class Solution {
public:

    bool isValid(int seatMask, int studentMask) 
    {
        return  !(studentMask & (studentMask >> 1)) ;
    }

    bool noCheating(int currMask, int prevMask) {
        if (currMask & (prevMask >> 1)) 
            return false; 
        if (currMask & (prevMask << 1)) 
            return false; 
        return true;
    }

    int maxStudents(vector<vector<char>>& seats) {
        int m = seats.size();
        int n = seats[0].size();

        vector<int> seatMasks(m); 
        for (int i = 0; i < m; i++) {
            int mask = 0;
            for (int j = 0; j < n; j++) {
                if (seats[i][j] == '.') 
                    mask |= (1 << j);
            }
            seatMasks[i] = mask;
        }

        unordered_map<int, int> prevDP;
        prevDP[0] = 0; // no one seated yet

        for (int r = 0; r < m; r++) 
        {
            unordered_map<int, int> currDP;
            for (int studentMask = seatMasks[r];studentMask>=0;studentMask=(studentMask-1)&seatMasks[r]) 
            {
                if (!isValid(seatMasks[r], studentMask)) 
                    continue;

                int count = __builtin_popcount(studentMask);

                for (auto [prevMask, prevCount] : prevDP) 
                {
                    if (!noCheating(studentMask, prevMask)) 
                        continue;

                    currDP[studentMask] = max(currDP[studentMask], prevCount + count);
                }
                if(studentMask==0)
                break;
            }


            prevDP = currDP;
        }

        int ans = 0;
        for (auto it : prevDP) {
            ans = max(ans, it.second);
        }
        return ans;
    }
};

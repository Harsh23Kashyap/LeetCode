class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<int> st;
        int prevTime = 0;

        for (string log : logs) {
            int id = 0, i = 0;
             
            while (log[i] != ':') {
                id = id * 10 + (log[i] - '0');
                i++;
            }
            i++; 
            bool isStart = (log[i] == 's');  
            i += isStart ? 6 : 4;  
 
            int time = 0;
            while (i < log.size()) {
                time = time * 10 + (log[i] - '0');
                i++;
            }

            if (isStart) {
                if (!st.empty()) {
                    ans[st.top()] += time - prevTime;
                }
                st.push(id);
                prevTime = time;
            } else {
                ans[st.top()] += time - prevTime + 1;
                st.pop();
                prevTime = time + 1;
            }
        }

        return ans;
    }
};
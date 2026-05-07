class Solution {
public:

    vector<int> exclusiveTime(int n, vector<string>& logs) {

        vector<int> ans(n, 0);

        // {id, type, timestamp}
        stack<tuple<int,string,int>> st;

        for(string log : logs) {

            int first = log.find(':');
            int second = log.find(':', first + 1);

            int id =
                stoi(log.substr(0, first));

            string type =
                log.substr(first + 1,
                           second - first - 1);

            int timestamp =
                stoi(log.substr(second + 1));

            // START
            if(type == "start") {

                // pause currently running process
                if(!st.empty()) {

                    auto [prevId, prevType, prevTime]
                        = st.top();

                    st.push({prevId, "end", timestamp});
                }

                st.push({id, "start", timestamp});
            }

            // END
            else {

                auto [currId, currType, startTime]
                    = st.top();

                st.pop();

                // complete current process
                ans[currId] +=
                    timestamp - startTime + 1;

                // process paused parent
                if(!st.empty()) {

                    auto [endId, endType, endTime]
                        = st.top();

                    st.pop();

                    auto [startId, startType, startTime2]
                        = st.top();

                    st.pop();

                    ans[startId] +=
                        endTime - startTime2;

                    // restart parent
                    st.push({
                        startId,
                        "start",
                        timestamp + 1
                    });
                }
            }
        }

        return ans;
    }
};
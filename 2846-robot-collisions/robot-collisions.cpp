class Solution {
public:
    typedef pair<vector<int>, char> pp;

    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pp> v;
        int n = positions.size();

        // Build initial vector
        for (int i = 0; i < n; i++) {
            v.push_back({{positions[i], healths[i], i}, directions[i]});
        }

        // Sort by position
        sort(v.begin(), v.end());  

        stack<pp> st;

        for (int i = 0; i < n; i++) {
            auto nit = v[i];
            int npos = nit.first[0];
            int nh = nit.first[1];
            int nind = nit.first[2];
            char ndir = nit.second;
 
            while (!st.empty()) {
                auto tit = st.top();
                int tpos = tit.first[0];
                int th = tit.first[1];
                int tind = tit.first[2];
                char tdir = tit.second;
 
                // Only valid collision case
                if (tdir == 'R' && ndir == 'L') { 

                    if (th == nh) { 
                        st.pop();
                        nh = 0;
                        break;
                    }
                    else if (th > nh) { 
                        st.pop();
                        st.push({{tpos, th - 1, tind}, tdir});
                        nh = 0;
                        break;
                    }
                    else { 
                        st.pop();
                        nh = nh - 1;
                        // continue to next stack robot (chain collision)
                    }
                } else { 
                    break;
                }
            }

            // Push only if alive
            if (nh > 0) { 
                st.push({{npos, nh, nind}, ndir});
            }
 
        }

        vector<pair<int,int>> res;

        while (!st.empty()) {
            auto it = st.top();
            st.pop(); 
            res.push_back({it.first[2], it.first[1]});
        }

        sort(res.begin(), res.end());

        vector<int> cc;
        for (auto it : res) {
            cc.push_back(it.second);
        }
  

        return cc;
    }
};
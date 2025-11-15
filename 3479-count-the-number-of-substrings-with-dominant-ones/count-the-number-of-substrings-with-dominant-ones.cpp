class Solution {
public:
    int numberOfSubstrings(string s) {
            int n = s.size();
    vector<int> zeros;      // store indices of zeros
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            zeros.push_back(i);

    int Z = zeros.size();
    int maxZ = sqrt(n) + 2;   // Z_limit = sqrt(n)

    vector<int> pref1(n+1, 0);
    for (int i = 0; i < n; i++)
        pref1[i+1] = pref1[i] + (s[i] == '1');

    long long ans = 0;

    // -------------------------
    // Case Z = 0  (all-ones substrings)
    // -------------------------
    {
        long long run = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') run++;
            else {
                ans += run * (run + 1) / 2;
                run = 0;
            }
        }
        ans += run * (run + 1) / 2;
    }

    // -------------------------
    // Z = 1 to sqrt(n)
    // -------------------------
    for (int z = 1; z <= maxZ && z <= Z; z++) {
        long long needLen = 1LL * z * z + z;   // L >= z² + z

        // Slide through blocks of exactly z zeros
        for (int i = 0; i + z - 1 < Z; i++) {

            int leftZero = zeros[i];
            int rightZero = zeros[i + z - 1];

            // Count left extension
            int leftLimit = (i == 0 ? 0 : zeros[i - 1] + 1);
            int leftChoices = leftZero - leftLimit;

            // Count right extension
            int rightLimit = (i + z == Z ? n - 1 : zeros[i + z] - 1);
            int rightChoices = rightLimit - rightZero;

            long long coreLen = rightZero - leftZero + 1;

            // Need:
            // coreLen + Lext + Rext >= needLen
            // → Rext >= needLen - coreLen - Lext

            for (int Lext = 0; Lext <= leftChoices; Lext++) {
                long long minR = needLen - coreLen - Lext;
                if (minR <= 0) {
                    // All right extensions valid
                    ans += (rightChoices + 1);
                } else if (minR <= rightChoices) {
                    ans += (rightChoices - minR + 1);
                }
            }
        }
    }

    return ans;
    }
};
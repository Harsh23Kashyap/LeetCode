class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) 
    {
	int n = nums.size();
	int dup=-1, missing=-1;
	unordered_map<int,int> mpp;
	for(int x: nums) {
		mpp[x] = mpp[x]+1;
	}
	for(int i=1; i<=n; ++i) {
		if(mpp[i]==2) {
			dup=i;
		}
		if(mpp[i]==0) {
			missing=i;
		}
		if(dup != -1 && missing != -1) {
			return vector<int>{dup,missing};
		}
	}
	return vector<int>{dup,missing};
}
};
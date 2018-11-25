static const int desync_io = []() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	return 0;
}();

class Solution {
public:
	vector<int> findDuplicates(vector<int>& nums) {
		int n{ static_cast<int>(nums.size()) };
		vector<int> d;
		d.reserve(n);
		for (int i = 0; i < nums.size();++i)
		{
			int index = abs(nums[i]) - 1;
			if (nums[index] < 0) //found you, dublicatemy old friend
				d.push_back(index + 1);
			else
				nums[index] *= -1;
		}

		// for(int i = 0; i < nums.size();++i) //to undo the changes
		//         nums[i] = abs(nums[i]);
		return d;
	}
};


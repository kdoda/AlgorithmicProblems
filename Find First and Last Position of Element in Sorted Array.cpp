class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target)
	{
		vector<int> pos(2);
		pos[0] = find(nums, target, true);
		pos[1] = pos[0] == -1 ? -1 : find(nums, target, false);

		return pos;
	}
	int find(vector<int>& nums, int target, bool first)
	{
		int l = 0;
		int r = nums.size() - 1;
		int index = -1;
		while (l <= r)
		{
			int m = (r + l) / 2;
			if (nums[m] == target)
			{
				index = m;
				first ? r = m - 1 : l = m + 1;
			}
			else
			{
				if (nums[m] > target)
					r = m - 1;
				else
					l = m + 1;
			}

		}
		return index;
	}

	//slightly faster more code though
	//     vector<int> searchRange(vector<int>& nums, int target) 
	//     {
	//         vector<int> pos(2);
	//         pos[0] = findMin(nums,target);
	//         pos[1] = pos[0] == -1 ? -1 : findMax(nums,target);

	//         return pos;
	//     }
	//     int findMax(vector<int>& nums, int target)
	//     {
	// 	    int l = 0;
	// 	    int r = nums.size() - 1;
	// 	    int index = -1;
	// 	    while (l <= r)
	// 	    {
	// 	        int m = (r + l) / 2;
	// 		    if (nums[m] == target)
	// 		    {
	// 			    index = m;
	// 			    l = m+1;
	// 		    }
	// 		    else
	// 		    {
	// 		    	if (nums[m] > target)
	// 		    		r = m - 1;
	// 		    	else
	// 		    		l = m + 1;
	//             }	
	// 	    }
	//     	return index;
	//     }

	//     int findMin(vector<int>& nums, int target)
	//     {
	// 	    int l = 0;
	// 	    int r = nums.size() - 1;
	// 	    int index = -1;
	// 	    while (l <= r)
	// 	    {
	// 	        int m = (r + l) / 2;
	// 		    if (nums[m] == target)
	// 		    {
	// 			    index = m;
	// 			    r = m - 1;
	// 		    }
	// 		    else
	// 		    {
	// 		    	if (nums[m] > target)
	// 		    		r = m - 1;
	// 		    	else
	// 		    		l = m + 1;
	//             }	
	// 	    }
	//     	return index;
	//     }

};
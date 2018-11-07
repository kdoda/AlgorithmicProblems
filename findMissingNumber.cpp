
//Find Missing Number
//Given a contiguous sequence of numbers in which each number repeats thrice, there is exactly one missing number.Find the missing number.
//
//eg: 11122333			: Missing number 2
//    11122233344455666 : Missing number 5

//We can obeserve that for a given index A[3i-1] = i, if 3i-1 is before the missing number 
//else A[3i-1] = i + 1, if 3i-1 is after the missing number, since this always holds true, 
//no matter the position of the array, we can do a binary search on i.
//Time complexity O(log (n/3)) => O(log n)
int missingNumber(const vector<int> & v)
{
	int l = 1;
	int r = v.size() / 3 + 1;

	while (l < r)
	{
		int i = (l + r) / 2;
		int index = 3 * i - 1;
		if (index == v.size())
			break;

		if (v[index] == i) // the missing number is on the right
			l = i + 1;
		else
			r = i;
	}

	return l;
}

int main()
{
	vector<int> v1 = { 1, 1, 1, 2, 2, 3, 3, 3 };
	vector<int> v2 = { 1, 1 };
	vector<int> v3 = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 6, 6, 6 };
	vector<int> v4 = { 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6 };
	vector<int> v5 = { 1, 1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6 };
	cout << missingNumber(v1) << endl; //2
	cout << missingNumber(v2) << endl; //1
	cout << missingNumber(v3) << endl; //5
	cout << missingNumber(v4) << endl; //6
	cout << missingNumber(v5) << endl; //2
}

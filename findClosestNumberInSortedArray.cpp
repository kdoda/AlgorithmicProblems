#include <vector>
#include <iostream>
#include <algorithms>

using namespace std;

//Find closest number in sorted array
//Given an array of sorted integers.We need to find the closest value to the given number.
//Array may contain duplicate values and negative numbers.
//
//Examples:
//
//Input: arr[] = { 1, 2, 4, 5, 6, 6, 8, 9 }
//	Target number = 11
//	Output : 9
//	9 is closest to 11 in given array
//
//Input : arr[] = { 2, 5, 6, 7, 8, 8, 9 };
//	Target number = 4
//	Output : 5

int findClosest(const vector<int> &v, int target)
{
	int minDiff = INT_MAX;
	//array should have at least one element in
	int closestTarget = 0;
	int l = 0;
	int r = v.size() - 1;

	while (l <= r)
	{
		int m = (l + r) / 2;
		if (v[m] == target)
			return target; // { closestTarget = target; break; } if we want one exit point

		int thisDiff = abs(v[m] - target);
		if (thisDiff < minDiff)
		{
			minDiff = thisDiff;
			closestTarget = v[m];
		}

		if (v[m] < target)
			l = m + 1;
		else
			r = m - 1;
	}

	return closestTarget;
}

//different approach recursive, can make it iteratively too
int findClosestRekUtil(const vector<int> &v, int target, int l, int r)
{
	int m = (l + r) / 2;

	//this improves the best case, and makes the worst case worse
	if (v[m] == target)
		return target;

	if (l == r)
		return (abs((l - 1 > 0 ? v[l - 1] : INT_MAX) - target) < abs(v[l] - target))
		? v[l - 1]
		: v[l];


	if (v[m] < target)
		return findClosestRekUtil(v, target, m + 1, r);
	else
		return findClosestRekUtil(v, target, l, m - 1);
}

int findClosestRek(const vector<int> &v, int target)
{
	return findClosestRekUtil(v, target, 0, v.size() - 1);
}

int main()
{
	vector<int> v = { 1,2,4,5,6,6,8,9,200 };
	cout << findClosest(v, 5) << endl; //5
	cout << findClosest(v, 11) << endl; //9
	cout << findClosest(v, -7) << endl; //1
	cout << findClosestRek(v, 5) << endl; //5
	cout << findClosestRek(v, 11) << endl; //9
	cout << findClosestRek(v, -7) << endl; //1
}

class Solution {
public:
	bool** createMatrix(int row, int col)
	{
		bool **m = new bool*[row]; //m rows

		for (int i = 0;i < row;++i)
			m[i] = new bool[col];

		return m;
	}

	//O(m*n) using Dynamic Programming
	bool isMatch(const string & text, const string & pattern)
	{
		int m = text.length();
		int n = pattern.length();

		bool **T = createMatrix(m + 1, n + 1);

		for (int i = 0;i < m;++i)
			for (int j = 0;j < n;++j)
				T[i][j] = false;

		T[0][0] = true;

		//do not remove leading * like the reg expression
		for (int i = 1;i <= n;++i)
		{
			if (pattern[i - 1] == '*')
				T[0][i] = T[0][i - 1]; //because if they are at the beginng they can represent an empty string
		}

		//first col is always false
		for (int i = 1;i <= m;++i)
		{
			for (int j = 1;j <= n;++j)
			{
				if (text[i - 1] == pattern[j - 1] || pattern[j - 1] == '?')
					T[i][j] = T[i - 1][j - 1];
				else if (pattern[j - 1] == '*')
				{
					T[i][j] = T[i][j - 1] || T[i - 1][j];
					// the second: count * as 0
					// the third: count as one or more extend it 
				}
				else //if they are !=
					T[i][j] = false;
			}
		}


		return T[m][n];
	}
};
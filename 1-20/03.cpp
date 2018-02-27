#include <iostream>

class Solution
{
  public:
	/*
     * @param : An integer
     * @param : An integer
     * @return: An integer denote the count of digit k in 1..n
     */
	int digitCounts(int k, int n)
	{
		// write your code here
		int rv = 0;

		for (int i = 0; i <= n; ++i)
		{

			int num = i;

			while (true)
			{

				if (num % 10 == k)
					++rv;

				num /= 10;

				if (num == 0)
					break;
			}
		}

		return rv;
	}
};

int main(int argc, char **argv)
{
	Solution s;

	std::cout << s.digitCounts(1, 12) << std::endl;

	return 0;
}
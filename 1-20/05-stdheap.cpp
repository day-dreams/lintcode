#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

class Solution
{
  public:
	/*
     * @param n: An integer
     * @param nums: An array
     * @return: the Kth largest element
     */
	int kthLargestElement(int n, vector<int> &nums)
	{
		// write your code here
		std::make_heap(nums.begin(), nums.end());

		for (int i = 0; i != n; ++i)
		{
			std::pop_heap(nums.begin(), nums.begin() + nums.size() - i);
		}

		return *(nums.begin() + nums.size() - n);
	}
};
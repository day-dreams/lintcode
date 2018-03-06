#include <vector>

using namespace std;

class Solution
{
  public:
	/**
     * @param nums: a rotated sorted array
     * @return: the minimum number in the array
     */
	int findMin(vector<int> &nums)
	{
		// write your code here
		if (nums.size() == 0)
			return 0;
		if (nums.size() == 1)
			return nums[0];

		int min = nums[0];

		for (int i = 1; i != nums.size(); ++i)
		{

			if (nums[i] < min)
				min = nums[i];
		}

		return min;
	}
};
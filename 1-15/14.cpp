class Solution
{
  public:
	/**
     * @param nums: The integer array.
     * @param target: Target to find.
     * @return: The first position of target. Position starts from 0.
     */
	int binarySearch(vector<int> &nums, int target)
	{
		// write your code here
		if (nums.size() == 0)
			return -1;

		int begin = 0, end = nums.size();
		int pos = -1;

		while (begin <= end)
		{

			if (begin == end)
			{

				if (target == nums[begin])
					pos = begin;

				break;
			}

			int mid = (begin + end) / 2;

			if (nums[mid] == target)
			{
				pos = mid;

				while (mid >= 0 && nums[mid] == target)
				{
					pos = mid;
					--mid;
				}

				break;
			}
			else if (nums[mid] < target)
			{
				begin = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}

		return pos;
	}
};
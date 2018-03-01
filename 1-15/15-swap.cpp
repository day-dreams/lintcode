#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
void print(const T &col)
{
	for (auto &x : col)
	{
		std::cout << x << ' ';
	}
	std::cout << std::endl;
}

class Solution
{
  public:
	/*
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
	vector<vector<int>> permute(vector<int> &nums)
	{
		// write your code here
		vector<vector<int>> rv;

		if (nums.size() == 0)
		{
			rv.push_back(vector<int>());
			return rv;
		}

		// rv = get_permute(nums);

		get_permute(rv, nums, 0);

		for (auto &x : rv)
			print(x);

		return rv;
	}

	/* 
		@pos:	第一个待排列的数的下表
	
	 */
	void get_permute(vector<vector<int>> &to_add, vector<int> &nums, int pos)
	{
		if (pos == nums.size() - 1)
		{
			//只剩下最后一个数待排列
			to_add.push_back(nums);
			return;
		}

		for (int i = pos; i != nums.size(); ++i)
		{

			std::swap(nums[pos], nums[i]);

			get_permute(to_add, nums, pos + 1);

			std::swap(nums[pos], nums[i]);
		}
	}
};

int main(int argc, char **argv)
{

	vector<int> eles = {1, 2, 3};

	Solution s;

	s.permute(eles);

	return 0;
}
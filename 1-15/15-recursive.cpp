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

		rv = get_permute(nums);

		return rv;
	}

	vector<vector<int>> get_permute(vector<int> &nums)
	{
		vector<vector<int>> rv;

		if (nums.size() == 1)
			rv.push_back(nums);
		else
		{

			for (int i = 0; i != nums.size(); ++i)
			{

				auto temp = nums;
				temp.erase(temp.begin() + i);

				auto sub_permute = get_permute(temp);

				for (auto &x : sub_permute)
				{
					x.push_back(nums[i]);
					rv.push_back(x);
				}
			}
		}

		return rv;
	}
};

int main(int argc, char **argv)
{

	// vector<int> eles = {};
	// vector<int> eles = {1, 2, 3};

	Solution s;

	s.permute(eles);

	return 0;
}
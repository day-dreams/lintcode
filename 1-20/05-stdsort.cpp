/* 

	不服不行,标准库做个完整排序都比我快

 */

#include <algorithm>
#include <vector>
#include <iostream>
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

		std::sort(nums.begin(), nums.begin() + nums.size(), std::greater<int>());

		return nums[n - 1];
	}
};

int main(int argc, char **argv)
{

	Solution s;

	vector<int> x = {1, 2, 3, 4, 5, 9, 8, 7, 6, 0};
	std::cout << s.kthLargestElement(1, x) << std::endl;
	std::cout << s.kthLargestElement(2, x) << std::endl;
	std::cout << s.kthLargestElement(3, x) << std::endl;
	std::cout << s.kthLargestElement(4, x) << std::endl;
	std::cout << s.kthLargestElement(5, x) << std::endl;
	std::cout << s.kthLargestElement(6, x) << std::endl;
	std::cout << s.kthLargestElement(7, x) << std::endl;
	std::cout << s.kthLargestElement(8, x) << std::endl;
	std::cout << s.kthLargestElement(9, x) << std::endl;
	std::cout << s.kthLargestElement(10, x) << std::endl;

	return 0;
}
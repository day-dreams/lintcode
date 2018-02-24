/* 

	快速排序

 */

#include <iostream>
#include <vector>

using std::vector;

template <class T>
void print(T *begin, T *end)
{
	while (begin != end)
	{
		std::cout << *begin << " ";
		++begin;
	}
	std::cout << std::endl;
}

template <class T>
T *partition(T *begin, T *end, const T &pivot)
{
	T *back = end - 1;

	while (begin < back)
	{
		while (*begin < pivot && begin != back)
			++begin;

		if (begin == back)
			return begin;

		std::swap(*begin, *back);

		while (*back >= pivot && begin != back)
			--back;
	}

	return begin;
}

template <class T>
void quick_sort(T *begin, T *end)
{
	// std::cout << "partition size:" << end - begin << std::endl;
	// std::cin.get();
	if (begin >= end)
		return;

	auto mid = partition(begin, end, *begin);

	quick_sort(begin, mid - 1);
	quick_sort(mid + 1, end);
}

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

		int *begin = &nums[0], *end = &nums[0] + nums.size();
		quick_sort(begin, end);
		return nums[nums.size() - n];
	}
};

int main(int argc, char **argv)
{
	Solution s;
	for (int i = 1; i != 9; ++i)
	{
		vector<int> col = {7, 6, 8, 1, 2, 3, 4, 5};
		std::cout << s.kthLargestElement(i, col) << std::endl;
	}
	return 0;
}
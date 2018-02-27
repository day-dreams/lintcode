/* 
	程序耗时1050ms
 */

#include <iostream>
#include <algorithm>
#include <vector>

class Solution
{
  public:
	/**
     * @param n: An integer
     * @return: the nth prime number as description.
     */
	int nthUglyNumber(int n)
	{
		// write your code here
		std::vector<long long> col;
		long long rv = 0;

		col.push_back(1);

		while (n--)
		{
			std::make_heap(col.begin(), col.end(), std::greater<long long>());
			std::pop_heap(col.begin(), col.end(), std::greater<long long>());

			rv = col.back();
			col.pop_back();

			if (std::find(col.begin(), col.end(), rv * 2) == col.end())
			{
				col.push_back(rv * 2);
			}
			if (std::find(col.begin(), col.end(), rv * 3) == col.end())
			{
				col.push_back(rv * 3);
			}
			if (std::find(col.begin(), col.end(), rv * 5) == col.end())
			{
				col.push_back(rv * 5);
			}
		}
		return rv;
	}
};
int main(int argc, char **argv)
{
	Solution s;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(1) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(2) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(3) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(4) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(5) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(6) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(7) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(8) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(9) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(10) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(11) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(12) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(13) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(14) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(15) << std::endl;
	std::cout << "nthUglyNumber:" << s.nthUglyNumber(41) << std::endl;
	return 0;
}
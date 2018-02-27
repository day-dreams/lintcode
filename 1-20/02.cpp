#include <iostream>

class Solution
{
  public:
	/*
     * @param n: A long integer
     * @return: An integer, denote the number of trailing zeros in n!
     */
	long long trailingZeros(long long n)
	{
		// write your code here, try to do it without arithmetic operators.

		/* 
			1. 只有2*5才会产生10,其他任何都无法产生.所以统计(2,5)有几对

			2. 但分解因子后,5的数量显然比2少,所以统计有多少个因子5

			3. 引理:1,2,...,n中,分解因数后只含有一个5的数共有n/5个.

			4. 设立迭代,第i次迭代统计形如x*(5^i)的数的个数
		 */

		long long rv = 0;
		while (n / 5 != 0)
		{
			n = n / 5;
			rv += n;
		}
		return rv;
	}
};

long long foo(long long x)
{
	long long rv = 1;
	for (int i = 1; i <= x; ++i)
		rv *= i;
	return rv;
}
int main(int argc, char **argv)
{
	Solution s;
	std::cout << s.trailingZeros(1) << " " << foo(1) << std::endl;
	std::cout << s.trailingZeros(2) << " " << foo(2) << std::endl;
	std::cout << s.trailingZeros(3) << " " << foo(3) << std::endl;
	std::cout << s.trailingZeros(4) << " " << foo(4) << std::endl;
	std::cout << s.trailingZeros(5) << " " << foo(5) << std::endl;
	std::cout << s.trailingZeros(6) << " " << foo(6) << std::endl;
	std::cout << s.trailingZeros(7) << " " << foo(7) << std::endl;
	std::cout << s.trailingZeros(105) << " " << foo(105) << std::endl;

	return 0;
}
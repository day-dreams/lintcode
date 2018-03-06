
class Solution
{
  public:
	/**
     * @param n: an integer
     * @return: an ineger f(n)
     */
	int fibonacci(int n)
	{
		// write your code here
		if (n == 1)
			return 0;
		if (n == 3 || n == 2)
			return 1;
		int x = 1, y = 1, temp;

		for (int i = 4; i <= n; ++i)
		{
			temp = x + y;
			x = y;
			y = temp;
		}
		return y;
	}
};

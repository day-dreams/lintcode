class Solution
{
  public:
	/**
     * @param a: A 32bit integer
     * @param b: A 32bit integer
     * @param n: A 32bit integer
     * @return: An integer
     */
	int fastPower(int a, int b, int n)
	{
		// write your code here

		long long base = a;
		long long rv = 1;

		if (n == 0)
			return 1 % b;

		while (n > 0)
		{

			if (n & 0x1 == 1)
			{
				rv = rv * base % b;
			}

			base = (base % b) * (base % b) % b;

			n >>= 1;
		}

		return rv;
	}
};

class Solution
{
  public:
	/*
     * @param num: An integer
     * @return: An integer
     */
	int countOnes(int num)
	{
		// write your code here

		int rv = 0;

		for (int i = 0; i != 32; ++i)
		{

			if (num & 0x1 == 1)
				++rv;

			num >>= 1;
		}
		return rv;
	}
};
class Solution
{
  public:
	/**
     * @return: The same instance of this class every time
     */
	int count = 0;
	static Solution *getInstance()
	{
		// write your code here

		static Solution *ptr;

		if (!ptr)
		{
			ptr = new Solution();
		}

		return ptr;
	}
};
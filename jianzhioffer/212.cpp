#include <iostream>

class Solution
{
  public:
	/*
     * @param string: An array of Char
     * @param length: The true length of the string
     * @return: The true length of new string
     */
	int replaceBlank(char string[], int length)
	{
		// write your code here
		if (length == 0)
			return 0;
		int rv = length;
		int back = length - 1;
		for (int i = length - 1; i >= 0; --i)
		{

			if (string[i] == ' ')
			{
				// insert %20
				int ite = back + 2;
				while (ite > i + 2)
				{
					string[ite] = string[ite - 2];
					--ite;
				}
				string[ite] = '0';
				string[ite - 1] = '2';
				string[ite - 2] = '%';
				back = back + 2;
				rv += 2;
			}
		}
		return rv;
	}
};

int main(int argc, char **argv)
{

	char x[100] = "Mr John Smith";
	int len = 13;

	Solution s;

	std::cout << x << std::endl;
	std::cout << s.replaceBlank(x, len) << std::endl;
	std::cout << x << std::endl;

	return 0;
}
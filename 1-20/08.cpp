#include <iostream>

#include <string>

using std::string;

class Solution
{
  public:
	/**
     * @param str: An array of char
     * @param offset: An integer
     * @return: nothing
     */
	void rotateString(string &str, int offset)
	{
		// write your code here
		if (str.empty())
			return;

		offset = offset % str.size();

		string rv;

		int begin;

		if (offset == 0)
			begin = 0;
		else
			begin = str.size() - offset;

		rv = str.substr(begin) + str.substr(0, begin);

		str = rv;
	}
};

int main(int argc, char **argv)
{
	Solution s;
	{
		string str = "12345678";
		s.rotateString(str, 0);
		std::cout << str << std::endl;
	}
	{
		string str = "12345678";
		s.rotateString(str, 1);
		std::cout << str << std::endl;
	}
	{
		string str = "12345678";
		s.rotateString(str, 2);
		std::cout << str << std::endl;
	}
	{
		string str = "12345678";
		s.rotateString(str, 3);
		std::cout << str << std::endl;
	}
	{
		string str = "12345678";
		s.rotateString(str, 4);
		std::cout << str << std::endl;
	}
	{
		string str = "12345678";
		s.rotateString(str, 8);
		std::cout << str << std::endl;
	}
	{
		string str = "12345678";
		s.rotateString(str, 10);
		std::cout << str << std::endl;
	}
	return 0;
}
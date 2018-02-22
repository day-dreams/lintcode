#include <iostream>

int aplusb(int a, int b)
{
	// write your code here

	int rv = 0;
	int carry = 0;
	int x, y;

	for (int i = 0; i != 32; ++i)
	{
		// std::cout << rv << ' ' << carry << std::endl;

		x = a & 1;
		y = b & 1;
		a = a >> 1;
		b = b >> 1;

		if (x & y == 1)
		{
			rv = rv | (carry << i);
			carry = 1;
		}
		else if (x | y == 1)
		{
			if (carry == 1)
			{
				carry = 1;
				rv = rv;
			}
			else
			{
				rv = rv | (1 << i);
				carry = 0;
			}
		}
		else
		{
			rv = rv | (carry << i);
			carry = 0;
		}
	}

	return rv;
}

int main(int argc, char **argv)
{
	std::cout << aplusb(1, 2) << std::endl;
	std::cout << aplusb(5, 2) << std::endl;
	std::cout << aplusb(9, 2) << std::endl;
	std::cout << aplusb(9, 9) << std::endl;
	std::cout << aplusb(0, 0) << std::endl;

	return 0;
}
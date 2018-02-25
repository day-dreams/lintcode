#include <vector>
#include <iostream>
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
class Solution
{
  public:
	/**
     * @param A: sorted integer array A
     * @param B: sorted integer array B
     * @return: A new sorted integer array
     */
	vector<int> mergeSortedArray(vector<int> &A, vector<int> &B)
	{
		// write your code here
		vector<int> rv;
		rv.resize(A.size() + B.size());
		rv.clear();

		auto itea = A.begin();
		auto iteb = B.begin();

		while (itea != A.end() || iteb != B.end())
		{
			print(&rv[0], &rv[0] + rv.size());

			if (itea == A.end())
			{
				rv.push_back(*iteb);
				++iteb;
			}
			else if (iteb == B.end())
			{
				rv.push_back(*itea);
				++itea;
			}
			else
			{
				// both valid
				if (*itea <= *iteb)
				{
					rv.push_back(*itea);
					++itea;
				}
				else
				{
					rv.push_back(*iteb);
					++iteb;
				}
			}
		}
		return rv;
	}
};

int main(int argc, char **argv)
{
	vector<int> a = {1, 2, 4}, b = {-1, 3, 9, 10};
	Solution s;
	auto x = s.mergeSortedArray(a, b);
	print(&x.front(), &x.back() + 1);
	return 0;
}
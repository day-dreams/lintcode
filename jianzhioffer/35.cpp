#include <iostream>

class ListNode
{
  public:
	int val;
	ListNode *next;
	ListNode(int val)
	{
		this->val = val;
		this->next = nullptr;
	}
};
class Solution
{
  public:
	/**
     * @param head: n
     * @return: The new head of reversed linked list.
     */
	ListNode *reverse(ListNode *head)
	{
		// write your code here

		if (head == nullptr)
			return head;

		ListNode *rv;

		ListNode *before;
		ListNode *cur;
		ListNode *next;

		before = head;
		cur = before->next;
		before->next = nullptr;
		next = nullptr;

		rv = before;

		while (cur)
		{
			// std::cout << before << ' ' << cur << ' ' << next << std::endl;

			rv = cur;

			next = cur->next;
			cur->next = before;

			before = cur;
			cur = next;
			// std::cout << ' ' << before << ' ' << cur << ' ' << next << std::endl;
		}

		std::cout << rv << std::endl;
		return rv;
	}
};

void show(ListNode *x)
{

	auto cur = x;
	while (cur != nullptr)
	{
		std::cout << cur->val << ' ';
		cur = cur->next;
	}
	std::cout << std::endl;
}

int main(int argc, char **argv)
{
	ListNode *x = new ListNode(0);

	x->next = new ListNode(1);

	x->next->next = new ListNode(2);

	// show(x);

	Solution s;

	auto y = s.reverse(x);

	show(y);

	return 0;
}
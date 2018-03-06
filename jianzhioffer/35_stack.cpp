#include <stack>

using namespace std;

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

		ListNode *rv = nullptr;
		ListNode *cur = nullptr;

		stack<int> col;

		while (head)
		{
			col.push(head->val);
			head = head->next;
		}

		while (!col.empty())
		{

			if (rv == nullptr)
			{
				rv = new ListNode(col.top());
				col.pop();
				cur = rv;
			}
			else
			{
				cur->next = new ListNode(col.top());
				col.pop();
				cur = cur->next;
			}
		}

		return rv;
	}
};
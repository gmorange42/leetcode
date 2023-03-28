#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
	public:
		ListNode*	addTwoNumbers(ListNode* l1, ListNode* l2)
		{
			int		value = 0;
			int		rest = 0;
			ListNode*	res = NULL;
			ListNode*	temp1 = l1;
			ListNode*	temp2 = l2;

			while (temp1 && temp2)
			{
				value = temp1->val + temp2->val + rest;
				rest = value / 10;
				value %= 10;

				add(&res, value);

				temp1 = temp1->next;
				temp2 = temp2->next;
			}
			while (temp1)
			{
				value = temp1->val + rest;
				rest = value / 10;
				value %= 10;

				add(&res, value);

				temp1 = temp1->next;
			}
			while (temp2)
			{
				value = temp2->val + rest;
				rest = value / 10;
				value %= 10;

				add(&res, value);

				temp2 = temp2->next;
			}
			if (rest != 0)
				add(&res, rest);
			return (res);
		}

		void	add(ListNode** list, int val)
		{
			ListNode*	newElement = new ListNode(val);

			if (newElement == NULL)
			{
				puts("Malloc failed");
				return ;
			}

			if (*list == NULL)
				*list = newElement;
			else
			{
				ListNode*	temp = *list;
				while (temp->next)
					temp = temp->next;
				temp->next = newElement;
			}
		}

		void	printList(ListNode*	list)
		{
			if (!list)
				return ;
			ListNode*	temp = list;
			while (temp)
			{
				printf("%d\n", temp->val);
				temp = temp->next;
			}
		}

		void	deleteList(ListNode* list)
		{
			if (list)
			{
				ListNode*	temp = NULL;
				while (list)
				{
					temp = list;
					list = list->next;
					delete temp;
					temp = NULL;
				}
			}
		}
};

int	main(void)
{
	ListNode*	list1 = NULL;
	ListNode*	list2 = NULL;
	ListNode*	list3 = NULL;

	Solution obj;

	obj.add(&list1, 9);
	obj.add(&list1, 9);
	obj.add(&list1, 9);
	obj.add(&list1, 9);
	obj.add(&list1, 9);
	obj.add(&list1, 9);
	obj.add(&list1, 9);

	obj.add(&list2, 9);
	obj.add(&list2, 9);
	obj.add(&list2, 9);
	obj.add(&list2, 9);

	puts("List1");
	obj.printList(list1);

	puts("\nList2");
	obj.printList(list2);

	list3 = obj.addTwoNumbers(list1, list2);
	puts("\nList3");
	obj.printList(list3);

	obj.deleteList(list1);
	obj.deleteList(list2);
	obj.deleteList(list3);
	return (0);
}

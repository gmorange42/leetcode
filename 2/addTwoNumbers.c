#include <stdio.h>
#include <stdlib.h>

struct	ListNode {
	int			val;
	struct ListNode		*next;
};

void	add(struct ListNode** list, int val);

struct ListNode*	addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int		value = 0;
	int		rest = 0;
	struct ListNode*	res = NULL;
	struct ListNode*	temp1 = l1;
	struct ListNode*	temp2 = l2;

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

void	add(struct ListNode** list, int val)
{
	struct ListNode*	newElement = malloc(sizeof(struct ListNode));

	if (newElement == NULL)
	{
		puts("Malloc failed");
		return ;
	}
	newElement->val = val;
	newElement->next = NULL;

	if (*list == NULL)
		*list = newElement;
	else
	{
		struct ListNode*	temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = newElement;
	}
}

void	printList(struct ListNode*	list)
{
	if (!list)
		return ;
	struct ListNode*	temp = list;
	while (temp)
	{
		printf("%d\n", temp->val);
		temp = temp->next;
	}
}

void	deleteList(struct ListNode* list)
{
	if (list)
	{
		struct ListNode*	temp = NULL;
		while (list)
		{
			temp = list;
			list = list->next;
			free(temp);
			temp = NULL;
		}
	}
}

int	main(void)
{
	struct ListNode*	list1 = NULL;
	struct ListNode*	list2 = NULL;
	struct ListNode*	list3 = NULL;

	add(&list1, 9);
	add(&list1, 9);
	add(&list1, 9);
	add(&list1, 9);
	add(&list1, 9);
	add(&list1, 9);
	add(&list1, 9);

	add(&list2, 9);
	add(&list2, 9);
	add(&list2, 9);
	add(&list2, 9);

	puts("List1");
	printList(list1);

	puts("\nList2");
	printList(list2);

	list3 = addTwoNumbers(list1, list2);
	puts("\nList3");
	printList(list3);

 	deleteList(list1);
 	deleteList(list2);
	deleteList(list3);
	return (0);
}

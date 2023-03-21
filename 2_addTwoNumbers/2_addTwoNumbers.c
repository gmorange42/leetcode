#include <stdio.h>
#include <stdlib.h>

struct	ListNode {
	int			val;
	struct ListNode		*next;
};

//add() is not called in this function, because add() goes through the whole chained list to add an element.
struct ListNode*	addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int		value = 0;
	int		rest = 0;
	struct ListNode		res;
	res.val = 0;
	res.next = NULL;
	struct ListNode*	temp = &res;

	while (l1 && l2)
	{
		value = l1->val + l2->val + rest;
		rest = value / 10;
		value %= 10;

		temp->next = malloc(sizeof(struct ListNode));
		temp->next->next = NULL;
		temp->next->val = value;
		temp = temp->next;

		l1 = l1->next;
		l2 = l2->next;
	}
	while (l1)
	{
		value = l1->val + rest;
		rest = value / 10;
		value %= 10;

		temp->next = malloc(sizeof(struct ListNode));
		temp->next->next = NULL;
		temp->next->val = value;
		temp = temp->next;

		l1 = l1->next;
	}
	while (l2)
	{
		value = l2->val + rest;
		rest = value / 10;
		value %= 10;

		temp->next = malloc(sizeof(struct ListNode));
		temp->next->next = NULL;
		temp->next->val = value;
		temp = temp->next;

		l2 = l2->next;
	}
	if (rest != 0)
	{
		temp->next = malloc(sizeof(struct ListNode));
		temp->next->next = NULL;
		temp->next->val = rest;
		temp = temp->next;
	}
	return (res.next);
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
	{
		*list = newElement;
		return ;
	}
	else
	{
		struct ListNode*	temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = newElement;
		return ;
	}
}

void	printList(struct ListNode*	list)
{
	struct ListNode*	temp = list;
	while (temp)
	{
		printf("%d\n", temp->val);
		temp = temp->next;
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
	return (0);
}

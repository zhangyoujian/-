#pragma once
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


struct cmp
{
	bool operator()(ListNode *x, ListNode *y)
	{
		return x->val >= y->val;
	}
};

ListNode* sortList(ListNode* head) {

	if (head == NULL)
		return head;

	priority_queue<ListNode*, vector<ListNode*>, cmp>data;
	ListNode* P = head;
	while (P)
	{
		data.push(P);
		P = P->next;
	}

	P = data.top();
    head = P;
	data.pop();
	while (data.size() > 0)
	{
		P->next = data.top();
		data.pop();
		P = P->next;
	}
	P->next = NULL;
	return head;
}

void SortListTest()
{
	int a[] = { 1,5,3,8,4,6,9,10,24,7 };
	int N = sizeof(a) / sizeof(a[0]);
	ListNode* head = new ListNode(a[0]);
	ListNode* Phead = head;
	for (int i = 1;i < N;++i)
	{
		head->next = new ListNode(a[i]);
		head = head->next;
	}

	sortList(Phead);
}







class Solution
{
	ListNode * merge(ListNode * head1, ListNode * head2)
	{
		if (!head1 || !head2)
			return (head1) ? head1 : head2;
		ListNode * result = head1;
		if (head1->val < head2->val)
			result->next = merge(head1->next, head2);
		else
		{
			result = head2;
			result->next = merge(head1, head2->next);
		}
		return result;
	}
	ListNode * midNode(ListNode * head)
	{
		ListNode * slow = head, *fast = head->next;
		for (; fast && fast->next; fast = fast->next->next, slow = slow->next);
		return slow;
	}
	ListNode * mergeSort(ListNode * head)
	{
		if (!head || !head->next)
			return head;
		ListNode * mid = midNode(head);
		ListNode * head2 = mid->next;
		mid->next = NULL;
		return merge(mergeSort(head), mergeSort(head2));
	}
public:
	ListNode* sortList(ListNode* head)
	{
		return mergeSort(head);
	}
};
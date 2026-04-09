#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode()
    {
        val = 0;
        next = nullptr;
    }

    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }

    ListNode(int x, ListNode *nextNode)
    {
        val = x;
        next = nextNode;
    }
};

ListNode *createLinkedList(vector<int> values)
{
    if (values.empty())
    {
        return nullptr;
    }

    ListNode *head = new ListNode(values[0]);
    ListNode *current = head;

    for (int i = 1; i < values.size(); i++)
    {
        current->next = new ListNode(values[i]);
        current = current->next;
    }

    return head;
}

void printLinkedList(ListNode *head)
{
    ListNode *current = head;

    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteLinkedList(ListNode *head)
{
    ListNode *current = head;

    while (current != nullptr)
    {
        ListNode *temp = current;
        current = current->next;
        delete (temp);
    }
}

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *dummy = new ListNode(-69);
        ListNode *tail = dummy;

        ListNode *p1 = list1;
        ListNode *p2 = list2;

        while (p1 != nullptr && p2 != nullptr)
        {
            if (p1->val <= p2->val)
            {
                tail->next = p1;
                p1 = p1->next;
            }
            else
            {
                tail->next = p2;
                p2 = p2->next;
            }

            tail = tail->next;
        }

        if (p1 == nullptr)
        {
            tail->next = p2;
        }
        else
        {
            tail->next = p1;
        }

        ListNode *head = dummy->next;
        delete (dummy);

        return head;
    }
};

int main()
{
    vector<int> list1 = {1, 2, 7, 8}; // represents 342
    vector<int> list2 = {5, 6}; // represents 465

    ListNode *l1 = createLinkedList(list1);
    ListNode *l2 = createLinkedList(list2);

    Solution solution;
    ListNode *ansHead = solution.mergeTwoLists(l1, l2);
    printLinkedList(ansHead);

    return 0;
}

// https://leetcode.com/problems/merge-two-sorted-lists/description/?envType=study-plan-v2&envId=top-interview-150
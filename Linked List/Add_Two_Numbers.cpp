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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-69);
        ListNode *current = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry == 1)
        {
            int sum = carry;

            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            current = current->next;
        }

        ListNode *head = dummy->next;
        delete (dummy);

        return head;
    }
};

int main()
{
    vector<int> list1 = {2, 4, 3}; // represents 342
    vector<int> list2 = {5, 6, 4}; // represents 465

    ListNode *l1 = createLinkedList(list1);
    ListNode *l2 = createLinkedList(list2);

    Solution solution;
    ListNode *ansHead = solution.addTwoNumbers(l1, l2);
    printLinkedList(ansHead);

    return 0;
}

// https://leetcode.com/problems/add-two-numbers/description/?envType=study-plan-v2&envId=top-interview-150
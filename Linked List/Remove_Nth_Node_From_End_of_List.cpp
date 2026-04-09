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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(-69, head);
        ListNode *slow = dummy;
        ListNode *fast = dummy;

        for (int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }

        while (fast != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *nodeToDelete = slow->next;
        slow->next = nodeToDelete->next;
        delete(nodeToDelete);

        return dummy->next;
    }
};

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode *head = createLinkedList(values);
    printLinkedList(head);

    Solution solution;
    head = solution.removeNthFromEnd(head, 5);
    printLinkedList(head);

    return 0;
}

// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=study-plan-v2&envId=top-interview-150
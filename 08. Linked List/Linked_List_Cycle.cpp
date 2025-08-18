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
        next = NULL;
    }

    ListNode(int x)
    {
        val = x;
        next = NULL;
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
        return NULL;
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

    while (current != NULL)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

void deleteLinkedList(ListNode *head)
{
    ListNode *current = head;

    while (current != NULL)
    {
        ListNode *temp = current;
        current = current->next;
        delete (temp);
    }
}

class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                return true;
            }
        }

        return false;
    }
};

int main()
{
    vector<int> values = {3, 2, 0, -4};
    ListNode *head = createLinkedList(values);
    head->next->next->next->next = head->next;
    // printLinkedList(head);

    Solution solution;
    cout << solution.hasCycle(head);

    return 0;
}

// https://leetcode.com/problems/linked-list-cycle/description/?envType=study-plan-v2&envId=top-interview-150
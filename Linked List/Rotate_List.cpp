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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr || head->next == nullptr || k == 0)
        {
            return head;
        }

        ListNode *tail = head;

        int length = 1;
        while (tail->next != nullptr)
        {
            length++;
            tail = tail->next;
        }

        tail->next = head;
        int steps = length - (k % length);

        for (int i = 0; i < steps; i++)
        {
            tail = tail->next;
        }

        head = tail->next;
        tail->next = nullptr;

        return head;
    }
};

int main()
{
    vector<int> values = {1, 2, 3, 4, 5};
    ListNode *head = createLinkedList(values);
    printLinkedList(head);

    Solution solution;
    head = solution.rotateRight(head, 2);
    printLinkedList(head);

    return 0;
}

// https://leetcode.com/problems/rotate-list/description/?envType=study-plan-v2&envId=top-interview-150
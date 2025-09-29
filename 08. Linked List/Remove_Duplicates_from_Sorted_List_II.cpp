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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(-69, head);
        ListNode *prev = dummy;
        ListNode *current = head;

        while (current != nullptr)
        {
            if (current->next != nullptr && current->val == current->next->val)
            {
                int duplicateVal = current->val;
                while (current != nullptr && current->val == duplicateVal)
                {
                    ListNode *toDelete = current;
                    current = current->next;
                    delete (toDelete);
                }

                prev->next = current;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }

        ListNode *resultHead = dummy->next;
        delete (dummy);
        return resultHead;
    }
};

int main()
{
    vector<int> values = {1, 2, 3, 3, 4, 4, 5};
    ListNode *head = createLinkedList(values);
    printLinkedList(head);

    Solution solution;
    head = solution.deleteDuplicates(head);
    printLinkedList(head);

    return 0;
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/?envType=study-plan-v2&envId=top-interview-150
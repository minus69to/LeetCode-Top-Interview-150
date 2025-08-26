#include <bits/stdc++.h>
using namespace std;

class Trie
{
    class TrieNode
    {
    public:
        TrieNode *children[26];
        bool isEndofWord;

        TrieNode()
        {
            for (int i = 0; i < 26; i++)
            {
                children[i] = nullptr;
            }
            isEndofWord = false;
        }
    };

    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(string word)
    {
        TrieNode *node = root;

        for (auto ch : word)
        {
            int index = ch - 'a';

            if (node->children[index] == nullptr)
            {
                node->children[index] = new TrieNode();
            }
            node = node->children[index];
        }

        node->isEndofWord = true;
    }

    bool search(string word)
    {
        TrieNode *node = root;

        for (auto ch : word)
        {
            int index = ch - 'a';

            if (node->children[index] == nullptr)
            {
                return false;
            }
            node = node->children[index];
        }

        return node->isEndofWord;
    }

    bool startsWith(string prefix)
    {
        TrieNode *node = root;

        for (auto ch : prefix)
        {
            int index = ch - 'a';

            if (node->children[index] == nullptr)
            {
                return false;
            }
            node = node->children[index];
        }

        return true;
    }
};

int main()
{
    Trie trie;

    trie.insert("apple");
    cout << boolalpha << trie.search("apple") << endl;   // true
    cout << boolalpha << trie.search("app") << endl;     // false
    cout << boolalpha << trie.startsWith("app") << endl; // true

    trie.insert("app");
    cout << boolalpha << trie.search("app") << endl;     // true
    cout << boolalpha << trie.search("apple") << endl;   // true
    cout << boolalpha << trie.startsWith("app") << endl; // true

    trie.insert("banana");
    cout << boolalpha << trie.search("banana") << endl;  // true
    cout << boolalpha << trie.search("ban") << endl;     // false
    cout << boolalpha << trie.startsWith("ban") << endl; // true

    cout << boolalpha << trie.startsWith("") << endl; // true

    cout << boolalpha << trie.search("grape") << endl; // false

    return 0;
}

// https://leetcode.com/problems/implement-trie-prefix-tree/description/?envType=study-plan-v2&envId=top-interview-150
#pragma once
#include <iostream>
using namespace std;

#define  ALPHABET_SIZE  26


// Структура узела дерева 
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    // isEndOfWord - true, если ключ является концом слова
    bool isEndOfWord;
};

TrieNode* getNewNode(void);
void insert(TrieNode*, string);
bool search(TrieNode*, string);
bool isEmpty(TrieNode*);
TrieNode* remove(TrieNode*, string, int depth = 0);
void findMinPrefixes(TrieNode*, char[], int, string&);
void print(TrieNode*, int depth = 0);

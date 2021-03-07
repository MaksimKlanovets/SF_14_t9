#pragma once
#include <iostream>
using namespace std;
#include <conio.h>
#define  ALPHABET_SIZE  26

// Структура узела дерева 
struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    // isEndOfWord - true, если ключ является концом слова
    bool isEndOfWord;

};

class Autocomplete
{
public:
   
	Autocomplete();
    ~Autocomplete();
    void insert(string key);
    bool search(string key);
   
    bool isEmpty(TrieNode* node);
    void printVersion(string);
    void start();
private:
    void depth(TrieNode*, string key,char buf[],int indexBuf, string &res);
    void has_prefix(TrieNode* node, int& cnt_ends);
    TrieNode* getNewNode();
    TrieNode* _root;
    int _counterWords;
};







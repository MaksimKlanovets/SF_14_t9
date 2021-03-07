#include "Autocomplete.h"

Autocomplete::Autocomplete()
{
    // �������� ������ �� ����� ����
     _root = new TrieNode;

    // ������������� ���� ����� ����� � false
    _root->isEndOfWord = false;

    // �������������� ����� ������� ���������
    for (int i = 0; i < ALPHABET_SIZE; i++)
        _root->children[i] = nullptr;
    
    _counterWords = 0;
}

Autocomplete::~Autocomplete()
{
    delete _root;
}

void Autocomplete::insert(string key)
{
    TrieNode* node = _root;

    for (char index : key)
    {
        // ��������� ������ � ������ ����� �������� ������������ ������ �����
        index -= 'a';

        // ���� ��������� �������, �.�. ����� � ����� ��������� ���
        // ������� ����� ����
        if (!node->children[index])
        {
            node->children[index] = getNewNode();
            _counterWords++;
        }

        node = node->children[index];
    }

    // �������� ��������� ����� ��� ����, �.�. ����� �����
    node->isEndOfWord = true;
}

bool Autocomplete::search(string key)
{
    struct TrieNode* node = _root;

    for (char index : key)
    {
        index -= 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr && node->isEndOfWord);
}

bool Autocomplete::isEmpty(TrieNode* node)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (node->children[i])
            return false;
    return true;
}

void Autocomplete::printVersion(string key)
{
    struct TrieNode* node = _root;
    //������� ���������� Key
    int cnt{ 0 };
    //������ ��� �������
    char buf[1000];
    int indexBuf{ 0 };
    string res{};
    for (char index : key)
    {
      
        index -= 'a';
        if (!node->children[index])        
            return;
        cnt++;
        node = node->children[index];
        if (cnt == key.size())
        {
            depth(node,key,buf,indexBuf,res);
        }
    }
        cout << res;
}

void Autocomplete::start()
{
    string inputSrting = {};
    cout << "entrence-> 0 " << endl;
    cout << "start input" << endl;
    cout << "to clear input-> 1" << endl;
    
    while (1)
    {
        if (_kbhit())
        {
         char ch = _getch();
    
         if (ch == '0')
         {
             break;
         }
         if (ch == '1')
         {
             inputSrting.clear();
             system("cls");
             continue;
         }
         if (ch == 13)
         {
             if (!search(inputSrting))
             {
                 insert(inputSrting);
                 cout << "word added" << endl;
             }
             
             inputSrting.clear();
             continue;
         }
         if (ch)
         {
             inputSrting.push_back(ch);
             system("cls");
             cout << inputSrting << endl;
             printVersion(inputSrting);
         }
       
        }
    }
}



void Autocomplete::has_prefix(TrieNode* node, int& cnt_ends)
{
    if (node->isEndOfWord)
        cnt_ends++;
    for (size_t i = 0; i < ALPHABET_SIZE; i++) // ���� �� ������ � ������� ��� ����� ����
    {
        if (node->children[i]) {
            has_prefix(node->children[i], cnt_ends);
        }
    }
}

void Autocomplete::depth(TrieNode* node, string key, char buf[], int indexBuf,string &res)
{
    if (!node)
        return;

        int cnt = 0;
        has_prefix(node, cnt);
        if (cnt == 1 && isEmpty(node))
        {
            buf[indexBuf] = '\0';
            res += string(buf) + '\n';
            return;
        }
        if (cnt !=0 && node->isEndOfWord)
        {
            buf[indexBuf] = '\0';
            res += string(buf) + '\n';
        }
       
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
        if (node->children[i] && !isEmpty(node))
        {
            int in = i + 'a';
            buf[indexBuf] = in;
          //  cout <<(char) in;
            depth(node->children[i], key, buf, indexBuf+1,res);
        }
    }
}


TrieNode* Autocomplete::getNewNode()
{
    // �������� ������ �� ����� ����
        struct TrieNode* pNode = new TrieNode;

    // ������������� ���� ����� ����� � false
    pNode->isEndOfWord = false;

    // �������������� ����� ������� ���������
    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}



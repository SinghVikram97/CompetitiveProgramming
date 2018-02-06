https://drive.google.com/open?id=1W_M4Slx9C6aWw_2B9W8Ey0EL7zqd-slj
https://drive.google.com/open?id=1v6lvBhbM5oBBAPTXnVjVcVVCBSadbgvu
#include<bits/stdc++.h>
using namespace std;
class TrieNode
{
public:

    /// Storing the character
    char data;

    /// Why not unordered_map<TrieNode,TrieNode*>
    /// This is more convenient
    /// A character points to more than one node
    unordered_map<char,TrieNode*> h;

    /// Storing whether a word ends at this node
    bool isTerminal;

    /// Constructor
    TrieNode(char ch)
    {
        /// Put character at that node
        data=ch;
        /// By default not a terminal node
        isTerminal=false;
    }
};
class Trie
{
private:
    TrieNode *root;
public:
    Trie()
    {
        /// Null at root node
        root=new TrieNode('\0');
    }
    void addWord(string word);
    bool isPresent(string word);
};
void Trie::addWord(string word)
{
    /// Start at root node
    TrieNode *temp=root;
    /// Iterate through the word
    for(int i=0;i<word.length();i++)
    {
        /// Current character
        char ch=word[i];
        /// See if current character present in this node's children
        if(temp->h.count(ch)==1)
        {
            /// It means present
            /// So move to next node
            temp=temp->h[ch];
        }
        else
        {
            /// It means not present
            /// Create a new TrieNode
            TrieNode *newNode=new TrieNode(ch);
            /// Link this node below current node's children
            temp->h.insert(make_pair(ch,newNode));
            /// Move to child
            temp=newNode;
        }
    }
    /// Set isTerminal as true
    temp->isTerminal=true;
}
bool Trie::isPresent(string word)
{
    TrieNode *temp=root;
    /// Iterate over characters of the word
    for(int i=0;i<word[i];i++)
    {
        /// Current character
        char ch=word[i];
        /// See if current character present in children of current node
        if(temp->h.count(ch)==1)
        {
            /// Present so move to next node
            temp=temp->h[ch];
        }
        else
        {
            /// Not present
            return false;
        }
    }
    /// See if this is terminal node
    if(temp->isTerminal==true)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    Trie T;
    cout<<"Enter the number of words"<<endl;
    int n;
    cin>>n;
    cout<<"Enter the words"<<endl;
    for(int i=0;i<n;i++)
    {
        string word;
        cin>>word;
        T.addWord(word);
    }
    cout<<"Enter the word to search for"<<endl;
    string word;
    cin>>word;
    if(T.isPresent(word))
    {
        cout<<"Word is present"<<endl;
    }
    else
    {
        cout<<"Word is not present"<<endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char ch;
    int freq;
    Node *left;
    Node *right;

    Node(char character, int frequency)
    {
        this->ch = character;
        this->freq = frequency;
        left = NULL;
        right = NULL;
    }

    ~Node()
    {
        delete left;
        delete right;
    }
};

class Compare
{
public:
    bool operator()(Node *left, Node *right)
    {
        return left->freq > right->freq;
    }
};

class HuffmanTree
{
    Node *root;
    unordered_map<char, string> huffmanCode;

public:
    void encode(Node* root,string str){
        if(!root) return ;
        if(!root->right && !root->left){
            huffmanCode[root->ch]=str;
            return;
        } 
        encode(root->left,str+'0');
        encode(root->right,str+'1');
    }
    
    void build(string text){
        unordered_map<char,int> fq;
        for(char ch:text){
            fq[ch]++;
        }

        priority_queue<Node*,vector<Node*>, Compare> pq;

        for(auto it:fq){
            pq.push(new Node(it.first,it.second));
        }

        while(pq.size()>1){
            Node* l=pq.top(); pq.pop();
            Node* r=pq.top(); pq.pop();

            Node* rt=new Node('\0',l->freq+r->freq);

            rt->left=l;
            rt->right=r;

            pq.push(rt);
        }
        root=pq.top();

        encode(root,"");
    }

    void printCode(){
        for(auto it:huffmanCode){
            cout<<it.first<<" : "<<it.second<<endl;
        }
        cout<<endl;
    }
};

int main()
{ 
    HuffmanTree tr;
    string str;
    cout<<"Enter the string : ";
    cin>>str;

    tr.build(str);
    tr.printCode();

    
    return 0;
}
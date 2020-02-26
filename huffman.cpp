#include <bits/stdc++.h>
using namespace std;

map<char, string> code_list; ///store code for each character


struct node
{
    int frequency;
    char ch;
    node *left, *right;

    node() ///constructor to create empty node
    {
        left = right = 0;
        ch = '\0';
    }

    node(char _ch, int _frequency) ///constructor to create a node with given information
    {
        frequency = _frequency;
        left = right = 0;
        ch = _ch;
    }
};

bool operator<(const node &a, const node &b) ///overload < (less then) operator so the priority_queue can
{
    return a.frequency > b.frequency;        ///use it to sort node according to frequency
}

node *huffman_tree(string str)
{
    map<char, int> freq;
    int len = str.size();

    for(int i = 0; i < len; i++) ///find the frequency of each character
        freq[str[i]]++;

    priority_queue<node> que;  ///que contains top element with smallest frequency
    for(auto it: freq) ///iterate through the map
    {
        char ch = it.first;
        int new_frequency = it.second;
        que.push(node(ch, new_frequency)); ///create a node with a character and its frequency
    }

    while(!que.empty())
    {
        node *node1, *node2; ///this two pointer to node will create another node

        node1 = new node; ///allocate memory for node1
        node2 = new node; ///allocate memory for node2

        node tmp = que.top(); ///now tmp contains smallest element
        que.pop();

        node1->left = tmp.left;   ///create a node with the information contains in tmp
        node1->right = tmp.right;
        node1->frequency = tmp.frequency;
        node1->ch = tmp.ch;

        if(que.empty())
            return node1;

        tmp = que.top(); ///now tmp contains another smallest element
        que.pop();

        node2->left = tmp.left; ///create a node with the information contains in tmp
        node2->right = tmp.right;
        node2->frequency = tmp.frequency;
        node2->ch = tmp.ch;

        node *root_node;      ///create e new root node
        root_node = new node;

        root_node->frequency = node1->frequency + node2->frequency; /// root node contains summation of frequency of its child
       // cout << new_node.frequency << endl;
        root_node->left = node1; /// make node1 root_nodes left child
        root_node->right = node2; /// make node2 root_nodes right child
        que.push(*root_node);       /// push value of root_node to the queue

        //cout << new_node.left << endl;
    }
}

void generate_code(node *root, string code)
{
    //cout << code << endl;
    if(root->left == 0){ ///If a node has no left child then also has no right child.
        //cout << root->ch << "  " << code << endl;
        code_list[root->ch] = code; ///found code for a character
        return ;
    }

    generate_code(root->left, code+"0"); ///go left
    generate_code(root->right, code+"1"); ///go right
}

int main()
{
    string str = "ababaacdcdbaefghaaa";
    node *root;
    root = huffman_tree(str);
    generate_code(root, "");
    for(auto i: code_list)
        cout << i.first << " " << i.second << endl;
}

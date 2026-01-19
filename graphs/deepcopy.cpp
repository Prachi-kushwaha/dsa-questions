#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Definition for a Node
class Node
{
public:
    int val;
    vector<Node *> neighbors;

    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }

    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }

    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

// Map to store original node -> cloned node
unordered_map<Node *, Node *> mp;

// DFS function to clone the graph (deep copy)
Node *cloneGraph(Node *node)
{
    if (node == nullptr)
        return nullptr;

    // If node already cloned return it
    if (mp.count(node))
        return mp[node];

    // Create new node
    Node *newNode = new Node(node->val);

    // Save mapping
    mp[node] = newNode;

    // Clone neighbors
    for (Node *neigh : node->neighbors)
    {
        newNode->neighbors.push_back(cloneGraph(neigh));
    }

    return newNode;
}

// Helper function to print graph (DFS)
void printGraph(Node *node, unordered_map<Node *, bool> &visited)
{
    if (!node || visited[node])
        return;

    visited[node] = true;
    cout << "Node " << node->val << " -> ";

    for (Node *neigh : node->neighbors)
    {
        cout << neigh->val << " ";
    }
    cout << endl;

    for (Node *neigh : node->neighbors)
    {
        printGraph(neigh, visited);
    }
}

int main()
{
    // Create a simple graph

    Node *n1 = new Node(1);
    Node *n2 = new Node(2);
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    n1->neighbors = {n2, n4};
    n2->neighbors = {n1, n3};
    n3->neighbors = {n2, n4};
    n4->neighbors = {n1, n3};

    cout << "Original Graph:" << endl;
    unordered_map<Node *, bool> visited1;
    printGraph(n1, visited1);

    // Clone graph
    Node *cloned = cloneGraph(n1);

    cout << "\nCloned Graph:" << endl;
    unordered_map<Node *, bool> visited2;
    printGraph(cloned, visited2);

    return 0;
}

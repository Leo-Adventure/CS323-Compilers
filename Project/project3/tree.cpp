#include "tree.hpp"

Node::Node(string name, int nodes_num, int line_num, ...) : nodetype(NONTERMINAL), name(name), nodes_num(nodes_num), line_num(line_num)
{
    va_list childnodes;
    va_start(childnodes, line_num);
    for (int i = 0; i < nodes_num; i++)
    {
        Node *node = (Node *)va_arg(childnodes, Node *);
        this->nodes_queue.push_back(node);
    }
    va_end(childnodes);
}

Node::Node(NodeType nodetype, char *char_value, int line_num) : nodetype(nodetype), line_num(line_num)
{
    this->char_value = new char[100];
    memcpy(this->char_value, char_value, strlen(char_value));
}

Node::Node(string name, int line_num) : nodetype(TERMINAL), name(name), line_num(line_num)
{
}

Node::Node(NodeType nodetype, string name, int int_value, int line_num) : nodetype(nodetype), int_value(int_value), line_num(line_num)
{
    this->name = string(name);
}

Node::Node(NodeType nodetype, string name, float float_value, int line_num) : nodetype(nodetype), float_value(float_value), line_num(line_num)
{
    this->name = string(name);
}

void printTree(Node *root, int space)
{
    printf("%s (%d)\n", root->name.c_str(), root->line_num);
    int nodes_num = root->nodes_num;
    vector<Node *> nodes_queue = root->nodes_queue;
    for (int i = 0; i < nodes_num; i++)
    {
        Node *node = nodes_queue[0];
        print(node, space + 2);
        vector<Node*>::iterator k = nodes_queue.begin();
	    nodes_queue.erase(k);
        // nodes_queue.pop();
    }
}

void print(Node *node, int space)
{
    if(node->nodes_num == 0 && node->nodetype == NONTERMINAL){
        return;
    }
    for (int i = 0; i < space; i++)
    {
        printf(" ");
    }
    switch (node->nodetype)
    {
    case Type:
    {
        printf("TYPE: %s\n", node->char_value);
        break;
    }
    case Int:
    {
        printf("INT: %s\n", node->name.c_str());
        break;
    }
    case Char:
    {
        printf("CHAR: %s\n", node->char_value);
        break;
    }
    case Float:
    {
        printf("FLOAT: %s\n", node->name.c_str());
        break;
    }
    case Id:
    {
        printf("ID: %s\n", node->char_value);
        break;
    }
    case TERMINAL:
    {
        printf("%s\n", node->name.c_str());
        break;
    }
    case NONTERMINAL:
    {
        printTree(node, space);
        break;
    }
    }
}
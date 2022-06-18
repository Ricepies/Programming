#include <iostream>
enum color
{
    red,
    black
};

struct RBnode
{
    int key;
    enum color color;
    RBnode *left;
    RBnode *right;
    RBnode *parent;
};

class RBtree
{
private:
    void leftRotate(RBnode *node);
    void rightRotate(RBnode *node);
    void fixProblem(RBnode *node);

public:
    RBnode *root = NULL;
    RBnode *search(int key);
    void insert(int key);
    void deleteNode(int key);
};

RBnode *RBtree::search(int key)
{
    RBnode *node = root;
    while (node != NULL)
    {
        if (node->key == key)
            return node;

        else if (node->key > key)
            node = node->left;
        else
            node = node->right;
    }
    return NULL;
}

void RBtree::leftRotate(RBnode *n)
{
    RBnode *r = n->right;
    n->right = r->left;
    if (r->left != NULL)
        r->left->parent = n;
    r->parent = n->parent;
    if (n->parent == nullptr)
        root = r;
    else if (n == n->parent->left)
        n->parent->left = r;
    else
        n->parent->right = r;
    r->left = n;
    n->parent = r;
    return;
}

void RBtree::rightRotate(RBnode *n)
{
    RBnode *l = n->left;
    n->left = l->right;
    if (l->right != NULL)
        l->right->parent = n;
    l->parent = n->parent;
    if (n->parent == nullptr)
        root = l;
    else if (n == n->parent->right)
        n->parent->right = l;
    else
        n->parent->left = l;
    l->right = n;
    n->parent = l;
    return;
}

void RBtree::fixProblem(RBnode *x)
{
    RBnode *uncle;
    while (x->parent->color == red)
    {
        if (x->parent == x->parent->parent->left)
            uncle = x->parent->parent->right;
        else
            uncle = x->parent->parent->left;
        if (uncle && uncle->color == red)
        {
            x->parent->parent->color = red;
            x->parent->color = black;
            uncle->color = black;
            if (x->parent->parent != root)
                x = x->parent->parent;
            else
                return;
        }
        else
        {
            if (x->parent == x->parent->parent->left)
            {
                if (x == x->parent->right)
                {

                    leftRotate(x->parent);
                    rightRotate(x->parent);
                    x->right->color = red;
                }
                else
                {
                    rightRotate(x->parent->parent);
                    x->parent->color = black;
                    x->parent->right->color = red;
                }
            }
            else
            {
                if (x == x->parent->left)
                {
                    rightRotate(x->parent);
                    leftRotate(x->parent);
                    x->left->color = red;
                }
                else
                {
                    leftRotate(x->parent->parent);
                    x->parent->color = black;
                    x->parent->left->color = red;
                }
            }
        }
        if (root->color == red)
            root->color = black;
    }
}

void RBtree::insert(int key)
{
    RBnode *newNode = new RBnode;
    newNode->key = key;
    newNode->color = red;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;

    if (root == NULL)
    {
        root = newNode;
        root->color = black;
        return;
    }

    RBnode *finder = root;
    RBnode *prev = NULL;

    while (finder != NULL)
    {
        prev = finder;
        if (key < finder->key)
            finder = finder->left;
        else
            finder = finder->right;
    }

    if (prev == NULL)
        prev = newNode;
    else if (key < prev->key)
        prev->left = newNode;
    else
        prev->right = newNode;
    newNode->parent = prev;
    if (newNode->parent->parent)
        fixProblem(newNode);
}
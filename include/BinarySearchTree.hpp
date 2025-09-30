#pragma once

#include <iostream>

template <typename T>
class BinarySearchTree
{
private:
    struct Node
    {
        T data;
        Node *left;
        Node *right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node *root;

    Node *insertRec(Node *node, T value)
    {
        if (!node)
        {
            return new Node(value);
        }

        if (value < node->data)
        {
            node->left = insertRec(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    void destroy(Node *node)
    {
        if (!node)
            return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    Node *copy(const Node *otherNode)
    {
        if (!otherNode)
            return nullptr;
        Node *newNode = new Node(otherNode->data);
        newNode->left = copy(otherNode->left);
        newNode->right = copy(otherNode->right);
        return newNode;
    }

    Node *searchRec(Node *node, T value) const
    {
        if (!node || node->data == value)
        {
            return node;
        }
        return value < node->data ? searchRec(node->left, value) : searchRec(node->right, value);
    }

    Node *findMax(Node *node) const
    {
        while (node && node->right)
        {
            node = node->right;
        }
        return node;
    }

    Node *removeRec(Node *node, T value)
    {
        if (!node)
            return nullptr;

        if (value < node->data)
        {
            node->left = removeRec(node->left, value);
        }
        else if (value > node->data)
        {
            node->right = removeRec(node->right, value);
        }
        else
        {
            if (!node->right)
            {
                Node *temp = node->left;
                delete node;
                return temp;
            }
            if (!node->left)
            {
                Node *temp = node->right;
                delete node;
                return temp;
            }

            Node *predecessor = findMax(node->left);
            node->data = predecessor->data;
            node->left = removeRec(node->left, predecessor->data);
        }
        return node;
    }

    void inorderRec(Node *node) const
    {
        if (!node)
            return;
        inorderRec(node->left);
        std::cout << node->data << " ";
        inorderRec(node->right);
    }

    int max(int heightLeft, int heightRight)
    {
        return heightLeft > heightRight ? heightLeft : heightRight;
    }

    int heightRec(Node *node)
    {
        if (!node)
        {
            return -1;
        }

        return 1 + max(heightRec(node->left), heightRec(node->right));
    }

    int countNodesRec(Node *node)
    {
        if (!node)
        {
            return 0;
        }

        return 1 + countNodesRec(node->left) + countNodesRec(node->right);
    }

    int countLeavesRec(Node *node)
    {
        if (!node)
        {
            return 0;
        }

        if (!node->left && !node->right)
        {
            return 1;
        }

        return countLeavesRec(node->left) + countLeavesRec(node->right);
    }

public:
    BinarySearchTree() : root(nullptr) {}

    BinarySearchTree(const BinarySearchTree &other) : root(nullptr)
    {
        this->root = copy(other.root);
    }

    BinarySearchTree &operator=(const BinarySearchTree &other)
    {
        if (this == &other)
            return *this;
        destroy(this->root);
        this->root = copy(other.root);
        return *this;
    }

    BinarySearchTree(BinarySearchTree &&other) noexcept : root(other.root)
    {
        other.root = nullptr;
    }

    BinarySearchTree &operator=(BinarySearchTree &&other) noexcept
    {
        if (this == &other)
            return *this;
        destroy(this->root);
        this->root = other.root;
        other.root = nullptr;
        return *this;
    }

    ~BinarySearchTree()
    {
        destroy(root);
    }

    void insert(T value)
    {
        root = insertRec(root, value);
    }

    bool search(T value) const
    {
        return searchRec(root, value) != nullptr;
    }

    void remove(T value)
    {
        root = removeRec(root, value);
    }

    void inorder()
    {
        inorderRec(root);
        std::cout << std::endl;
    }

    int height()
    {
        return heightRec(root);
    }

    int countNodes()
    {
        return countNodesRec(root);
    }

    int countLeaves()
    {
        return countLeavesRec(root);
    }
};
#pragma once

#include "BinarySearchTree.hpp"
#include "Sale.hpp"

class SalesHistoryTree : public BinarySearchTree<Sale>
{
public:
    enum Trend
    {
        UP,
        DOWN,
        STABLE,
        DATA_MISSING
    };

    Trend getSalesTrend(int startDate, int endDate) const
    {
        Node *startNode = this->searchRec(this->root, Sale(startDate));
        Node *endNode = this->searchRec(this->root, Sale(endDate));

        if (!startNode || !endNode)
        {
            return DATA_MISSING;
        }

        if (endNode->data.getTotal() > startNode->data.getTotal())
            return UP;
        if (endNode->data.getTotal() < startNode->data.getTotal())
            return DOWN;
        return STABLE;
    }

    Sale findHighestSale() const
    {
        if (!this->root)
        {
            throw std::runtime_error("A arvore de vendas esta vazia.");
        }
        Sale highest = this->root->data;
        findHighestSaleRec(this->root, highest);
        return highest;
    }

    void removeOlderThan(int referenceDate)
    {
        this->root = removeOlderThanRec(this->root, referenceDate);
    }

private:
    void findHighestSaleRec(Node *node, Sale &highest) const
    {
        if (!node)
            return;

        if (node->data.getTotal() > highest.getTotal())
        {
            highest = node->data;
        }
        findHighestSaleRec(node->left, highest);
        findHighestSaleRec(node->right, highest);
    }

    Node *removeOlderThanRec(Node *node, int referenceDate)
    {
        if (!node)
            return nullptr;

        node->left = removeOlderThanRec(node->left, referenceDate);
        node->right = removeOlderThanRec(node->right, referenceDate);

        if (node->data.getDate() < referenceDate)
        {
            Node *newNode = this->removeRec(node, node->data);
            return newNode;
        }

        return node;
    }
};
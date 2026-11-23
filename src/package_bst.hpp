#pragma once
#include "models.hpp"

class PackageBST {
private:
    struct Node {
        Package data;
        Node* left;
        Node* right;
    };

    Node* root;

    Node* findNode(Node* node, const std::string& id) const;
    Node* removeNode(Node* node, const std::string& id);
    Node* findMin(Node* node) const;
    void clear(Node* node);

public:
    PackageBST();
    ~PackageBST();

    bool insert(const Package& pkg);
    bool exists(const std::string& id) const;
    std::string getDestination(const std::string& id) const;
    bool remove(const std::string& id);
};
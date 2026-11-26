#include "package_bst.hpp"

PackageBST::PackageBST() {
    root = nullptr;
}
PackageBST::Node* PackageBST::findNode(Node* node, const std::string& id) const {
    while (node != nullptr) {
        if (id == node->data.package_id) {
            return node;
        }
        else if (id < node->data.package_id) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return nullptr;
}

bool PackageBST::insert(const Package& pkg) {
    if (pkg.package_id.empty()) {
        return false;
    }

    if (root == nullptr) {
        root = new Node{pkg, nullptr, nullptr};
        return true;
    }

    Node* current = root;

    while (current != nullptr) {
        if (pkg.package_id == current->data.package_id) {
            return false;
        }

        if (pkg.package_id < current->data.package_id) {
            if (current->left == nullptr) {
                current->left = new Node{pkg, nullptr, nullptr};
                return true;
            }
            current = current->left;
        }
        else {
            if (current->right == nullptr) {
                current->right = new Node{pkg, nullptr, nullptr};
                return true;
            }
            current = current->right;
        }
    }

    return false;
}

bool PackageBST::exists(const std::string& id) const {
    if (findNode(root, id) != nullptr) {
        return true;
    }
    return false;
}

std::string PackageBST::getDestination(const std::string& id) const {
    Node* node = findNode(root, id);

    if (node == nullptr) {
        return "";
    }

    return node->data.destination;
}

PackageBST::Node* PackageBST::findMin(Node* node) const {
    if (node == nullptr) {
        return nullptr;
    }

    while (node->left != nullptr) {
        node = node->left;
    }

    return node;
}


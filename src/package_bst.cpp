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
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
    Node* root;

    Node* insertNode(Node* root, int value) {
        if (root == nullptr) {
            return new Node(value);
        }
        if (value < root->data) {
            root->left = insertNode(root->left, value);
        }
        if (value > root->data) {
            root->right = insertNode(root->right, value);
        }
        return root;
    }
    Node* removeNode(Node* node, int value) {
        if (node == nullptr) {
            return nullptr;
        }
        if (value < node->data) {
            node->left = removeNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = removeNode(node->right, value);
        }
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = node->right;
            while (temp && temp->left != nullptr) {
                temp = temp->left;
            }
            node->data = temp->data;
            node->right = removeNode(node->right, temp->data);
        }
        return node;
    }
    bool searchNode(Node* root, int key) {
        if (root == nullptr) {
            return false;
        }
        if (root->data == key) {
            return true;
        }
        if (key < root->data) {
            return searchNode(root->left, key);
        }
        if (key > root->data) {
            return searchNode(root->right, key);
        }
        return false;
    }
    int kthMaxNode(Node* root, int k, int& count) {
        if (root == nullptr) {
            return -1;
        }
        int right = kthMaxNode(root->right, k, count);
        if (right != -1) {
            return right;
        }
        count++;
        if (count == k) {
            return root->data;
        }
        return kthMaxNode(root->left, k, count);
    }
    int kthMinNode(Node* root, int k, int& count) {
        if (root == nullptr) {
            return -1;
        }
        int left = kthMinNode(root->left, k, count);
        if (left != -1) {
            return left;
        }
        count++;
        if (count == k) {
            return root->data;
        }
        return kthMinNode(root->right, k, count);
    }
    void inOrderTraversal(Node* root) {
        if (root != nullptr) {
            inOrderTraversal(root->left);
            cout << root->data << " ";
            inOrderTraversal(root->right);
        }
    }
    void preOrderTraversal(Node* root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
    }
    void postOrderTraversal(Node* root) {
        if (root != nullptr) {
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout << root->data << " ";
        }
    }
public:
    BST() {
        root = nullptr;
    }
    void insert(int value) {
        root = insertNode(root, value);
    }
    void remove(int value) {
        root = removeNode(root, value);
    }
    void search(int key) {
        if (searchNode(root, key)) {
            cout << key << " is Found!\n";
            return;
        }
        cout << key << " is not Found!\n";
    }
    int max() {
        Node* temp = root;
        if (temp == nullptr) {
            cout << "BST is Empty.";
            return -1;
        }
        while (temp->right != nullptr) {
            temp = temp->right;
        }
        return temp->data;
    }
    int min() {
        Node* temp = root;
        if (temp == nullptr) {
            cout << "BST is Empty.";
            return -1;
        }
        while (temp->left != nullptr) {
            temp = temp->left;
        }
        return temp->data;
    }
    int kthMax(int k) {
        if (root == nullptr) {
            cout << "BST is empty.";
        }
        int count = 0;
        return kthMaxNode(root, k, count);
    }
    int kthMin(int k) {
        if (root == nullptr) {
            cout << "BST is empty.";
        }
        int count = 0;
        return kthMinNode(root, k, count);
    }
    void inOrder() {
        inOrderTraversal(root);
    }
    void preOrder() {
        preOrderTraversal(root);
    }
    void postOrder() {
        postOrderTraversal(root);
    }
    void display() {
        inOrderTraversal(root);
        cout << endl;
    }
};

int main() {
    BST obj;

    obj.insert(5);
    obj.insert(4);
    obj.insert(7);
    obj.insert(3);
    obj.insert(2);
    obj.insert(8);
    obj.insert(6);
    obj.insert(10);
    obj.insert(9);
    obj.insert(1);

    cout << "\nInOrder Traversal in BST   : ";
    obj.inOrder();

    cout << "\nPreOrder Traversal in BST  : ";
    obj.preOrder();

    cout << "\nPostOrder Traversal in BST : ";
    obj.postOrder();

    cout << endl;
    cout << endl;

    obj.search(0);
    obj.search(4);

    obj.remove(2);

    cout << "\nAfter Remove Value from BST : ";
    obj.display();

    cout << endl;
    cout << "Max Value in BST is : " << obj.max() << endl;
    cout << "4th Max Value in BST is : " << obj.kthMax(4) << endl << endl;
    cout << "Min Value in BST is : " << obj.min() << endl;
    cout << "4th Min Value in BST is : " << obj.kthMin(4) << endl;


    return 0;
}
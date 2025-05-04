#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* root;

    BinarySearchTree() {
        root = nullptr;
    }

    ~BinarySearchTree() {
        destroyTree(root);
    }

    void insert(int val) {
        root = insertNode(root, val);
    }

    void search(int val) {
        if (searchNode(root, val)) {
            cout << val << " is found in the tree." << endl;
        } else {
            cout << val << " is not found in the tree." << endl;
        }
    }

    int findMin() {
        Node* current = root;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current ? current->data : -1;
    }

    int longestPath() {
        return calculateHeight(root);
    }

    void mirror() {
        mirrorTree(root);
    }

    void display() {
        cout << "In-order traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }

private:
    Node* insertNode(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insertNode(node->left, val);
        } else if (val > node->data) {
            node->right = insertNode(node->right, val);
        }
        return node;
    }

    bool searchNode(Node* node, int val) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == val) {
            return true;
        } else if (val < node->data) {
            return searchNode(node->left, val);
        } else {
            return searchNode(node->right, val);
        }
    }

    int calculateHeight(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    void mirrorTree(Node* node) {
        if (node == nullptr) {
            return;
        }
        swap(node->left, node->right);
        mirrorTree(node->left);
        mirrorTree(node->right);
    }

    void inOrderTraversal(Node* node) {
        if (node == nullptr) {
            return;
        }
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }

    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
};

int main() {
    BinarySearchTree bst;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert Node\n";
        cout << "2. Search Node\n";
        cout << "3. Find Minimum Value\n";
        cout << "4. Find Longest Path\n";
        cout << "5. Mirror the Tree\n";
        cout << "6. Display Tree\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;

            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                bst.search(value);
                break;

            case 3:
                cout << "Minimum value in the tree: " << bst.findMin() << endl;
                break;

            case 4:
                cout << "Longest path (height) in the tree: " << bst.longestPath() << endl;
                break;

            case 5:
                bst.mirror();
                cout << "Tree has been mirrored." << endl;
                break;

            case 6:
                bst.display();
                break;

            case 7:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}











/*
#include <iostream>
using namespace std;
#include <iostream>: Allows the use of cin, cout, etc., for input and output.

using namespace std;: So we don’t need to write std::cout, etc., every time.

✅ Node Structure
cpp
Copy
Edit
struct Node {
    int data;
    Node* left;
    Node* right;
struct Node: Creates a structure to store each node of the BST.

int data: Holds the data value of the node.

Node* left and Node* right: Pointers to left and right children.

cpp
Copy
Edit
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
A constructor that sets the node’s value to val and sets both child pointers to nullptr (no child yet).

✅ BinarySearchTree Class
cpp
Copy
Edit
class BinarySearchTree {
public:
    Node* root;
class BinarySearchTree: A class to manage the BST.

Node* root: The root node of the BST.

cpp
Copy
Edit
    BinarySearchTree() {
        root = nullptr;
    }
Constructor: When an object is created, it starts with an empty tree (root = nullptr).

cpp
Copy
Edit
    ~BinarySearchTree() {
        destroyTree(root);
    }
Destructor: Automatically deletes all nodes when the object is destroyed (cleans memory).

✅ Public Member Functions
cpp
Copy
Edit
    void insert(int val) {
        root = insertNode(root, val);
    }
Adds a value into the tree using a helper function insertNode.

cpp
Copy
Edit
    void search(int val) {
        if (searchNode(root, val)) {
            cout << val << " is found in the tree." << endl;
        } else {
            cout << val << " is not found in the tree." << endl;
        }
    }
Searches for a value and prints whether it’s found or not.

cpp
Copy
Edit
    int findMin() {
        Node* current = root;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current ? current->data : -1;
    }
Finds the minimum value in the tree by going left as far as possible.

cpp
Copy
Edit
    int longestPath() {
        return calculateHeight(root);
    }
Returns the height of the tree (longest path from root to leaf).

cpp
Copy
Edit
    void mirror() {
        mirrorTree(root);
    }
Converts the tree into its mirror image (left ↔ right).

cpp
Copy
Edit
    void display() {
        cout << "In-order traversal: ";
        inOrderTraversal(root);
        cout << endl;
    }
Prints the tree in in-order (Left → Root → Right).

✅ Private Helper Functions
cpp
Copy
Edit
    Node* insertNode(Node* node, int val) {
        if (node == nullptr) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insertNode(node->left, val);
        } else if (val > node->data) {
            node->right = insertNode(node->right, val);
        }
        return node;
    }
Recursive function to insert a new value in the correct position (left if smaller, right if larger).

cpp
Copy
Edit
    bool searchNode(Node* node, int val) {
        if (node == nullptr) return false;
        if (node->data == val) return true;
        else if (val < node->data) return searchNode(node->left, val);
        else return searchNode(node->right, val);
    }
Recursively searches for a value in the tree.

cpp
Copy
Edit
    int calculateHeight(Node* node) {
        if (node == nullptr) return 0;
        int leftHeight = calculateHeight(node->left);
        int rightHeight = calculateHeight(node->right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
Finds the height of the tree recursively.

cpp
Copy
Edit
    void mirrorTree(Node* node) {
        if (node == nullptr) return;
        swap(node->left, node->right);
        mirrorTree(node->left);
        mirrorTree(node->right);
    }
Swaps left and right children of every node recursively to create a mirror image.

cpp
Copy
Edit
    void inOrderTraversal(Node* node) {
        if (node == nullptr) return;
        inOrderTraversal(node->left);
        cout << node->data << " ";
        inOrderTraversal(node->right);
    }
In-order traversal: prints tree in sorted order.

cpp
Copy
Edit
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }
Deletes all nodes recursively to free memory.

✅ Main Function
cpp
Copy
Edit
int main() {
    BinarySearchTree bst;
Creates an object bst of the BinarySearchTree class.

cpp
Copy
Edit
    int choice, value;
    while (true) {
        cout << "\nMenu:\n";
        ...
        cout << "Enter your choice: ";
        cin >> choice;
Displays a menu and asks the user to enter a choice.

cpp
Copy
Edit
        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
Case 1: Insert a value.

cpp
Copy
Edit
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                bst.search(value);
                break;
Case 2: Search a value.

cpp
Copy
Edit
            case 3:
                cout << "Minimum value in the tree: " << bst.findMin() << endl;
                break;
Case 3: Show the minimum value.

cpp
Copy
Edit
            case 4:
                cout << "Longest path (height) in the tree: " << bst.longestPath() << endl;
                break;
Case 4: Show height of the tree.

cpp
Copy
Edit
            case 5:
                bst.mirror();
                cout << "Tree has been mirrored." << endl;
                break;
Case 5: Convert tree to mirror image.

cpp
Copy
Edit
            case 6:
                bst.display();
                break;
Case 6: Display the tree in-order.

cpp
Copy
Edit
            case 7:
                cout << "Exiting program." << endl;
                return 0;
Case 7: Exit the program.

cpp
Copy
Edit
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}
Handles invalid input and keeps looping until exit.   */






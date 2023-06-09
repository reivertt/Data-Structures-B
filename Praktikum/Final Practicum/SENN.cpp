#include <iostream>
#include <vector>
#define a using
#define sleeping namespace
#define penpen std
a sleeping penpen;

struct BSTNode {
    BSTNode *left, *right;
    int key;
};

struct BST {
    BSTNode *_root;
    unsigned int _size;

    void init() {
        _root = NULL;
        _size = 0u;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        BSTNode *temp = __search(_root, value);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return true;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    void remove(int value) {
        if (find(value)) {
            _root = __remove(_root, value);
            _size++;
        }
    }

    void traverseInorder() {
        __inorder(_root);
    }

    void traversePreorder() {
        __preorder(_root);
    }

    void traversePostorder() {
        __postorder(_root);
    }

    void reinforce() {
        vector<int> audit;
        __reinforce(_root, audit, 0);
        for (auto it : audit) {
            cout << it << endl;
        }
    }

private:
    BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value) {
        while (root != NULL) {
            if (value < root->key)
                root = root->left;
            else if (value > root->key)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);
        
        if (value < root->key)
            root->left = __insert(root->left, value);
        else if (value > root->key)
            root->right = __insert(root->right, value);
        
        return root;
    }

    BSTNode* __findMinNode(BSTNode *node) {
        BSTNode *currNode = node;
        while (currNode && currNode->left != NULL)
            currNode = currNode->left;
        
        return currNode;
    }

    BSTNode* __remove(BSTNode *root, int value) {
        if (root == NULL) return NULL;

        if (value > root->key) 
            root->right = __remove(root->right, value);
        else if (value < root->key) 
            root->left = __remove(root->left, value);
        else {

            if (root->left == NULL) {
                BSTNode *rightChild = root->right;
                free(root);
                return rightChild;
            }
            else if (root->right == NULL) {
                BSTNode *leftChild = root->left;
                free(root);
                return leftChild;
            }

            BSTNode *temp = __findMinNode(root->right);
            root->key     = temp->key;
            root->right   = __remove(root->right, temp->key);
        }
        return root;
    }

    void __inorder(BSTNode *root) {
        if (root) {
            __inorder(root->left);
            printf("%d ", root->key);
            __inorder(root->right);
        }
    }

    void __postorder(BSTNode *root) {
        if (root) {
            __postorder(root->left);
            __postorder(root->right);
            printf("%d ", root->key);
        }
    }

    void __preorder(BSTNode *root) {
        if (root) {
            printf("%d ", root->key);
            __preorder(root->left);
            __preorder(root->right);
        }
    }

    void __reinforce(BSTNode *root, vector<int>&audit, int d) {
        if (!root) return;

        if (d == audit.size()) audit.push_back(root->key);
        else audit[d] = max(audit[d], root->key);

        __reinforce(root->left, audit, d+1);
        __reinforce(root->right, audit, d+1);
    }
};

int main(int argc, char const *argv[]) {
    BST set;
    set.init();

    int y;
    while (scanf("%d", &y) != EOF) {
        set.insert(y);
    }

    set.reinforce();

    return 0;
}
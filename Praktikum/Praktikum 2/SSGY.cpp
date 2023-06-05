#include <stdio.h>
#include <stdlib.h>

struct BSTNode {
    BSTNode *left, *right;
    int key, depth;
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

    int find(int value) {
        int depth = 1;
        BSTNode *temp = __search(_root, value, &depth);
        if (!temp)
            return false;
        
        if (temp->key == value)
            return depth;
        else
            return false;
    }

    void insert(int value) {
        if (!find(value)) {
            _root = __insert(_root, value);
            _size++;
        }
    }

    bool supplyDrop(int value){
        if (!find(value)) return false;

        int depth = 1, less = 0, more = 0;
        BSTNode *temp = __search(_root, value, &depth);

        if (temp->left == NULL && temp->right == NULL) return false;

        wingAllies(_root, depth, temp->key, &less, &more);
        if (!less || !more) return false;

        return true;
    }

    void wingAllies(BSTNode* root, int depth, int value, int *less, int *more){
        if (root == NULL)
            return;
        if (depth == 1){
            if (root->key < value) *less += 1; 
            if (root->key > value) *more += 1;
        }
        else if (depth > 1) {
            wingAllies(root->left, depth - 1, value, less, more);
            wingAllies(root->right, depth - 1, value, less, more);
        }
    }

private:
    BSTNode* __createNode(int value) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    
    BSTNode* __search(BSTNode *root, int value, int *depth) {
        while (root != NULL) {
            if (value == root->key) 
                return root;
            else if (value < root->key){
                root = root->left;
                *depth += 1;
            }
            else if (value > root->key){
                root = root->right;
                *depth += 1;
            }
        }
        return root;
    }

    BSTNode* __insert(BSTNode *root, int value) {
        if (root == NULL)
            return __createNode(value);
        
        if (value < root->key){
            root->left = __insert(root->left, value);
        }
        else if (value > root->key){
            root->right = __insert(root->right, value);
        }
        return root;
    }
};

int main(int argc, char const *argv[]) {
    BST set;
    set.init();

    int N, i = 0;
    scanf("%d", &N);
    while(i < N){
        int x;
        scanf("%d", &x);
        set.insert(x);
        i++;
    }

    int m;
    scanf("%d", &m);
    (set.supplyDrop(m)) ? printf("Supply aman\n") : printf("Ga aman, ganti lokasi!\n"); 

    return 0;
}
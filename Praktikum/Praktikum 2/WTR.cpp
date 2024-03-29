#include <stdio.h>
#include <stdlib.h>
#include <vector>

std::vector<int> leaf;

struct BSTNode {
    BSTNode *left, *right, *parent;
    int key, distance;
};

struct BST {
    // Member
    BSTNode *_root;
    unsigned int _size;

    // Function
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

    void insert(int value, int distance) {
        if (!find(value)) {
            _root = __insert(_root, value, distance);
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

    int distance(int value) {
        if (find(value)){
            std::vector<int> distance, temp = leaf;
            while(!temp.empty()){
              if (value == temp.back()) distance.push_back(0);
              else
              distance.push_back(findDistWrapper(_root, value, temp.back()));
              temp.pop_back();
            }
            int min = 100000;
            while(!distance.empty()){
              if (distance.back() < min) min = distance.back();
              distance.pop_back();
            }
            return min;
        }
        return -1;
    }

    //modify so this has weight
    int distanceFromRoot(BSTNode* root, int x){
        if (root->key == x)
            return 0;
        else if (root->key > x)
            return root->left->distance + distanceFromRoot(root->left, x);
            
        return root->right->distance + distanceFromRoot(root->right, x);
    }
    
    int distanceBetween2(BSTNode* root, int a, int b){
        if (!root)
            return 0;
            
        if (root->key > a && root->key > b)
            return distanceBetween2(root->left, a, b);
            
        if (root->key < a && root->key < b) // same path
            return distanceBetween2(root->right, a, b);
            
        if (root->key >= a && root->key <= b)
            return distanceFromRoot(root, a) + distanceFromRoot(root, b);
    }
    
    int findDistWrapper(BSTNode *root, int a, int b){
        if (a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        return distanceBetween2(root, a, b);  
    }
    
    void leaves(){
      __leaf_inorder(_root);
    }

private:
    // Utility Function
    BSTNode* __createNode(int value, int distance) {
        BSTNode *newNode = (BSTNode*) malloc(sizeof(BSTNode));
        newNode->key = value;
        newNode->distance = distance;
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

    //how to thingymajig, atau alternative ya lgsg bikin fungsi yg traverse everything trs assigns a parent
    BSTNode* __insert(BSTNode *root, int value, int distance) {
        if (root == NULL)
            return __createNode(value, distance);
        
        if (value < root->key){
            root->left = __insert(root->left, value, distance);
            root->left->parent = root;
        }
        else if (value > root->key){
            root->right = __insert(root->right, value, distance);
            root->right->parent = root;
        }
        
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
    
    void __leaf_inorder(BSTNode *root) {
        if (root) {
          __leaf_inorder(root->left);
          if (root->left == NULL && root->right == NULL) leaf.push_back(root->key);
          __leaf_inorder(root->right);
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
};

int main(int argc, char const *argv[]) {
    BST set;
    set.init();

    int n, t, m;
    scanf("%d %d", &n, &t);
    set.insert(t, 0);
    while(n--){
        int s, d;
        scanf("%d %d", &s, &d);
        set.insert(s, d);
    }
    
    set.leaves();
   
    scanf("%d", &m);

    while(m--){
        int p;
        scanf("%d", &p);
        printf("%d\n", set.distance(p));
    }
    return 0;
}
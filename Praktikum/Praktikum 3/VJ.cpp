#include <iostream>
#define we using
#define bare namespace
#define bears std
we bare bears;

struct AVLNode {
    int data;
    AVLNode *left, *right;
    int height, l, r, flag;
};

struct AVL {
private:
    AVLNode *_root;
    unsigned _size;

    AVLNode* _avl_createNode(int value, int flag) {
        AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
        newNode->data = value;
        newNode->height = 1;
        newNode->left = newNode->right = NULL;
        newNode->flag = flag;
        return newNode;
    }

    AVLNode* _search(AVLNode *root, int value) {
        while (root != NULL) {
            if (value < root->data)
                root = root->left;
            else if (value > root->data)
                root = root->right;
            else
                return root;
        }
        return root;
    }

    int _getHeight(AVLNode* node){
        if(node == NULL)
            return 0; 
        return node->height;
    }

    int _max(int a,int b){
        return (a > b) ? a : b;
    }

    AVLNode* _rightRotate(AVLNode* pivotNode){
        AVLNode* newParrent = pivotNode->left;
        pivotNode->left = newParrent->right;
        newParrent->right = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
        newParrent->height = _max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;
        
        return newParrent;
    }

    AVLNode* _leftRotate(AVLNode* pivotNode) {
        AVLNode* newParrent = pivotNode->right;
        pivotNode->right = newParrent->left;
        newParrent->left = pivotNode;

        pivotNode->height = _max(_getHeight(pivotNode->left), _getHeight(pivotNode->right)) + 1;
        newParrent->height = _max(_getHeight(newParrent->left), _getHeight(newParrent->right)) + 1;
        
        return newParrent;
    }

    AVLNode* _leftCaseRotate(AVLNode* node) {
        return _rightRotate(node);
    }

    AVLNode* _rightCaseRotate(AVLNode* node) {
        return _leftRotate(node);
    }

    AVLNode* _leftRightCaseRotate(AVLNode* node) {
        node->left = _leftRotate(node->left);
        return _rightRotate(node);
    }

    AVLNode* _rightLeftCaseRotate(AVLNode* node) {
        node->right = _rightRotate(node->right);
        return _leftRotate(node);
    }

    int _getBalanceFactor(AVLNode* node) {
        if(node == NULL)
            return 0;
        return _getHeight(node->left) - _getHeight(node->right);
    }

    AVLNode* _insert_AVL(AVLNode* node,int value, int flag) {
        if(node == NULL)
            return _avl_createNode(value, flag);
        if(value < node->data)
            node->left = _insert_AVL(node->left, value, flag);
        else if(value > node->data)
            node->right = _insert_AVL(node->right, value, flag);
        
        node->height = 1 + _max(_getHeight(node->left), _getHeight(node->right)); 

        int balanceFactor = _getBalanceFactor(node);
        
        if (balanceFactor > 1 && value < node->left->data)
            return _leftCaseRotate(node);
        if (balanceFactor > 1 && value > node->left->data)
            return _leftRightCaseRotate(node);
        if (balanceFactor < -1 && value > node->right->data)
            return _rightCaseRotate(node);
        if (balanceFactor < -1 && value < node->right->data)
            return _rightLeftCaseRotate(node);
        
        return node;
    }

    void _inorder(AVLNode *node) {
        if (node) {
            _inorder(node->left);
            printf("%d ", node->data);
            _inorder(node->right);
        }
    }

    int _travel(AVLNode *node) {
        if (node) {
            node->l = _travel(node->left);
            node->r = _travel(node->right);

            int dist = 0;
            if (node->l) dist += 1;
            if (node->r) dist += 1;
            if (dist + node->flag) dist += 1;

            return dist + node->l + node->r;
        }
        return 0;
    }

public:
    void init() {
        _root = NULL;
        _size = 0U;
    }

    bool isEmpty() {
        return _root == NULL;
    }

    bool find(int value) {
        AVLNode *temp = _search(_root, value);
        if (temp == NULL)
            return false;
        
        if (temp->data == value) return true;
        else return false;
    }

    void insert(int value, int flag) {
        if (!find(value)) {
            _root = _insert_AVL(_root, value, flag);
            _size++;
        }
    }

    void inorder() {
        this->_inorder(_root);
    }

    int travel() {
        return _travel(_root);
    }
};

int main(int argc, char const *argv[]) {
    AVL set;
    set.init();

    int n;
    cin >> n;
    while (n--){
        int a;
        char b;
        cin >> a >> b;
        (b == 'Y') ? set.insert(a, 1) : set.insert(a, 0);
    }

    cout << set.travel() << endl;

    return 0;
}
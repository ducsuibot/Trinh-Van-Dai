#include <iostream>
#include <string>
using namespace std;

// Dinh nghia node
struct Node {
    string data;  // Luu toan tu va toan hang
    Node* left;
    Node* right;

    // HHam tao node
    Node(string value) : data(value), left(NULL), right(NULL) {}
};

// Dinh nghia cay
struct ExpressionTree {
    Node* root;

    // HKhoi tao cay
    ExpressionTree() : root(NULL) {}
};

// Ham kiem tra toan hang toan tu
bool isOperand(const string& s) {
    return (isalpha(s[0]) || isdigit(s[0]));
}

// Ham kiem tra uu tien toan tu
int precedence(const string& op) {
    if (op == "+" || op == "-") return 1;
    if (op == "*" || op == "/") return 2;
    if (op == "^") return 3;
    return 0;
}

Node* buildExpressionTree(const string expr[], int& idx, int n) {
    if (idx >= n) return NULL;  // Ð?n cu?i bi?u th?c

    string token = expr[idx++];
    Node* newNode = new Node(token);

    if (isOperand(token)) {
        // Neu la toan hang ttra ve node nay
        return newNode;
    }

    // Neu la toan tu thi tiep tuc xay dung cay
    newNode->left = buildExpressionTree(expr, idx, n);   // Xay dung cay con trai
    newNode->right = buildExpressionTree(expr, idx, n);  // Xay dung cay con phai

    return newNode;
}

void preOrder(Node* root) {
    if (root == NULL) return;
    cout << root->data << " ";  // XXu ly node goc
    preOrder(root->left);       // Duyet cay con trai
    preOrder(root->right);      // Duyet cay con phai
}

void inOrder(Node* root) {
    if (root == NULL) return;
    inOrder(root->left);        // DUyet cay con trai
    cout << root->data << " ";  // Xu ly node goc
    inOrder(root->right);       // Duyet cay con phai
}

void postOrder(Node* root) {
    if (root == NULL) return;
    postOrder(root->left);      // DDuyet cay con trai
    postOrder(root->right);     // Duyet cay con phai
    cout << root->data << " ";  // Xu ly node goc
}

int main() {
    string expr[] = {"+", "-", "*", "a", "5", "/", "*", "b", "^", "c", "6", "d", "*", "-", "h", "f", "^", "e", "1", "2"};
    int idx = 0;
    int n = sizeof(expr) / sizeof(expr[0]);

    ExpressionTree tree;
    tree.root = buildExpressionTree(expr, idx, n);  // Tao cay

    cout << "Pre-order: ";
    preOrder(tree.root);
    cout << endl;

    cout << "In-order: ";
    inOrder(tree.root);
    cout << endl;

    cout << "Post-order: ";
    postOrder(tree.root);
    cout << endl;

    return 0;
}


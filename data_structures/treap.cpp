struct node {
    int val, pri;
    node *left, *right;
    node(int val) : val(val), pri(rand()), left(NULL), right(NULL) { }
    node(int val, int pri) : val(val), pri(pri), left(NULL), right(NULL) { }
};

//node *root;

// i store some of the pointers as references to allow for modification
// what these functions (split and merge) basically need to do, is to give us a pointer to the root of the
// two trees after splitting or one tree after merging
void split(node *root, int x, node *&left, node *&right) {
    if (!root) {
        left = right = NULL;
        return;
    }
    if (root->val <= x) {
        split(root->right, x, root->right, right);
        left = root;
    } else {
        split(root->left, x, left, root->left);
        right = root;
    }
}

void merge(node *&root, node *left, node *right) {
    if (!left || !right) {
        root = left ? left : right;
        return;
    }
    if (left->pri > right->pri) {
        merge(left->right, left->right, right);
        root = left;
    } else {
        merge(right->left, left, right->left);
        root = right;
    }
}

node *search(node *root, int val) {
    if (root == NULL || root->val == val) {
        return root;
    }
    if (root->val < val) return search(root->right, val);
    else return search(root->left, val);
}

void insert(node *&root, node *x) {
    if (!root) {
        root = x;
        return;
    }
    if (x->pri > root->pri) {
        split(root, x->val, x->left, x->right);
        root = x;
    } else {
        insert(root->val <= x->val ? root->right : root->left, x);
    }
}

void erase(node *&root, int val) {
    if (root->val == val) {
        node *to_delete = root;
        merge(root, root->left, root->right);
        delete to_delete;
    } else {
        erase(root->val <= val ? root->right : root->left, val);
    }
}

node *unite(node *left, node *right) {
    if (!left || !right) {
        return left ? left : right;
    }
    if (left->pri < right->pri) std::swap(left, right);
    node *leftch, *rightch;
    split(right, left->val, leftch, rightch);
    left->left = unite(left->left, leftch);
    left->right = unite(left->right, rightch);
    return left;
}

// not working, will fix in the future !!
void intersect(node *&root, node *left, node *right) {
    if (left == NULL || right == NULL) {
        return;
    }
    if (left->pri < right->pri) std::swap(left, right);
    node *leftch, *rightch;
    split(right, left->val, leftch, rightch);

    intersect(left, left->left, leftch);
    intersect(right, left->right, rightch);

    if (rightch == NULL) {
        merge(right, leftch, rightch);
    } else {
        node duplicate = node(left->val, left->pri);
        insert(root, &duplicate);
        root->left = left;
        root->right = right;
    }
}

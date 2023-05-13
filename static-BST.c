#include <stdlib.h>
#include <stdio.h>

int cmpfunc (const void * a, const void * b) {return ( *(int*)a - *(int*)b );}

typedef struct node {
    struct node *left_child;
    int key;
    struct node *right_child;
} Node;

Node *new_Node (int key) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->left_child = NULL;
    node->key = key;
    node->right_child = NULL;
    return node;
}

Node *new_BST (int sorted_arr[], int start, int end) {
    if (start > end) return NULL;

    int median = (start + end) / 2;
    Node *root = new_Node(sorted_arr[median]);
    root->left_child = new_BST(sorted_arr, start, median - 1);
    root->right_child = new_BST(sorted_arr, median + 1, end);
    return root;
}

Node *predecessor_query (Node *output, Node *current, int search_value) {
    if (current->key == search_value) return current;
    else if (current->key > search_value) {
        if (current->left_child == NULL)
            if (output->key > search_value) return NULL;
            else return output;
        else if (current->left_child->key > search_value) return predecessor_query(output, current->left_child, search_value);
        else return predecessor_query(current->left_child, current->left_child, search_value);
    } else {
        if (current->right_child == NULL) return current;
        else if (current->right_child->key > search_value) return predecessor_query(output, current->right_child, search_value);
        else return predecessor_query(current->right_child, current->right_child, search_value);
    }
}

int main () {
    int n = 500000;

    int data[n];
    FILE *DS = fopen("ds.txt", "r");
    for (int i = 0; i < n; i++) fscanf(DS, "%d", &data[i]);
    fclose(DS);
    
    qsort(data, n, sizeof(int), cmpfunc);
    Node *root = new_BST(data, 0, n - 1);

    int queries[n];
    int no = 0, query;
    char qry[3];
    FILE *QRY = fopen("qry.txt", "r");
    while (fscanf(QRY, "%s %d", qry, &query) == 2) queries[no++] = query;
    fclose(QRY);

    Node *predecessor;
    FILE *OUTPUT = fopen("output.txt", "w");
    for (int i = 0; i < n; i++) {
        predecessor = predecessor_query(root, root, queries[i]);
        if (predecessor != NULL) fprintf(OUTPUT, "%d\n", predecessor->key);
        else fprintf(OUTPUT, "no\n");
    }
    fclose(OUTPUT);
}

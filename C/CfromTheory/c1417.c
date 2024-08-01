/* Write a recursive function that counts the nodes of the tree. */

void tree_nodes(node *p)
{
    if(p == NULL) 
        return;
    cnt++;
    tree_nodes(p->left);
    tree_nodes(p->right);
}

/*  cnt could be a global variable initialized with 0 and incremented by one each time a node is visited */
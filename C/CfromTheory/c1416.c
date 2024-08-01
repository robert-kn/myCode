/* Add a recursive function that displays the smallest key value in the tree. */

void find_min(node *p)
{
    if(p == NULL) 
        return;
    if(p->left == NULL)
    {
        printf("Min:%d\n", p->key);
        return;
    }
    find_min(p->left);
}

/* In a binary search tree, the smallest value is stored in the leftmost node. Then, the recursion ends. 
To fnd the largest value, just change the pointer to p->right, to fnd the rightmost node. Call the function 
with argument the root pointer, to test its operation. For an alternative nonrecursive solution, try U.14.16. */
/* Write the following function to delete the key from the array. Hashing example */

int del_key(node **cur, int key);

Here is an example how to call it:

pos = hash_func(key);
del_key(&hash_arr[pos], key);

Answer:

int del_key(node **cur, int key)
{
    node *p, *prev;

    p = prev = *cur;
    while(p != NULL)
    {
        if(p->key == key)
        {
            if(p == *cur)
                *cur = p->next;
            else
                prev->next = p->next;
            
            free(p);
            return 0;
        }
        prev = p;
        p = p->next;
    }
    return -1;
}

/* The implementation is similar to that of del_node() in C.14.13. 

Before we fnish this chapter, we’d like to underline how important it is to have a basic knowledge of 
algorithms and data structures. To become an expert programmer in any language, not only in C, you’ll 
defnitely need it. With the data structures presented in this chapter and the algorithms in Chapter 12, 
we tried to introduce you to these concepts and give you an idea. Because there is still a lot to learn, 
our suggestion is to read a book that focuses on these subjects. It’d be for your own beneft.
*/
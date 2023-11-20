#include <iostream>
#include <vector>

struct t_node
{
    int key;
    t_node *left;
    t_node *right;

    t_node(int key)
        : key(key), left(NULL), right(NULL) {}

    void    insert(int insert_key)
    {
        if (key > insert_key)
        {
            if (left == NULL)
                left = new t_node(insert_key);
            else
                left->insert(insert_key);
        }
        else
        {
            if (right == NULL)
                right = new t_node(insert_key);
            else
                right->insert(insert_key);
        }
    }

    void    delete_sub(void)
    {
        if (left != NULL)
            left->delete_sub(), delete left;
        if (right != NULL)
            right->delete_sub(), delete right;
    }

    void    post_order(void)
    {
        if (left != NULL)
            left->post_order();

        if (right != NULL)
            right->post_order();

        std::cout << key << '\n';
    }
};


int main(void)
{
    int key;
    std::cin >> key;

    t_node  root(key);
    while (std::cin >> key)
        root.insert(key);

    root.post_order();
    root.delete_sub();
    return (0);
}

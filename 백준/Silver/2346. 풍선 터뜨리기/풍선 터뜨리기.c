#include <stdio.h>
#include <stdlib.h>

typedef struct s_node {
    struct s_node *left;
    struct s_node *right;
    int num;
    int idx;
} t_node;

t_node *readAndMakeNode() {
    int num;
    t_node *node = malloc(sizeof(t_node));

    scanf(" %d", &num);
    node->num = num;
    node->left = node->right = NULL;
    return node;
}

t_node *makeList(int size) {
    t_node *head;
    t_node *cur, *prev;

    head = prev = readAndMakeNode();
    head->idx = 1;
    for (int i = 2; i <= size; i++) {
        cur = readAndMakeNode();
        cur->idx = i;

        cur->left = prev;
        prev->right = cur;
        prev = cur;
    }
    prev->right = head;
    head->left = prev;
    return head;
}

t_node *moveRight(t_node *cur, int moveAmount) {
    while (moveAmount-- > 0) {
        cur = cur->right;
    }
    return cur;
}

t_node *moveLeft(t_node *cur, int moveAmount) {
    while (moveAmount-- > 0) {
        cur = cur->left;
    }
    return cur;
}

t_node *move(t_node *cur) {
    int moveAmount = cur->num;

    if (moveAmount > 0) {
        return moveRight(cur, moveAmount);
    }
    return moveLeft(cur, -moveAmount);
}

void simulation(t_node *head, int size) {
    while (size-- > 0) {
        t_node *toFree = head;
        head->left->right = head->right;
        head->right->left = head->left;

        printf("%d ", head->idx);

        if (size > 0) {
            head = move(head);
        }
        free(toFree);
    }
    printf("\n");
}

int main(void) {
    int size;

    scanf(" %d", &size);
    simulation(makeList(size), size);
    return (0);
}

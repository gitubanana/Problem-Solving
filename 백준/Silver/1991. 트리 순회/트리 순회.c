#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
    char data;
    struct tree* leftChild;
    struct tree* rightChild;
}tree;
typedef struct tree *treePointer;


treePointer Finder(treePointer node, char data){
    if(node == NULL){
        return NULL;
    }
    if(node->data == data){
    	return node;
    }
    else{
    	treePointer temp = Finder(node->leftChild, data);
    	if(temp != NULL){
    		return temp;
    	}
    	return Finder(node->rightChild, data);
    }
    return NULL;
}

treePointer maketreePointer(char data){
    treePointer node = (treePointer)malloc(sizeof(tree));
    node->data = data;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

void Preorder(treePointer node){
    if(node == NULL){
        return;
    }
    printf("%c", node->data);
    Preorder(node->leftChild);
    Preorder(node->rightChild);
}

void Inorder(treePointer node){
    if(node == NULL){
        return;
    }
    Inorder(node->leftChild);
    printf("%c", node->data);
    Inorder(node->rightChild);
}

void Postorder(treePointer node){
    if(node == NULL){
        return;
    }
    Postorder(node->leftChild);
    Postorder(node->rightChild);
    printf("%c", node->data);
}

int main(){
    treePointer node = maketreePointer(NULL);
    treePointer temp;
    int N;
    scanf("%d ", &N);
    for(int i = 0; i < N; i++){
        char a, b, c;
        scanf("%1c %1c %1c ", &a, &b, &c);
        temp = Finder(node, a);
        if(temp == NULL){
            node->data = a;
            if(b != '.'){
                node->leftChild = maketreePointer(b);
            }
            if(c != '.'){
                node->rightChild = maketreePointer(c);
            }
        }
        else{
            temp->data = a;
            if(b != '.'){
                temp->leftChild = maketreePointer(b);
            }
            if(c != '.'){
                temp->rightChild = maketreePointer(c);
            }
        }
    }
    Preorder(node);
    puts("");
    Inorder(node);
    puts("");
    Postorder(node);
    puts("");
    return 0;
}



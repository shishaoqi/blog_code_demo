#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct bt {
    void *root;
    int userSize, totalSize;
}btType;

typedef struct subData {
    void * left, * right;
}childDataT;

void MapBST(btType *bst)
{
    RecMapBST(bst, bst->root);
}

void RecMapBST(btType *top, void *t) {
    int value;
    childDataT *childData;

    if (t != NULL) {
        childData = (childDataT *) ((char *)t + top->userSize);

        value = *(int *)t;
        printf("%d\n", value);
        RecMapBST(top, childData->left);
        RecMapBST(top, childData->right);
    }
}


int main() {
    btType *top;
    childDataT *childData;

    top = (btType*)malloc(sizeof(btType));
    top->root = NULL;
    top->userSize = sizeof(int);
    top->totalSize = top->userSize + sizeof(btType);

    top->root = malloc(top->totalSize);
    *((int*)top->root) = 2;
    childData = (childDataT *) ((char *)top->root + top->userSize);
    childData->left = NULL;
    childData->right = NULL;

    
    //btType *leftChild;
    childDataT *childData2;
    childDataT *tmp;


    // leftChild = (btType*)malloc(sizeof(btType));
    // leftChild->root = NULL;
    // leftChild->userSize = top->userSize;
    // leftChild->totalSize = top->totalSize;

   childData2 = malloc(top->totalSize);
    *((int*)childData2) = 5;
    tmp = (childDataT *) ((char *)childData2 + top->userSize);
    tmp->left = NULL;
    tmp->right = NULL;
    childData->left = childData2;

    //btType *rightChild;
    childDataT *childData3;

    // rightChild = (btType*)malloc(sizeof(btType));
    // rightChild->root = NULL;
    // rightChild->userSize = top->userSize;
    // rightChild->totalSize = top->totalSize;

    childData3 = malloc(top->totalSize);
    *((int*)childData3) = 9;
    tmp = (childDataT *) ((char *)childData3 + top->userSize);
    tmp->left = NULL;
    tmp->right = NULL;
    childData->right = childData3;

    MapBST(top);
 }
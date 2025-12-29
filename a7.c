#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int item;
    struct Node *llink;
    struct Node *rlink;
};

typedef struct Node* NODE;

/* Create a new node */
NODE createNode(int item)
{
    NODE temp = (NODE)malloc(sizeof(struct Node));
    temp->item = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

/* Insert into BST */
NODE insert(int item, NODE root)
{
    NODE temp = createNode(item);
    NODE cur = root, prev = NULL;

    if (root == NULL)
        return temp;

    while (cur != NULL)
    {
        prev = cur;
        if (item < cur->item)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }

    if (item < prev->item)
        prev->llink = temp;
    else
        prev->rlink = temp;

    return root;
}

/* Find Minimum */
NODE findMin(NODE root)
{
    if (root == NULL)
        return NULL;

    while (root->llink != NULL)
        root = root->llink;

    return root;
}

/* Find Maximum */
NODE findMax(NODE root)
{
    if (root == NULL)
        return NULL;

    while (root->rlink != NULL)
        root = root->rlink;

    return root;
}

/* Count leaf nodes */
int countLeafNodes(NODE root)
{
    if (root == NULL)
        return 0;

    if (root->llink == NULL && root->rlink == NULL)
        return 1;

    return countLeafNodes(root->llink) +
           countLeafNodes(root->rlink);
}

int main()
{
    int n, item, choice, i;
    NODE root = NULL;

    while (1)
    {
        printf("\n--- BST MENU ---\n");
        printf("1. Create BST with N integers\n");
        printf("2. Find Minimum\n");
        printf("3. Find Maximum\n");
        printf("4. Count Leaf Nodes\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter %d integers:\n", n);
                for (i = 0; i < n; i++)
                {
                    scanf("%d", &item);
                    root = insert(item, root);
                }
                break;

            case 2:
                if (root == NULL)
                    printf("BST is empty!\n");
                else
                    printf("Minimum value = %d\n", findMin(root)->item);
                break;

            case 3:
                if (root == NULL)
                    printf("BST is empty!\n");
                else
                    printf("Maximum value = %d\n", findMax(root)->item);
                break;

            case 4:
                printf("Number of leaf nodes = %d\n", countLeafNodes(root));
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
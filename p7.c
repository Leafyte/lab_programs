#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int item;
    struct Node *llink;
    struct Node *rlink;
};

typedef struct Node* NODE;

NODE createNode(int item)
{
    NODE temp = (NODE)malloc(sizeof(struct Node));
    temp->item = item;
    temp->llink = NULL;
    temp->rlink = NULL;
    return temp;
}

NODE insert(int item, NODE root)
{
    NODE temp = createNode(item);
    NODE cur = root, prev = NULL;

    if(root == NULL)
        return temp;

    while(cur != NULL)
    {
        prev = cur;
        if(item < cur->item)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }

    if(item < prev->item)
        prev->llink = temp;
    else
        prev->rlink = temp;

    return root;
}

NODE search(int item, NODE root)
{
    NODE cur = root;
    while(cur != NULL)
    {
        if(item == cur->item)
            return cur;
        else if(item < cur->item)
            cur = cur->llink;
        else
            cur = cur->rlink;
    }
    return NULL;
}

void inorder(NODE root)
{
    if(root == NULL)
         return;
     inorder(root->llink);
     printf("%d ", root->item);
     inorder(root->rlink);
 }

void preorder(NODE root)
{
    if(root == NULL)
         return;
     printf("%d ", root->item);
     preorder(root->llink);
     preorder(root->rlink);
  }

void postorder(NODE root)
{
    if(root == NULL)
        return;
     postorder(root->llink);
     postorder(root->rlink);
     printf("%d ", root->item);
 }

int height(NODE root)
{
    if(root == NULL)
        return 0;
    int lh = height(root->llink);
    int rh = height(root->rlink);

    return (lh > rh ? lh : rh) + 1;
}

void zigzagTraversal(NODE root)
{
    if(root == NULL)
    {
        printf("Tree is empty.\n");
        return;
    }

    NODE s1[100], s2[100];
    int top1 = -1, top2 = -1;

    s1[++top1] = root;

    while(top1 != -1 || top2 != -1)
    {
        while(top1 != -1)
        {
            NODE temp = s1[top1--];
            printf("%d ", temp->item);

            if(temp->llink) s2[++top2] = temp->llink;
            if(temp->rlink) s2[++top2] = temp->rlink;
        }

        while(top2 != -1)
        {
            NODE temp = s2[top2--];
            printf("%d ", temp->item);

            if(temp->rlink) s1[++top1] = temp->rlink;
            if(temp->llink) s1[++top1] = temp->llink;
        }
    }
}

int main()
{
    int choice, item, n, i;
    NODE root = NULL, result;

    while(1)
    {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Create BST with N integers\n");
        printf("2. Insert an element\n");
        printf("3. Search an element\n");
        printf("4. Display Traversals\n");
        printf("5. Display Height of Tree\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter number of elements: ");
                scanf("%d", &n);
                printf("Enter %d integers:\n", n);
                for(i = 0; i < n; i++)
                {
                    scanf("%d", &item);
                    root = insert(item, root);
                }
                printf("BST created successfully.\n");
                break;

            case 2:
                printf("Enter item to insert: ");
                scanf("%d", &item);
                root = insert(item, root);
                printf("Item inserted.\n");
                break;

            case 3:
                printf("Enter item to search: ");
                scanf("%d", &item);
                result = search(item, root);
                if(result == NULL)
                    printf("Item not found in BST.\n");
                else
                    printf("Item %d found in BST.\n", item);
                break;

            case 4:
                printf("\nInorder   : ");
                inorder(root);
                printf("\nPreorder  : ");
                preorder(root);
                printf("\nPostorder : ");
                postorder(root);
                printf("\nZigzag    : ");
                zigzagTraversal(root);
                printf("\n");
                break;

            case 5:
                printf("Height of BST = %d\n", height(root));
                break;

            case 6:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
//string functions
#include <stdio.h>

int my_strlen(char str[]) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int my_strcmp(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i])
            return str1[i] - str2[i];
        i++;
    }
    return str1[i] - str2[i];
}

void my_strcat(char str1[], char str2[]) {
    int i = 0, j = 0;

    while (str1[i] != '\0') {
        i++;
    }

    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
}

void my_strrev(char str[]) {
    int i = 0, j = my_strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

int main() {

    int choice;
    char str1[90], str2[90];

    do {
        printf("\n--- Menu ---\n");
        printf("1. String Length\n");
        printf("2. String Compare\n");
        printf("3. String Concatenate\n");
        printf("4. String Reverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {

            case 1:
                printf("Enter a string: ");
                gets(str1);
                printf("Length = %d\n", my_strlen(str1));
                break;

            case 2:
                printf("Enter first string: ");
                gets(str1);
                printf("Enter second string: ");
                gets(str2);

                if (my_strcmp(str1, str2) == 0)
                    printf("Strings are equal\n");
                else
                    printf("Strings are not equal\n");
                break;

            case 3:
                printf("Enter first string: ");
                gets(str1);
                printf("Enter second string: ");
                gets(str2);
                my_strcat(str1, str2);
                printf("Concatenated string: %s\n", str1);
                break;

            case 4:
                printf("Enter a string: ");
                gets(str1);
                my_strrev(str1);
                printf("Reversed string: %s\n", str1);
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}

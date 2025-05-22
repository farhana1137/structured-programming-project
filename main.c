#include <stdio.h>
#include <stdlib.h>

int main() {
    int a[200];
    int size = 0;
    int cho;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Input array size and values\n");
        printf("2. Display array\n");
        printf("3. Update array\n");
        printf("4. Delete an value\n");
        printf("5. Sort array (Ascending or Descending)\n");
        printf("6. Search for an element\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &cho);

        switch (cho) {
            case 1: {
                printf("Enter the size of the array (1-200): ");
                scanf("%d", &size);
                if (size <= 0 || size > 200) {
                    printf("INVALID size. Must be between 1 and 200.\n");
                    size = 0;
                    break;
                }
                printf("Enter %d values:\n", size);
                for (int i = 0; i < size; i++) {
                    printf("Value %d: ", i + 1);
                    scanf("%d", &a[i]);
                }
                break;
            }

            case 2: {
               if (size == 0) {
                    printf("Array is not initialized.\n");
                    break;
                }
                printf("Array elements: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", a[i]);
                }
                printf("\n");
                break;
            }

            case 3: {
                 if (size == 0) {
                    printf("Array is not initialized. Use option 1 first.\n");
                    break;
                }
                int n;
                printf("Enter the index to update (0 to %d): ", size - 1);
                scanf("%d", &n);
                if (n >= 0 && n < size) {
                    printf("Enter the new value: ");
                    scanf("%d", &a[n]);
                    printf("Index %d updated.\n", n);
                } else {
                    printf("INVALID index.\n");
                }
                break;
            }

            case 4: {
                if (size == 0) {
                    printf("Array is not initialized. Use op 1.\n");
                    break;
                }
                int b;
                printf("Enter value to delete: ");
                scanf("%d", &b);
                int found = 0;
                for (int i = 0; i < size; i++) {
                    if (a[i] == b) {
                        for (int j = i; j < size - 1; j++) {
                            a[j] = a[j + 1];
                        }
                        found = 1;
                        size--;
                        printf("value %d deleted.\n", b);
                        break;
                    }
                }
                if (!found) {
                    printf("INVALID.\n");
                }
                break;
            }

            case 5: {
                if (size == 0) {
                    printf("Array is not initialized. Use op 1.\n");
                    break;
                }
                char X;
                printf("Enter A or a for ascending or D or d for descending: ");
                scanf(" %c", &X);
                if (X != 'A' && X != 'a' && X != 'D' && X != 'd') {
                    printf("INVALID option. Use A or D.\n");
                    break;
                }
                for (int i = 0; i < size - 1; i++) {
                    for (int j = i + 1; j < size; j++) {
                        if ((X == 'A' || X == 'a') && a[i] > a[j]) {
                            int temp = a[i];
                            a[i] = a[j];
                            a[j] = temp;
                        } else if ((X == 'D' || X == 'd') && a[i] < a[j]) {
                            int temp = a[i];
                            a[i] = a[j];
                            a[j] = temp;
                        }
                    }
                }
                printf("Array sorted is %s.\n", (X == 'A' || X == 'a') ? "ascending" : "descending");
                break;
            }

            case 6: {
                if (size == 0) {
                    printf("Array is not initialized. Use op 1.\n");
                    break;
                }
                int key;
                printf("Enter value to search: ");
                scanf("%d", &key);
                int ind[200], count = 0;
                for (int i = 0; i < size; i++) {
                    if (a[i] == key) {
                        ind[count++] = i;
                    }
                }
                if (count == 0) {
                    printf("value %d not found.\n", key);
                } else if (count == 1) {
                    printf("value %d found at index %d.\n", key, ind[0]);
                } else {
                    printf("value %d found at %d indexes: ", key, count);
                    for (int i = 0; i < count; i++) {
                        printf("%d ", ind[i]);
                    }
                    printf("\nEnter the index number: ");
                    int sel;
                    scanf("%d", &sel);
                    int flag = 0;
                    for (int i = 0; i < count; i++) {
                        if (ind[i] == sel) {
                            printf("Selected value %d at index %d.\n", key, sel);
                            flag = 1;
                            break;
                        }
                    }
                    if (!flag) {
                        printf("INVALID index.\n");
                    }
                }
                break;
            }

            case 7: {
                printf("Program Ended.\n");
                return 0;
            }

            default: {
                printf("Invalid.Enter a number from 1 and 7.\n");
            }
        }
    }

    return 0;
}

#include <iostream>
using namespace std;

void traversal(int arr[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion(int arr[], int n) {
    int i, insert_num, pos;
    printf("Enter the number you want to insert: ");
    scanf("%d", &insert_num);
    printf("Enter the position where you want to insert this number: ");
    scanf("%d", &pos);
    for(i = n; i >= pos-1; i--) {
        arr[i+1] = arr[i];
    }
    arr[pos-1] = insert_num;
    ++n;
    traversal(arr, n);
}

void deletion(int arr[], int n) {
    int i, del_num, pos;
    printf("Enter the position from where you want to delete the number: ");
    scanf("%d", &pos);
    for(i = pos-1; i < n; i++) {
        del_num = arr[pos-1];
        arr[i] = arr[i+1];
    }
    traversal(arr, n);
    printf("\nDeleted number is %d", del_num);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr)/sizeof(arr[0]);
    traversal(arr, size);
    insertion(arr, size);
    deletion(arr, size);
    return 0;
}

#include <stdio.h>


struct Item {
    int weight;
    int value;
    float ratio;
};


void swap(struct Item *a, struct Item *b) {
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}


void sortItems(struct Item arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].ratio < arr[j + 1].ratio) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}


float fractionalKnapsack(struct Item arr[], int n, int capacity) {

    sortItems(arr, n);

    float totalProfit = 0.0;

    for (int i = 0; i < n; i++) {


        if (arr[i].weight <= capacity) {
            totalProfit += arr[i].value;
            capacity -= arr[i].weight;
        }


        else {
            totalProfit += arr[i].ratio * capacity;
            break;
        }
    }

    return totalProfit;
}

int main() {

    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    for (int i = 0; i < n; i++) {

        printf("Enter weight and value of item %d: ", i + 1);
        scanf("%d %d", &arr[i].weight, &arr[i].value);


        arr[i].ratio = (float)arr[i].value / arr[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    float maxProfit = fractionalKnapsack(arr, n, capacity);

    printf("Maximum Profit = %.2f\n", maxProfit);

    return 0;
}
#include <stdio.h>

#define MAX 100

void Toposs(int V[MAX][MAX], int n) {
    int indegree[MAX], visited[MAX];
    int TP[MAX];
    int i, j, tp_count = 0;

    
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
        for (j = 0; j < n; j++) {
            if (V[j][i] == 1) {
                indegree[i]++;
            }
        }
    }


    for (i = 0; i < n; i++) {
        visited[i] = 0;
    }

   
    while (1) {
        int w = -1;

   
        for (i = 0; i < n; i++) {
            if (visited[i] == 0 && indegree[i] == 0) {
                w = i;
                break;
            }
        }

        
        if (w == -1)
            break;

        
        TP[tp_count++] = w;
        visited[w] = 1;

        // Reduce indegree of adjacent vertices
        for (i = 0; i < n; i++) {
            if (V[w][i] == 1) {
                indegree[i]--;
            }
        }
    }

 
    if (tp_count < n) {
        printf("No Topological Sequence (cycle detected)\n");
    } else {
        printf("Topological Sequence:\n");
        for (i = 0; i < tp_count; i++) {
            printf("%d ", TP[i]);
        }
        printf("\n");
    }
}

int main() {
    int n, i, j;
    int V[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &V[i][j]);
        }
    }

    Toposs(V, n);

    return 0;
}
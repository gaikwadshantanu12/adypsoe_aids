#include <iostream>
using namespace std;

#define INF 999
void printMatrix(int size, int graph[][]);

void floydWarshall(int size, int graph[][]) {
    // int graph[size][size];
    int matrix[size][size], i, j, k;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            matrix[i][j] = graph[i][j];
    
    // Adding vertices individually
    for (k = 0; k < size; k++) {
        for (i = 0; i < size; i++) {
            for (j = 0; j < size; j++) {
                if (matrix[i][k] + matrix[k][j] < matrix[i][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    printMatrix(size, matrix);
}

void printMatrix(int size, int matrix[][]) {
    //int matrix[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int no_of_vertices;
    cout << "\nNote - Use 999 number for denoting infinity\n\nEnter number of vertices : ";
    cin >> no_of_vertices;

    int MyGraph[no_of_vertices][no_of_vertices];

    cout << "\nEnter graph elements : " << endl;
    for(int i=0; i<no_of_vertices; i++) {
        for(int j=0; j<no_of_vertices; j++) {
            cout << "Enter element [" << i << "][" << j << "] : ";
            cin >> MyGraph[i][j];
        }
        cout << "\n";
    }

    cout << "\nYour graph elements : " << endl;
    for(int i=0; i<no_of_vertices; i++) {
        for(int j=0; j<no_of_vertices; j++) {
            cout << MyGraph[i][j] << "\t";
        }

        cout << "\n";
    }
    
    floydWarshall(no_of_vertices, MyGraph);
}


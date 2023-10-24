import java.util.Scanner;

class WarshallAlgorithm {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int no_of_vertices;
        System.out.print("\nNote - Use 999 number for denoting infinity\n\nEnter number of vertices : ");
        
        no_of_vertices = sc.nextInt();

        int MyGraph[][] = new int [no_of_vertices][no_of_vertices];

        System.out.println("\nEnter graph elements : ");

        for(int i=0; i<no_of_vertices; i++) {
            for(int j=0; j<no_of_vertices; j++) {
                System.out.print("Enter element ["+i+"]["+j+"] : ");
                MyGraph[i][j] = sc.nextInt();
             
            }
            System.out.println("\n");
        }

        System.out.println("\nYour graph elements : ");
        for(int i=0; i<no_of_vertices; i++) {
            for(int j=0; j<no_of_vertices; j++) {
                System.out.print(MyGraph[i][j] + "\t");
            }

            System.out.println();
        }
    
        floydWarshall(no_of_vertices, MyGraph);
        sc.close();
    }

    static void floydWarshall(int size, int graph[][]) {
        int matrix[][] = new int [size][size];
        int i, j, k;
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

    static void printMatrix(int size, int matrix[][]) {
        System.out.println("\n\nFinal Result :- ");
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (matrix[i][j] == 999)
                    System.out.print("INF");
                else
                    System.out.print(matrix[i][j]+"\t");
            }
            System.out.println("\n");
        }
    }
}
Program Description:
	
Scan the file and set the input data to the adjacency matrix[][]
(Detect @ and EOF by return of fscanf)

path[i][j]: 
Record the visited node except start and end in shortest path from i to j.

distance[i][j]:
Record the minimun of cost from i to j.

	/* count all costs and record the path */
	
void allCosts(int n, int matrix[][maxsize], int distance[][n], int path[][n]);

Record shortest distance and path in single source / All destination.

Because we record the shortest link each time, so there must be a node between a link from i to j.
I use a 2D array to record the node passed.


For example with the path A->D->C->B.
D->B    <C>
A->B    <D>
A->B    <E>    // not the shortest, not record






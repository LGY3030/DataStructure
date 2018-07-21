
ee: early time of all events
le: late time of all events
e: early time of all activities
l: late of all activities

/* set each array */
void set_ee(int n, int ee[], int matrix[][maxsize]);
void set_le(int n, int le[], int matrix[][maxsize]);
int set_EandL(int n, int e[], int l[], int ee[], int le[], int matrix[][maxsize]);
/* set the critical path in path[] */
void getPath(int n, int matrix[][maxsize], struct node path[], struct node cpath[], int *index, int id, int step);



<set array>
First, set ee[] and le[].
ee:
	start with ee[0] = 0
	ee[j] = max{ee[i] + cost(i, j)}
le:
	start with le[n-1] = ee[n-1]
	le[j] = min{le[i] - cost(i, j)}	
And we can set e & l by ee & le
e:
	e[i] = ee[k]
l:
	l[i] = le[l]
	
<set critical path>
cpath[]: an array to hold the data of the current path.
path[]: the array to hold the critical path.

To track the critical path, we can use DFS with back-tracking to set the cost and the node in the path.
When we reach the end node, compare the total cost with that of the last.
If it need more cost, copy the temp array's data to the target array, and track back until all paths are checked.

	
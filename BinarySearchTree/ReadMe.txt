Program Description:

#define:
	Exchange(): swap two value.
	max_size: max size of the tree.
	

<main>

Create a BST and flush all value to -1.
Use the %d and getchar to get a int and space until meet  '\n' char or -1.
Print the BST.

Get into a infinite loop to delete value.
User have to choice element to delete the particular index, and print the BST.


<curLevel>
	return the level index in.
	
<add>
	If it's empty, set the value to root.
	Compare the value inserted and current node value and move to the child node.
	When meet the -1, insert the value.
	Check whether the level increase.
	
<renewLevel>
	Scan all node in the level to check whether the level is empty.
	If so, decrease level.
	
<deleteValue>
	Check whether the node has a subtree, and set the lr.
	If it doesn't have, just delete.
	Else find the largest value in left subtree or smallest value in right subtree.
	Swap the value with the deleted node and delete the extreme value.
	If the node is the root of the subtree then continue swap and delete.
        So the time complexity of deleteValue is O(n).
	
<printBST>
	Use nested for loop to print the BST.
	




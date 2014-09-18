static int tree_size = 20;
static int tree_nodes = 0;

// Node struct
typedef struct node_stc {
	int left;
	int left_pos;
	int value;
	int right;
	int right_pos;
	int level;
	int father_pos;
} Node_Stc;

/**
 * Initialize a new tree
 * @author Luiz Venturote
 * @param int *T Tree
 * @return void
 */
void initTree(Node_Stc *T) {

	int size = tree_size, i=0, j=0, aux=0, next_val=0, level=0;
	
	for(i=0; i<size; i++) {
		
		// Node value
		T[i].value = 0;	
		T[i].father_pos = 0;
		
		// Lenf and Right position calc
		T[i].left_pos = (i*2)+1;
		T[i].right_pos = (i*2)+2;
		
		// Level calc
		T[i].level = level;
		switch(level) {
			case 0:
				level++;
				next_val++;	
				break;
			case 1:
				if(aux == 0) {
					aux = 1;
				} else {
					next_val = 6;	
					aux++;
					level++;
				}
				break;
			default:
				if(i==next_val) {					
					aux++;
					next_val = (int) next_val+pow(2.0, aux);
					level++;	
				}
				break;
		}
	}
	
	T[0].value = 10;
	T[1].value = 5;
	T[2].value = 15;
	T[3].value = 1;
	T[4].value = 7;
	T[4].value = 12;
	T[4].value = 20;
	
	// Father posistion
	for(i=0; i<size; i++) {
		
		// First position
		if(i == 0) {
		} else {
			
			for(j=0; j<size; j++) {
				
				if(T[j].level == (T[i].level-1) ) {
					
					if(T[ T[j].left_pos ].value == T[i].value) {
						printf("\n Left: i: %d - j: %d - T[i].value:%d - T[j].value:%d - T[i].level: %d - T[j].level: %d \n", i, j, T[i].value, T[j].value, T[i].level, T[j].level);
					}
					
					if(T[ T[j].right_pos ].value == T[i].value) {
						printf("\n Right: i: %d - j: %d - T[i].value:%d - T[j].value:%d - T[i].level: %d - T[j].level: %d \n", i, j, T[i].value, T[j].value, T[i].level, T[j].level);
					}
					
					printf("\n ----- \n");
					
				}
				
			}
			
			printf("\n +=====+ \n");
		}
		
//		printf(" Node: %d - Father: %d - Level: %d\n\n", T[i].value, T[T[i].father_pos].value, T[i].level);
			
	}
	
	
		
	
	
	
	
}

/**
 * Checks if the tree is empty
 * @author Luiz Venturote
 * @param int *T Tree
 * @return int Yes or No
 */
int checkTreeEmpty(Node_Stc *T) {
	return (T[0].value == 0);
}

/**
 * Add a new Node
 * @author Luiz Venturote
 * @param int *T Tree
 * @param int value Node value
 * @return int Yes or No
 */
int addNode(Node_Stc *T, int value) {

//	int i=0;
//	
//	// Increments a node
//	tree_nodes++;
//
//	// Check if the tree is empty
//	if(T[0].value == 0) {
//		T[0].value = value;
//		printf("\n Node add = %d \n\n", T[0].value);
//	} else {
//		for(i=0; i<tree_size; i++) {
//		
//			int left = (i*2)+1;
//			int right = (i*2)+2;
//			
//			printf("\n T[i]-Node: %d - Left: %d - Right: %d - Value: %d - T[left]: %d - T[right]: %d\n", T[i], left, right, value, T[left], T[right]);
//		
//			// Left
//			if( T[left] == 0 && value<T[i] ) {
//				T[left] = value;
//				printf("\n Node add left of the %d = %d \n\n", T[i], T[left]);
//				return 1;	
//			} else {
//				
//				// Right
//				if( T[right] == 0 && value>T[i] ) {
//					T[right] = value;
//					printf("\n Node add right of the %d = %d \n\n", T[i], T[right]);
//					return 1;
//				}
//				
//			}
//			
//		}
//	}
	
	return 0;
}

char * getSpace(int space_qty) {
	
	int i=0;
	char * space = malloc( space_qty * (sizeof(char)) );
	
	strcpy(space, "");
	for(i=0; i<space_qty; i++) {
		strcat(space, " ");
	}
	
	return space;
}

/**
 * Display tree
 * @author Luiz Venturote
 * @param int *T Tree
 * @return void
 */
void printTree(Node_Stc *T) {
	
	int i=0;
	
	for(i=0; i<tree_size; i++) {
			
		printf("\n - Node: %d - Left-Pos: %d - Right-Pos: %d - Level: %d\n\n", T[i].value, T[i].left_pos, T[i].right_pos, T[i].level);
			
	}				

}

/**
 * Initialize sequential binary tree representation
 * @author Luiz Venturote
 * @return void
 */
void BinaryTreeSeq() {
	
	// Initializes a new tree
	Node_Stc tree[tree_size];
	initTree(tree);
	
	// Print Tree
	printf("\n=====================\n");
	printTree(tree);
	printf("\n=====================\n");
	
	// Checks if the tree is empty
	printf("\nThe tree is empty? %d\n\n", checkTreeEmpty(tree) );
	
	// Add node
//	addNode(tree, 10);
//	addNode(tree, 5);
//	addNode(tree, 15);
//	addNode(tree, 1);
//	addNode(tree, 7);
//	addNode(tree, 25);
//	addNode(tree, 3);
//	
	// Print Tree
	printf("\n=====================\n");
	printTree(tree);
	printf("\n=====================\n");
	
	// Checks if the tree is empty
	printf("\nThe tree is empty? %d\n\n", checkTreeEmpty(tree) );
	
}
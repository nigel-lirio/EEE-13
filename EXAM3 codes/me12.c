/**
 * ME12 - Graph Query
 *
 * This program parses a graph file set-up as (source, dest, cost).
 * After parsing, the program prompts for a node and displays its
 * neighbors.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_CHUNK 1024

/**
 * typedef struct edgelist_t
 *
 * This edgelist_t structure contains the destination node and
 * cost of the connecting edge between the two nodes. This is used
 * to create an adjacency list with type edgelist_t**.
 *
 * An adjacency list is a list of nodes, with each containing a list
 * of its neighbors. For instance, if we have a code listing below:
 *
 *     edgelist_t **adjlist;
 *     // Some initialization here
 *     adjlist[0];
 *     adjlist[0][0].cost;
 *     printf("%d %d\n", adjlist[10][5].dest, adjlist[10][5].cost);
 *
 * Then, adjlist[0] contains a list of neighbors for the node named 0,
 * adjlist[0][0].cost contains the number neighbors of node 0 (which is
 * actually a hacked thing because it doesn't use the struct properly),
 * and the two calls to adjlist[10][5].dest and adjlist[10][5].cost define
 * the neighboring node and connecting edge cost in between. This means that
 * there is an edge between node 10 and node adjlist[10][5].dest, and that the
 * cost of the edge is adjlist[10][5].cost. This also means that adjlist[10][5]
 * is the 4th neighboring node of node 10 in the list.
 *
 * As a textual representation of the adjacency list, here is a bidirectional
 * graph with 6 nodes labeled from 0 to 5:
 *
 * node 0 => 2 neighbors
 *        => node 3, cost 10
 *        => node 4, cost 20
 * node 1 => 0 neighbors
 * node 2 => 3 neighbors
 *        => node 3, cost 2
 *        => node 4, cost 32
 *        => node 5, cost 48
 * node 3 => 2 neighbors
 *        => node 0, cost 10
 *        => node 2, cost 2
 * node 4 => 2 neighbors
 *        => node 0, cost 20
 *        => node 2, cost 32
 * node 5 => 2 neighbors
 *        => node 2, cost 48
 */
typedef struct {
	int dest;
	int cost;
} edgelist_t;

/**
 * void safe_free(void *ptr)
 *
 * @desc Frees a pointer safely. It just checks whether the
 * pointer is not null before freeing.
 * @params ptr The pointer to free
 */
void safe_free(void *ptr) {
	if(ptr != NULL) {
		free(ptr);
	}
}

/**
 * void chk_null_ptr(void *ptr)
 *
 * @desc Checks for a NULL pointer. This function is used after
 * each memory allocation.
 * @params ptr The pointer to check for NULL
 */
void chk_null_ptr(void *ptr) {
	if(ptr == NULL) {
		printf("Error: Cannot do alloc() :(\n");
		exit(1);
	}
}

/**
 * void clean_fgets(char *(*buf))
 *
 * @desc Removes the trailing newline inserted by fgets(),
 * if any.
 * @params buf A double pointer to the buffer to be cleaned.
 *
 * NB. This function changes the buffer buf
 */
void clean_fgets(char *(*buf)) {
	if((*buf)[strlen(*buf) - 1] == '\n') {
		(*buf)[strlen(*buf) - 1] = 0;
	}
}

int main(void) {
	int nmazes;
	int nnodes, nedges;
	int cnode;
	int na, nb, wt;
	int t, i;

	char *inbuf;
	FILE *fh;

	edgelist_t **adjlist;

	printf("Reading adjacency list...\n");

	/* Open file handle for reading */
	fh = fopen("maze_me12_sample4", "r");
	chk_null_ptr(fh);

	/* Read number of nodes and edges */
	fscanf(fh, "%d %d", &nnodes, &nedges);

	/* Initialize adjacency list */
	adjlist = (edgelist_t**) calloc(nnodes + 1, sizeof(edgelist_t *));
	chk_null_ptr(adjlist);

	for(i = 0; i < nnodes; i++) {
		adjlist[i] = (edgelist_t *) calloc(1, sizeof(edgelist_t));
		chk_null_ptr(adjlist[i]);

		adjlist[i][0].cost = 0;
	}

	/* Scan input */
	while(nedges--) {
		fscanf(fh, "%d %d %d", &na, &nb, &wt);

		/* Readjust adjacency list */
		adjlist[na] = (edgelist_t *) realloc(adjlist[na], (adjlist[na][0].cost + 2) * sizeof(edgelist_t));
		adjlist[nb] = (edgelist_t *) realloc(adjlist[nb], (adjlist[na][0].cost + 2) * sizeof(edgelist_t));
		chk_null_ptr(adjlist[na]);
		chk_null_ptr(adjlist[nb]);

		/* Bidirectional assignment */
		adjlist[na][adjlist[na][0].cost + 1].dest = nb;
		adjlist[nb][adjlist[nb][0].cost + 1].dest = na;
		adjlist[na][adjlist[na][0].cost + 1].cost = wt;
		adjlist[nb][adjlist[nb][0].cost + 1].cost = wt;

		/* Add number of edges */
		adjlist[na][0].cost++;
		adjlist[nb][0].cost++;
	}

	/* Print some statistics */
	printf("Adjacency list read successfully!\n");
	printf("Number of nodes is %d\n\n", nnodes);

	/* Initialize buffer */
	inbuf = (char *) calloc(FILE_CHUNK, sizeof(char));

	/* Infinite loop! */
	while(1) {
		printf("Enter a node to examine (enter \"exit\" to exit): ");
		fflush(stdout);

		/* Use fgets to get input and trim newline */
		fgets(inbuf, FILE_CHUNK, stdin);
		clean_fgets(&inbuf);

		/* Check if the user intends to exit the program */
		if(!strcmp(inbuf, "exit")) {
			break;
		}

		/* Convert input to integer without regard for malformed input */
		cnode = atoi(inbuf);

		/* Check for out-of-bounds integer index */
		if(cnode < 0 || cnode >= nnodes) {
			printf("ERROR: Range out of bounds. Please enter only nodes between 0 and %d.\n", nnodes - 1);
			continue;
		}

		/* Print neighbors */
		printf("Neighbors of node %d are:\n", cnode);
		for(i = 1; i <= adjlist[cnode][0].cost; i++) {
			printf("Node %d with edge cost %d\n", adjlist[cnode][i].dest, adjlist[cnode][i].cost);
		}
		printf("---END\n");
	}

	printf("Exiting program. Freeing memory...\n");

	/* Free input buffer */
	safe_free(inbuf);

	/* Free adjacency list */
	for(i = 0; i < nnodes; i++) {
		safe_free(adjlist[i]);
	}
	safe_free(adjlist);

	/* Close file handle */
	fclose(fh);

	printf("Closed program!\n");

	return 0;
}

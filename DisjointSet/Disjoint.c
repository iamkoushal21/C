#include <stdio.h>

void makeset(int s[], int nos)
{
	int i;
	for (i = 0; i <= nos; i++) {
		s[i] = i;
	}
}

int find(int x, int s[], int size)
{
	if (x < 0 || x > size) {
		return -1;
	}
	if (s[x] == x) {
		return x;
	} else {
		return find(s[x], s, size);
	}
}	

void unionset(int set1, int set2, int s[]) 
{
	if (set1 == set2 && set1 != -1) {
		return;
	}
	s[set1] = set2;
}


void makesetweight(int s[], int nos)
{
	for (int i = 0; i < nos; i++) {
		s[i] = -1;
	}
}

int findweight(int x, int s[])
{
	if (s[x] < 0) {
		return x;
	}
	return findweight(s[x], s);
}

void unionweight(int set1, int set2, int s[]) 
{
	if (set1 == set2) {
		return;
	}
	if (s[set1] < s[set2]) {
		s[set1] += s[set2];
		s[set2] = set1;
	} else {
		s[set2] += s[set1];
		s[set1] = set2;
	}
}

void makesetrank(int s[], int nos) 
{
	for (int i = 0; i < nos; i++) {
		s[i] = -1;
	}
}

int findrank(int s[], int x) 
{
	if (s[x] < 0) {
		return x;
	}

	//Path compression
	s[x] = findrank(s, s[x]);	

	return s[x];
}

void unionrank(int s[], int set1, int set2) 
{
	if (set1 == set2) {
		return;
	}

	if (s[set1] < s[set2]) {
		s[set2] = set1;
	} else if (s[set1] == s[set2]) {
		s[set1] = s[set1] - 1;
		s[set2] = set1;
	} else {
		s[set1] = set2;
	}
}

int main()
{
	int nos;
	int rnos;
	int i;
	int val1;
	int val2;
	int set1;
	int set2;
	int loop;
	int j;
	int temp;
	printf("No. of elements in Disjoint set ");
	scanf("%d", &nos);
	int s[nos];
	printf("Enter the nos. of relationships: ");
	scanf("%d", &rnos);

	/* Simple
	makeset(s, nos);
	for (i = 0; i < rnos; i++) {
		printf("\nEnter the element of %d relationship:\n", i + 1);
		scanf("%d%d", &val1, &val2);
		set1 = find(val1, s, nos);
		set2 = find(val2, s, nos);
		unionset(set1, set2, s);
	}*/

	//weight
	makesetweight(s, nos);
	for (i = 0; i < rnos; i++) {
		printf("\nEnter the element of %d relationship:\n", i + 1);
		scanf("%d%d", &val1, &val2);
		set1 = findweight(val1, s);
		set2 = findweight(val2, s);
		unionweight(set1, set2, s);
	}	

	for (i = 0; i < nos; i++) {
	/*	if (s[i] == -1234) {
			continue;
		}
	*/	loop = 1;
		j = i;
		while (loop) {
			if ((s[j] >= 0)) {
				printf("%d ->", j);
				temp = s[j];
				// putting a value because not to traverse again
	//			s[j] = -1234;
				j = temp;
			} else {
				printf("%d(ROOT)", j);
	//			s[j] = -1234;
				loop = 0;
			}
		}
		printf("\n");
	}
	
	//Rank 
	makesetrank(s, nos);
	for (i = 0; i < rnos; i++) {
		printf("\nEnter the element of %d relationship:\n", i + 1);
		scanf("%d%d", &val1, &val2);
		set1 = findrank(s, val1);
		set2 = findrank(s, val2);
		unionrank(s, set1, set2);
	}	
	
	for (i = 0; i < nos; i++) {
		printf("%d ", s[i]);
	}

	printf("\n");
	for (i = 0; i < nos; i++) {
		/*if (s[i] == -1234) {
			continue;
		}*/
		loop = 1;
		j = i;
		while (loop) {
			if (!(s[j] < 0)) {
				printf("%d ->", j);
				temp = s[j];
				// putting a value because not to traverse again
		//		s[j] = -1234;
				j = temp;
			} else {
				printf("%d(ROOT)", j);
		//		s[j] = -1234;
				loop = 0;
			}
		}
		printf("\n");
	}






	//No. of connected componenets AND Connectivity
	printf("\nNo. of connected componenets:\n");
	int T;
	int V;
	int v1, v2;
	int count;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &V);
		int vertices[V];
		int adj[V][V];
		makesetweight(vertices, V);
		for (i = 0; i < V; i++) {
			for (j = 0; j < V; j++) {
				scanf("%d", &adj[i][j]);
				if (adj[i][j] == 1) {
					v1 = findweight(i, vertices);
					v2 = findweight(j, vertices);
					unionweight(v1, v2, vertices);
				}
			}
		}
		count = 0;
		
		//TO PRINT REPRESENTATIVE
		/*for (i = 0; i < V; i++) {
			if (vertices[i] < 0) {
				printf("%d", i);
				count++;
			}
		}*/

		if (count == 1) {
			printf("Connected\n");
		} else {
			printf("Disconnected\n");
		}
		printf("Connected components  is %d\n", count);
	}
}

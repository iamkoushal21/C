#include <stdio.h>

//Disjoint set using union by weight
void makeset(int s[], int nos) 
{
	for (int i = 0; i < nos; i++) {
		s[i] = -1;
	}
}

int find(int s[], int x) 
{
	if (s[x] < 0) {
		return x;
	}	
	return find(s, s[x]);
}

void unionset(int s[], int set1, int set2) 
{
	if (s[set1] < s[set2]) {
		s[set1] += s[set2];
		s[set2] = set1;

	} else {
		s[set2] += s[set1];
		s[set1] = set2;
	}
}

void main()
{
	int nos;
	int T;
	int i;
	int j;
	int set1;
	int set2;
	int cycle;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &nos);
		int vertices[nos];
		int adj[nos][nos];
		makeset(vertices, nos);
		for (i = 0; i < nos; i++) {
			for (j = 0; j < nos; j++) {
				scanf("%d", &adj[i][j]);
			}
		}

		for (i = 0; i < nos; i++) {
			for (j = i; j < nos; j++) {
				if (adj[i][j] == 1) {
					set1 = find(vertices, i);
					set2 = find(vertices, j);
					if (set1 == set2) {
						printf("YES\n");
						cycle = 1;

						break;
					} else {
						cycle = 0;
					}	
					unionset(vertices, set1, set2);
				}
			}
			if (cycle == 1) {
				break;
			}
		}
		if (cycle == 0) {
			printf("NO\n");
		} 
	}
}

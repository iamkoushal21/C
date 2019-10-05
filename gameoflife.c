#include <stdio.h>

int nos;
static int gen = 1;
void generation(int currentgen[nos][nos])
{
	int i,j,k,l;
	int saturation = 0;
	int alives = 0;
	int zerogame = 0;
	int gamenextgen[nos][nos];
	for (i = 0; i < nos; i++) {
		for (j = 0; j < nos; j++) {
			gamenextgen[i][j] = 0;
		}
	}
	
	for (i = 1; i < nos - 1; i++) {
		for (j = 1; j < nos - 1; j++) {
			alives = 0;
			alives = currentgen[i-1][j-1] + currentgen[i-1][j] + currentgen[i-1][j+1] + currentgen[i][j-1] + currentgen[i][j+1] + currentgen[i+1][j-1] + currentgen[i+1][j] + currentgen[i+1][j+1];
			if (currentgen[i][j] == 1 && alives < 2) {
				gamenextgen[i][j] = 0;
			} else if (currentgen[i][j] == 1 && alives > 3) {
				gamenextgen[i][j] = 0;
			} else if (currentgen[i][j] == 0 && alives == 3) {
				gamenextgen[i][j] = 1;
			} else {
				gamenextgen[i][j] = currentgen[i][j];
			}
		}
	}
	printf("Game of Life Next Generation:\n");
	for (i = 1; i < nos - 1; i++) {
		for (j = 1; j < nos - 1; j++) {
			printf("%3d", gamenextgen[i][j]);
		}
		printf("\n");
	}
	for (i = 1; i < nos - 1; i++) {
		for (j = 1; j < nos - 1; j++) {
			if (gamenextgen[i][j] != 0) {
				zerogame++;
			}
		       	if (gamenextgen[i][j] != currentgen[i][j]) {
				saturation++;
			}
		}
	}
	
	if (gen == 5) {
		printf("\nGeneration are going further on so creating till 5 generation to only");
		
		return;
	}

	if (zerogame != 0 && saturation != 0) {
		gen++;
		generation(gamenextgen);
	}
}

int main()
{
	int i,j;
	printf("Enter the Game of life matrix size: ");
	scanf("%d", &nos);
	nos = nos + 2;
	int game[nos][nos];			
	printf("\nEnter the matrix in only 0-Dead or 1-Alive Form:\n");
	for(i = 1; i < nos -1; i++) {
		for (j = 1; j < nos -1; j++) {
			scanf("%d", &game[i][j]);
		}
	}

	printf("Game of life matrix before generation::\n");
	for (i = 1; i < nos -1; i++) {
		for (j = 1; j < nos-1; j++) {
				printf("%3d", game[i][j]);
		}
		printf("\n");
	}
	for (j = 0; j < nos; j++) {
		game[0][j] = 0;
		game[nos-1][j] = 0;
	}
	for (i = 0; i < nos; i++) {
		game[i][0] = 0;
		game[i][nos-1] = 0;
	}
	generation(game);

	return 0;
}

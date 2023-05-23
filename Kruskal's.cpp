#include<stdio.h>

int main(){
	int row = 0, col = 0;
	printf("Enter row and column: "); scanf("%d %d",&row, &col);
	
	int v[row][col];
	printf("\nEnter Edges: ");
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			printf("Enter %dth row and %dth col: , ", row, col); scanf("%d",&v[row][col]);
		}
	}
	
	
	return 0;
}
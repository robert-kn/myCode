#include <stdio.h>
#include <stdlib.h>

/********************************
function prototypes
********************************/
void displayBoard();
int verifySelection(int, int);
void checkForWin();


/******************
global variables
******************/

char board[8];
char cWhoWon = '\0';
int iCurrentPlayer=0;

/******************************************************
begin main function
******************************************************/

void main(){

	int x;
	int iSquareNum = 0;

	for(x = 0; x < 9; x++)
		board[x] = '\0';

	displayBoard();

	while(cWhoWon == '\0'){
	
		printf("\n %c \n", cWhoWon);

		if(iCurrentPlayer == 1 || iCurrentPlayer == 0){

			printf("\n PLAYER 1 \n");

			printf("Enter an available square number (1-9): ");

			scanf("%d", &iSquareNum);

			if( verifySelection(iSquareNum, iCurrentPlayer) == 1)
				iCurrentPlayer = 1;
			else
				iCurrentPlayer = 2;

		}

		else {
			printf(" \n PLAYER 2 \n");
			printf("Enter an available square number (1-9): ");
			scanf("%d", &iSquareNum);

			if( verifySelection(iSquareNum, iCurrentPlayer) == 1)
				iCurrentPlayer = 2;
			else
				iCurrentPlayer = 1;
		} // end-if

		displayBoard();
		checkForWin();

	} // end-loop

} // end-main-function


/*********************************************************
begin function definition
*********************************************************/

void displayBoard() {

	system("clear");
	printf("\n\t|\t|\n");
	printf("\t|\t|\n");
	printf("   %c\t|   %c\t|   %c\n", board[0], board[1], board[2]);
	printf("--------|-------|---------\n");
	printf("\t|\t|\n");
	printf("   %c\t|   %c\t|   %c\n", board[3], board[4], board[5]);
	printf("--------|-------|---------\n");
	printf("\t|\t|\n");
	printf("   %c\t|   %c\t|   %c\n", board[6], board[7], board[8]);
	printf("\t|\t|\n");

} // end function definition



/********************************************************
begin function definition
********************************************************/

int verifySelection(int iSquare, int iPlayer) {


	if( board[iSquare - 1] == '\0' && (iPlayer == 1 || iPlayer == 0) ){
			
		board[iSquare - 1] = 'X';
		return 0;
	}

	else if( board[iSquare - 1] == '\0' && iPlayer == 2) {

		board[iSquare - 1] = '0';
		return 0;
	}
	else
		return 1;

} // end function definition



/********************************************************
begin function definition
********************************************************/

void checkForWin() {

	int catTotal;
	int x;

	if(board[0] == 'X' && board[1] == 'X' && board[2] == 'X')
		cWhoWon = 'X';

	else if(board[3] == 'X' && board[4] == 'X' && board[5] == 'X')
		cWhoWon = 'X';

	else if(board[6] == 'X' && board[7] == 'X' && board[8] == 'X')
		cWhoWon = 'X';

	else if(board[0] == 'X' && board[3]== 'X' && board[6] == 'X')
		cWhoWon = 'X';

	else if(board[1] == 'X' && board[4] == 'X' && board[7] == 'X')
		cWhoWon = 'X';

	else if(board[2] == 'X' && board[5] == 'X' && board[8] == 'X')
		cWhoWon = 'X';

	else if(board[0] == 'X' && board[4] == 'X' && board[8] == 'X')
		cWhoWon = 'X';

	else if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
		cWhoWon = 'X';

	// '0' tranche

	if(board[0] == '0' && board[1] == '0' && board[2] == '0')
		cWhoWon = '0';

	else if(board[3] == '0' && board[4] == '0' && board[5] == '0')
		cWhoWon = '0';

	else if(board[6] == '0' && board[7] == '0' && board[8] == '0')
		cWhoWon = '0';

	else if(board[0] == '0' && board[3]== '0' && board[6] == '0')
		cWhoWon = '0';

	else if(board[1] == '0' && board[4] == '0' && board[7] == '0')
		cWhoWon = '0';

	else if(board[2] == '0' && board[5] == '0' && board[8] == '0')
		cWhoWon = '0';

	else if(board[0] == '0' && board[4] == '0' && board[8] == '0')
		cWhoWon = '0';

	else if(board[2] == 'X' && board[4] == 'X' && board[6] == 'X')
		cWhoWon = 'X';
	

	if( cWhoWon == 'X' ){
		printf("\nX wins!\n");
		return;
	}

	else if( cWhoWon == '0' ){
		printf("\n0 wins!\n");
		return;
	}

	for(x = 0; x < 9; x++){
		if(board[x] != '\0')
			catTotal += 1;
	}

	if(catTotal == 9){
		cWhoWon = 'C';
		printf("\nCAT game\n");
		return;
	}


}































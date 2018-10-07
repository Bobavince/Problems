#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
using namespace std;

//structure to define a move
struct Move
{
    int row, col;
};

char pc = 'X', opponent = 'O';


//returns true/false depending upon the moves left on the board
bool isMovesLeft(char board[3][3])
{
    for (int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (board[i][j]=='_')
                return true;
    return false;
}

void display_board(char board[3][3])                      //Displays the current contents of the board
{
    cout<<"\n";
	for(int i=0;i<3;i++)
		{
            for(int j=0;j<3;j++)
            {
                cout<<board[i][j]<<"\t";
            }
            cout<<endl;
        }
    cout<<"\n";
}

//Checking if the PC or the Opponent has won
int possible_win(char player,char b[3][3])
{
    // checking rows for a win
	for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] &&
            b[row][1]==b[row][2])
        {
            if (b[row][0]==player)
                return 1;
        }
    }
    // checking  columns for a win
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] &&
            b[1][col]==b[2][col])
        {
            if (b[0][col]==player)
                return 1;
        }
    }
    // checking diagonals for a win
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==player)
            return 1;
    }

    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==player)
            return 1;
    }

    //if neither wins..
    return 0;
}

//Evaluation function
int evaluate(char b[3][3])
{
    // checking rows for a win
    for (int row = 0; row<3; row++)
    {
        if (b[row][0]==b[row][1] &&
            b[row][1]==b[row][2])
        {
            if (b[row][0]==pc)
                return +10;
            else if (b[row][0]==opponent)
                return -10;
        }
    }

    // checking  columns for a win
    for (int col = 0; col<3; col++)
    {
        if (b[0][col]==b[1][col] &&
            b[1][col]==b[2][col])
        {
            if (b[0][col]==pc)
                return +10;

            else if (b[0][col]==opponent)
                return -10;
        }
    }

    // checking diagonals for a win
    if (b[0][0]==b[1][1] && b[1][1]==b[2][2])
    {
        if (b[0][0]==pc)
            return +10;
        else if (b[0][0]==opponent)
            return -10;
    }

    if (b[0][2]==b[1][1] && b[1][1]==b[2][0])
    {
        if (b[0][2]==pc)
            return +10;
        else if (b[0][2]==opponent)
            return -10;
    }

    //if neither wins..
    return 0;
}

// function to try out every possibility
int minimax(char board[3][3], int depth, bool isMax, int alpha, int beta)
{
    int score = evaluate(board);

    // score of +10 indicates maximizer's win
    if (score == 10)
        return score;

    // score of -10 indicates minimizer's win
    if (score == -10)
        return score;

    // if no moves left
    if (isMovesLeft(board)==false)
        return 0;

    if (isMax)
    {
        int best = -1000;

        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Checking if cell is empty
                if (board[i][j]=='_')
                {
                    board[i][j] = pc;

                    // Calling minimax recursively and choosing the maximum value
                    best = max( best,
                        minimax(board, depth+1, !isMax, alpha, beta) );

                    // Undo the move
                    board[i][j] = '_';
                    alpha = max(alpha, best);

                    // Alpha Beta Pruning
                    if (beta <= alpha)
                        break;
                }
            }
        }
        return best;
    }

    // If this minimizer's move
    else
    {
        int best = 1000;

        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {

                if (board[i][j]=='_')
                {

                    board[i][j] = opponent;

                    best = min(best,
                           minimax(board, depth+1, !isMax, alpha, beta));

                    board[i][j] = '_';
                    beta = min(beta, best);

                    // Alpha Beta Pruning
                    if (beta <= alpha)
                        break;
                        }
            }
        }
        return best;
    }
}

// This will return the best possible move for the player
Move findBestMove(char board[3][3])
{
    int bestVal = -1000;
    Move bestMove;
    bestMove.row = -1;
    bestMove.col = -1;


    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {

            if (board[i][j]=='_')
            {

                board[i][j] = pc;

                int moveVal = minimax(board, 0, false,-1000,1000);

                board[i][j] = '_';

                // If the value of the current move is more than the best value
                if (moveVal > bestVal)
                {
                    bestMove.row = i;
                    bestMove.col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    return bestMove;
}



int main()
{
	char board[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            board[i][j]='_';
        }
    }
	int t;
	cout<<"The current board is \n";
	display_board(board);
	cout<<"Enter the turn"<<endl;
	cout<<"1. Press 0 for Player's turn first"<<endl;
	cout<<"2. Press 1 for PC's turn first"<<endl;
	cin>>t;
	if(t==0)       //user turn
	{
        cout<<"It is the Player's turn first"<<endl;
        while(1)
        {
            if(t%2==0)
                {
                    if(t!=0)
                    {
                        cout<<"PC's turn"<<endl;
                        Move bestMove = findBestMove(board);
                        board[bestMove.row][bestMove.col]=pc;
                        display_board(board);
                    }
                }
            else
                {
                int rown, coln;
                cout<<"Please enter your next move row and column respectively"<<endl;
                cin>>rown;
                cin>>coln;
                while(board[rown][coln]!='_')
                {
                    cout<<"Please enter a valid position"<<endl;
                    cin>>rown;
                    cin>>coln;
                }
                board[rown][coln]=opponent;
                display_board(board);

                if(t==9)
                {
                    cout<<"Game Drawn"<<endl;
                    exit(0);
                }
                }
				if (possible_win(pc,board)==1)
                    {
                        cout<<"The PC Won!!!!"<<endl;
                        exit(0);
                    }
            if (possible_win(opponent,board)==1)
                    {
                        cout<<"The Player Defeated the PC!!!!"<<endl;
                        exit(0);
                    }
            t++;

        }
	}
	else
	{
	    cout<<"It is the PC's turn first"<<endl;
		while(1)
	{
		if(t%2==0)
		{
			int rown, coln;
			cout<<"Please enter your next move row and column respectively"<<endl;
			cin>>rown;
			cin>>coln;
			while(board[rown][coln]!='_')
            {
                cout<<"Please enter a valid position"<<endl;
                cin>>rown;
                cin>>coln;
            }
            board[rown][coln]=opponent;
			display_board(board);
		}
		else
        {
            if(t!=0)
                {
                    cout<<"PC's turn"<<endl;
                    Move bestMove = findBestMove(board);
                    board[bestMove.row][bestMove.col]=pc;
                    display_board(board);
                }
            if(t==9)
            {
                cout<<"Game Drawn"<<endl;
                exit(0);
            }
		}
		if (possible_win(pc,board)==1)
                {
                    cout<<"The PC Won!!!!"<<endl;
                    exit(0);
                }
        if (possible_win(opponent,board)==1)
                {
                    cout<<"The Player Defeated the PC!!!!"<<endl;
                    exit(0);
                }
		t++;
	}
	}


}


/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(TicTacToeBoardTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, getPiece)
{
	TicTacToeBoard TTT;
	TTT.placePiece(0,0);
	ASSERT_TRUE(TTT.getPieceOnLoc(0,0) == 'A');
}

TEST(TicTacToeBoardTest, clearBoard)
{
	bool checker = true;
	TicTacToeBoard TTT;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
			TTT.placePiece(i,j);
	}
	TTT.clearBoard();
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(TTT.getPieceOnLoc(i, j)!='B')
				checker = false;
		}
	}
	ASSERT_TRUE(checker);		
}

TEST(TicTacToeBoardTest, checkWinnerforBLANK)
{
	TicTacToeBoard TTT;	
	bool check = false;
	if(TTT.getWinner() == X || TTT.getWinner() == O)
	{
		check = true;
	}
	ASSERT_FALSE(check);
}

TEST(TicTacToeBoardTest, checkwinnerFORWARD_DIAGONAL)
{
	TicTacToeBoard TTT;
	bool check = false;
	TTT.placePiece(0,0);
	TTT.placePiece(0,1);
	TTT.placePiece(1,1);
	TTT.placePiece(1,0);
	TTT.placePiece(2,2);
	if(TTT.getWinner() == X)
		check = true;
	ASSERT_TRUE(check);
}

TEST(TicTacToeBoardTest, checkWinnerREVERSE_DIAGONAL)
{
	TicTacToeBoard TTT;
	bool check = false;
	TTT.placePiece(0,2);
	TTT.placePiece(0,0);
	TTT.placePiece(1,1);
	TTT.placePiece(2,2);
	TTT.placePiece(2,0);
	if(TTT.getWinner() == X)
		check = true;
	ASSERT_TRUE(check);
}

TEST(TicTacBoardText, checkWinnerBLANK)
{
	TicTacToeBoard TTT;
	bool check = false;
	TTT.placePiece(0,0); //X
	TTT.placePiece(0,1); //Y
	TTT.placePiece(0,2); //X
	TTT.placePiece(1,0); //Y
	TTT.placePiece(1,2); //X
	TTT.placePiece(1,1); //Y
	TTT.placePiece(2,1); //X
	TTT.placePiece(2,2); //Y
	TTT.placePiece(2,0); //X
	if(TTT.getWinner() == Blank)
		check = true;
	ASSERT_TRUE(check);
}
TEST(TicTacToeBoardTest, checkWinnerHORIZONTAL)
{
	TicTacToeBoard TTT;
	bool check = false;
	TTT.placePiece(0,0);
	TTT.placePiece(1,1);
	TTT.placePiece(0,2);
	TTT.placePiece(1,0);
	TTT.placePiece(0,1);
	if(TTT.getWinner() == X)
		check = true;
	ASSERT_TRUE(check);
}

TEST(TicTacToeBoardTest, checkWinnerVertical)
{
	TicTacToeBoard TTT;
	bool check = false;
	TTT.placePiece(0,0);
	TTT.placePiece(2,2);
	TTT.placePiece(1,0);
	TTT.placePiece(1,2);
	TTT.placePiece(2,0);
	if(TTT.getWinner() == X)
		check = true;
	ASSERT_TRUE(check);
}

TEST(TicTacBoardTest, checkWinnerINVALID)
{
	TicTacToeBoard TTT;
	bool check = false;
	TTT.placePiece(0,0);
	if(TTT.getWinner() == Invalid)
		check = true;
	ASSERT_TRUE(check);
}
TEST(TicTacToeBoardTest, checkToggle)
{
	bool checker = false;
	TicTacToeBoard TTT;
	if(TTT.getTurn() == 'X')
	{
		TTT.placePiece(0, 0);
		if(TTT.getTurn() == 'O')
		{
			TTT.placePiece(0,1);
			if(TTT.getTurn() == 'X')
				checker = true;
		}
	}
	else
	{
		TTT.placePiece(0,0);
		if(TTT.getTurn() == 'X')
		{
			TTT.placePiece(0,1);
			if(TTT.getTurn() == 'O')
				checker = true;
		}
	}
	ASSERT_TRUE(checker);
}















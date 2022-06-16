#include <iostream>
#include <cctype>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char currentMarker;
int currentPlayer;

void drawBoard()
{
  cout << "Tic Tac Toe v1.0" << endl;
  cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
  cout << "---------" << endl;
  cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
  cout << "---------" << endl;
  cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

char detWinner()
{
  for (int i = 0; i < 3; i++)
    {
      if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
        return currentPlayer; 
      if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
        return currentPlayer; 
    }
  if(board[0][0] == board[1][1] && board[1][1] == board[2][2])
    return currentPlayer; 
  if(board[0][2] == board[1][1] && board[1][1] == board[2][0])
    return currentPlayer;

  return 0;
}

void locateMarker(int boardVal)
{
  int row = boardVal / 3;
  int col;
  
  if (boardVal % 3 == 0)
    row -= 1;
  else
    row = row;
  if (boardVal % 3 == 0)
    col = 2;
  else
    col = (boardVal % 3) - 1;

  board[row][col] = currentMarker;
}

void game()
{
  char player1Mkr;
  int slot;
  int winner;
  
  do{
  cout << "Player one, choose your marker (X or O) : " << endl;
  cin >> player1Mkr;
  currentPlayer = 1;
  currentMarker = player1Mkr;
  player1Mkr = toupper(player1Mkr);
  system("clear");
  
    if(player1Mkr == 'X' || player1Mkr == 'O')
  {
    drawBoard();
    for (int i = 0; i < 9; i++)
    {
      cout << endl;
      cout << "Player " << currentPlayer << " turn. Enter the slot number : ";
      cin >> slot;
      if(slot == 1)
  {
    if(board[0][0] == '1')
      board[0][0] = player1Mkr; 
    else
    {
       cout << "Slot in used. Please try again!"<< endl;
      cin >> slot;
    }
  }
      if(slot == 2)
      {
        if(board[0][1] == '2')
          board[0][1] = player1Mkr;
        else
        {
          cout << "Slot in used. Please try again!"<< endl;
      cin >> slot;
        }
      }
      if(slot == 3)
      {
        if(board[0][2] == '3')
          board[0][2] = player1Mkr;
        else
        {
            cout << "Slot in used. Please try again!"<< endl;
      cin >> slot;
      cin >> slot;
        }
      }
      if(slot == 4)
      {
        if(board[1][0] == '4')
          board[1][0] = player1Mkr;
        else
        {
            cout << "Slot in used. Please try again!"<< endl;
      cin >> slot;
        }
      }
      if(slot == 5)
      {
        if(board[1][1] == '5')
          board[1][1] = player1Mkr;
        else
        {
            cout << "Slot in used. Please try again!"<< endl;
      cin >> slot;
        }
      }
      if(slot == 6)
      {
        if(board[1][2] == '6')
          board[1][2] = player1Mkr;
        else
        {
            cout << "Slot in used. Please try again!"<< endl;
      cin >> slot;
        }
      }
      if(slot == 7)
      {
        if(board[2][0] == '7')
          board[2][0] = player1Mkr;
        else
        {
            cout << "Slot in used. Please try again!"<< endl;
      cin >> slot;
        }
      }
      if(slot == 8)
      {
        if(board[2][1] == '8')
          board[2][1] = player1Mkr;
        else
        {
            cout << "Slot in used. Please try again!"<< endl;
      cin >> slot;
        }
      }
      if(slot == 9)
      {
        if(board[2][2] == '9')
          board[2][2] = player1Mkr;
        else
        {
            cout << "Slot in used. Please try again!"<< endl;
      cin >> slot;
        }
      }
      system("clear");
      locateMarker(slot);
      drawBoard();
      winner = detWinner();
      
      if(winner == 1)
      {
        cout << endl << "Congratulations, player 1 won" << endl;
        exit(0);
      } 
      if(winner == 2)
      {
        cout << endl << "Congratulations, player 2 won" << endl;
        exit(0);
      } 
  
      if(currentMarker == 'X')
        currentMarker = 'O';
      else 
        currentMarker = 'X';

      if(currentPlayer == 1)
        currentPlayer = 2;
      else
        currentPlayer = 1;
    }
    
    if(winner == 0)
    {
      cout << endl << "Tie Game" << endl;
      exit(0);
    }
  }
  else
    cout << "Wrong Marker Chose" << endl << "==================" << endl;
    }while(player1Mkr != 'X' || player1Mkr != 'O');
}

int main()
{
  game(); 
}
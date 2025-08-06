#include <iostream>
#include <string>
#include <stdlib.h>
#include <limits>

using namespace std;
// Array for the board
char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
// Variable Declaration
int choice;
int row, column;
char turn = 'X';
bool draw = false;

void display_board() // Render Game Board Layout
{
    system("cls");
    cout << "GIOCATORE - 1 [X]\t   GIOCATORE - 2 [O]\n\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t " << board[0][0] << "   |  " << board[0][1] << "  |  " << board[0][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t " << board[1][0] << "   |  " << board[1][1] << "  |  " << board[1][2] << " \n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t " << board[2][0] << "   |  " << board[2][1] << "  |  " << board[2][2] << " \n";
    cout << "\t\t     |     |     \n";
}

void player_turn() // Func to take player input and update board
{
    while (true) // this loop is to check if the input is a number between 1 and 9, if true goes to the switch, if not then two outcomes
    {
        if (turn == 'X')
        {
            cout << "\n\tGiocatore - 1 [X] turno : ";
        }
        else if (turn == 'O')
        {
            cout << "\n\tGiocatore - 2 [O] turno : ";
        }

        if (!(cin >> choice)) // if the choise is no number, outputs specific message, cleans the stream and restart the input
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Input non valido! Devi inserire un numero, dio demonio.\n";
            continue;
        }

        if (choice < 1 || choice > 9) // if the choise is a number out of limits, outputs specific message, cleans the stream and restarts the input
        {
            cout << "Mossa non valida! Scegli un numero tra 1 e 9, madonna sborrata.\n";
            continue;
        }

        break;
    }

    switch (choice) // switch case to update the chosen position
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    // if statement that check's in turn X if there's a free space, if so updates the space with the corresponding input and passes to next turn
    {
        board[row][column] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    // else if statement that check's in turn O if there's a free space, if so updates the space with the corresponding input and passes to next turn
    {
        board[row][column] = 'O';
        turn = 'X';
    }
    else
    // else statement that reinitiate player_turn func if no correct choice is made
    {
        cout << "Casella presa!\n Prendine un'altra, coglione\n\n";
        player_turn();
    }

    display_board(); // here we reinitiate the updated board
}

bool gameover()
{
    // checks win for columns or rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
            return false;

    // checks win for both diagonals
    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
        return false;

    // checks if game is in continue mode or not
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return true;

    draw = true;
    return false;
}

int main()
{
    cout << "\t\t\tG I O C H I A M O -- A -- T R I S\t\t\t";
    cout << "\n\t\t\t\t PER 2 GIOCATORI\n\t\t\t";
    while (gameover())
    {
        display_board();
        player_turn();
        gameover();
    }
    if (turn == 'O' && draw == false)

        cout << "\n\nCongratulazioni Giocatore 1! Hai vinto, porcoddio gesuita!";

    else if (turn == 'X' && draw == false)
    {
        cout << "\n\nCongratulazioni Giocatore 2! Hai vinto, diocane inculato!";
    }
    else
        cout << "\n\nPAREGGIO RITARDATI!!!\n\n";
}
#include <iostream>
#include <vector>
using namespace std;

// Function to check if a player has won
char checkWinner(const vector<vector<char>> &board)
{
    // Check rows
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return board[i][0];
    }

    // Check columns
    for (int i = 0; i < 3; ++i)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return board[0][2];

    // No winner yet
    return ' ';
}

int main()
{
    vector<vector<char>> board = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}};

    const char player_X = 'X';
    const char player_O = 'O';
    char cur_player = 'X';
    char number;
    int row = -1;
    int col = -1;
    bool valid_input = false; // Flag to check if input is valid

    for (int x = 0; x < 9; x++)
    {
        // Display the board
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                cout << " " << board[i][j] << " ";
                if (j < 2)
                    cout << "|";
            }
            cout << endl;
            if (i < 2)
                cout << "---+---+---" << endl;
        }

        cout << "current player is " << cur_player << endl;
        valid_input = false; // Reset the flag

        // Prompt the user for input until valid input is provided
        while (!valid_input)
        {
            cout << "Enter the number you want play on : ";
            cin >> number;

            // Check if the input is within the valid range
            if (number < '1' || number > '9')
            {
                cout << "Wrong input please select the numbers from 1-9" << endl;
                continue; // Restart the loop to prompt for input again
            }

            // Convert char to int for indexing
            int selected_number = number - '0';

            // Check if the selected number is available
            if (board[(selected_number - 1) / 3][(selected_number - 1) % 3] != number)
            {
                cout << "Number already used. Please select another number." << endl;
                continue; // Restart the loop to prompt for input again
            }

            valid_input = true; // Input is valid, exit the loop
        }

        // Convert char to int for indexing
        int selected_number = number - '0';

        // Calculate row and column based on the selected number
        row = (selected_number - 1) / 3;
        col = (selected_number - 1) % 3;

        // Update the board with the player's move
        board[row][col] = cur_player;

        // Check if there's a winner
        char winner = checkWinner(board);
        if (winner == 'X' || winner == 'O')
        {
            cout << "Player " << winner << " wins!" << endl;
            break; // End the game
        }

        // Switch player for the next turn
        cur_player = (cur_player == player_X) ? player_O : player_X;
    }

    return 0;
}

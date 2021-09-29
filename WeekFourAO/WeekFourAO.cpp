/* Austin Ozan 
 * Week Four Assignment
 * Your assignment this week is to implement a computer-controlled opponent for the classic game Tic Tac Toe.
 * The base code for the game is provided.
 */

#include <iostream>

using namespace std;

class TicTacToe
{
public:
    // TTT board, empty by default
    char board[3][3] =
    {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    // used for keeping track what's in each space, and what value each player has
    enum Entry
    {
        EMPTY = ' ',
        PLAYER_ONE = 'x',
        PLAYER_TWO = 'o'
    };

    // has the board been completely filled?
    bool isFull()
    {
        bool result = true;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[i][j] == Entry::EMPTY)
                    result = false;
            }
        }

        return result;
    }

    // has someone won?
    bool isVictory(Entry e)
    {

        // first col
        if (board[0][0] == (char)e && board[0][1] == (char)e && board[0][2] == (char)e)
        {
            return true;
        }

        // second col
        else if (board[1][0] == (char)e && board[1][1] == (char)e && board[1][2] == (char)e)
        {
            return true;
        }

        // third col
        else if (board[2][0] == (char)e && board[2][1] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // first row
        else if (board[0][0] == (char)e && board[1][0] == (char)e && board[2][0] == (char)e)
        {
            return true;
        }

        // second row
        else if (board[0][1] == (char)e && board[1][1] == (char)e && board[2][1] == (char)e)
        {
            return true;
        }

        // third row
        else if (board[0][2] == (char)e && board[1][2] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // diagonal 1
        else if (board[0][0] == (char)e && board[1][1] == (char)e && board[2][2] == (char)e)
        {
            return true;
        }

        // diagonal 2
        else if (board[0][2] == (char)e && board[1][1] == (char)e && board[2][0] == (char)e)
        {
            return true;
        }

        return false;
    }

    // return size of the board; mostly just in case I wanted to make the board expandable
    int getSize()
    {
        return 3;
    }


    void dump()
    {
        cout << "----------------------------------------" << endl << endl;
        for (int i = 0; i < getSize(); i++)
        {
            for (int j = 0; j < getSize(); j++)
            {
                cout << " | " << board[i][j] << " | ";
            }

            cout << endl;
        }
        cout << "----------------------------------------" << endl << endl;
    }

};

static bool getHumanMove(int maxValue, TicTacToe::Entry human, TicTacToe& t)
{
    // check if player is able to move
    if (t.isVictory(t.PLAYER_ONE) || t.isVictory(t.PLAYER_TWO) || t.isFull())
        return true;

    int rowChoice = 0;
    int colChoice = 0;

    do {

        do {

            cout << "Enter column number (x) : 0 ... 2 : ";
            cin >> colChoice;
            cout << endl;

        } while (colChoice > maxValue || colChoice < 0);

        do {

            cout << "Enter row number (y) : 0 ... 2 : ";
            cin >> rowChoice;
            cout << endl;

        } while (rowChoice > maxValue || rowChoice < 0);


        if (t.board[rowChoice][colChoice] == t.EMPTY)
        {
            t.board[rowChoice][colChoice] = (char)human;

            return false;
        }

        else
        {
            cout << "Not a valid option! Please try again..." << endl;
        }


    } while (t.board[rowChoice][colChoice] != t.EMPTY);

    // move complete
    return false;
}


/* * * * * * * *
 * OBJECTIVES  *
 * * * * * * * *
 * 
 * a) If the computer can win immediately, it should do so {DONE}
 * 
 * b) If the human's next move would result in a victory, the 
 *    AI should choose that square to block {DONE}
 * 
 * c) If the center square is open, choose it {DONE}
 * 
 * d) If any of the corner squares are open, choose one of them {DONE}
 * 
 * e) Choose any open square at random {DONE}
 */

// Choose a square to keep human from winning
void preventHWin() {

}

// Choose a corner square if available
void cornerSquare() {

}

static bool getComputerMove(TicTacToe::Entry computer, TicTacToe:: Entry human, TicTacToe& t)
{
    // check if computer is able to move
    if (t.isVictory(t.PLAYER_ONE) || t.isVictory(t.PLAYER_TWO) || t.isFull())
        return true;

    // handle computer's move

    int rowChoice = 0;
    int colChoice = 0;
    int cornerChoice = 0;

    do {
        // Choose Winning Square
        // first col
        if (t.board[0][0] == (char)computer && t.board[0][1] == (char)computer && t.board[0][2] == t.EMPTY)
        {
            t.board[0][2] = (char)computer; // Down
            return false;
        }
        else if (t.board[0][2] == (char)computer && t.board[0][1] == (char)computer && t.board[0][0] == t.EMPTY)
        {
            t.board[0][0] = (char)computer; // Up
            return false;
        }
        else if (t.board[0][0] == (char)computer && t.board[0][2] == (char)computer && t.board[0][1] == t.EMPTY)
        {
            t.board[0][1] = (char)computer; // Middle
            return false;
        }

        // second col
        else if (t.board[1][0] == (char)computer && t.board[1][1] == (char)computer && t.board[1][2] == t.EMPTY)
        {
            t.board[1][2] = (char)computer; // Down
            return false;
        }
        else if (t.board[1][2] == (char)computer && t.board[1][1] == (char)computer && t.board[1][0] == t.EMPTY)
        {
            t.board[1][0] = (char)computer; // Up
            return false;
        }
        else if (t.board[1][0] == (char)computer && t.board[1][2] == (char)computer && t.board[1][1] == t.EMPTY)
        {
            t.board[1][1] = (char)computer; // Middle
            return false;
        }

        // third col
        else if (t.board[2][0] == (char)computer && t.board[2][1] == (char)computer && t.board[2][2] == t.EMPTY)
        {
            t.board[2][2] = (char)computer; // Down
            return false;
        }
        else if (t.board[2][2] == (char)computer && t.board[2][1] == (char)computer && t.board[2][0] == t.EMPTY)
        {
            t.board[2][0] = (char)computer; // Up
            return false;
        }
        else if (t.board[2][0] == (char)computer && t.board[2][2] == (char)computer && t.board[2][1] == t.EMPTY)
        {
            t.board[2][1] = (char)computer; // Middle
            return false;
        }

        // first row
        else if (t.board[0][0] == (char)computer && t.board[1][0] == (char)computer && t.board[2][0] == t.EMPTY)
        {
            t.board[2][0] = (char)computer; // Right
            return false;
        }
        else if (t.board[2][0] == (char)computer && t.board[1][0] == (char)computer && t.board[0][0] == t.EMPTY)
        {
            t.board[0][0] = (char)computer; // Left
            return false;
        }
        else if (t.board[0][0] == (char)computer && t.board[0][2] == (char)computer && t.board[0][1] == t.EMPTY)
        {
            t.board[0][1] = (char)computer; // Middle
            return false;
        }

        // second row
        else if (t.board[0][1] == (char)computer && t.board[1][1] == (char)computer && t.board[2][1] == t.EMPTY)
        {
            t.board[2][1] = (char)computer; // Right
            return false;
        }
        else if (t.board[2][1] == (char)computer && t.board[1][1] == (char)computer && t.board[0][1] == t.EMPTY)
        {
            t.board[0][1] = (char)computer; // Left
            return false;
        }
        else if (t.board[0][1] == (char)computer && t.board[2][1] == (char)computer && t.board[1][1] == t.EMPTY)
        {
            t.board[1][1] = (char)computer; // Middle
            return false;
        }

        // third row
        else if (t.board[0][2] == (char)computer && t.board[1][2] == (char)computer && t.board[2][2] == t.EMPTY)
        {
            t.board[2][2] = (char)computer; // Right
            return false;
        }
        else if (t.board[2][2] == (char)computer && t.board[1][2] == (char)computer && t.board[0][2] == t.EMPTY)
        {
            t.board[0][2] = (char)computer; // Left
            return false;
        }
        else if (t.board[0][2] == (char)computer && t.board[2][2] == (char)computer && t.board[1][2] == t.EMPTY)
        {
            t.board[1][2] = (char)computer; // Middle
            return false;
        }

        // diagonal 1
        else if (t.board[0][0] == (char)computer && t.board[1][1] == (char)computer && t.board[2][2] == t.EMPTY)
        {
            t.board[2][2] = (char)computer; // Left to Right Diagonal
            return false;
        }
        else if (t.board[2][2] == (char)computer && t.board[1][1] == (char)computer && t.board[0][0] == t.EMPTY)
        {
            t.board[0][0] = (char)computer; // Right to Left Diagonal
            return false;
        }
        else if (t.board[0][0] == (char)computer && t.board[2][2] == (char)computer && t.board[1][1] == t.EMPTY)
        {
            t.board[1][1] = (char)computer; // Middle
            return false;
        }

        // diagonal 2
        else if (t.board[0][2] == (char)computer && t.board[1][1] == (char)computer && t.board[2][0] == t.EMPTY)
        {
            t.board[2][0] = (char)computer; // Left to Right Diagonal
            return false;
        }
        else if (t.board[2][0] == (char)computer && t.board[1][1] == (char)computer && t.board[0][2] == t.EMPTY)
        {
            t.board[0][2] = (char)computer; // Right to Left Diagonal
            return false;
        }
        else if (t.board[0][2] == (char)computer && t.board[2][0] == (char)computer && t.board[1][1] == t.EMPTY)
        {
            t.board[1][1] = (char)computer; // Up
            return false;
        }

        // For choosing a blocking square
        // first col
        if (t.board[0][0] == (char)human && t.board[0][1] == (char)human && t.board[0][2] == t.EMPTY)
        {
            t.board[0][2] = (char)computer; // Down
            return false;
        }
        else if (t.board[0][2] == (char)human && t.board[0][1] == (char)human && t.board[0][0] == t.EMPTY)
        {
            t.board[0][0] = (char)computer; // Up
            return false;
        }
        else if (t.board[0][0] == (char)human && t.board[0][2] == (char)human && t.board[0][1] == t.EMPTY)
        {
            t.board[0][1] = (char)computer; // Middle
            return false;
        }

        // second col
        else if (t.board[1][0] == (char)human && t.board[1][1] == (char)human && t.board[1][2] == t.EMPTY)
        {
            t.board[1][2] = (char)computer; // Down
            return false;
        }
        else if (t.board[1][2] == (char)human && t.board[1][1] == (char)human && t.board[1][0] == t.EMPTY)
        {
            t.board[1][0] = (char)computer; // Up
            return false;
        }
        else if (t.board[1][0] == (char)human && t.board[1][2] == (char)human && t.board[1][1] == t.EMPTY)
        {
            t.board[1][1] = (char)computer; // Middle
            return false;
        }

        // third col
        else if (t.board[2][0] == (char)human && t.board[2][1] == (char)human && t.board[2][2] == t.EMPTY)
        {
            t.board[2][2] = (char)computer; // Down
            return false;
        }
        else if (t.board[2][2] == (char)human && t.board[2][1] == (char)human && t.board[2][0] == t.EMPTY)
        {
            t.board[2][0] = (char)computer; // Up
            return false;
        }
        else if (t.board[2][0] == (char)human && t.board[2][2] == (char)human && t.board[2][1] == t.EMPTY)
        {
            t.board[2][1] = (char)computer; // Middle
            return false;
        }

        // first row
        else if (t.board[0][0] == (char)human && t.board[1][0] == (char)human && t.board[2][0] == t.EMPTY)
        {
            t.board[2][0] = (char)computer; // Right
            return false;
        }
        else if (t.board[2][0] == (char)human && t.board[1][0] == (char)human && t.board[0][0] == t.EMPTY)
        {
            t.board[0][0] = (char)computer; // Left
            return false;
        }
        else if (t.board[0][0] == (char)human && t.board[0][2] == (char)human && t.board[0][1] == t.EMPTY)
        {
            t.board[0][1] = (char)computer; // Middle
            return false;
        }

        // second row
        else if (t.board[0][1] == (char)human && t.board[1][1] == (char)human && t.board[2][1] == t.EMPTY)
        {
            t.board[2][1] = (char)computer; // Right
            return false;
        }
        else if (t.board[2][1] == (char)human && t.board[1][1] == (char)human && t.board[0][1] == t.EMPTY)
        {
            t.board[0][1] = (char)computer; // Left
            return false;
        }
        else if (t.board[0][1] == (char)human && t.board[2][1] == (char)human && t.board[1][1] == t.EMPTY)
        {
            t.board[1][1] = (char)computer; // Middle
            return false;
        }

        // third row
        else if (t.board[0][2] == (char)human && t.board[1][2] == (char)human && t.board[2][2] == t.EMPTY)
        {
            t.board[2][2] = (char)computer; // Right
            return false;
        }
        else if (t.board[2][2] == (char)human && t.board[1][2] == (char)human && t.board[0][2] == t.EMPTY)
        {
            t.board[0][2] = (char)computer; // Left
            return false;
        }
        else if (t.board[0][2] == (char)human && t.board[2][2] == (char)human && t.board[1][2] == t.EMPTY)
        {
            t.board[1][2] = (char)computer; // Middle
            return false;
        }

        // diagonal 1
        else if (t.board[0][0] == (char)human && t.board[1][1] == (char)human && t.board[2][2] == t.EMPTY)
        {
            t.board[2][2] = (char)computer; // Left to Right Diagonal
            return false;
        }
        else if (t.board[2][2] == (char)human && t.board[1][1] == (char)human && t.board[0][0] == t.EMPTY)
        {
            t.board[0][0] = (char)computer; // Right to Left Diagonal
            return false;
        }
        else if (t.board[0][0] == (char)human && t.board[2][2] == (char)human && t.board[1][1] == t.EMPTY)
        {
            t.board[1][1] = (char)computer; // Middle
            return false;
        }

        // diagonal 2
        else if (t.board[0][2] == (char)human && t.board[1][1] == (char)human && t.board[2][0] == t.EMPTY)
        {
            t.board[2][0] = (char)computer; // Left to Right Diagonal
            return false;
        }
        else if (t.board[2][0] == (char)human && t.board[1][1] == (char)human && t.board[0][2] == t.EMPTY)
        {
            t.board[0][2] = (char)computer; // Right to Left Diagonal
            return false;
        }
        else if (t.board[0][2] == (char)human && t.board[2][0] == (char)human && t.board[1][1] == t.EMPTY)
        {
            t.board[1][1] = (char)computer; // Up
            return false;
        }

        // Choose Center Square
        if (t.board[1][1] == t.EMPTY) {
            t.board[1][1] = (char)computer;
            return false;
        }

        // Choose a middle square if computer has a corner square
        if (t.board[0][0] == (char)computer && t.board[1][0] == t.EMPTY) {
            t.board[1][0] = (char)computer;
            return false;
        }
        else if (t.board[0][0] == (char)computer && t.board[0][1] == t.EMPTY) {
            t.board[0][1] = (char)computer;
            return false;
        }
        else if (t.board[2][0] == (char)computer && t.board[1][0] == t.EMPTY) {
            t.board[1][0] = (char)computer;
            return false;
        }
        else if (t.board[2][0] == (char)computer && t.board[2][1] == t.EMPTY) {
            t.board[2][1] = (char)computer;
            return false;
        }
        else if (t.board[0][2] == (char)computer && t.board[0][1] == t.EMPTY) {
            t.board[0][1] = (char)computer;
            return false;
        }
        else if (t.board[0][2] == (char)computer && t.board[1][2] == t.EMPTY) {
            t.board[1][2] = (char)computer;
            return false;
        }
        else if (t.board[2][2] == (char)computer && t.board[1][2] == t.EMPTY) {
            t.board[1][2] = (char)computer;
            return false;
        }
        else if (t.board[2][2] == (char)computer && t.board[2][1] == t.EMPTY) {
            t.board[2][1] = (char)computer;
            return false;
        }

        /*
        // If a corner square is open, randomly picks one, and then continues from there
        cornerChoice = rand() % 4 + 1;
        if (cornerChoice == 1 && t.board[0][0] == t.EMPTY) {
            t.board[0][0] = (char)computer;
            return false;
        }
        else if (cornerChoice == 2 && t.board[0][2] == t.EMPTY) {
            t.board[0][2] = (char)computer;
            return false;
        }
        else if (cornerChoice == 3 && t.board[2][0] == t.EMPTY) {
            t.board[2][0] = (char)computer;
            return false;
        }
        else if (cornerChoice == 4 && t.board[2][2] == t.EMPTY) {
            t.board[2][2] = (char)computer;
            return false;
        }
        */

        // choose at random until we find a space that's empty
        do {

            rowChoice = rand() % ((t.getSize() - 0) + 1) + 0;

        } while (rowChoice > t.getSize() || rowChoice < 0);

        do {

            colChoice = rand() % ((t.getSize() - 0) + 1) + 0;

        } while (colChoice > t.getSize() || colChoice < 0);


        if (t.board[rowChoice][colChoice] == t.EMPTY)
        {
            t.board[rowChoice][colChoice] = (char)computer;

            return false;
        }

        else
        {
            //cout << "Not a valid option! Please try again..." << endl;
        }


    } while (t.board[rowChoice][colChoice] != t.EMPTY);

    // move complete
    return false;
}

// ----------------------------
// main
// ----------------------------

int main()
{
    TicTacToe t;
    TicTacToe::Entry human = TicTacToe::PLAYER_ONE;
    TicTacToe::Entry computer = TicTacToe::PLAYER_TWO;

    int maxValue = t.getSize();

    cout << "----------------------------------------" << endl;

    cout << "You are '" << (char)human << "', " <<
        "the computer is: '" << (char)computer << "'" << endl;

    cout << "----------------------------------------" << endl << endl;

    // run the game until one player isn't able to go again
    do
    {
        // show board
        t.dump();
    } while (!getHumanMove(maxValue, human, t) && !getComputerMove(computer, human, t));


    t.dump();

    cout << endl;

    if (t.isVictory(human))
        cout << "Human Victory" << endl;

    else if (t.isVictory(computer))
        cout << "Computer Victory" << endl;

    else if (t.isFull())
        cout << "Tie" << endl;

    return(0);
}
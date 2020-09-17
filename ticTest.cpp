#include <iostream>
#include <string>
#include <vector>
using namespace std;

void printBoard(char array[])
{
    cout << array[0] << "|" << array[1] << "|" << array[2] << endl;
    cout << "-----" << endl;
    cout << array[3] << "|" << array[4] << "|" << array[5] << endl;
    cout << "-----" << endl;
    cout << array[6] << "|" << array[7] << "|" << array[8] << endl;
}

bool checkWinner(char array[])
{
    //Horizontal
    if (array[0] == array[1] && array[1] == array[2])
        return true;
    else if (array[3] == array[4] && array[4] == array[5])
        return true;
    else if (array[6] == array[7] && array[7] == array[8])
        return true;

    //Vertical
    else if (array[0] == array[3] && array[3] == array[6])
        return true;
    else if (array[1] == array[4] && array[4] == array[7])
        return true;
    else if (array[2] == array[5] && array[5] == array[8])
        return true;

    //Diagonal
    else if (array[0] == array[4] && array[4] == array[8])
        return true;
    else if (array[2] == array[4] && array[4] == array[6])
        return true;
    else
    {
        return false;
    }
}

int main()
{
    char boardArray[9] = {'0', '1', '2', '3', '4', '5', '6', '7', '8'};
    int answer;
    int answer2;

    printBoard(boardArray);

    while (checkWinner(boardArray) != true)
    {
        cout << "Player 1 turn" << endl;
        cin >> answer;

        if (boardArray[answer] == 'x' || boardArray[answer] == 'o')
            cout << "Please enter another position." << endl;

        boardArray[answer] = 'x';
        printBoard(boardArray);
        cout << endl;

        if (checkWinner(boardArray) == true)
        {
            cout << "Player 1 won!" << endl;
            return 0;
        }

        cout << "Player 2 turn" << endl;
        cin >> answer2;
        if (boardArray[answer2] == 'x' || boardArray[answer2] == 'o')
            cout << "Please enter another position." << endl;

        boardArray[answer2] = 'o';
        printBoard(boardArray);
        cout << endl;
        if (checkWinner(boardArray) == true)
        {
            cout << "Player 2 won!" << endl;
            return 0;
        }
    }

    cout << endl;

    return 0;
}
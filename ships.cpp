#include <iostream>
#include <ctime>
#include "shipDeclarations.h"




int main()
{
    int ** board = new int * [rows]; //table
    int ** boardPc = new int * [rows]; //table
    srand(time(NULL)); 
    create2dArray(board);
    create2dArray(boardPc);
    Clear(board); // setting "-" to every spot on board
    Clear(boardPc);
    Show(board, 0 );
    SetShips(board, 0); // setting ships on board
    SetShips(boardPc, 1); // setting ships for Pc
    int pos1, pos2;
    while(1)
    {
          std::cout<<" O - You/Pc missed shot!" << std::endl;
          std::cout <<" X - You/Pc hit enemy ship!" << std::endl;
          std::cout <<" 1, 2 , 3 - Place of your ships" << std::endl;
        Show(board, 0); // display board
        Show(boardPc, 1); //display Pc board
        
        std::cout << "Please input location X(rows) Y(columns) ";
        std::cin >> pos1 >> pos2;
        if (pos1 >= rows || pos2 >= columns)
        {
            std::cout << "Invalid location!" << std::endl;  //Invalid location
            continue;
        }
        if(Attack(boardPc, pos1, pos2))//If user hit computer's ship
        {
            std::cout << "You got me! :)" << std::endl; 
        }
        else // if user miss shot
        {
            std::cout << "Sorry, no ship at that position!" << std::endl;
        }

        std::cout << "Number of ships left: " << calculateShipNumber(board, 0) << std::endl; // showing number of ships left
        std::cout << "Number of PC ships left: " << calculateShipNumber(boardPc, 1) << std::endl; //
        if (calculateShipNumber(board, 0) == 0 || calculateShipNumber(boardPc, 1)== 0)
        {
            std::cout << "Congratulations! You have won the game!" << std::endl; // if player wins
            break;
        }
        ComputerAttack(board);
    }
    Show(board, 0); // showing boards
    Show(boardPc, 1);
    delete2dArray(board); //deleting arrays
    delete2dArray(boardPc );
    std::cout << "Game over!" << std::endl;

    return 0;
}

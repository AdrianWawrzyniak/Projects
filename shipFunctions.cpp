#include <iostream>
#include "shipDeclarations.h"
void create2dArray(int **&board)
{
    for (int i = 0; i < rows; i++)
    {
        board[i] =  new int [columns];
    }
}
void delete2dArray(int **&board)
{
    for (int i = 0; i < columns; i++)
    {
     delete [] board[i];
    }
    delete [] board;
}

void Clear(int **&board)
{
    // setting 0 for full board
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < columns; j++)
        {
            board[i][j] = 0;
        }
    }
}

void Show(int **&board, int ifPc) //prints board on screen
{
    
    if (ifPc == 0) // for player
    {
        std::cout<<"     Your Board"<<std::endl;
    }
    else if (ifPc == 1) //for pc
    {
        std::cout<<"        Pc Board"<<std::endl;
    }

    std::cout << "  ";
    for(int i=0; i < columns; i++)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for(int i=0; i < rows; i++)
    {
        std::cout << i << " ";
        for(int j=0; j < columns; j++)
        {
            if (ifPc == 0) //for player
            {
            if (board[i][j] == 0) // empty spot
                std::cout << "- ";
            else if (board[i][j] == 1) // spot with I ship
                std::cout << "1 ";
            else if (board[i][j] == 11) // spot with II ship
                std::cout << "2 ";
            else if (board[i][j] == 111) // spot with III ship
                std::cout << "3 ";
            else if (board[i][j] == -2) // hit spot
                std::cout << "O ";
            else if (board[i][j] == 3) // miss spot
                std::cout << "X ";
            }
            if (ifPc == 1)
            {
                if (board[i][j] == 0) // empty spot
                std::cout << "- ";
            else if (board[i][j] == 2) // spot with I ship
                std::cout << "1 ";
            else if (board[i][j] == 22) // spot with II ship
                std::cout << "2 ";
            else if (board[i][j] == 222) // spot with III ship
                std::cout << "3 ";
            else if (board[i][j] == 4) // hit spot
                std::cout << "X ";
            else if (board[i][j] == -1) // miss spot
                std::cout << "O ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int calculateShipNumber(int **&board, int ifPc)
{
    //function returning number of ships on board
    int numberOfPlayerShips = 0;
    int numberofPcShips = 0;

    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < columns; j++)
        {

            if (ifPc == 0) //for player
            {
            if(board[i][j] == 1 || board[i][j] == 11 || board[i][j] == 111)
                numberOfPlayerShips++;
            }
            if (ifPc == 1) //for Pc
            {
               if(board[i][j] == 2 || board[i][j] == 222 || board[i][j] == 22)
                numberofPcShips++; 
            }
        }
    }
    if (ifPc == 0) // for player
    {
        return numberOfPlayerShips;
    }
     else //for Pc
    {
        return numberofPcShips;
    }
    
}

bool noTouch(int **&board, int x, int y, int z)
{       
    //function checking if spot [x][y] is not touching any other ship
        if (x>0 && y>0 && x<9 && y<9)
        {
           if(board[x][y] != z && 
           board[x+1][y] != z && board[x+1][y+1] != z && board[x+1][y-1] != z && 
           board[x-1][y] != z && board[x-1][y+1] != z && board[x-1][y-1] != z &&
           board[x][y+1] != z && 
           board[x][y-1] != z 
           )
           {
            return true;
           }
           else return false;
        }
        if (x==0 && y==0)
        {
            if(board[x][y] != z && 
           board[x+1][y] != z && board[x+1][y+1] != z && 
           board[x][y+1] != z  
          
           )
           {
            return true;
           }
           else return false;

        }
        if (x==0 && y==9)
        {
             if(board[x][y] != z && 
           board[x+1][y] != z &&  board[x+1][y-1] != z && 
           board[x][y-1] != z 
           )
           {
            return true;
           }
           else return false;
        }
        if (y==0 && x==9)
        {
            if(board[x][y] != z &&  
           board[x-1][y] != z && board[x-1][y+1] != z && 
           board[x][y+1] != z 
           )
           {
            return true;
           }
           else return false;
        }
        if (x==9 && y==9)
        {
            if(board[x][y] != z && 
           board[x-1][y] != z &&  board[x-1][y-1] != z &&
           board[x][y-1] != z  
           )
           {
            return true;
           }
           else return false;
        }
        if (x==0 && y>0 && y<9)
        {
            if(board[x][y] != z && 
           board[x+1][y] != z &&   
           board[x][y-1] != z && board[x+1][y-1] != z && 
           board[x+1][y+1] != z && board[x][y+1] != z 
           )
           {
            return true;
           }
           else return false;
        }
        if (x==9 && y>0 && y<9)
        {
            if(board[x][y] != z && 
           board[x-1][y] != z &&   
           board[x][y-1] != z && board[x-1][y-1] != z && 
           board[x-1][y+1] != z && board[x][y+1] != z 
           )
           {
            return true;
           }
           else return false;
        }
        if (y==9 && x>0 && x<9)
        {
            if(board[x][y] != z && 
           board[x-1][y] != z &&   
           board[x][y-1] != z && board[x-1][y-1] != z && 
           board[x+1][y] != z && board[x+1][y-1] != z
           )
           {
            return true;
           }
           else return false;
        }
        else
        {
            if(board[x][y] != z && 
           board[x-1][y] != z &&   
           board[x][y+1] != z && board[x-1][y+1] != z && 
           board[x+1][y] != z && board[x+1][y+1] != z
           )
           {
            return true;
           }
           else return false;
        }
}
void setIIIShip(int **&board, int x, int y, int ifPc)
{   
    //setting III ship
    int ship;
    if (ifPc == 0)
    {
        ship = 111;
    }
    if (ifPc == 1)
    {
        ship = 222;
    }
    
    int helper;
    int helper2;
                helper = rand() % 3; //generating random number to set ship (4 different ways)
                if (helper == 0)
                {
                    board[x+1][y] = ship;
                    helper2 = rand() % 1; //making it even more random
                    if (helper2 == 0)
                    {
                        board[x+2][y] = ship;
                    }
                    if (helper2 == 1)
                    {
                        board[x-1][y] = ship;
                    }
                }
                if (helper == 1)
                {
                    board[x-1][y] = ship;
                    helper2 = rand() % 1;
                    if (helper2 == 0)
                    {
                        board[x-2][y] = ship;
                    }
                    if (helper2== 1)
                    {
                        board[x+1][y] = ship;
                    }
                }
                if (helper == 2)
                {
                    board[x][y+1] = ship;
                    helper2 = rand() % 1;
                    if (helper2 == 0)
                    {
                        board[x][y+2] = ship;
                    }
                    if (helper2 == 1)
                    {
                        board[x][y-1] = ship;
                    }
                }
                if (helper == 3)
                {
                    board[x][y-1] = ship;
                    helper2 = rand() % 1;
                    if (helper2 == 0)
                    {
                        board[x][y-2] = ship;
                    }
                    if (helper2 == 1)
                    {
                        board[x][y+1] = ship;
                    }
                }
}

void setIIShip(int **&board, int x, int y, int ifPc)
{   
    //setting II ship
    int ship3;
    int ship2;
    if (ifPc == 0)
    {
        ship3 = 111;
        ship2 = 11;
    }
    if (ifPc == 1)
    {
        ship3 = 222;
        ship2 = 22;
    }
    int helper =0;
    helper = rand() % 3; //again random generator for different ways
        if (helper == 0)
        {   
            if (noTouch(board, x+1,y, ship3)) //checking if ship will not touch any other ship
            board[x+1][y] = ship2;
            
        }
        if (helper == 1)
        {
            if (noTouch(board, x-1,y, ship3))
            board[x-1][y] = ship2;
        }
        if (helper == 2)
        {
           if (noTouch(board, x,y+1,ship3))
            board[x][y+1] = ship2;
        }
        if (helper == 3)
        {
            if (noTouch(board,x , y-1,ship3))
            board[x][y-1] = ship2;
        }
}
void SetShips(int **&board, int ifPc)
{
    //function sets ships on board
    int s = 0;
    int j = 0;
    int ship3;
    int ship2;
    int ship1;
    if (ifPc == 0)
    {
        ship3 = 111;
        ship2 = 11;
        ship1 = 1;
    }
    if (ifPc == 1)
    {
        ship3 = 222;
        ship2 = 22;
        ship1 = 2;
    }
        while (j < 1)
        {
        int x = rand() % rows; 
        int y = rand() % columns;
        
        
        
            
            if(x > 1 && y > 1 && x < 8 && y < 8) //checking if can put ship in this position (ship3 takes 3 slots)
            {
            board[x][y] = ship3;
            setIIIShip(board,x, y, ifPc);
            j++;
            } 
        
        }
        
        while (j <2)
        {
            int x =rand() % rows;
            int y = rand() % rows;
            if(noTouch(board, x, y, ship3))//this if makes sure that ships wont touch each other
            {
                if(x > 0 && y > 0 && x < 9 && y < 9) //ship II takes 2 slots so checking it
            {
            board[x][y] = ship2;
            setIIShip(board, x, y, ifPc);
            
            j++;
            }
            }
        }
        
        while (j < 9)
        {
            int x =rand() % rows;
            int y = rand() % rows;
            if (noTouch(board, x, y, ship2) && noTouch(board, x, y, ship1) && noTouch(board, x, y, ship1)) //checking if ship1 wont touch any other ship
            {
                board[x][y] = ship1;
                j++;
            }
        }
    
}
bool Attack(int **&boardPc, int x, int y)
{   
    
   
    // "shoots" spot [x][y]
    if(boardPc[x][y] == 2 || boardPc[x][y] == 22 || boardPc[x][y] == 222) //checking if there is ship
    {
        // hit spot
        boardPc[x][y] = 4;
        
        return true;
    }
    else
    {
        // miss spot
        boardPc[x][y] = -1; 
        return false;
    }
}
void ComputerAttack(int **&board)
{
    // generating Pc shot 
    int x = rand() % rows;
    int y = rand() % columns;
    
    if(board[x][y] == 1 || board[x][y] == 11 || board[x][y] == 111) //checking if there is ship
    {
        board[x][y] = 3;
        std::cout << "Computer hit your ship at " << x << "," << y << "!" << std::endl;
    }
    else
    {
        board[x][y] = -2;
        std::cout << "Computer missed at " << x << "," << y << "." << std::endl;
    }
}
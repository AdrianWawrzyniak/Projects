const int rows = 10; // Number of rows
const int columns = 10; // Number of columns


void create2dArray(int **&board);
void delete2dArray(int **&board);
void Clear(int **&board);
void Show(int **&board, int ifPc);
int calculateShipNumber(int **&board, int ifPc);
void checkShipNumber(int *&board, int ifPc);
bool noTouch(int **&board, int x, int y, int z);
void setIIIShip(int **&board, int x, int y, int ifPc); 
void setIIShip(int **&board, int x, int y, int ifPc);
void SetShips(int **&board, int ifPc);
bool Attack(int **&boardPc, int x, int y);
void ComputerAttack(int **&board);
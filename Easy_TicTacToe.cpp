//Lorinda Peoples
//CECS 130 Section 2
//Lab 9: Tic Tac Toe
//Due Date: 11/10/11

//Program Assignment:   Create a C++ program where the user plays Tic Tac Toe
                     // against the computer.  The program should:
                     // 1.  Choose a random first player
                     // 2.  Notify the user if the cell is already occupied.
                     // 3.  Announce winner or draw game.
                     

#include <iostream>
#include <string>
#include <ctime> // processor clock time
#include <cstdlib> // random cell for computer move

using namespace std;

enum MakeNumber {X = 'X', O = 'O', blank = ' '};

class Randomize
{ //Chooise first player: user or Computer
   public:
          int firstPlayer();
          
};


int Randomize::firstPlayer()
{
   srand(time(NULL));
   int second = 2;
   int first = ((rand() % 2) + 1); 
   if (first == 1)
     return first;
   else if (first == 2)
     return second;
}

class BoardDesign
{ //all game functions: draw board, play, choose winner
   protected:
           int ROWS; //# of rows in board
           int COLUMNS; //# of columns in board
           int* Board; //array for board
           
   public:
          //Constructor
           BoardDesign() : ROWS(3), COLUMNS(3)
           {
               //Allocates memory for game board
               Board = new int[10];
               //Initializes all cells as ' ' (empty).
               for (int i=0; i <10; i++)
                   *(Board + i) = blank;
           }
           //Destructor
           ~BoardDesign()
           {
               //Deletes allocated memory in Board
               delete[] Board;
           }
           void printboard(); //Function to show Board
          //place player's moves
          void placeX(int Rnum, int Cnum);
          void placeO(int Rnum, int Cnum);
          //Check if array cell is already filled:
          //place player's moves
          BoardDesign* playerPlay(int player, string splayer, BoardDesign* bd); 
          bool checkCell(int Rnum, int Cnum);
          MakeNumber win(); //Checks for 3 X/O in a row
          int printWinner(string splayer, BoardDesign* bd, int count);
}; 

//Fuction to show Board
void BoardDesign::printboard()
{ //Prints board w/ blanks, X's, or O's
   cout << endl;
   //Display Column and Row #s
   cout <<"COLUMN#\t  1\t2\t3";
   cout <<"\nROW#\n";
   for (int i=0; i < ROWS; i++)
   {
      cout << i + 1; // Print Row #
      cout <<"\t  " 
           //Typecast as char. Blank state is ASCII space character = 32.
           << (char)*(Board + i*ROWS + 1);
      for(int c=2; c <= COLUMNS; c++)
         cout << "  |  " 
         //Typecast as char. Blank state is ASCII space character = 32.
              << (char)*(Board + i*COLUMNS + c);
      if (i == ROWS-1)
         break; //Break so that another line isnt't printed
      cout << endl << "\t ---------------" << endl; //Horizontal line
   }
} //end printboard()

void BoardDesign::placeX(int Rnum, int Cnum)
{ //Stores X in cell (Rnum,Cnum)
   *(Board + Rnum*ROWS + Cnum -3) = X;
}

void BoardDesign::placeO(int Rnum, int Cnum)
{ //Stores O in cell (Rnum, Cnum)
   *(Board + Rnum*ROWS + Cnum -3) = O;
}

bool BoardDesign::checkCell(int Rnum, int Cnum)
{ //Checks to cell already has an X or O  (true)
  return *(Board + Rnum*ROWS + Cnum -3) != blank;
} 

BoardDesign* BoardDesign::playerPlay(int player, string splayer, BoardDesign* bd)
{
 int Rnum =0; //row number
 int Cnum = 0; //column number
 int count = 0; //to count if user must repeat cell choice
 system("cls");
 bd->printboard();
 if (player == 1) //Player is user
 {
    do
    {
       count++; //Necessary to display cell taken error
       if (count > 1)
          cout <<"\nCell already taken!! Try again!";
       cout << endl;
       cout << endl <<splayer.c_str() <<", choose a row number to place your X: ";
       cin >> Rnum;
       cout << "Choose a column number to place your Y:  ";       
       cin >> Cnum;
    }while(bd->checkCell(Rnum,Cnum)); //Do While cell is already marked
    bd->placeX(Rnum, Cnum); //insert X
 }
 else if (player == 2) //Player is Computer
 {
     do
     {
        //Begin partial Artificial Intelligence. Can't tell difference btw X and O
        if((bd->checkCell(1,1)) && (bd->checkCell(1,2)) && (!bd->checkCell(1,3))) { Rnum=1; Cnum=3; }
        
        else if((bd->checkCell(2,1)) && (bd->checkCell(2,2)) && (!bd->checkCell(2,3))) { Rnum=2; Cnum=3; }
        
        else if((bd->checkCell(3,1)) && (bd->checkCell(3,2)) && (!bd->checkCell(3,3))) { Rnum=3; Cnum=3; }
        
        else if((bd->checkCell(1,1)) && (bd->checkCell(1,3)) && (!bd->checkCell(1,2))) { Rnum=1; Cnum=2; }
        
        else if((bd->checkCell(2,1)) && (bd->checkCell(2,3)) && (!bd->checkCell(2,2))) { Rnum=2; Cnum=2; }
        
        else if((bd->checkCell(3,1)) && (bd->checkCell(3,3)) && (!bd->checkCell(3,2))) { Rnum=3; Cnum=2; }
        
        //Diagonals
        else if((bd->checkCell(1,1)) && (bd->checkCell(2,2)) && (!bd->checkCell(3,3))) { Rnum=3; Cnum=3; }
        
        else if((bd->checkCell(1,3)) && (bd->checkCell(2,2)) && (!bd->checkCell(3,1))) { Rnum=3; Cnum=1; }
        
        else if((bd->checkCell(1,2)) && (bd->checkCell(2,2)) && (!bd->checkCell(3,2))) { Rnum=3; Cnum=2; }
        
        else if((bd->checkCell(3,3)) && (bd->checkCell(2,2)) && (!bd->checkCell(1,1))) { Rnum=1; Cnum=1; }
        
        else if((bd->checkCell(3,1)) && (bd->checkCell(2,2)) && (!bd->checkCell(1,3))) { Rnum=1; Cnum=3; }
        
        //End Artificial Intelligence
        else //Choose random cell
        {
           Rnum = ((rand() % 3) + 1);
           Cnum = ((rand() % 3) + 1);
        }
     }while(bd->checkCell(Rnum,Cnum)); //Do while cell is already marked
     bd->placeO(Rnum, Cnum);   //Place O in cell
 }   
 return bd; //return board with marked spaces
}   

MakeNumber BoardDesign::win()
{
   //Check for 3 X's in a line and return X as winner
   if(*(Board + 1) == X && *(Board + 2) == X && *(Board + 3)==X)
      return X;
   if(*(Board + 4) == X && *(Board + 5) == X && *(Board + 6)==X)
      return X;
   if(*(Board + 7) == X && *(Board + 8) == X && *(Board + 9)==X)
      return X;
   if(*(Board +1) == X && *(Board + 4) == X && *(Board + 7)==X)
      return X;
   if(*(Board + 2) == X && *(Board + 5) == X && *(Board + 8)==X)
      return X;
   if(*(Board + 3) == X && *(Board + 6) == X && *(Board + 9)==X)
      return X;
   if(*(Board + 1) == X && *(Board + 5) == X && *(Board + 9)==X)
      return X;
   if(*(Board + 3) == X && *(Board + 5) == X && *(Board + 7)==X)
      return X;
   
   //Check for 3 O's in a line and return O as winner
   if(*(Board + 1) == O && *(Board + 2) == O && *(Board + 3)==O)
      return O;
   if(*(Board + 4) == O && *(Board + 5) == O && *(Board + 6)==O)
      return O;
   if(*(Board + 7) == O && *(Board + 8) == O && *(Board + 9)==O)
      return O;
   if(*(Board +1) == O && *(Board + 4) == O && *(Board + 7)==O)
      return O;
   if(*(Board + 2) == O && *(Board + 5) == O && *(Board + 8)==O)
      return O;
   if(*(Board + 3) == O && *(Board + 6) == O && *(Board + 9)==O)
      return O;
   if(*(Board + 1) == O && *(Board + 5) == O && *(Board + 9)==O)
      return O;
   if(*(Board + 3) == O && *(Board + 5) == O && *(Board + 7)==O)
      return O;
   
   //If X or O are not 3 in a row   
   return blank;
} //end win()

int BoardDesign::printWinner(string splayer, BoardDesign* bd, int count)
{
     int again; //Variable to determine if user wants to play again
     cout <<endl;
     bd->printboard();
     if (count != 9) //Print winner
        cout <<endl<<endl<<endl<<"**"<<splayer<<" wins!!!!**"<<endl<<endl;
     else
        cout <<endl<<endl<<"No Winner.  Tied Game!"<<endl;   
     
     cout << "\n\nPlay again? \n1=Yes \nAny Other Key=No:  ";
     cin >> again;
     return again; //1 = Play again
}
 

int main (void)
{
   int player, again;
   string splayer, You;
   Randomize r; //Create object of Randomize
   do
   {
       BoardDesign* bd = new BoardDesign;//Create ptr object of BoardDesign
       int count = 0; //to count # of plays
       cout << "\n\tTIC TAC TOE";
       cout << "\n\nYou will be playing against the computer.";
       cout << "\nColumns and Rows number 1-3.";
       cout << "\nFirst to fill THREE in a line WINS!!.";
       cout << "\n\nPlease enter your first name:  ";
       cin >> You; //user's name
       cout << "\n\nChoosing a 1st player....";
       cout << endl;
       player = r.firstPlayer(); //random first player
       if (player == 1)
       {
          player = 1;
          splayer = You;
       }
       else
       {   
          player = 2;
          splayer = "Computer";
       }
       
       cout <<endl<<splayer<<" will go first:"<<endl;
       system("pause");
       while (bd->win() == blank) //if X or O not 3 in a row (line)
       {
          count++;
          bd=bd->playerPlay(player,splayer,bd);
          
          if (bd->win()==blank) //if X or O not 3 in a row (line)
          {
             cout <<"\n\n\n"<<"\t"<< splayer<<"'s move: "<<endl;
             if (player == 2)
             {
                player = 1;
                splayer = You; //Switch from computer to user
             }
             else if (player == 1)
             {
                player = 2;
                splayer = "Computer"; //Switch from user to computer
             }      
          }
          if (count==9) //all 9 cells filled.  Tie game.
             break; //Stop while loop.
       } //Close while
       again=bd->printWinner(splayer,bd,count);  
       delete bd; //delete board for new game.  (re-create board line 228)
   }while (again == 1); //repeat while user picks 1
   cout << "\n\nGoodBye!!";    
   return 0;
} //end main()

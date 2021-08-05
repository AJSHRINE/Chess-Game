
  
#include <iostream>
#include<cctype>
#include<cstring>
#include <fstream>
using namespace std;

// * sr - source row 
// * sc - source column
// * dr - destination row 
// * dc - destination column
// * Captial Alphabets - black pieces
// * Small letter alphabets - white pieces
// * R/r- rook; N/n- Knight; B/b- Bishop; K/k- King; Q/q- Queen; P/p- Pawn;
struct EntityInChess
{
    int PieceRowCol;
    char blackOrWhite;
}chess[8][8];

char str[9][9]={{' ','1','2','3','4','5','6','7','8'},
				{'1','R','N','B','K','Q','B','N','R'},
				{'2','P','P','P','P','P','P','P','P'},
				{'3','0','0','0','0','0','0','0','0'},
				{'4','0','0','0','0','0','0','0','0'},
				{'5','0','0','0','0','0','0','0','0'},
				{'6','0','0','0','0','0','0','0','0'},
				{'7','p','p','p','p','p','p','p','p'},
				{'8','r','n','b','k','q','b','n','r'}};

const int rook=1;
const int knight=2;
const int bishop=3;
const int king=4;
const int queen=5;
const int pawn=6;

char ch='n';

class ChessConditions
{
public:
    int i;
    char your_move;
    void startBoard()
    {
        int count=1;
        //Arranging the pieces , As per in the chess board ,For eg : 1 2 3 4 5 3 2 1
        for(i=0;i<8;i++)
        {
            chess[0][i].PieceRowCol=count; 
            chess[7][i].PieceRowCol=count;
            chess[0][i].blackOrWhite='b';
            chess[7][i].blackOrWhite='w';
            chess[1][i].blackOrWhite='b';
            chess[6][i].blackOrWhite='w';
            chess[1][i].PieceRowCol=6;
            chess[6][i].PieceRowCol=6;

            if(i<=3)
                count++;
            else if(i==4)
                count-=2;
            else
                count--;
        }
        for(int i=2;i<6;i++)
            for(int j=0;j<8;j++)
            {
                chess[i][j].PieceRowCol=0;
                chess[i][j].blackOrWhite='n';
            }
    }
    
	// * Check  the piece that is there or not.
    // * source row and column should be his blackOrWhite and it should'nt be zero 
    int check(int sr,int sc,int dr,int dc,char ch)
    {
        if(chess[sr][sc].PieceRowCol!=0 && chess[sr][sc].blackOrWhite==ch)
        {
            if(chess[dr][dc].PieceRowCol==0 || chess[dr][dc].blackOrWhite==((ch=='b')?'w':'b'))
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
	
	// Check diagonally and Kill the Opponent
    int checkDiagonal(int &sr,int &sc,int &dr,int &dc)
    {
                if(sr>dr && sc<dc)
                {
                    for(i=1;i<sr-dr;i++)
                    {
                        if(chess[sr-i][sc+i].PieceRowCol!=0)
                        {
                            if(chess[sr-i][sc+i].blackOrWhite==ch)
                            {
                                cout<<"Same team  player is on the path";
                                cout<<"Can't attack";
                                return 0;
                            }
                            else
                            {
                                label3:
                                    cout<<"Do you want kill the opponent piece : (y/n):";
                                        cin>>your_move;
                                        if(your_move=='y' || your_move=='Y')
                                        {
                                            dr=dr+(dr-sr-i);
                                            dc=dc-(dr-sr-i);
                                            break;
                                        }
                                        else if(your_move=='n' || your_move=='N')
                                        {
                                            cout<<"Wrong path!!";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\n Please type again correctly";
                                            goto label3;

                                        }

                            }
                        }
                    }
                    return 1;
                }


                else if(sr<dr && sc>dc)
                {
                    for(i=1;i<dr-sr;i++)
                    {
                        if(chess[sr+i][sc-i].PieceRowCol!=0)
                        {
                            if(chess[sr+i][sc-i].blackOrWhite==ch)
                            {
                            	cout<<"Same team player is on the path";
                                cout<<"Can't attack";
                                return 0;
                            }
                            else
                            {
                                label4:
                                	cout<<"Do you want kill the opponent piece : (y/n):";
                                        cin>>your_move;
                                        if(your_move=='y' || your_move=='Y')
                                        {
                                            dr=dr-(dr-sr-i);
                                            dc=dc+(dr-sr-i);
                                            break;
                                        }
                                        else if(your_move=='n' || your_move=='N')
                                        {
                                            cout<<"Wrong Path!!";
                                            return 0;
                                        }
                                        else
                                        {
                                        	cout<<"\n Please type again correctly\n";
                                            goto label4;

                                        }

                            }
                        }
                    }
                    return 1;
                }

                else if(sr<dr && sc<dc)
                {
                    for(i=1;i<dr-sr;i++)
                    {
                        if(chess[sr+i][sc+i].PieceRowCol!=0)
                        {
                            if(chess[sr+i][sc+i].blackOrWhite==ch)
                            {
                                cout<<"Same team Player in path";
                                cout<<"Can't attack";
                                return 0;
                            }
                            else
                            {
                                label5:
                                	cout<<"Do you want kill the opponent piece : (y/n):";
                                        cin>>your_move;
                                        if(your_move=='y' || your_move=='Y')
                                        {
                                            dr=dr-(dr-sr-i);
                                            dc=dc-(dr-sr-i);
                                            break;
                                        }
                                        else if(your_move=='n' || your_move=='N')
                                        {
                                            cout<<"Wrong Path!!";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\n Please type again correctly\n";
                                            goto label5;

                                        }

                            }
                        }
                    }
                    return 1;
                }

                else
                {
                    for(i=1;i<sr-dr;i++)
                    {
                        if(chess[sr-i][sc-i].PieceRowCol!=0)
                        {
                            if(chess[sr-i][sc-i].blackOrWhite==ch)
                            {
                                cout<<"Own Player in path";
                                cout<<"Cant attack";
                                return 0;
                            }
                            else
                            {
                                 label6:
                                	 cout<<"Do you want kill the opponent piece : (y/n):";
                                        cin>>your_move;
                                        if(your_move=='y' || your_move=='Y')
                                        {
                                            dr=dr+(sr-dr-i);
                                            dc=dc+(sr-dr-i);
                                            break;
                                        }
                                        else if(your_move=='n' || your_move=='N')
                                        {
                                            cout<<"Wrong Path!! ";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nPlease type correctly\n";
                                            goto label6;

                                        }
                            }
                        }
                    }
                    return 1;
                }
    }
  
    //check Row and Kill the opponent
    int forRow(int &sr,int &sc,int &dr,int &dc)
    {
                    if(dc<=sc)
                    {
                        for(i=sc-1;i>=dc+1;i--)
                        {
                            if(chess[sr][i].PieceRowCol!=0)
                            {
                            	//if path contains the attacking own team  piece
                                if(chess[sr][i].blackOrWhite==ch)               
                                {
                                    cout<<"\nOwn Player in path\n";
                                    cout<<"Can't attack\n";
                                    return 0;
                                }

                                else
                                {
                                    label7:                               
                                    	//if path contains opponents piece & asking if you want to take over the opponent in path 
                                        cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>your_move;                   
                                        if(your_move=='y' || your_move=='Y')
                                        {
                                            dc=i;
                                            break;
                                        }
                                        else if(your_move=='n' || your_move=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately\n";
                                            goto label7;
                                        }
                                }
                            }
                        }

                    }
                    else
                    {
                        for(i=sc+1;i<=dc-1;i++)
                        {
                            if(chess[sr][i].PieceRowCol!=0)
                            {
                                if(chess[sr][i].blackOrWhite==ch)
                                {
                                    cout<<"\nOwn Player in path\n";
                                    cout<<"Can't attack\n";
                                    return 0;
                                }
                                else
                                {
                                    label8:
                                        cout<<"Do u want to take over the piece in path(y/n):";
                                        cin>>your_move;
                                        if(your_move=='y' || your_move=='Y')
                                        {
                                            dc=i;
                                            break;
                                        }
                                        else if(your_move=='n' || your_move=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nGive answer appropriately\n";
                                            goto label8;
                                        }
                                }
                            }
                        }
                    }
                    return 1;
    }

    // check Column
    int checkColumn(int &sr,int &sc,int &dr,int &dc)
    {
                    if(sr<=dr)
                    {
                        for(i=sr+1;i<=dr-1;i++)
                        {
                            if(chess[i][sc].PieceRowCol!=0)
                            {
                                if(chess[i][sc].blackOrWhite==ch)
                                {
                                    cout<<"Own Player in path";
                                    cout<<"cant attack";
                                    return 0;
                                }
                                else
                                {
                                    label9:
                                    	cout<<"Do you want kill the opponent piece : (y/n):";
                                        cin>>your_move;
                                        if(your_move=='y' || your_move=='Y')
                                        {
                                            dr=i;
                                            break;
                                        }
                                        else if(your_move=='n' || your_move=='N')
                                        {
                                            cout<<"Wrong Path";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\nPlease type correctly\n";
                                            goto label9;
                                        }
                                }
                            }
                        }
                    }
					//if wrongly written this else part.modifications required
                    else                                     
                    {
                        for(i=sr-1;i>=dr+1;i--)
                        {
                            if(chess[i][sc].PieceRowCol!=0)
                            {
                                if(chess[i][sc].blackOrWhite==ch)
                                {
                                    cout<<"\n Same team Player in path\n";
                                    cout<<"Can't attack\n";
                                    return 0;
                                }
                                else
                                {
                                    label10:
                                    	cout<<"Do you want kill the opponent piece : (y/n):";
                                        cin>>your_move;
                                        if(your_move=='y' || your_move=='Y')
                                        {
                                            dc=i;
                                            break;
                                        }
                                        else if(your_move=='n' || your_move=='N')
                                        {
                                            cout<<"Wrong Path!!";
                                            return 0;
                                        }
                                        else
                                        {
                                            cout<<"\n Please type the answer correctly";
                                            goto label10;
                                        }
                                }
                            }
                        }
                    }
                    return 1;
    }
    //checks whether move is valid
    int isMoveValid(int &sr,int &sc,int &dr,int &dc)                       
    {
        switch(chess[sr][sc].PieceRowCol)
        {
      //for king
            case 4:                                                     
                if(((dr==sr+1 || dr==sr-1) && (dc==sc+1 || dc==sc-1)) || ((dr==sr+1 || dr==sr-1) && (dc==sc)) || ((dc==sc+1 || dc==sc-1) && (dr==sr)))
                    return 1;
                else
                    return 0;
      //for queen & checking if queen moves in a horizontal row
            case 5:                                                        
                if(sr==dr)                                                 
                {
                    if(forRow(sr,sc,dr,dc))
                        return 1;
                    else 
                        return 0;
                    
                }

                else if(sc==dc)                                     //if moves in a vertical column
                {
                    if(checkColumn(sr,sc,dr,dc))
                        return 1;
                    else 
                        return 0;
 
                }

                else if(checkDiagonal(sr,sc,dr,dc))
                    return 1;

                else 
                    return 0;

            case 3:
                if(checkDiagonal(sr,sc,dr,dc))
                    return 1;
                else
                    return 0;

            case 2:
                if((dr==sr+2 && dc==sc+1) || (dr==sr+2 && dc==sc-1) || (dr==sr-2 && dc==sc+1) || (dr==sr-2 && dc==sc-1)|| (dc==sc+2 && dr==sr+1) || (dc==sc+2 && dr==sr-1)|| (dc==sc-2 && dr==sr+1) || (dc==sc-2 && dr==sr-1))
                    return 1;
                else
                    return 0;
        //for pawn
            case 6:                                                                   
                if(chess[sr][sc].blackOrWhite=='b')
                {
                    if(chess[dr][dc].blackOrWhite=='w')
                        if(dr==sr+1 && (dc==sc+1 || dc==sc-1))
                            return 1;
                        else 
                            return 0;
                    else if(sr==1)
                    {
                        if((dr==sr+1 || dr==sr+2) && dc==sc)
                            return 1;
                        else 
                            return 0;
                    } 
                    else if(dr==sr+1 && dc==sc)
                        return 1;
                    else 
                        return 0;
                }

                else
                {
                    if(chess[dr][dc].blackOrWhite=='b')
                        if(dr==sr-1 && (dc==sc+1 || dc==sc-1))
                            return 1;
                        else 
                            return 0;
                    else if(sr==6)
                    {
                        if((dr==sr-1 || dr==sr-2) && dc==sc)
                            return 1;
                        else 
                            return 0;
                    } 
                    else if(dr==sr-1 && dc==sc)
                        return 1;
                    else 
                        return 0;
                }

            case 1:
                if(dr==sr)
                {
                    if(forRow(sr,sc,dr,dc))
                        return 1;
                    else 
                        return 0;
                }
                else if(sc==dc)
                {
                    if(checkColumn(sr,sc,dr,dc))
                        return 1;
                    else 
                        return 0;
                }
                else 
                    return 0;
        }
    }
    
    //check the piece move
    void pieceMove(int sr,int sc,int dr,int dc)
    {
        chess[dr][dc].PieceRowCol=chess[sr][sc].PieceRowCol;
        chess[dr][dc].blackOrWhite=chess[sr][sc].blackOrWhite;
        
            switch(chess[dr][dc].PieceRowCol)
            {
                case 4:str[dr+1][dc+1]=((chess[dr][dc].blackOrWhite=='b')?'K':'k');
                        break;
                case 5:str[dr+1][dc+1]=((chess[dr][dc].blackOrWhite=='b')?'Q':'q');
                        break;
                case 3:str[dr+1][dc+1]=((chess[dr][dc].blackOrWhite=='b')?'B':'b');
                        break;
                case 2:str[dr+1][dc+1]=((chess[dr][dc].blackOrWhite=='b')?'N':'n');
                        break;
                case 1:str[dr+1][dc+1]=((chess[dr][dc].blackOrWhite=='b')?'R':'r');
                        break;
                case 6:str[dr+1][dc+1]=((chess[dr][dc].blackOrWhite=='b')?'P':'p');
                        break;
            }

        chess[sr][sc].PieceRowCol=0;
        chess[sr][sc].blackOrWhite='n';
        str[sr+1][sc+1]='0';
    }
    //display the chess board
    void display()
    {
        cout<<endl<<endl;
        for(int i=0;i<9;i++)
        {

            for(int j=0;j<9;j++)
                cout<<str[i][j]<<"  ";
            cout<<endl;
            if(i==0)
                cout<<endl;
        }
        
        cout<<endl;
    }
};

int main()
{
	//for recording the inputs
	fstream Records;
	Records.open("Records.txt", ios::out);
    ChessConditions obj;

    obj.startBoard();

    int sr,sc,dr,dc,counter=0;

    obj.display();
    int timer =0;

    cout<<"Lets START the game";

    label1:

    if(timer++%2==0)
    {
        cout<<"\nBLACK's turn\n";
        ch='b';
    }
    else
    {
        cout<<"\nWHITE's turn\n";
        ch='w';
    }
    cout<<"Enter source row and column(for eg: 1 1)";
    cin>>sr>>sc;
    cout<<"\nEnter destination row and column:";
    cin>>dr>>dc;
    
	//Recording the inputs
	Records<<"\n"<<++counter<<"\nSource Row:"<<sr;
	Records<<"\nSource Column:"<<sc;
	Records<<"\nDestinatiom Row:"<<dr;
	Records<<"\nDestination Column:"<<sr;
    cout<<endl;

    if(sr>=8 && sr<=-1 && sc>=8 && sc<=-1 && dr>=8 && dr<=-1 && dc>=8 && dc<=-1 && sr==dr && sc==dc)
    {
        cout<<"\nWrong Input\n";
        timer-=1;
        goto label1;
    }
    else{
    	Records<<"--above input are Correct--";
	}
    // exit or continue
    cout<<" * if you want exit, type 'exit' \n * else press any other key and give enter to continue & print the board: ";
    char arr[10];
    cin>>arr;
   	int i=0;
    while(i<5)
    {
        arr[i]=toupper(arr[i]);
        i++;
    }
    if(!strcmp(arr,"EXIT")){
    	cout<<"Thanks for playing";
    	return 0;
	}
    int a,b,c,d;
        a=sr-1;
        b=sc-1;
        c=dr-1;
        d=dc-1;
    if(obj.check(a,b,c,d,ch))
    {
        
        if(obj.isMoveValid(a,b,c,d))
        {
           obj.pieceMove(a,b,c,d);

           obj.display();

        }
        else
        {
            cout<<"\nWrong Input\n";
            timer-=1;
            goto label1;
        }
    }
    else
    {
        cout<<"\nWrong Input\n";
        timer-=1;
        goto label1;
    }

    int flag=0;

    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
            if(chess[i][j].PieceRowCol==4)
                flag++;
    }
    if(flag==2)
        goto label1;
    else
    {
        if(ch=='b')
           cout<<"\n BLACK WINS \n";
        else
            cout<<"\nWHITE WINS\n";
    Records.close();
    }
}

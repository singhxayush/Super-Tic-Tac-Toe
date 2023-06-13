#include<bits/stdc++.h>
using namespace std;

char ref[3][3];
char board[9][9];
int turn = 1;

void init()
{
    for(int i=0; i<9; i++)
    for(int j=0; j<9; j++)
    board[i][j] = ' ';

    system("clear");

    cout<<"INITAL BOARD 9x9 EMPTY!\n";
    cout<<"TURN FOR X"<<"\n\n";

    for(int i=0; i<9; i++)
    {
        if(i==0) cout<<"\t1   2   3---------------4   5   6---------------7   8   9\n\n";

        cout<<i+1<<"\t";
        for(int j=0; j<9; j++)
        {
            // if((j+1)%3 == 0) cout<<board[i][j]<<" | ";
            
            cout<<board[i][j];
            if((j+1)%3 != 0) cout<<" | ";
            else if(j!=8) cout<<"\t"<<i+1<<"\t";

        }
        cout<<"\n";
        // if((i+1)%3 !=0 ) cout<<"---------               ---------               ---------\n";
        if((i+1)%3 !=0 ) cout<<"\t---------               ---------               ---------\n";
        if((i+1)%3 == 0) cout<<"\n";
        if((i+1)%3 == 0) cout<<"\t1   2   3---------------4   5   6---------------7   8   9\n\n";
    }
    cout<<"\n";
}

void print_bord()
{
    system("clear");

    cout<<"The Game is ONNNN!\n";
    if(turn == 1) cout<<"MOVE FOR X\n\n";
    else cout<<"MOVE FOR O\n\n";

    for(int i=0; i<9; i++)
    {
        if(i==0) cout<<"\t1   2   3---------------4   5   6---------------7   8   9\n\n";

        cout<<i+1<<"\t";
        for(int j=0; j<9; j++)
        {
            // if((j+1)%3 == 0) cout<<board[i][j]<<" | ";
            
            cout<<board[i][j];
            if((j+1)%3 != 0) cout<<" | ";
            else if(j!=8) cout<<"\t"<<i+1<<"\t";

        }
        cout<<"\n";
        // if((i+1)%3 !=0 ) cout<<"---------               ---------               ---------\n";
        if((i+1)%3 !=0 ) cout<<"\t---------               ---------               ---------\n";
        if((i+1)%3 == 0) cout<<"\n";
        if((i+1)%3 == 0) cout<<"\t1   2   3---------------4   5   6---------------7   8   9\n\n";
    }
    cout<<"\n";
}

// bool check()
// {

// }

int x, y;
int main()
{
    init();
    int c = 1;
    bool b = true;


    while(1)
    {
        if(turn  == 1)
        {
            cout<<"Enter co-oridnates for \"X\" :\n";
            cin>>x>>y;
            if((board[x-1][y-1] != ' ') && (x>9 || x<1 || y>9 || y<1))
            {
                cout<<"Invalid Entry, Enter Again!\n";
                continue;
            }
            turn ^= 1;
            board[x-1][y-1] = 'X';
            print_bord();
        }
        else
        {
             cout<<"Enter co-oridnates for \"O\" :\n";
            cin>>x>>y;
            if((board[x-1][y-1] != ' ') && (x>9 || x<1 || y>9 || y<1))
            {
                cout<<"Invalid Entry, Enter Again!\n";
                continue;
            }
            turn ^= 1;
            board[x-1][y-1] = 'O';
            print_bord();
        }
    }
}
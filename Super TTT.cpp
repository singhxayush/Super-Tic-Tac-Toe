#include<bits/stdc++.h>
using namespace std;

char ref[3][3];
char board[9][9];
int turn = 1;

void wrong_entry()
{
    system
    (
        "gum style \
        --foreground=\"#ff3399\" \
        --bold \
        \"Invalid Entry, Enter Again!\""
    );    
}

void init()
{
    for(int i=0; i<9; i++)
    for(int j=0; j<9; j++)
    board[i][j] = ' ';

    system("clear");

    cout<<"INITAL BOARD 9x9 EMPTY!\n";
    cout<<"TURN : X"<<"\n\n";

    for(int i=0; i<9; i++)
    {
        if(i==0) cout<<"\t1   2   3---------------4   5   6---------------7   8   9\n\n";

        cout<<i+1<<"\t";
        for(int j=0; j<9; j++)
        {
            cout<<board[i][j];
            if((j+1)%3 != 0) cout<<" | ";
            else if(j!=8) cout<<"\t"<<i+1<<"\t";
        }

        cout<<"\n";
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
    if(turn == 1) cout<<"TURN : X\n\n";
    else cout<<"TURN : O\n\n";

    for(int i=0; i<9; i++)
    {
        if(i==0) cout<<"\t1   2   3---------------4   5   6---------------7   8   9\n\n";

        cout<<i+1<<"\t";
        for(int j=0; j<9; j++)
        {
            cout<<board[i][j];
            if((j+1)%3 != 0) cout<<" | ";
            else if(j!=8) cout<<"\t"<<i+1<<"\t";

        }

        cout<<"\n";
        if((i+1)%3 != 0) cout<<"\t---------               ---------               ---------\n";
        if((i+1)%3 == 0) cout<<"\n";
        if((i+1)%3 == 0) cout<<"\t1   2   3---------------4   5   6---------------7   8   9\n\n";
    }
    cout<<"\n";
}

// bool check()
// {

// }

int main()
{
    init();
    int c = 1;
    bool b = true;

    int x, y;
    int col_low, col_high, row_low, row_high;
    int segment;

    while(1)
    {

        if(turn)
        {
            if(b) cout<<"Enter Anywhere!\n";
            else
            {
                cout<<"Enter [co-oridnates] in SEGMET ["<<segment<<"] for \"X\"\n";
                cout<<"In the Range : ROW["<<row_low<<", "<<row_high<<"] : "<<"COL["<<col_low<<", "<<col_high<<"]\n";
            }

            cin>>x>>y;
            if(board[x-1][y-1] == ' ')
            {
                if(x>9 || x<1 || y>9 || y<1)
                {
                    cout<<"Invalid Entry, Enter Again!\n";
                    system("sleep 2");
                    print_bord();
                    continue;
                }
                else
                {
                    turn ^= 1;
                    board[x-1][y-1] = 'X';
                    b = false;
                    print_bord();
                }
            }
            else
            {
                wrong_entry();
                system("sleep 2");
                print_bord();
                continue;
            }
        }
        else
        {
            if(b) cout<<"Enter Anywhere!\n";
            else
            {
                cout<<"Enter [co-oridnates] in SEGMET ["<<segment<<"] for \"O\"\n";
                cout<<"In the Range : ROW["<<row_low<<", "<<row_high<<"] : "<<"COL["<<col_low<<", "<<col_high<<"]\n";
            }
            cin>>x>>y;
            if(board[x-1][y-1] == ' ')
            {
                if(x>9 || x<1 || y>9 || y<1)
                {
                    wrong_entry();
                    system("sleep 2");
                    print_bord();
                    continue;
                }
                else
                {
                    turn ^= 1;
                    board[x-1][y-1] = 'O';
                    b = false;
                    print_bord();
                }
            }
            else
            {
                wrong_entry();
                system("sleep 2");
                print_bord();
                continue;
            }
        }

        // Calculating next constrained range from current x and y

        // Calc which segment
        int tempx, tempy;
        if(x%3) tempx = x%3;
        else tempx = 3;

        if(y%3) tempy = y%3;
        else tempy = 3;
        
        if(tempx == 1 && tempy == 1)      segment = 1;
        else if(tempx == 1 && tempy == 2) segment = 2;
        else if(tempx == 1 && tempy == 3) segment = 3;
        else if(tempx == 2 && tempy == 1) segment = 4;
        else if(tempx == 2 && tempy == 2) segment = 5;
        else if(tempx == 2 && tempy == 3) segment = 6;
        else if(tempx == 3 && tempy == 1) segment = 7;
        else if(tempx == 3 && tempy == 2) segment = 8;
        else if(tempx == 3 && tempy == 3) segment = 9;
        

        // ROW Calc
        if(segment == 1)      { row_low = 1, row_high = 3, col_low = 1, col_high = 3; }
        else if(segment == 2) { row_low = 4, row_high = 6, col_low = 1, col_high = 3; }
        else if(segment == 3) { row_low = 7, row_high = 9, col_low = 1, col_high = 3; }
        else if(segment == 4) { row_low = 1, row_high = 3, col_low = 4, col_high = 6; }
        else if(segment == 5) { row_low = 4, row_high = 6, col_low = 4, col_high = 6; }
        else if(segment == 6) { row_low = 7, row_high = 9, col_low = 4, col_high = 6; }
        else if(segment == 7) { row_low = 1, row_high = 3, col_low = 7, col_high = 9; }
        else if(segment == 8) { row_low = 4, row_high = 6, col_low = 7, col_high = 9; }
        else if(segment == 9) { row_low = 7, row_high = 9, col_low = 7, col_high = 9; }

    }
}
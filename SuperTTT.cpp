#include<bits/stdc++.h>
using namespace std;

char final_board[3][3];
char board[9][9];
char temp_segment[3][3];
int turn = 1;

void already_filled()
{
    system
    (
        "gum style \
        --foreground=\"#ff3399\" \
        --bold \
        \"Invalid Entry position is already filled, Enter Again!\""
    );
}

void wrong_range()
{
    system
    (
        "gum style \
        --foreground=\"#ff3399\" \
        --bold \
        \"Range Error, Enter Again!\""
    );    
}

void out_of_bounds()
{
    system
    (
        "gum style \
        --foreground=\"#ff3399\" \
        --bold \
        \"Out of bounds, Enter Again!\""
    );    
}

void init()
{
    for(int i=0; i<9; i++)
    for(int j=0; j<9; j++)
    board[i][j] = ' ';

    for(int i=0; i<3; i++)
    for(int j=0; j<3; j++)
    final_board[i][j] = ' ';

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


void print_segment(int rl, int rh, int cl, int ch)
{
    for(int i=rl-1; i<rh; i++)
    {

        if(i==0) cout<<"\t"<<cl<<"   "<<cl+1<<"   "<<ch<<"\n\n";

        cout<<i+1<<"\t";
        for(int j=cl-1; j<ch; j++)
        {
            cout<<board[i][j];
            if((j+1)%3 != 0) cout<<" | ";
            else if(j==0) cout<<"\t"<<i+1<<"\t";

        }

        cout<<"\n";
        if((i+1)%3 != 0) cout<<"\t---------\n";
        if((i+1)%3 == 0) cout<<"\n";
    }
    cout<<"\n";
}

bool checkWin(char player)
{
    // Check rows
    for (int i = 0; i < 3; ++i)
    {
        if (temp_segment[i][0] == player && temp_segment[i][1] == player && temp_segment[i][2] == player)
        {
            return true; // Player has won
        }
    }

    // Check columns
    for (int i = 0; i < 3; ++i)
    {
        if (temp_segment[0][i] == player && temp_segment[1][i] == player && temp_segment[2][i] == player)
        {
            return true; // Player has won
        }
    }

    // Check diagonals
    if (temp_segment[0][0] == player && temp_segment[1][1] == player && temp_segment[2][2] == player)
    {
        return true; // Player has won
    }

    if (temp_segment[0][2] == player && temp_segment[1][1] == player && temp_segment[2][0] == player)
    {
        return true; // Player has won
    }

    return false; // No winner
}

void update_ref(char update_char, int rl, int rh, int cl, int ch, int segX, int segY)
{
    int cnt = 0;

    for(int i=rl-1; i<rh; i++)
    for(int j=cl-1; j<ch; j++)
    board[i][j] = temp_segment[i][j];

    if (checkWin(update_char)) final_board[segX-1][segY-1] = update_char;
}

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

            if(x>9 || x<1 || y>9 || y<1)
            {
                out_of_bounds();
                this_thread::sleep_for(std::chrono::seconds(2));
                print_bord();
                continue;
            }
            else if((x<row_low || x>row_high || y<col_low || y>col_high) && !b)
            {
                wrong_range();
                this_thread::sleep_for(std::chrono::seconds(2));
                print_bord();
                continue;
            }
            else if(board[x-1][y-1] == ' ')
            {
                turn ^= 1;
                board[x-1][y-1] = 'X';
                b = false;
                print_bord();
            }
            else
            {
                already_filled();
                this_thread::sleep_for(std::chrono::seconds(2));
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
                cout<<"In the Range : ROW["<<row_low<<", "<<row_high<<"] : "<<"ROW["<<col_low<<", "<<col_high<<"]\n";
            }

            cin>>x>>y;

            if(x>9 || x<1 || y>9 || y<1)
            {
                out_of_bounds();
                this_thread::sleep_for(std::chrono::seconds(2));
                print_bord();
                continue;
            }
            else if((x<row_low || x>row_high || y<col_low || y>col_high) && !b)
            {
                wrong_range();
                this_thread::sleep_for(std::chrono::seconds(2));
                print_bord();
                continue;
            }
            else if(board[x-1][y-1] == ' ')
            {
                turn ^= 1;
                board[x-1][y-1] = 'O';
                b = false;
                print_bord();
            }
            else
            {
                already_filled();
                this_thread::sleep_for(std::chrono::seconds(2));
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

        swap(col_low, row_low);
        swap(col_high, row_high);



        // Calculating current range and current segment wise co-ordinate from current x and y for ref check

        int cur_row_l, cur_row_h, cur_col_l, cur_col_h;

        if(x < 4) { cur_row_l = 1; cur_row_h = 3; }
        else if(x > 3 && x < 7) { cur_row_l = 4; cur_row_h = 6; }
        else if(x > 6) { cur_row_l = 7; cur_row_h = 9; }

        if(y < 4) { cur_col_l = 1; cur_col_h = 3; }
        else if(y > 3 && y < 7) { cur_col_l = 4; cur_col_h = 6; }
        else if(y > 6) { cur_col_l = 7; cur_col_h = 9; }

        int segX, segY;

        if(x < 4)
        {
            if(y < 4) { segX = 1; segY = 1; }
            else if(y > 3 && y < 7) { segX = 1; segY = 2; }
            else if(y > 6) { segX = 1; segY = 3; }
        }
        else if(x > 3 && x < 7)
        {
            if(y < 4) { segX = 2; segY = 1; }
            else if(y > 3 && y < 7) { segX = 2; segY = 2; }
            else if(y > 6) { segX = 2; segY = 3; }
        }
        else if(x > 6)
        {
            if(y < 4) { segX = 3; segY = 1; }
            else if(y > 3 && y < 7) { segX = 3; segY = 2; }
            else if(y > 6) { segX = 3; segY = 3; }
        }

        if(final_board[segX-1][segY-1] != 'X' || final_board[segX-1][segY-1] != 'Y')
        update_ref(board[x-1][y-1], cur_row_l, cur_row_h, cur_col_l, cur_col_h, segX, segY);



        this_thread::sleep_for(std::chrono::seconds(5));
    }
}
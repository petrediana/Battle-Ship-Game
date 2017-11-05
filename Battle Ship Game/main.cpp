#include <bits/stdc++.h>
#include <ctime>
using namespace std;

const int rows = 10;
const int elements = 10;

int a[rows][elements];
int maxships = 10;

void Clear()
{
    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < elements; j++)
        {
            a[i][j] = 0;
        }
    }
}

void SetShips()
{
    int s = 0;
    while(s < maxships)
    {
        int x = rand() % rows;
        int y = rand() % elements;
        if(a[x][y] != 1)
        {
            s++;
            a[x][y] = 1;
        }
    }
}

void Show()
{
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<elements; j++)
            cout<<a[i][j]<<" ";

        cout<<endl;
    }

}

bool Attack ( int x, int y )
{
    if ( a[x][y] == 1)
    {
        a[x][y] = 2;
        return true;
    }
    return false;
}

int NrShips()
{
    int c = 0;

    for(int i=0; i < rows; i++)
    {
        for(int j=0; j < elements; j++)
        {
            if(a[i][j] == 1)
                c++;
        }
    }

    return c;
}


int main()
{
    //srand(time(NULL));
    Clear();
    SetShips();


    int pos1, pos2,nr=1;
    char Surrender;
    while(1)
    {
        cout<< string( 35, ' ' )<<"Current number of guesses: "<<nr<<endl;
        cout<< "Enter ship coordinates: ";
        cin>>pos1 >> pos2;

        if(Attack(pos1,pos2))
            cout<< string(5,' ') <<"Yarrrrr, you've sunk one of my ships!"<<endl;
        else
            cout<<string(5,' ')<<"Try again, land-lover!"<<endl;

        cout<<"Numer of ships left: " <<NrShips()<<endl;

        cout<<"Number of conquered ships: " <<maxships-NrShips()<<endl;

        if(NrShips()==0)
        {

            cout<<endl;
            cout<<"Congrats! You beat the mighty pirate!";
            cout<<endl;
            break;
        }
        else
        {


            cout<<"Would you like to give up (y,n)? ";
            cin>>Surrender;

            if(Surrender == 'y')
            {
                cout<<endl;
                break;
            }
        }

        nr++;
        cout<<endl;



    }
    cout<<"Game Over!!!" <<endl;
    cout<<endl;
    Show();
    return 0;
}

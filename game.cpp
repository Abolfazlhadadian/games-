#include <math.h>
#include <string>
#include <iostream>
using namespace std;

char table[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char turn = 'X';
int radif, soton, flag = 0;

void nobatbazikon(); // نوبت هر بازیکن
void mainasle();     // صفحه ی اول بازی که نشون میده
int natigah();

int main()
{
    while (natigah())
    {
        mainasle();
        nobatbazikon();
        natigah();
    }
    if (turn == 'X' && flag == 0)
    {
        cout << " bazikon 2{O} bordi Mashallah:)" << endl;
    }
    else if (turn == 'O' && flag == 0)
    {
        cout << " bazikon 2{X} bordi Mashallah:)" << endl;
    }
    else
    {
        cout << " mosavi shod hardo noob hastid" << endl;
    }
    return 0;
}

void mainasle() // صفحه ی اول بازی که نشون میده
{
    system("cls");
    cout << "\tplayer1 {X} hast:";
    cout << "\n \tplayer2 {O} hast:" << endl;
    cout << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << table[0][0] << "  |  " << table[0][1] << "  |  " << table[0][2] << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << table[1][0] << "  |  " << table[1][1] << "  |  " << table[1][2] << endl;
    cout << "\t\t_____|_____|_____" << endl;
    cout << "\t\t     |     |     " << endl;
    cout << "\t\t  " << table[2][0] << "  |  " << table[2][1] << "  |  " << table[2][2] << endl;
    cout << "\t\t     |     |     " << endl;
    cout << endl;
}
void nobatbazikon() // نوبت هر بازیکن
{
    int nobat;

    if (turn == 'X')
    {
        cout << "\t nobat player 1 ke x hast adadi entekhab kon:";
        cin >> nobat;
    }
    if (turn == 'O')
    {
        cout << "\tnobat player 2 ke x hast adadi entekhab kon:";
        cin >> nobat;
    }
    switch (nobat)
    {
    case 1:
        radif = 0;
        soton = 0;
        break;
    case 2:
        radif = 0;
        soton = 1;
        break;
    case 3:
        radif = 0;
        soton = 2;
        break;
    case 4:
        radif = 1;
        soton = 0;
        break;
    case 5:
        radif = 1;
        soton = 1;
        break;
    case 6:
        radif = 1;
        soton = 2;
        break;
    case 7:
        radif = 2;
        soton = 0;
        break;
    case 8:
        radif = 2;
        soton = 1;
        break;
    case 9:
        radif = 2;
        soton = 2;
        break;
    default:
        cout << " error eshtebah dar nobat..!!" << endl;
        break;
    }
    if (turn == 'X' && table[radif][soton] != 'X' && table[radif][soton] != 'O')
    {
        table[radif][soton] = 'X';
        turn = 'O';
    }
    else if (turn == 'O' && table[radif][soton] != 'X' && table[radif][soton] != 'O')
    {
        table[radif][soton] = 'O';
        turn = 'X';
    }
    else
    {
        cout << "eshtebah zadi dobarah bezan:" << endl;
        nobatbazikon();
    }
    mainasle();
}

int natigah()
{
    for (int i = 0; i < 3; i++)
    {
        if (table[i][0] == table[i][1] && table[i][0] == table[i][2] || table[0][i] == table[1][i] && table[0][i] == table[2][i])
            return false;
    }
    if (table[0][0] == table[1][1] && table[0][0] == table[2][2] || table[0][2] == table[1][1] && table[0][2] == table[2][0])
    {
        return false;
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (table[i][j] != 'X' && table[i][j] != 'O')
            {
                return true;
            }
    flag = 1;

    return -1;
}
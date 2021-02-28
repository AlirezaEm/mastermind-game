                                /* MasterMind Game By Alireza EM */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>

using namespace std;
string withrepetition();
string withoutrepetition();
void checking1(string,string,string);

int main()
{
    int repeat;
    string answer;
    string guess;
    string answer2;
    cout << "!!! WELCOME TO MASTERMIND GAME !!!" << endl;
    cout << "Please Enter UpperCase Letters to PLAY!!!"<<endl;
    cout << "Can i use same colors??? Enter <<1>> for <<YES>> OR Enter <<0>> for <<NO>>!" << endl;
    cin >> repeat;

    if(repeat)
    {
        answer = withrepetition();

        for(int i=0; i<10; i++)
        {
            answer2=answer;
			cin >> guess;
            checking1(answer2,guess,answer);
        }
        cout << "YOU LOSE :) !!!!" << endl;
        cout << "answer was: " << answer;

    }
    else
    {
        answer = withoutrepetition();
        for(int i=0; i<10; i++)
        {
            cin >> guess;
            checking1(answer,guess,answer);
        }
        cout << "YOU LOSE !!!!" << endl;
        cout << "answer was: " << answer;
    }

    return 0;
}

string withrepetition()  //making answer with repetition colors function.
{
    int i,j;
    int a[4];
    string answer;
    string colors="ABCDEFGH";
    srand((unsigned)time(NULL));

    for(i=0;i<4;i++)
    {
        a[i]= rand()%8;
        answer+=colors[a[i]];
    }

    return answer;
}

string withoutrepetition() //making answer without repetition colors function.
{
    int i,j;
    int a[4];
    string answer;
    string colors="ABCDEFGH";
    bool check;
    srand((unsigned)time(NULL));

    for(i=0;i<4;i++)
    {
        check = false;
        do
        {
            check=true;
            a[i] = rand()%8;
            for(j=0; (check) && j<i;j++)
            {
                check=(a[i] != a[j]);
            }
        }while(check==false);
        answer+=colors[a[i]];
    }

    return answer;
}

void print(string input) //printing with order function.
{
    int i=0, O=0, T=0, X=0;
    for(i=0;i<4;i++)
    {
        if(input[i] == 'O')
            O++;
        if(input[i] == 'T')
            T++;
        if(input[i] == 'X')
            X++;
    }
    for(i=0; i<O; i++)
        cout << 'O';
    for(i=0; i<T; i++)
        cout << 'T';
    for(i=0; i<X; i++)
        cout << 'X';
}

void checking1(string answer,string guess,string answer2) //checking answer with guess function.
{
    int i,j;
    string output;

    for(j=0;j<4;j++)
    {
        if(answer[j] == guess[j])
        {
            output+='O';
          answer[j]='Z';
            guess[j]='Q';
        }
    }
        for(j=0 ; j<4 ; j++)
        {
            for(i=0; i<=3; i++)
            {

                if(answer[j] == guess[i])
                {
                    output+='T';
                    answer[j]='Z';
                    guess[i]='Q';
                }
        	}
		}
		int len=output.length();
		while(len<4)
		{
			output+="X";
			len=output.length();
		}

    if(output=="OOOO")
    {
        cout << "You Win :D !!!" << endl;
        cout << "Answer is:"<< answer2;
        exit (EXIT_FAILURE);
    }
    print(output);
    cout << endl;
}







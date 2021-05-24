// DiceGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;
//Github Test
//player structure 
struct Player
{
    char name[30];
    int score = 0;
    int total = 0;
};

//Dice Structure
struct Dice
{
    int value;
};

//initializing maximum score 
int MaxScore = 0;

// function prototype

void Instruction();
void Menu();
void line();
void setMax();

//pass by pointers
void Read_player(struct Player *player, string);

void play(struct Player*, struct Player*, struct Dice*, struct Dice*);

struct Dice* Roll_dice(struct Dice*);

//initializing winner and winner score 
int winner_score = 0;
string winner = "";


int main()
{
    // Creating pointer tags for the dice
    Dice *dice1, *dice2,dice11,dice22; 

    dice1 = &dice11;
    dice2 = &dice22;

    // Creating pointer tags for the player
    Player *player1, *player2, player11,player22;

    player1 = &player11;
    player2 = &player22;

    
    int option;

    do {
        Menu();
        cout << "\nEnter your option :  ";
        cin >> option;
        cin.ignore();    // clearing input buffer


        switch (option)
        {
        case 1: Instruction(); break;

        case 2: { 
                   setMax();
                   break;
                 }

        case 3 : {
                    Read_player(player1, "Player1");
                    Read_player(player2, "Player2");
                    break;
                   }


        case 4 :{
                    player1->score = 0;  // reset the score and total
                    player1->total = 0;
                    player2->score = 0;
                    player2->total = 0;

                    play(player1, player2, dice1, dice2);
                    break;
                  }
       
        case 5: {
                    cout << "\n\n \t\t\tScore Board\n";
                    line();
                    cout << "\nFinal score of "<< player1->name <<"  is "<< player1->total;
                    cout << "\n\nFinal score of " << player2->name << "  is " << player2->total;
                    cout << "\n\n Winner    " << winner;
                    cout << "  Congrats !!!!! ";
                    line();
                    break;
                 }

        default: exit(0);

        }

    } while (option < 6);


    return 0;

}

void  Menu()
{
    cout << " \nTwo Players Dice Game-- Pre set Maximum Score \n";
    cout << "************************************************\n\n";
    cout << "1. Instruction\n";
    cout << "2. Set Maximum Score\n";
    cout << "3. Read Players\n";
    cout << "4. Play\n";
    cout << "5. Display ScoreBoard\n";
    cout << "6. End\n";
       
}

void Instruction()
{
    cout << "\n\n \t\t\tInstruction\n";
    line();
    cout << "  1. Players must feed their names and pre-set the Maximum score before game starts.\n";
    cout << "  2. Each player has two 6 face dice to roll, and the players get turns to earn score.\n";
    cout << "  3. For each roll, dice 1 and dice 2 values will be added for the corresponding players.\n";
    cout << "  4. If both dice values are same then the score will be two times the sum of the value \n \tEg : dice 1 returns 2 and dice 2 returns 2 then 2+2 = 4 *2 = 8 .\n";
    cout << "  5. Whoever reaches the maximum score first will be declared winner, \n \tand the game will be finished. \n";
    cout << "  6. After each roll, each player score board will be updated and displayed. \n";
    line();
}

void line()
{
    cout << "\n";

    for (int i = 0; i < 80; i++)
        cout << "*";
    cout << "\n";


}

void Read_player(struct Player *player,string s)
{
    cout << "Enter "<<s<<" name : ";
    cin.getline(player->name, 30);
  //  cin.ignore();
}



void setMax()
{
    cout << "Enter the Maximum Score : ";
    cin >> MaxScore;
}



void play(struct Player* player1, struct Player* player2, struct Dice* dice1, struct Dice* dice2)
{
    int Roll = 1;
    do {
        cout << "\n\n";
        cout << player1->name << " Roll " << Roll << " \n ";

        dice1 = Roll_dice(dice1);
        srand(time(0));
        dice2 = Roll_dice(dice2);

        cout << "\n Dice 1 " << dice1->value;
        cout << "\n Dice 2 " << dice2->value;
        if (dice1->value != dice2->value)
        {
            player1->score = dice1->value + dice1->value;
        }
        else
        {
            player1->score = dice1->value + dice1->value;
            player1->score *= 2;

        }
        cout << "\n Player 1 Score : " << player1->score;

        player1->total += player1->score;
        cout << "\n Player 1 total : " << player1->total << endl;

        //player 2
        cout << "\n";

        cout << player2->name << " Roll " << Roll << " \n";

        dice1 = Roll_dice(dice1);
        srand(time(0));
        dice2 = Roll_dice(dice2);

        cout << "\n Dice 1 " << dice1->value;
        cout << "\n Dice 2 " << dice2->value;
        if (dice1->value != dice2->value)
        {
            player2->score = dice1->value + dice1->value;
        }
        else
        {
            player2->score = dice1->value + dice1->value;
            player2->score *= 2;

        }
        cout << "\n Player 2 Score : " << player2->score;

        player2->total += player2->score;
        cout << "\n Player 2 total : " << player2->total;
        Roll++;
        cout << "\nPlease press any key to proceed rolling...\n";
        _getch();

        if (player1->total >= player2->total)
        {
            winner_score = player1->total;
            winner = player1->name;
        }
        else
        {
            winner_score = player2->total;
            winner = player2->name;

        }
    } while (player1->total < MaxScore && player2->total < MaxScore);
}

struct Dice* Roll_dice(struct Dice* d)
{
   // srand(time(0));
    d->value = rand() % 6 + 1;
    return d;
}


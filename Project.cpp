#include <iostream>
#include <windows.h> // to include COORD - to move cursor on screen
#include <ctime>
#include <cstdlib>
#include <unistd.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <cctype>
#include <string>
#include <ctime>
#include <vector>
#include <algorithm>
#include <set>
#include <stack>
using namespace std;
void startGame();
void InitialiseCharacter();
void Room1();
bool isSafe(int x, int y, int n, int m, vector<vector<int>> &maze, vector<vector<int>> visited);
void solve(vector<vector<int>> &maze, int n, int m, int x, int y, string path, vector<string> &ans, vector<vector<int>> visited);
vector<string> possiblePaths(vector<vector<int>> &maze);
void DragonMaze();
void Room1L();
void startBattle();
void Room1R();
void Room2();
void Room2L();
void GameofWits();
void Room2R();
void StartBossFight();
void BossRoom();
void GameEnding();

// Player Stats
string ign;
int hp;
int atk = 10;
int def = 15;
int agi = 5;

// Room Tracker
int room1L = 0;
int room1R = 0;
int room2R = 0;
int bossR = 0;
int Medallion[2] = {0, 0};

// Score Tracker
int sc = 0;

// START GAME
int main()
{
    startGame();
    return 0;
}

void InitialiseCharacter()
{
    system("CLS");
    hp = rand() % 20 + 90;
    room1L = 0;
    room1R = 0;
    room2R = 0;
    bossR = 0;
    Medallion[0] = 0;
    Medallion[1] = 0;
    cout << "Enter your In Game Name (IGN)" << endl;
    cin >> ign;
    cout << "Your name will be " << ign << endl
         << "This Cannot be Changed again in Future" << endl
         << "Do you want to continue? (Y/N)" << endl;
    char choice;
    cin >> choice;
    choice = toupper(choice);
    if (choice == 'Y')
    {
        system("CLS");
        cout << "Lets Begin!" << endl;
        cout << ".... .... ...." << endl;
        cout << ".... .... ...." << endl;
        cout << "Press Any Key to continue . . ." << endl;
        getch();
        system("CLS");
        Room1();
    }
    else if (choice == 'N')
    {
        system("CLS");
        InitialiseCharacter();
    }
    else
    {
        cout << "Wrong Input\nPress Any Key to continue . . ." << endl;
        getch();
        system("CLS");
        InitialiseCharacter();
    }
}

void Room1()
{
    system("CLS");
    cout << "You are in the Green Meadows of Dragonbarrows." << endl
         << "A cool pleasent gust of wind brushes past you" << endl
         << "Seeing Straight you see a Bridge" << endl
         << "Seeing left, you see a Promising Cave" << endl
         << "Seeing Right, you see a Morbid house and you get a sinister feeling.";
    cout << "What do you want to do?" << endl
         << "1 - Go towards the Bridge\n2 - Go Left\n3 - Go Right" << endl
         << "Enter your choice" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        Room2();
    }
    else if (choice == 2)
    {
        Room1L();
    }
    else if (choice == 3)
    {
        Room1R();
    }
    else
    {
        cout << "Wrong Input\nPress Any Key to continue . . ." << endl;
        getch();
        Room1();
    }
}

void Room1L()
{
    system("CLS");
    if (room1L == 0)
    {
        cout << "You are greeted by an Old yet Fierce Dragon." << endl
             << "The Dragon says" << endl
             << "'Ye Traveller, What is your Name?'" << endl
             << "You Reply" << endl
             << "'My name is " << ign << "'" << endl
             << "The Dragon then Replies" << endl
             << "'My Chains bind me to through the Depths of Teyvat into Hell. Can you untangle them and free me from this Abomination? I shall reward you with Knowledge for your help'" << endl;
        cout << "What do you want to do?" << endl
             << "1 - Help the Dragon\n2 - Go Back" << endl
             << "Enter your choice" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            DragonMaze();
        }
        else if (choice == 2)
        {
            Room1();
        }
        else
        {
            cout << "Wrong Input\nPress Any Key to continue . . ." << endl;
            getch();
            Room1L();
        }
    }
    else
    {
        cout << "The Old yet Fierce Dragon is lost in Thought. You dont want to disturb him." << endl;
        cout << "What do you want to do?" << endl
             << "1 - Go Back" << endl
             << "Enter your choice" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            Room1();
        }
        else
        {
            cout << "Wrong Input\nPress Any Key to continue . . ." << endl;
            getch();
            Room1L();
        }
    }
}

bool isSafe(int x, int y, int n, int m, vector<vector<int>> &maze, vector<vector<int>> visited)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < m) && visited[x][y] == 0 && maze[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void solve(vector<vector<int>> &maze, int n, int m, int x, int y, string path, vector<string> &ans, vector<vector<int>> visited)
{
    if (x == n - 1 && y == m - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, m, maze, visited))
    {
        path.push_back('D');
        solve(maze, n, m, newx, newy, path, ans, visited);
        path.pop_back();
    }
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, m, maze, visited))
    {
        path.push_back('U');
        solve(maze, n, m, newx, newy, path, ans, visited);
        path.pop_back();
    }
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, n, m, maze, visited))
    {
        path.push_back('L');
        solve(maze, n, m, newx, newy, path, ans, visited);
        path.pop_back();
    }
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, m, maze, visited))
    {
        path.push_back('R');
        solve(maze, n, m, newx, newy, path, ans, visited);
        path.pop_back();
    }
    visited[x][y] = 0;
}

vector<string> possiblePaths(vector<vector<int>> &maze)
{
    int n = maze.size();
    int m = maze[0].size();
    vector<string> ans;
    if (maze[0][0] == 0 || maze[n - 1][m - 1] == 0)
    {
        return ans;
    }
    int x = 0;
    int y = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    string path = "";
    solve(maze, n, m, x, y, path, ans, visited);
    sort(ans.begin(), ans.end());
    return ans;
}

void DragonMaze()
{
    system("CLS");
    vector<vector<int>> maze = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> paths = possiblePaths(maze);
    cout << "The Floor is Represented using 0s and 1s.\n0 means you cannot traverse the point and 1 means you can traverse it.\n"
         << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << maze[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Give a possible solution for the Untanglement if you are to start at (1,1) and reach (4,4)\nType the answer with L for left, D for Down, U for Up and R for Right" << endl;
    string solution;
    cin >> solution;
    int check = 0;
    for (int i = 0; i < paths.size(); i++)
    {
        if (solution == paths[i])
            check = 1;
    }
    if (check == 1)
    {
        cout << "Well Done, " << ign << endl;
        cout << "You have Succeeded. I give you my Gratitude" << endl
             << "Now, I shall tell you how to claim the Fabled 'Black Sword'" << endl
             << "You need to Kill Margit, The Fell Omen to get the Sword." << endl
             << "For that, you first need to obtain the 2 pieces of Medallion of Dectus to access the Gingus Lift." << endl
             << "Only then can you access the Castle and Face off The Fell Omen . . ." << endl;
        cout << "Press Any Key to continue . . ." << endl;
        getch();
        room1L = 1;
        Room1L();
    }
    else
    {
        cout << "You Almost Fell, " << ign << endl;
        cout << "Be Careful Next Time, Young Traveller . . ." << endl;
        cout << "Press Any Key to continue . . ." << endl;
        getch();
        Room1L();
    }
}

void startBattle()
{
    system("CLS");
    int choice;
    int i, hurt, mhurt, sc;
    srand((unsigned)time(0));
    int mhp = rand() % 50 + 60;
    int matk = 10;
    int mdef = 15;
    int magi = 5;
    int init = rand() % 2 + 1;
    if (init == 1)
    {
        cout << "You start.\n==========\n";
        while (hp > 0 || mhp > 0)
        {
            cout << "What do you want to do?\n1 - Fierce Attack\n2 - Light Attack\n3 - Defensive moves\n";
            do
            {
                cin >> choice;
            } while (choice > 3 || choice < 1);
            switch (choice)
            {
            case 1:
                atk = rand() % 20 + 10;
                def = rand() % 10 + 10;
                agi = rand() % 5;
                break;
            case 2:
                atk = rand() % 5 + 10;
                def = rand() % 10 + 10;
                agi = rand() % 15;
                break;
            case 3:
                atk = rand() % 10 + 10;
                def = rand() % 20 + 10;
                agi = rand() % 5;
                break;
            }
            choice = rand() % 3;
            switch (choice)
            {
            case 1:
                matk = rand() % 20 + 10;
                mdef = rand() % 10 + 10;
                magi = rand() % 5;
                break;
            case 2:
                matk = rand() % 5 + 10;
                mdef = rand() % 10 + 10;
                magi = rand() % 15;
                break;
            case 3:
                matk = rand() % 10 + 10;
                mdef = rand() % 20 + 10;
                magi = rand() % 5;
                break;
            }
            mhurt = (atk - magi) - (mdef / atk);
            if (mhurt < 0)
            {
                mhurt = 0;
            }
            mhp = mhp - mhurt;
            cout << "You did " << mhurt << " damage to the Troll!\n";
            cin.get();
            if (mhp < 1)
            {
                cout << "You killed the Troll!! You won with " << hp << " hp left.\n";
                cout << "You also find the First Part of the Medallion of Dectus in the Troll's Heart" << endl;
                Medallion[0] = 1;
                sc = 50 + hp;
                room1R = 1;
                cout << "Press Any Key to Continue . . ." << endl;
                getch();
                Room1R();
            }
            cout << "The Troll now have " << mhp << " hp left.\n";
            hurt = (matk - agi) - (def / matk);
            if (hurt < 0)
            {
                hurt = 0;
            }
            hp = hp - hurt;
            cout << "The Troll hit you for " << hurt << " damage.\n";
            if (hp < 1)
            {
                cout << "You died. The Troll still has " << mhp << " hp left.\n";
                sc = 50 - mhp;
                cout << "Your Final Score is " << sc << endl;
                cout << "Press Any Key to Continue . . ." << endl;
                getch();
                startGame();
            }
            cout << "You now have " << hp << " hp left.\n\n";
        }
    }
    else
    {
        cout << "Troll starts.\n==============\n";
        while (hp > 0 || mhp > 0)
        {
            choice = rand() % 3;
            switch (choice)
            {
            case 1:
                matk = rand() % 20 + 10;
                mdef = rand() % 10 + 10;
                magi = rand() % 5;
                break;
            case 2:
                matk = rand() % 5 + 10;
                mdef = rand() % 10 + 10;
                magi = rand() % 15;
                break;
            case 3:
                matk = rand() % 10 + 10;
                mdef = rand() % 20 + 10;
                magi = rand() % 5;
                break;
            }
            hurt = (matk - agi) - (def / matk);
            if (hurt < 0)
            {
                hurt = 0;
            }
            hp = hp - hurt;
            cout << "The Troll hit you for " << hurt << " damage.\n";
            if (hp < 1)
            {
                cout << "You died. The Troll still has " << mhp << " hp left.\n";
                sc = 50 - mhp;
                cout << "Your Final Score is " << sc << endl;
                cout << "Press Any Key to Continue . . ." << endl;
                getch();
                startGame();
            }
            cout << "You now have " << hp << " hp left.\n\n";
            cout << "What do you want to do?\n1 - Fierce Attack\n2 - Lithe Attack\n3 - Defensive moves\n";
            do
            {
                cin >> choice;
            } while (choice > 3 || choice < 1);
            switch (choice)
            {
            case 1:
                atk = rand() % 20 + 10;
                def = rand() % 10 + 10;
                agi = rand() % 5;
                break;
            case 2:
                atk = rand() % 5 + 10;
                def = rand() % 10 + 10;
                agi = rand() % 15;
                break;
            case 3:
                atk = rand() % 10 + 10;
                def = rand() % 20 + 10;
                agi = rand() % 5;
                break;
            }
            mhurt = (atk - magi) - (mdef / atk);
            if (mhurt < 0)
            {
                mhurt = 0;
            }
            mhp = mhp - mhurt;
            cout << "You did " << mhurt << " damage to the Troll!\n";
            cin.get();
            if (mhp < 1)
            {
                cout << "You killed the Troll!! You won with " << hp << " hp left.\n";
                cout << "You also find the First Part of the Medallion of Dectus in the Troll's Heart" << endl;
                Medallion[0] = 1;
                sc = 50 + hp;
                room1R = 1;
                cout << "Press Any Key to Continue . . ." << endl;
                getch();
                Room1R();
            }
            cout << "The Troll now have " << mhp << " hp left.\n";
        }
    }
}

void Room1R()
{
    system("CLS");
    if (room1R == 0)
    {
        cout << "You find yourself gazing upon a troll who seems to have mastered the arts of Fire Breathing." << endl
             << "The Monster says" << endl
             << "'No one shall pass. You shall die like the rest. Mua ha ha ha !! Now be ready to face my wrath!!!'" << endl;
        cout << "What do you want to do?" << endl
             << "1 - Fight\n2 - Escape and Go Back" << endl
             << "Enter your choice" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            startBattle();
        }
        else if (choice == 2)
        {
            Room1();
        }
        else
        {
            cout << "Wrong Input\nPress Any Key to continue . . ." << endl;
            getch();
            Room1R();
        }
    }
    else
    {
        cout << "In front of you remains the dead body of the Troll. There is Nothing left to do here now." << endl;
        cout << "What do you want to do?" << endl
             << "1 - Go Back" << endl
             << "Enter your choice" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            Room1();
        }
        else
        {
            cout << "Wrong Input\nPress Any Key to continue . . ." << endl;
            getch();
            Room1R();
        }
    }
}

void Room2()
{
    system("CLS");
    cout << "Passing through the bridge, you get to the Grand Hall" << endl
         << "Seeing staright, you see the Entrance to the Gingus Lift" << endl
         << "On your left, you see a promising Door" << endl
         << "On you right, you see a Door with a Nameplate stating Meridian's House" << endl;
    cout << "What do you want to do?" << endl
         << "1 - Access the Gingus Lift\n2 - Go Left\n3 - Go Right\n4 - Go Back" << endl
         << "Enter your choice" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        if (Medallion[0] == 1 && Medallion[1] == 1)
        {
            cout << "You can Now Access the Gingus Lift . . ." << endl;
            cout << "Press Any Key to continue . . ." << endl;
            getchar();
            BossRoom();
        }
        else
        {
            cout << "You Cannot Access the Gingus Lift yet . . ." << endl;
            cout << "Press Any Key to continue . . ." << endl;
            getchar();
            Room2();
        }
    }
    else if (choice == 2)
    {
        Room2L();
    }
    else if (choice == 3)
    {
        Room2R();
    }
    else if (choice == 4)
    {
        Room1();
    }
    else
    {
        cout << "Wrong Input\nPress Any Key to continue . . ." << endl;
        getch();
        Room2();
    }
}

void Room2L()
{
    system("CLS");
    cout << "You enter, and the floor suddenly starts shaking" << endl
         << "Before you could even react, The Floor suddenly retracts, and you start falling." << endl
         << "You realise, while you are falling, a faint song-like sound is present in background." << endl
         << "You try to make out the words, it goes like -" << endl
         << "Never gonna give you up\nNever gonna let you down\nNever gonna run around and desert you" << endl
         << "And then spat!, You are Dead." << endl
         << "You got RICK ROLLED." << endl
         << "Your Final Score is " << sc << endl;
    cout << "Press any Key to continue . . ." << endl;
    getch();
    startGame();
}

void GameofWits()
{
    system("CLS");
    int counter = 0;
    cout << "My 1st Riddle shall be -:" << endl
         << "What has to be broken before you can use it?" << endl;
    char answer[10];
    char answerm1[10];
    cout << "What is your Answer ?" << endl;
    cin >> answer;
    for (int i = 0; i < strlen(answer); i++)
    {
        answerm1[i] = toupper(answer[i]);
    }
    if (answerm1[0] == 'E' && answerm1[1] == 'G' && answerm1[2] == 'G')
    {
        cout << "Correct Answer!" << endl;
        cout << "Moving on to the Next Riddle" << endl;
        cout << "Press Any Key to Continue . . ." << endl;
        getchar();
    }
    else
    {
        counter++;
        cout << "Tread Carefully, Traveller. Do Not Make Me ANGRY!" << endl;
        cout << "Press Any Key to Continue . . ." << endl;
        getchar();
    }
    char answerm2[10];
    cout << "My 2nd Riddle shall be -:" << endl
         << "I'm tall when I'm young, and I'm short when I'm old. What am I?" << endl;
    cout << "What is your Answer ?" << endl;
    cin >> answer;
    for (int i = 0; i < strlen(answer); i++)
    {
        answerm2[i] = toupper(answer[i]);
    }
    if (answerm2[0] == 'C' && answerm2[1] == 'A' && answerm2[2] == 'N' && answerm2[3] == 'D' && answerm2[4] == 'L' && answerm2[5] == 'E')
    {
        cout << "Correct Answer!" << endl;
        cout << "Moving on to the Last Riddle" << endl;
        cout << "Press Any Key to Continue . . ." << endl;
        getchar();
    }
    else
    {
        counter++;
        if (counter == 2)
        {
            cout << "You have made me ANGRY. You DO NOT DESERVE to continue. DIEEEE!!!" << endl
                 << "The Sage suddenly whips out a wand, chants 'AVADA KEDAVRA' on you." << endl
                 << "You are now dead." << endl;
            cout << "Press Any Key to Continue . . ." << endl;
            getchar();
            getchar();
            startGame();
        }
        else
        {
            counter++;
            cout << "Tread Carefully, Traveller. Do Not Make Me ANGRY!" << endl;
            cout << "Press Any Key to Continue . . ." << endl;
            getchar();
        }
    }
    char answerm3[10];
    cout << "My Last Riddle shall be -:" << endl
         << "What is full of holes but still holds water?" << endl;
    cout << "What is your Answer ?" << endl;
    cin >> answer;
    for (int i = 0; i < strlen(answer); i++)
    {
        answerm3[i] = toupper(answer[i]);
    }
    if (answerm3[0] == 'S' && answerm3[1] == 'P' && answerm3[2] == 'O' && answerm3[3] == 'N' && answerm3[4] == 'G' && answerm3[5] == 'E')
    {
        cout << "Correct Answer!" << endl;
        cout << "Congrulations Traveller, You have won the Game Of Wits." << endl
             << "I shall now reward you with the second part of Medallion of Dectus." << endl;
        Medallion[1] = 1;
        room2R = 1;
        cout << "Press Any Key to Continue . . ." << endl;
        getchar();
        getchar();
        Room2R();
    }
    else
    {
        counter++;
        if (counter == 2)
        {
            cout << "You have made me ANGRY. You DO NOT DESERVE to continue. DIEEEE!!!" << endl
                 << "The Sage suddenly whips out a wand, chants 'AVADA KEDAVRA' on you." << endl
                 << "You are now dead." << endl;
            cout << "Press Any Key to Continue . . ." << endl;
            getchar();
            getchar();
            startGame();
        }
        else
        {
            cout << "Wrong Answer!" << endl;
            cout << "Congrulations Traveller, You have won the Game Of Wits." << endl
                 << "I shall now reward you with the second part of Medallion of Dectus." << endl;
            Medallion[1] = 1;
            room2R = 1;
            cout << "Press Any Key to Continue . . ." << endl;
            getchar();
            getchar();
            Room2R();
        }
    }
}

void Room2R()
{
    system("CLS");
    if (room2R == 0)
    {
        cout << "You are greeted by a Wise but Old Sage" << endl
             << "The Sage says -" << endl
             << "'Young Traveller, Do you fancy a Game of Wits?\nAnswer my Riddles and you shall recieve the second part of Medallion of Dectus which will let you access the Gingus Lift." << endl;
        cout << "What do you want to do?" << endl
             << "1 - Play with the Sage\n2 - Go Back" << endl
             << "Enter your choice" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            GameofWits();
        }
        else if (choice == 2)
        {
            Room2();
        }
        else
        {
            cout << "Wrong Input\nPress Any Key to continue . . ." << endl;
            getch();
            Room2R();
        }
    }
    else
    {
        cout << "The Wise but Old Sage stands quitely, with a glimmer of Hope in his Eyes. " << endl
             << "You have Nothing else to do here now." << endl;
        cout << "What do you want to do?" << endl
             << "1 - Go Back" << endl
             << "Enter your choice" << endl;
        int choice;
        cin >> choice;
        if (choice == 1)
        {
            Room2();
        }
        else
        {
            cout << "Wrong Input\nPress Any Key to continue . . ." << endl;
            getch();
            Room2R();
        }
    }
}

void StartBossFight()
{
    system("CLS");
    int choice;
    int i, hurt, mhurt, sc;
    srand((unsigned)time(0));
    int mhp = rand() % 50 + 70;
    int matk = 12;
    int mdef = 17;
    int magi = 7;
    int init = rand() % 2 + 1;
    if (init == 1)
    {
        cout << "You start.\n==========\n";
        while (hp > 0 || mhp > 0)
        {
            cout << "What do you want to do?\n1 - Fierce Attack\n2 - Light Attack\n3 - Defensive moves\n";
            do
            {
                cin >> choice;
            } while (choice > 3 || choice < 1);
            switch (choice)
            {
            case 1:
                atk = rand() % 20 + 10;
                def = rand() % 10 + 10;
                agi = rand() % 5;
                break;
            case 2:
                atk = rand() % 5 + 10;
                def = rand() % 10 + 10;
                agi = rand() % 15;
                break;
            case 3:
                atk = rand() % 10 + 10;
                def = rand() % 20 + 10;
                agi = rand() % 5;
                break;
            }
            choice = rand() % 3;
            switch (choice)
            {
            case 1:
                matk = rand() % 20 + 10;
                mdef = rand() % 10 + 10;
                magi = rand() % 5;
                break;
            case 2:
                matk = rand() % 5 + 10;
                mdef = rand() % 10 + 10;
                magi = rand() % 15;
                break;
            case 3:
                matk = rand() % 10 + 10;
                mdef = rand() % 20 + 10;
                magi = rand() % 5;
                break;
            }
            mhurt = (atk - magi) - (mdef / atk);
            if (mhurt < 0)
            {
                mhurt = 0;
            }
            mhp = mhp - mhurt;
            cout << "You did " << mhurt << " damage to Margit!\n";
            cin.get();
            if (mhp < 1)
            {
                cout << "You killed Margit!! You won with " << hp << " hp left.\n";
                sc = 50 + hp;
                bossR = 1;
                cout << "Press Any Key to Continue . . ." << endl;
                getch();
                GameEnding();
            }
            cout << "Margit now has " << mhp << " hp left.\n";
            hurt = (matk - agi) - (def / matk);
            if (hurt < 0)
            {
                hurt = 0;
            }
            hp = hp - hurt;
            cout << "Margit hit you for " << hurt << " damage.\n";
            if (hp < 1)
            {
                cout << "You died. Margit still has " << mhp << " hp left.\n";
                sc = 50 - mhp;
                cout << "Your Final Score is " << sc << endl;
                cout << "Press Any Key to Continue . . ." << endl;
                getch();
                startGame();
            }
            cout << "You now have " << hp << " hp left.\n\n";
        }
    }
    else
    {
        cout << "Margit starts.\n==============\n";
        while (hp > 0 || mhp > 0)
        {
            choice = rand() % 3;
            switch (choice)
            {
            case 1:
                matk = rand() % 20 + 10;
                mdef = rand() % 10 + 10;
                magi = rand() % 5;
                break;
            case 2:
                matk = rand() % 5 + 10;
                mdef = rand() % 10 + 10;
                magi = rand() % 15;
                break;
            case 3:
                matk = rand() % 10 + 10;
                mdef = rand() % 20 + 10;
                magi = rand() % 5;
                break;
            }
            hurt = (matk - agi) - (def / matk);
            if (hurt < 0)
            {
                hurt = 0;
            }
            hp = hp - hurt;
            cout << "Margit hits you for " << hurt << " damage.\n";
            if (hp < 1)
            {
                cout << "You died. Margit still has " << mhp << " hp left.\n";
                sc = 50 - mhp;
                cout << "Your Final Score is " << sc << endl;
                cout << "Press Any Key to Continue . . ." << endl;
                getch();
                startGame();
            }
            cout << "You now have " << hp << " hp left.\n\n";
            cout << "What do you want to do?\n1 - Fierce Attack\n2 - Lithe Attack\n3 - Defensive moves\n";
            do
            {
                cin >> choice;
            } while (choice > 3 || choice < 1);
            switch (choice)
            {
            case 1:
                atk = rand() % 20 + 10;
                def = rand() % 10 + 10;
                agi = rand() % 5;
                break;
            case 2:
                atk = rand() % 5 + 10;
                def = rand() % 10 + 10;
                agi = rand() % 15;
                break;
            case 3:
                atk = rand() % 10 + 10;
                def = rand() % 20 + 10;
                agi = rand() % 5;
                break;
            }
            mhurt = (atk - magi) - (mdef / atk);
            if (mhurt < 0)
            {
                mhurt = 0;
            }
            mhp = mhp - mhurt;
            cout << "You did " << mhurt << " damage to the Troll!\n";
            cin.get();
            if (mhp < 1)
            {
                cout << "You killed Margit!! You won with " << hp << " hp left.\n";
                sc = 50 + hp;
                bossR = 1;
                cout << "Press Any Key to Continue . . ." << endl;
                getch();
                GameEnding();
            }
            cout << "Margit now has " << mhp << " hp left.\n";
        }
    }
}

void BossRoom()
{
    system("CLS");
    cout << "Just before going through the door, you suddenly start to faint" << endl
         << "You see yourself in a Dream, with a blurred image of a Maiden standing in front of you" << endl
         << "The Maiden says -" << endl
         << "'Ye Traveller, you need to defeat the DemiGod, only then can our souls be free..." << endl
         << "I shall give you this gift. It will help you . . .'" << endl;
    cout << "You have recieved a Health Boost!" << endl;
    hp = rand() % 20 + 120;
    cout << "Press Any Key to continue . . .";
    getchar();
    system("CLS");
    cout << "You wake up from the Dream, stand up and walk through the Door" << endl;
    cout << "As soon as you walk through the door, Big Horns start levitating from the air" << endl
         << "The Horns seem to be giving off a War Call" << endl
         << "Suddenly, a DemiGod Jumps from High Above to the Ground" << endl
         << "He seems to be weilding the Fabled 'Black Sword'"
         << "He says -" << endl
         << "Ye Tarnished, I am Margit, the Fell Omen. The King of the Dragonbarrow." << endl
         << "Prepare to DIE!!!" << endl;
    cout << "What do you want to do?" << endl
         << "1 - Fight to Claim the Black Sword\n2 - Escape and Go Back" << endl
         << "Enter your choice" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        StartBossFight();
    }
    else if (choice == 2)
    {
        Room2();
    }
    else
    {
        cout << "Wrong Input\nPress Any Key to continue . . ." << endl;
        getch();
        BossRoom();
    }
}

void GameEnding()
{
    system("CLS");
    cout << "You have Finally obtained the Black Sword" << endl
         << "All the Souls previosuly killed would now have some Peace" << endl
         << "You take gushing breaths of Relief and are now finally at Peace" << endl;
    cout << "Press Any Key to continue . . ." << endl;
    getchar();
    startGame();
}

void startGame()
{
    system("CLS");
    cout << "    ,o888888o.           .8.          8 8888         8 888888888o.          ,o888888o.     8 888888888o.   " << endl
         << "   8888     `88.        .888.         8 8888         8 8888    `^888.    . 8888     `88.   8 8888    `88.  " << endl
         << ",8 8888       `8.      :88888.        8 8888         8 8888        `88. ,8 8888       `8b  8 8888     `88  " << endl
         << "88 8888               . `88888.       8 8888         8 8888         `88 88 8888        `8b 8 8888     ,88  " << endl
         << "88 8888              .8. `88888.      8 8888         8 8888          88 88 8888         88 8 8888.   ,88'  " << endl
         << "88 8888             .8`8. `88888.     8 8888         8 8888          88 88 8888         88 8 888888888P'   " << endl
         << "88 8888            .8' `8. `88888.    8 8888         8 8888         ,88 88 8888        ,8P 8 8888`8b       " << endl
         << "`8 8888       .8' .8'   `8. `88888.   8 8888         8 8888        ,88' `8 8888       ,8P  8 8888 `8b.     " << endl
         << "   8888     ,88' .888888888. `88888.  8 8888         8 8888    ,o88P'    ` 8888     ,88'   8 8888   `8b.   " << endl
         << "    `8888888P'  .8'       `8. `88888. 8 888888888888 8 888888888P'          `8888888P'     8 8888     `88. " << endl
         << endl << endl << endl
         << "#######                   #####                                                                        ######                                  #####                              " << endl
         << "   #    #    # ######    #     # #    # ######  ####  #####     ####  ######    ##### #    # ######    #     # #        ##    ####  #    #    #     # #    #  ####  #####  #####  " << endl
         << "   #    #    # #         #     # #    # #      #        #      #    # #           #   #    # #         #     # #       #  #  #    # #   #     #       #    # #    # #    # #    # " << endl
         << "   #    ###### #####     #     # #    # #####   ####    #      #    # #####       #   ###### #####     ######  #      #    # #      ####       #####  #    # #    # #    # #    # " << endl
         << "   #    #    # #         #   # # #    # #           #   #      #    # #           #   #    # #         #     # #      ###### #      #  #            # # ## # #    # #####  #    # " << endl
         << "   #    #    # #         #    #  #    # #      #    #   #      #    # #           #   #    # #         #     # #      #    # #    # #   #     #     # ##  ## #    # #   #  #    # " << endl
         << "   #    #    # ######     #### #  ####  ######  ####    #       ####  #           #   #    # ######    ######  ###### #    #  ####  #    #     #####  #    #  ####  #    # #####  " << endl
         << endl << endl << endl
         << "What do you want to do" << endl
         << "1. To Start Game\n2. Exit" << endl;
    int choice;
    cin >> choice;
    if (choice == 1)
    {
        InitialiseCharacter();
    }
    else if (choice == 2)
    {
        system("CLS");
        exit(1);
    }
    else
    {
        cout << "Wrong Input\nPress Any Key to continue . . ." << endl;
        getch();
        startGame();
    }
}
struct snake
{
    int x;
    int y;
    snake *next;
};
int map[40][120];
int mapX = 90;
int mapY = 20;
int score = 0;
int FoodX = 4;
int FoodY = 10;
snake *head;
snake *tail;
void SnakeBody(int x, int y)
{
    snake *body = new snake;
    body->x = x;
    body->y = y;
    if (!head)
        head = tail = body;
    else
    {
        tail->next = body;
        tail = body;
    }
    tail->next = NULL;
}
void MapMake()
{
    for (int i = 0; i < mapY; i++)
    {
        for (int j = 0; j < mapX; j++)
        {
            if (i == 0 || i == mapY - 1 || j == 0 || j == mapX - 1)
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }
    }
    map[FoodY][FoodX] = 3;
}
void traverseMap(int x, int y)
{
    COORD c = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void createFood()
{
    srand(time(NULL));
    map[FoodY][FoodX] = 0;
    do
    {
        FoodX = rand() % (mapX - 1) + 1;
        FoodY = rand() % (mapY - 1) + 1;
    } while (map[FoodY][FoodX] != 0);
    map[FoodY][FoodX] = 3;
    traverseMap(FoodX, FoodY);
    cout << "*";
}
void DisplayMap()
{
    for (int i = 0; i < mapY; i++)
    {
        for (int j = 0; j < mapX; j++)
        {
            if (map[i][j] == 1)
                cout << (char)178;
            else if (map[i][j] == 3)
                cout << "*";
            else
                cout << " ";
        }
        cout << "" << endl;
    }
}
bool moveSnake(int x, int y)
{
    snake *curr = head;
    int tempX;
    int tempY;
    int helpX;
    int helpY;
    while (curr)
    {
        if (curr == head)
        {
            if (score > 2)
            {
                snake *vcurr = head->next->next;
                while (vcurr)
                {
                    if (vcurr->x == head->x && vcurr->y == head->y)
                    {
                        return false;
                    }
                    vcurr = vcurr->next;
                }
            }

            map[curr->y][curr->x] = 0;
            if (head->x + x < 1 || head->x + x > mapX - 2 || head->y + y < 1 || head->y + y > mapY - 2)
            {
                return false;
            }
            if (head->x == FoodX && head->y == FoodY)
            {
                int newX = tail->x - x;
                int newY = tail->y - y;
                SnakeBody(newX, newY);
                score++;
                createFood();
            }

            traverseMap(curr->x, curr->y);
            cout << " ";
            tempX = curr->x;
            tempY = curr->y;
            curr->x = curr->x + x;
            curr->y = curr->y + y;
        }
        else
        {

            map[curr->y][curr->x] = 0;
            traverseMap(curr->x, curr->y);
            cout << " ";
            helpX = tempX;
            helpY = tempY;

            tempX = curr->x;
            tempY = curr->y;

            curr->x = helpX;
            curr->y = helpY;
        }

        map[curr->y][curr->x] = 2;
        traverseMap(curr->x, curr->y);
        cout << (char)178;
        curr = curr->next;
    }
    return true;
}
void play()
{
    char keyPress;
    int dir = 4;
    bool flag = true;
    int speed;
    score = 0;
    while (flag)
    {
        if (score > 10)
            speed = 150;
        else if (score > 20)
            speed = 100;
        else if (score < 11)
            speed = 200;
        else
            speed = 50;

        if (kbhit())
        {
            switch (tolower(keyPress = getch()))
            {
            case 'w':
                if (dir != 3)
                    dir = 1;
                if (dir == 1)
                    speed = speed / 2;
                break;
            case 'a':
                if (dir != 4)
                    dir = 2;
                if (dir == 2)
                    speed = speed / 2;
                break;
            case 's':
                if (dir != 1)
                    dir = 3;
                if (dir == 3)
                    speed = speed / 2;
                break;
            case 'd':
                if (dir != 2)
                    dir = 4;
                if (dir == 4)
                    speed = speed / 2;
                break;
            }
        }
        switch (dir)
        {
        case 1:
            flag = moveSnake(0, -1);
            break;
        case 2:
            flag = moveSnake(-1, 0);
            break;
        case 3:
            flag = moveSnake(0, 1);
            break;
        case 4:
            flag = moveSnake(1, 0);
            break;
        }
        traverseMap(1, mapY + 1);
        cout << "Score : " << score;
        Sleep(speed);
    }
}
void freeSpace()
{
    while (head)
    {
        snake *curr;
        curr = head;
        head = head->next;
        free(curr);
    }
}
void snakeGame()
{
    SnakeBody(4, 4);
    MapMake();
    DisplayMap();
    int choice = 0;
    while (choice != 2)
    {
        system("cls");
        puts("1.Play");
        puts("2.Exit");
        cin >> choice;
        fflush(stdin);
        if (choice == 1)
        {
            system("cls");
            SnakeBody(4, 4);
            MapMake();
            DisplayMap();
            play();
            traverseMap(1, mapY + 2);
            cout << "Game Over!";
            char m;
            cin >> m;
            fflush(stdin);
            freeSpace();
        }
        if (choice == 2)
        {
            exit;
        }
    }
}
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
struct nijonode
{
    bool value = false;
    bool play = false;
    nijonode *left = NULL;
    nijonode *right = NULL;
    nijonode *up = NULL;
    nijonode *down = NULL;
};
void clearscreen()
{
    HANDLE hOut;
    COORD Position;
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    Position.X = 0;
    Position.Y = 0;
    SetConsoleCursorPosition(hOut, Position);
}
void winscreen(nijonode *head, int c, int r)
{
    clearscreen();
    Sleep(100);
    nijonode *temp = head;
    for (int t = 1; t <= r; t++)
    {
        nijonode *first = temp;
        for (int j = 1; j <= c; j++)
        {
            if (first->value == true)
            {
                cout << " X ";
            }
            else
            {
                cout << " . ";
            }
            first = first->right;
        }
        cout << endl;
        temp = temp->down;
    }
}
void nijowin(nijonode *head, nijonode *winpos, int c, int r)
{
    nijonode *temp1 = winpos;
    nijonode *temp2 = winpos;
    nijonode *temp3 = winpos;
    nijonode *temp4 = winpos;
    for (int i = 1; i < max(c, r); i++)
    {
        if (temp1->right != NULL)
        {
            temp1->right->value = true;
            temp1 = temp1->right;
        }
        if (temp2->left != NULL)
        {
            temp2->left->value = true;
            temp2 = temp2->left;
        }
        if (temp3->up != NULL)
        {
            temp3->up->value = true;
            temp3 = temp3->up;
        }
        if (temp4->down != NULL)
        {
            temp4->down->value = true;
            temp4 = temp4->down;
        }
        if (i == 2)
        {
            system("cls");
        }
        winscreen(head, c, r);
    }
}
int nijogamescreen(nijonode *head, int c, int r, int count)
{
    clearscreen();
    nijonode *temp = head;
    for (int i = 1; i <= r; i++)
    {
        nijonode *first = temp;
        for (int j = 1; j <= c; j++)
        {
            if (first->value == true && first->play != true && count % 5 == 0)
            {
                cout << " X ";
            }
            else if (first->play == true && first->value != true)
            {
                cout << " O ";
            }
            else if (first->play == true && first->value == true)
            {
                nijowin(head, first, c, r);
                return 1;
            }
            else
            {
                cout << " . ";
            }
            first = first->right;
        }
        cout << endl;
        temp = temp->down;
    }
    return 0;
}
int nijotest(nijonode *head, int c, int r, int inst, int count)
{
    bool flag = 0;
    nijonode *temp = head;
    for (int i = 1; i <= r; i++)
    {
        nijonode *first = temp;
        for (int j = 1; j <= c; j++)
        {
            if (first->play == true)
            {
                bool check = 0;
                first->play = false;
                if (inst == 8)
                {
                    if (first->up != NULL)
                    {
                        first->up->play = true;
                        check = 1;
                    }
                }
                else if (inst == 2)
                {
                    if (first->down != NULL)
                    {
                        first->down->play = true;
                        check = 1;
                    }
                }
                else if (inst == 4)
                {
                    if (first->left != NULL)
                    {
                        first->left->play = true;
                        check = 1;
                    }
                }
                else if (inst == 6)
                {
                    if (first->right != NULL)
                    {
                        first->right->play = true;
                        check = 1;
                    }
                }
                if (check == 0)
                {
                    first->play = true;
                }
                j = c + 1;
                flag = 1;
            }
            first = first->right;
        }
        temp = temp->down;
        if (flag == 1)
        {
            i = r + 1;
        }
    }
    flag = 0;
    temp = head;
    for (int i = 1; i <= r; i++)
    {
        nijonode *first = temp;
        for (int j = 1; j <= c; j++)
        {
            if (first->value == true)
            {
                bool check = 0;
                first->value = false;
                while (check == 0)
                {
                    srand(time(0));
                    int dir = rand() % 4;
                    if (dir == 0)
                    {
                        if (first->right != NULL)
                        {
                            first->right->value = true;
                            check = 1;
                        }
                    }
                    else if (dir == 1)
                    {
                        if (first->left != NULL)
                        {
                            first->left->value = true;
                            check = 1;
                        }
                    }
                    else if (dir == 2)
                    {
                        if (first->up != NULL)
                        {
                            first->up->value = true;
                            check = 1;
                        }
                    }
                    else if (dir == 3)
                    {
                        if (first->down != NULL)
                        {
                            first->down->value = true;
                            check = 1;
                        }
                    }
                }
                j = c + 1;
                flag = 1;
            }
            if (flag == 1)
            {
                i = r + 1;
            }
            first = first->right;
        }
        temp = temp->down;
    }
    int v = nijogamescreen(head, c, r, count);
    return v;
}
int nijo1(nijonode *head, int c, int r)
{
    int flag = 0;
    int count = 1;
    while (flag == 0)
    {
        switch (int q = getch())
        {
        case KEY_UP:
            flag = nijotest(head, c, r, 8, count++);
            break;
        case KEY_DOWN:
            flag = nijotest(head, c, r, 2, count++);
            break;
        case KEY_LEFT:
            flag = nijotest(head, c, r, 4, count++);
            break;
        case KEY_RIGHT:
            flag = nijotest(head, c, r, 6, count++);
            break;
        }
    }
    return count;
}
void nijoplayer(nijonode *head, int c, int r, int *nums)
{
    srand(time(0));
    int pc = nums[0];
    int pr = nums[1];
    while (pc == nums[0])
    {
        pc = rand() % (c);
    }
    while (pr == nums[1])
    {
        pr = rand() % (r);
    }
    nijonode *temp = head;
    for (int i = 0; i < pc; i++)
    {
        temp = temp->right;
    }
    for (int i = 0; i < pr; i++)
    {
        temp = temp->down;
    }
    temp->play = true;
}
int *nijogamemech(nijonode *head, int c, int r)
{
    srand(time(0));
    int col = rand() % (c);
    int row = rand() % (r);
    nijonode *temp = head;
    for (int i = 0; i < col; i++)
    {
        temp = temp->right;
    }
    for (int i = 0; i < row; i++)
    {
        temp = temp->down;
    }
    temp->value = true;
    static int arr[2];
    arr[0] = col;
    arr[1] = row;
    return arr;
}
void nijocreate()
{
    int c, r;
    cout << "Welcome to the game: 'Seek and Catch'" << endl;
    cout << "Use arrow keys to move 'O'(you) to catch the hiding 'X'" << endl;
    cout << "'X' reveals itself every 5th move. So watch out." << endl;
    cout << "Press enter to proceed." << endl;
    int q;
    while (q != 13)
    {
        q = getch();
    }
    system("cls");
    cout << "Enter the map size in columns and rows respectively." << endl;
    cin >> c;
    cin >> r;
    system("cls");
    nijonode *arr[r];
    for (int j = 0; j <= r - 1; j++)
    {
        nijonode *newnode = new nijonode;
        arr[j] = newnode;
        for (int i = 1; i <= c - 1; i++)
        {
            nijonode *temp = new nijonode;
            newnode->right = temp;
            temp->left = newnode;
            newnode = newnode->right;
        }
    }
    nijonode *head = arr[0];
    for (int j = 0; j <= r - 2; j++)
    {
        nijonode *temp1 = arr[j];
        nijonode *temp2 = arr[j + 1];
        for (int i = 0; i < c; i++)
        {
            temp1->down = temp2;
            temp2->up = temp1;
            temp1 = temp1->right;
            temp2 = temp2->right;
        }
    }
    int *nums = nijogamemech(head, c, r);
    nijoplayer(head, c, r, nums);
    nijogamescreen(head, c, r, 0);
    int moves = nijo1(head, c, r);
    cout << endl
         << "Moves used: " << moves - 1 << endl;
    cout << "Press enter to proceed." << endl;
    q = 0;
    while (q != 13)
    {
        q = getch();
    }
}
struct node
{
    node *right = NULL;
    node *left = NULL;
    node *up = NULL;
    node *down = NULL;
    int value = NULL;
};
int arr2[9][9] = {NULL};
int arr[9][9] =
    {{0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0}};

int generate(int range)
{
    srand(clock());
    int random = 1 + (rand() % range);
    return (1 + (rand() % range));
}

void printgrid(node *root)
{
    node *TEMP = root;
    node *TEMP2 = root;
    while (TEMP2 != NULL)
    {
        TEMP = TEMP->down;
        cout << endl;
        while (TEMP2 != NULL)
        {
            cout << TEMP2->value << " ";
            TEMP2 = TEMP2->right;
        }
        TEMP2 = TEMP;
    }
}

node *convert()
{
    node *varr[9];
    for (int i = 0; i < 9; i++)
    {
        node *head = new node;
        varr[i] = head;
        head->value = arr[i][0];
        for (int j = 1; j < 9; j++)
        {
            node *new_node = new node;
            new_node->value = arr[i][j];
            node *temp = head;
            while (temp->right != NULL)
            {
                temp = temp->right;
            }
            temp->right = new_node;
            new_node->left = temp;
        }
    }
    for (int i = 0; i < 8; i++)
    {
        node *temp1 = varr[i];
        node *temp2 = varr[i + 1];
        for (int j = 0; j < 9; j++)
        {
            temp1->down = temp2;
            temp2->up = temp1;
            temp1 = temp1->right;
            temp2 = temp2->right;
        }
    }
    return varr[0];
}

bool checkrow(int n, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[n][i] == num)
        {
            return false;
        }
    }
    return true;
}

bool checkcol(int m, int num)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][m] == num)
        {
            return false;
        }
    }
    return true;
}

bool checkbox(int n, int m, int num)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[n + i][m + j] == num)
            {
                return false;
            }
        }
    }
    return true;
}

bool supercheck(int n, int m, int num)
{
    return (checkbox(n - n % 3, m - m % 3, num) && checkrow(n, num) && checkcol(m, num));
}

bool fillRemaining(int i, int j)
{
    if (j >= 9 && i < 8)
    {
        i = i + 1;
        j = 0;
    }
    if (i >= 9 && j >= 9)
    {
        return true;
    }
    if (i < 3)
    {
        if (j < 3)
        {
            j = 3;
        }
    }
    else if (i < 6)
    {
        if (j == (int)(i / 3) * 3)
        {
            j = j + 3;
        }
    }
    else
    {
        if (j == 6)
        {
            i = i + 1;
            j = 0;
            if (i >= 9)
            {
                return true;
            }
        }
    }
    for (int num = 1; num <= 9; num++)
    {
        if (supercheck(i, j, num))
        {
            arr[i][j] = num;
            if (fillRemaining(i, j + 1))
            {
                return true;
            }
            arr[i][j] = 0;
        }
    }
    return false;
}
void copy()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            arr2[i][j] = arr[i][j];
        }
    }
}

void gameready(int x)
{

    int count = 0;
    while (count <= x)
    {
        int i = generate(9);
        int j = generate(9);
        if (arr2[i][j] == 0)
        {
            continue;
        }
        else
        {
            arr2[i][j] = 0;
            count++;
        }
    }
    return;
}

void create_sudoku()
{
    //    filldiagonal();
    // initializing THE DIAGONAL

    for (int i1 = 0; i1 < 9; i1 = i1 + 3)
    {
        int num;
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                do
                {
                    num = generate(9);
                } while (!checkbox(i1, i1, num));
                arr[i1 + i][i1 + j] = num;
            }
        }
    }

    node *HEAD = convert();
    fillRemaining(0, 3);
    copy();

    // Now we will fill the remaining boxes by creating multilist
    //    fillother();
}

void prints(int a[9][9])
{
    cout << "    ";
    for (int k = 1; k <= 9; k++)
    {
        cout << k << "   ";
    }
    cout << endl
         << "    ______________________________________";
    cout << endl
         << "    |" << endl;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (j == 0)
            {
                cout << i + 1 << "   "
                     << "|"
                     << "   ";
            }
            cout << a[i][j] << "   ";
        }
        cout << endl
             << "    |" << endl;
    }
}
bool check()
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (arr2[i][j] == 0)
            {
                return false;
            }
        }
    }
    return true;
}
void startgame()
{
    int x = 1;
    while (x > 0)
    {

        if (check())
        {
            cout << "Congratulations you have won!!!!!!!";
            x = -1;
            continue;
        }
        int row, col, num;
        prints(arr2);
        cout << endl
             << endl
             << endl;
        cout << "Please enter Row(1-9)" << endl;
        cin >> row;
        cout << "Please enter Column(1-9)" << endl;
        cin >> col;
        cout << "Please enter number to be inputted" << endl;
        cin >> num;
        if (row > 9 || col > 9 || num > 9)
        {
            system("cls");
            cout << "wrong choice" << endl;
            continue;
        }
        if (arr2[row - 1][col - 1] != 0)
        {
            system("cls");
            cout << "Number already present" << endl;
            continue;
        }
        else if (num == arr[row - 1][col - 1])
        {
            system("cls");
            cout << "Correct Answer" << endl;
            arr2[row - 1][col - 1] = num;
            continue;
        }
        else
        {
            system("cls");
            cout << "wrong Answer" << endl;
            continue;
        }
    }
}
void playSoduko()
{
    int choice;
    create_sudoku();
    cout << endl;
    node *HEAD = convert();
    printgrid(HEAD);
    cout << endl;
    cout << endl
         << endl;
    cout << "WHICH LEVEL DO YOU WANNA PLAY?" << endl;
    cout << "ENTER 1 for HARD" << endl
         << "ENTER 2 for MEDIUM" << endl
         << "ENTER 3 for EASY" << endl;
    cin >> choice;
    if (choice > 3)
    {
        cout << "Wrong Choice" << endl;
    }
    else if (choice == 1)
    {
        system("cls");
        gameready(20);
        startgame();
    }
    else if (choice == 2)
    {
        system("cls");
        gameready(15);
        startgame();
    }
    else
    {
        system("cls");
        gameready(10);
        startgame();
    }
}
// Menu
void menu()
{
    int option;
    cout << "Welcome to the Gaming Arcade!" << endl;
    cout << "Please Enter your choice for playing -:\n1. Snake Game\n2. Seek and Catch Game\n3. Soduko\n4. Caldor - Quest of the black sword\n5. Exit\n";
    cin >> option;
    while (option != 5)
    {
        if (option == 1)
        {
            snakeGame();
            cout << "Please Enter your choice for playing -:\n1. Snake Game\n2. Seek and Catch Game\n3. Soduko\n4. Exit\n";
            cin >> option;
        }
        else if (option == 2)
        {
            nijocreate();
            cout << "Please Enter your choice for playing -:\n1. Snake Game\n2. Seek and Catch Game\n3. Soduko\n4. Exit\n";
            cin >> option;
        }
        else if (option == 3)
        {
            playSoduko();
            cout << "Please Enter your choice for playing -:\n1. Snake Game\n2. Seek and Catch Game\n3. Soduko\n4. Exit\n";
            cin >> option;
        }
        else if(option == 4)
        {
            startGame();
        }
    }
}
int main()
{
    menu();
    return 0;
}

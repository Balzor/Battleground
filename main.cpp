#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

void stackGame();

void heapGame();

using namespace std;

int main() {
    int x =5;
    while(x>2){
        cout << "Do you want to play the game on the (1) heap or on the (2) stack?\n";
        cin >> x;
        if (x==1){
            heapGame();
        }
       if (x==2){
           stackGame();
       }
    }
}

void heapGame() {

    srand(time(nullptr));

    int x;
    cout << "choose the x size\n";
    cin >> x;

    int y;
    cout << "choose the y size\n";
    cin >> y;

    bool ** battleground = new bool * [ x ];
    for (int i=0; i < x; i++)
        battleground[i] = new bool [y];

    int countRand=0;
    int amount = 20;
    for (int i = 0; i < x; i++){
        for(int j=0; j < y; j++){

            int randomval = rand() % 2;

            if (randomval == 1){
                countRand++;
            }

            if (countRand<amount){
                battleground[i][j]= randomval;
            }else{
                battleground[i][j]= false;
            }

            cout << battleground[i][j] << " ";
        }
        cout << "\n";
    }

    bool ** battlegroundData = new bool * [ x ];
    for (int i=0; i < x; i++)
        battlegroundData[i] = new bool [y];
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
                battlegroundData[i][j] = false;
    }

    int guesses;
    cout << "Type the number of guesses you want\n";
    cin >> guesses;

    int count = 0;
    int hits = 0;

    while(hits != amount && count != guesses){
        cout << "This is the map\n";
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                cout << battlegroundData[i][j] << " ";
            }
            cout << "\n";
        }

        cout << "guess the coordinates of the ships in a 2D space\n";
        int first = 10;
        int second = 10;
        while( (first >=y) || (second >=x) ){
            cout << "guess the y-coordinates (under "<< y << " )\n";
            cin >> first;
            cout << "guess the x-coordinates (under "<< x <<  " )\n";
            cin >> second;
        }

        if (battleground[first][second]){
            count++;
            hits++;
            cout << "You hit the ship\n";
            cout << "You hit " << hits << " ships\n";
            battleground[first][second] = 0;
            battlegroundData[first][second] = 1;
        }else{
            count++;
            cout << "U no hit ship\n";
        }
        cout << "You have " << guesses-count << " guesses left\n";
    }
    if (guesses==count){
        cout << "\n --------------------------------------You lost--------------------------------------------";
    }else{
        cout << "\n --------------------------------------You win the game--------------------------------------------";
    }

    delete [] battleground;
    delete [] battlegroundData;
}

void stackGame() {

    const int battleground = 5;
    bool x = false;
    bool o = true;
    bool battleArray [battleground] [battleground] = {{x,x,x,x,x},
                                                      {x,o,x,x,x},
                                                      {x,o,x,x,x},
                                                      {x,o,x,x,x},
                                                      {x,x,x,o,o}};

    bool battleGameplay [battleground] [battleground] = {{x,x,x,x,x},
                                                         {x,x,x,x,x},
                                                         {x,x,x,x,x},
                                                         {x,x,x,x,x},
                                                         {x,x,x,x,x}};

    int guesses;
    cout << "Type the number of guesses you want\n";
    cin >> guesses;

    int count = 0;
    int hits = 0;

    while(hits != 5 && count != guesses){

        cout << "\nThis is the map\n";
        for (int i = 0; i < battleground; i++){
            for(int j=0; j < battleground; j++)
                cout << battleGameplay[i][j] << " ";
            cout << "\n";
        }

        cout << "guess the coordinates of the ships in a 2D space\n";
        int first = 10;
        int second = 10;
        while( (first >=5) || (second >=5) ){
            cout << "guess the y-coordinates (under 5)\n";
            cin >> first;
            cout << "guess the x-coordinates (under 5)\n";
            cin >> second;
        }

        if (battleArray[first][second]){
            count++;
            hits++;
            cout << "You hit the ship\n";
            cout << "You hit " << hits << " ships\n";
            battleArray[first][second] = 0;
            battleGameplay[first][second] = 1;
        }else{
            count++;
            cout << "U no hit ship\n";
        }
        cout << "You have " << guesses-count << " guesses left\n";
    }
    if (guesses==count){
        cout << "\n --------------------------------------You lost--------------------------------------------";
    }else{
        cout << "\n --------------------------------------You win the game--------------------------------------------";
    }
}

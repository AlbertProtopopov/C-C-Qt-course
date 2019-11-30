#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

class BasePlayer{
    int id;
    string name;
public:
    void setID(int id){
        this->id = id;
    }
    int getID(){
        return id;
    }
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }
    virtual int makeMove(char * field);
};

class Player: public BasePlayer{
public:
    int makeMove (char * field) override {
        int step;
        cout << getName() << " введите номер клетки: ";

        while(true){
            cin >> step;
            if ( step > 9 or step < 1 or field[step-1] == '0' or field[step-1] == 'X' )
                cout << "Неверный ввод, повторите заново" << endl;               
            else
                break;
        }
        return step;        
    }
};

class AI: public BasePlayer{
public:
    int makeMove (char * field) override {
        int step;

        while(true){
            step = rand()%10;
            if ( step >9 or step < 1 or field[step-1] == '0' or field[step-1] == 'X' );               
            else
                break;
        }
        return step;
    }
};

class Game {
    char field[9];
    int fieldCount = 0;
    int mode = 0;
public:
    Game(){
        init();
    }
    void init(){
        for (int i = 0; i < 9; i++){
            field[i] = '-';
        }
    }
    void show(){
        cout << "Номера клеток" << endl;
        cout << 1 << '|' << 2 << '|' << 3 << endl;
        cout << 4 << '|' << 5 << '|' << 6 << endl;
        cout << 7 << '|' << 8 << '|' << 9 << endl;
        cout << "Игровое поле" << endl;
        cout << field[0] << '|' << field[1] << '|' << field[2] << endl;
        cout << field[3] << '|' << field[4] << '|' << field[5] << endl;
        cout << field[6] << '|' << field[7] << '|' << field[8] << endl;
    }
    void writeMove(int move, int id){
        if (id == 1)
            field[move - 1] = 'X';
        else
            field[move - 1] = '0';
        fieldCount++;
    }
    char * getField(){
        return field;
    }
    void setMode(int mode){
        this->mode = mode;
    }
    int getMode(){
        return mode;
    }
    
};

int main(){

    Game game;
    game.init();
    game.show();
    
    Player player1;
    player1.setName("player1");
    player1.setID(1);
    
    Player player2;
    
    AI AIplayer2;
    
    BasePlayer * p_player2;
    
    //game.setMode(TWO_PLAYERS);
    game.setMode(2);
    
    if (game.getMode() == 1){
        p_player2 = &player2;
        p_player2->setName("player2");
        p_player2->setID(2);
    }
    if (game.getMode() == 2){
        p_player2 = &AIplayer2;
        p_player2->setName("AI");
        p_player2->setID(3);
    }
        game.writeMove(player1.makeMove(game.getField()), player1.getID());
        game.show();
    
        game.writeMove(p_player2->makeMove(game.getField()), p_player2->getID());
        game.show();

    return 0;
}

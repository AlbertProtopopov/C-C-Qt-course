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
    virtual int makeMove(char * field) {};
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
    char winnerChar;
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
    void menu(){
        while (true){
        cout << "Выберите режим (1 or 2)" << endl;
        cout << "1. 2 игрока" << endl;
        cout << "2. Играть против ИИ" << endl;
        
        string input;
        int tempMode = 0;
        
        getline(cin, input);
        tempMode;
        if (input == "1"){
            setMode(1);
            break;
        }
        if (input == "2"){
            setMode(2);
            break;
        }
        else
            cout << "Неправильный ввод. Выберите 1 или 2" << endl;
        }
    }
    bool checkWinner(){
        bool noWinner = true;
        for(int i = 0; i < 3; i++)
            if (field[i*3] == field[i*3+1] and field[i*3+1] == field[i*3+2] and (field[i*3] != '-')){
                winnerChar = field[i*3];
                noWinner = false;
            } else
            if ((field[i] == field[i+3] and field[i+3] == field[i+6]) and field[i] != '-'){
                winnerChar = field[i];
                noWinner = false;
            } else
            if (((field[2] == field[4] and field[4] == field[6]) or (field[0] == field[4] and field[4] == field[8])) and (field[4] != '-')){
                winnerChar = field[4];
                noWinner = false;
            };
        return noWinner;     
    }
    
    bool checkField (){
        bool notFull = true;
        if (fieldCount == 9)
            notFull = false;
        return notFull;        
    }
    
    char getWinnerChar(){
        return winnerChar;
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
    
    game.menu();
    
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
    while (true){
        cout << "game.checkWinner()" << game.checkWinner() << endl;
        cout << "game.checkField()" << game.checkField() << endl;
        
        if (game.checkField() and game.checkWinner()){
            game.show();
            game.writeMove(player1.makeMove(game.getField()), player1.getID());
        } else {
            game.show();
            break;
        }
        cout << "game.checkWinner()" << game.checkWinner() << endl;
        cout << "game.checkField()" << game.checkField() << endl;
        
        if (game.checkField() and game.checkWinner()){
        game.show();
        game.writeMove(p_player2->makeMove(game.getField()), p_player2->getID());
        } else {
            game.show();
            break;
        }
    }
    cout << "Игра закончена. ";
    
    if (game.getWinnerChar() == 'X')
        cout << "Победил " << player1.getName() << endl;
    else if (game.getWinnerChar() == '0' and player2.getID() == 2)
        cout << "Подедил " << player2.getName() << endl;
    else if (game.getWinnerChar() == '0' and player2.getID() == 3)
        cout << "Победил ИИ" << endl;

    return 0;
}

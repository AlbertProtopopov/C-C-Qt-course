#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>

using namespace std;

class Player{
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
    
};

class GameField{

    char field[9];
    int full = 0;
    char winnerChar = '-';
    int mode;
    
public:

    GameField(){
        init();
    }
    
    void init(){
        for (int i = 0; i < 9; i++){
            field[i] = '-';
        }
    }
    
    char getWinnerChar(){
        return winnerChar;
    }
    
    void setMode(int mode){
        this->mode = mode;
    }
    
    int getMode(){
        return mode;
    }
    
    void step(Player player){
        int step;
        if (player.getID() == 1 or player.getID() == 2){
            cout << player.getName() << " введите номер клетки: ";

            while(true){
                cin >> step;
                if (step >9 or step < 1 or field[step-1] == '0' or field[step-1] == 'X')
                    cout << "Неверный ввод, повторите заново" << endl;               
                else{
                    full++;
                    break;
                }
            }
        }
        else {
            while(true){
                step = rand()%10;
                if (step >9 or step < 1 or field[step-1] == '0' or field[step-1] == 'X'){
                
                }else{
                    full++;
                    break;
                }
            }
        }
        
        if (player.getID() == 1) field[step - 1] = 'X';
        else 
            field[step - 1] = '0'; 
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
    
    bool check (){
        bool notFull = true;
        if (full == 9)
            notFull = false;
        return notFull;        
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
            if (((field[2] == field[4] and field[4] == field[6]) or (field[0] == field[4] and field[4] == field[8]) and (field[0] != '-')) and (field[2] != '-')){
                winnerChar = field[4];
                noWinner = false;
            };
        return noWinner;     
    }
};

int main(){
    
    GameField field;
        
    cout << "Игра крестики и нолики" << endl;
    
    while (true){
        cout << "Выберите режим (1 or 2)" << endl;
        cout << "1. 2 игрока" << endl;
        cout << "2. Играть против ИИ" << endl;
        
        string input;
        int tempMode = 0;
        
        getline(cin, input);
        tempMode;
        if (input == "1"){
            field.setMode(1);
            break;
        }
        if (input == "2"){
            field.setMode(2);
            break;
        }
        else
            cout << "Неправильный ввод. Выберите 1 или 2" << endl;
    }
    
    Player player1;
    player1.setName("Игрок1");
    player1.setID(1);
    Player player2;
    
    
    switch(field.getMode()){
        case 1: { player2.setID(2); player2.setName("Игрок2"); };
            break;
        case 2: { player2.setID(3); player2.setName("Игрок2"); };
            break;
    }

    while(true) {
    
        if (field.check() and field.checkWinner()){
            field.show();
            field.step(player1);
        }else{
            field.show();        
            break;
        }
        if (field.check() and field.checkWinner()){
            field.show();
            field.step(player2);
        }else{
            field.show();
            break;
        }
    }
    
    cout << "Игра закончена. ";
    
    if (field.getWinnerChar() == 'X')
        cout << "Победил " << player1.getName() << endl;
    else if (field.getWinnerChar() == '0' and player2.getID() == 2)
        cout << "Подедил " << player2.getName() << endl;
    else if (field.getWinnerChar() == '0' and player2.getID() == 3)
        cout << "Победил ИИ" << endl;

    return 0;
}

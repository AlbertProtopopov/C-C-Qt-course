#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NAME_MAX 1001
#define NUMBER_MAX 1001

struct phonebook{

    char name[NAME_MAX];
    char number[NUMBER_MAX];
};

void showPhonebook();    // показать список контактов

void addContact();       // добавить контакт

int main(){

    char choice[1];

    while(1){
        
    printf("Select the action (1 or 2 or 3):\n"
    "1.To see a list of contacts\n2.Add contact\n3.Exit\nEnd press ENTER\n");

    gets(choice);    // применил gets, так как другие 
                     // операторы вылетали в цикл while
    if (!strcmp(choice, "1"))
        showPhonebook();
    else if (!strcmp(choice, "2"))
        addContact();
    else if (!strcmp(choice, "3"))
        break;
    else
        printf("\nInvalid input. Select menu item 1 to 3 and press ENTER\n");
        
    printf("\n");                    
    }
    return 0;
}

void showPhonebook(){

    FILE * file;
    file = fopen("file.txt", "r");
    
    if(file){
        printf("\nPhonebook:\n\n");
        
        int ch = 0;
        int size = 0;
        
        while((ch = fgetc(file)) != EOF){
            printf("%c", ch);
            
            if (isgraph(ch))    // проверяем есть ли цифры и буквы в файле
                ++size;
        }
        if (size == 0)    // если в файле нет букв и цифр
            printf("Phonebook is empty\n");
        fclose(file);
    }
    else
        printf("Phnonebook open error\n");
}

void addContact(){

    struct phonebook contact;
    
    int letters;
    int plus;
    int digits;
    
    printf("\nEnter a name\n");
    gets(contact.name);

    printf("Enter a number\n");
    gets(contact.number);

    
    FILE * file;
    file = fopen("file.txt", "a");
        
    if(file)
        {
            fprintf(file, "Name: %s\nNumber: %s\n\n", contact.name, contact.number);
                printf("\nContact added\n");
            fclose(file);
        }
        else
            printf("Phnonebook open error\n");
}   


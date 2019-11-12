#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define TEMP_STR_MAX 80
#define PHONE_BOOK_MAX 100
#define NAME_MAX 50
#define NUMBER_MAX 30
#define FILE_NAME "phonebook.txt"

struct contact{
    char name[NAME_MAX];
    char number[NUMBER_MAX];
};

void show_phonebook();

void add_contact();

int main(){
    while(1){    
    printf("Select the action (1 or 2 or 3):\n1.To see a list of contacts\n2.Add contact\n3.Exit\n");
    int choise;
    scanf("%d", &choise);
    
    if (choise == 1)
        show_phonebook();    

    if (choise == 2)
        add_contact();
    
    if (choise == 3)
        break;
    }
    
    return 0;
}

void show_phonebook(){
    FILE * pfile;
    
    pfile = fopen(FILE_NAME, "r");
    
    if (pfile){
        struct contact phonebook[PHONE_BOOK_MAX];
    
        char temp_str[TEMP_STR_MAX];
        
        if (fgetc(pfile) == EOF)
            printf("The phonebook is empty\n");
        else 
        {
            fseek (pfile, 0, SEEK_SET);    
            bool write_numbers = false;
            int j = 0;
            int k = 0;
            int count = 0;
        
            printf("Phonebook:\n");
    
            while (fgets(temp_str, TEMP_STR_MAX, pfile) != NULL){

                for (int i = 0; temp_str[i] != 0; i++){
                                
                    if (temp_str[i] == '+')
                        write_numbers = true;
                    
                    if (!write_numbers)
                        phonebook[k].name[i] = temp_str[i];
                    
                    else{
                        phonebook[k].number[j] = temp_str[i];
                        j++;
                    }
                }
                j = 0;
                k++;
                write_numbers = false;
                count++;
            }
        
            for (int i = 0; i < count; i++)
                printf("%d. %s %s", i + 1, phonebook[i].name, phonebook[i].number);
                printf("\n");
        }        
        fclose(pfile);
    }
    else
        perror("Cannot open file");
}

void add_contact(){
    char temp1[TEMP_STR_MAX];
    printf("Enter the name and the number(number starting with the sign '+')\n");
    gets(temp1);
    
    FILE * pfile1;
    
    pfile1 = fopen(FILE_NAME, "r+");
    
    if (pfile1){
      
        fseek (pfile1, 0, SEEK_END);
        bool result = fputs (temp1, pfile1);      
        fclose(pfile1);
    }
    else
        perror("Cannot open file");
}

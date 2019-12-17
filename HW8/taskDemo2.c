#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{

    int id;
    int time;
    int priority;
    char * name;
    struct Node * next;
};

struct Node nodes[20];

struct Stack{

    struct Node * top;
    int count;
};

void init(struct Node * node){
    
    node->time = rand() % 3 + 1;
    node->priority = rand() % 10 + 1;
    node->name = "Task ";
};

void push(struct Stack * stack){

    struct Node * temp = malloc(sizeof(struct Node));
    
    if (temp == NULL)
        printf("Ошибка выделения памяти в куче");
    else{
        init(temp);
    
        if (stack->top == NULL){
            temp->next == NULL;
            stack->top = temp;
        } else {
            temp->next = stack->top;
            stack->top = temp;
        }
    }
    
    stack->count++;
    stack->top->id = stack->count;
    
}

void pushManual(struct Stack * stack){
    struct Node * temp = malloc(sizeof(struct Node));
    
    if (temp == NULL)
        printf("Ошибка выделения памяти в куче");
    else{
        
        temp->name = "mTask";            
        
        
        while(1){
            printf("Введите время выполнение задачи в пределах от 1 до 3 секунд:\n");
            char input[1];
            gets(input);
            if (atoi(input) > 0 && atoi(input) < 4){
                temp->time = atoi(input);
                break;
            } else
                printf("Слишком длинное время задачи. Введите заново\n");
        }
        
        while(1){
            printf("Введите приоритет задачи в пределах от 1 до 10:\n");
            char input[2];
            gets(input);
            if (atoi(input) > 0 && atoi(input) < 11){
                temp->priority = atoi(input);
                break;
            } else
                printf("Приоритет вне диапазона. Введите заново\n");
        }
    
        if (stack->top == NULL){
            temp->next == NULL;
            stack->top = temp;
        } else {
            temp->next = stack->top;
            stack->top = temp;
        }
    }
    
    stack->count++;
    stack->top->id = stack->count;
    
}

void pop(struct Stack * stack){

    struct Node * delete = stack->top;
    stack->top = stack->top->next;
    free(delete);
    stack->count--; 
}

void sort(struct Stack * stack) {	

    int size = stack->count;

    struct Node * temp;

    temp = stack->top;

    for (int i = 0; i < size; ++i){

        nodes[i].name = temp->name;
        nodes[i].time = temp->time;
        nodes[i].priority = temp->priority;

        temp = temp->next;
    }
    	
    for (int i = 0; i < size -1; ++i){

        for (int j = 0; j < size - 1; ++j){

            if (nodes[j+1].priority > nodes[j].priority){

	            struct Node temp = nodes[j+1];

	            temp.name = nodes[j+1].name;
	            temp.time = nodes[j+1].time;
	            temp.priority = nodes[j+1].priority;					
	        	nodes[j+1].name = nodes[j].name;
	        	nodes[j+1].time = nodes[j].time;	        	
	        	nodes[j+1].priority = nodes[j].priority;
				nodes[j].name = temp.name;
				nodes[j].time = temp.time;
				nodes[j].priority = temp.priority;
            }
        }
    }

    temp = stack->top;

    for (int i = 0; i < size; ++i){
        temp->name = nodes[i].name;
        temp->time = nodes[i].time;
        temp->priority = nodes[i].priority;
        temp = temp->next;

    }
}

void peek(struct Stack * stack){
    printf("%d %s time = %d priority = %d\n", stack->top->id, stack->top->name, stack->top->time, stack->top->priority);
}

void print(struct Stack * stack){
    if (stack->count == 0)
        printf("Стэк задач пуст\n");
    else{
        struct Node * temp;
        temp = stack->top;
        printf("Список задач\n\n");
        while(temp != NULL){
            printf("%d %s time = %d priority = %d\n", temp->id, temp->name, temp->time, temp->priority);
            temp = temp->next;
        }
    }
}

void genAuto(struct Stack * stack){
    
    while(1){
        printf("Введите количество задач в пределах от 1 до 999:\n");
        char input[3];
        gets(input);

        if (atoi(input) < 999 && atoi(input) > 0){
            int num = atoi(input);
            for (int i = 0; i < num; i ++){
                push(stack);
            }
            break;
        } else {
            printf("Некорректный ввод или слишком большое число задач. Введите число задач меньше 999 заново\n");
        }
    }
}

void perform(struct Stack * stack){
    if (stack->count == 0)
        printf("Стэк задач пуст\n");
    else{
        sort(stack);
        while (stack->top != NULL){
            printf("Осталось задач: %d\n\n", stack->count);
            print(stack);
            printf("\nВыполняется - ");
            peek(stack);
            printf("\n");
            sleep(stack->top->time);
            pop(stack);
        }
        printf("Стэк задач пуст\n");
    }
}


void menu(struct Stack * stack){
    while(1){
        printf("Выберите и введите действие по номеру:\n\n");
        printf("1. Сгенерировать задачи автоматически\n");
        printf("2. Добавить задачи вручную\n");
        printf("3. Показать задачи\n");
        printf("4. Выполнить задачи\n");
        printf("5. Выйти из программы\n");
        
        char choice[1];
        
        gets(choice);
        
        if (!strcmp(choice, "1"))
            genAuto(stack);
        else if (!strcmp(choice, "2"))
            pushManual(stack);
        else if (!strcmp(choice, "3"))
            print(stack);    
        else if (!strcmp(choice, "4"))
            perform(stack);
        else if (!strcmp(choice, "5"))
            break;
        else
        printf("\nНеправильный ввод. Выберите номер из списка\n");
        
        printf("\n");
    }
}

int main(){

    printf("Добро пожаловать! Вас приветствует менеджер задач реализованный на языке С\n\n");
    
    struct Node task;
    
    struct Stack Tasks;
    Tasks.top = NULL;
    Tasks.count = 0;
        
    struct Stack * pTasks;
    pTasks = &Tasks;
            
    menu(pTasks);       

    
    if (Tasks.top != NULL){
        while (Tasks.top != NULL){
            pop(pTasks);
        }
        printf("Стек автоматически очищен\n");        
    }
    
    return 0;
}

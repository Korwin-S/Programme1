/**
 * @file list.c
 * @brief Файл з описом розроблених функцій
 *
 * @author Starovoytov N.
 * @date 07-may-2021
 * @version 1.0
 */

#include "library.h"

struct List *New_list()
{
    struct List *list = malloc(sizeof(struct List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

struct Bird *New_bird(struct Bird *bird)
{
    bird->next = NULL;
    bird->prev = NULL;
    return bird;
}

void Add_element_to_end(struct List *list, struct Bird *bird){
    bird = New_bird(bird);
    bird->prev = list->tail;
    if (list->tail) {
        list->tail->next = bird;
    }else {
        list->head = bird;
    }
    list->tail = bird;
}

void Add_element_to_begin(struct List *list, struct Bird *bird){
    bird = New_bird(bird);
    bird->next = list->head;
    if(list->head){
        list->head->prev = bird;
    }else{
        list->tail = bird;
    }
    list->head = bird;
}

void Insert_element(struct List *list, int pos, struct Bird *bird){
    if(pos <= 0){
        Add_element_to_begin(list, bird);
        return;
    }
    struct Bird *p = list->head;
    for(int i = 0; i < pos; i++){
        if(p->next == NULL) {
            Add_element_to_end(list, bird);
            return;
        }
        p = p->next;
    }
    bird = New_bird(bird);
    bird->prev = p->prev;
    bird->next = p;
    bird->next->prev = bird;
    bird->prev->next = bird;
}

void Delete_element(struct List *list, int pos){
    if(pos < 0){
        return;
    }
    struct Bird *p = list->head;
    if(pos == 0){
        if(!list->head){
            return;
        }
        list->head = list->head->next;
        if(p->next){
            p->next->prev = NULL;
        }else{
            list->tail = NULL;
        }
        return;
    }
    for(int i = 0; i < pos; i++){
        if(p->next == NULL) {
            return;
        }
        p = p->next;
    }
    p->prev->next = p->next;
    if(p->next){
        p->next->prev = p->prev;
    }else{
        list->tail = p->prev;
    }
}

void Print_bird(struct Bird *bird){
    if(bird->LOTR == 1){
        printf("Is bird the Lord of the Ring: Yes\n");
    }else{
        printf("Is bird the Lord of the Ring: NO\n");
    }
    printf("Name:%s\n", bird->name);
    printf("Age: %d months\n", bird->age);
    printf("   Home area: %d sm^2\n", bird->home.space);
    printf("   Home height: %d sm\n", bird->home.height);
    printf("   Home feeders amount: %d\n", bird->home.count_of_feeders);
    if(bird->home.if_nest == 1){
        printf("   Is bird's home a nest: Yes\n");
    }else{
        printf("   Is bird's home a nest: NO\n");
    }
    if(bird->enumSex == Male){
        printf("Sex: male\n");
    } else if(bird->enumSex == Female) {
        printf("Sex: female\n");
    }
    printf("\n");
}

void Print_Date(){
    struct tm *u;
    time_t timer = time(NULL);
    u = localtime(&timer);
    char s[60];
    for (int i = 0; i < 60; i++) s[i] = 0;
    switch (u->tm_wday)
    {
        case 0: strcpy(s, " Воскресенье, "); break;
        case 1: strcpy(s, " Понедельник, "); break;
        case 2: strcpy(s, " Вторник, ");     break;
        case 3: strcpy(s, " Среда, ");       break;
        case 4: strcpy(s, " Четверг, ");     break;
        case 5: strcpy(s, " Пятница, ");     break;
        case 6: strcpy(s, " Суббота, ");     break;
    }
    char tmp[20];
    strftime(tmp, 40, "%d.%m.%Y, %H:%M:%S.", u);
    strcat(s, tmp);
    printf("\nТекущие дата и время:%s", s);
}

bool Regex_Check(struct Bird *bird){
    bool result = true;
    regex_t regex;
    regcomp(&regex, "^[0-1]$", 0);
    char boool[2];
    sprintf(boool, "%d", bird->LOTR);
    if (regexec(&regex, boool, 0, NULL, 0) != 0) result = false;

    regcomp(&regex, "^ ?[A-ZА-Я]([A-ZА-Яa-zа-я]+ ?)+$", REG_EXTENDED);
    if (regexec(&regex, bird->name, 0, NULL, 0) != 0) result = false;

    char num[5];
    sprintf(num, "%d", bird->age);
    regcomp(&regex, "^[0-9]{1,3}$", REG_EXTENDED);
    if (regexec(&regex, num, 0, NULL, 0) != 0) result = false;

    sprintf(num, "%d", bird->home.space);
    regcomp(&regex, "^[0-9]{1,4}$", REG_EXTENDED);
    if (regexec(&regex, num, 0, NULL, 0) != 0) result = false;

    sprintf(num, "%d", bird->home.height);
    regcomp(&regex, "^[0-9]{1,4}$", REG_EXTENDED);
    if (regexec(&regex, num, 0, NULL, 0) != 0) result = false;

    sprintf(boool, "%d", bird->home.count_of_feeders);
    regcomp(&regex, "^[0-9]$", REG_EXTENDED);
    if (regexec(&regex, boool, 0, NULL, 0) != 0) result = false;

    regcomp(&regex, "^[0-1]$", 0);
    sprintf(boool, "%d", bird->home.if_nest);
    if (regexec(&regex, boool, 0, NULL, 0) != 0) result = false;

    regcomp(&regex, "^[0-1]$", 0);
    sprintf(boool, "%d", bird->enumSex);
    if (regexec(&regex, boool, 0, NULL, 0) != 0) result = false;

    return result;
}

void Print_Regex_Two_Words(struct List * list) {
    regex_t regex;
    for (struct Bird *bird = list->head; bird != NULL; bird = bird->next) {
        regcomp(&regex, "^ ?[A-ZА-Яa-zа-я]{1,} [A-ZА-Яa-zа-я]{1,}", REG_EXTENDED);
        if (regexec(&regex, bird->name, 0, NULL, 0) == 0) {
            Print_bird(bird);
        }
    }

}

void Read_list_from_file(struct List* list){
    FILE *file = fopen("birds.txt", "r");
    if (file == NULL) {
        printf("Unable to open file: %s", strerror(errno));
        exit(1);
    }
    for(int i = 0; i < N; i++){
        struct Bird *bird = malloc(sizeof (struct Bird));
        fscanf(file, "%d%[^0-9]%d%d%d%d%d%d", &(bird->LOTR), (bird ->name), &(bird->age),
               &(bird->home.space), &(bird->home.height), &(bird->home.count_of_feeders),
               &(bird->home.if_nest), &(bird->enumSex));
        if (Regex_Check(bird)) Add_element_to_end(list, bird);
        else {
            printf("\nОшибка: Некорректные входные данные в строке №%d.\n", i);
            exit(1);
        }
    }
    fclose(file);
}


void Show_list(struct List *list) {
    for (struct Bird *bird = list->head; bird != NULL; bird = bird->next) {
        Print_bird(bird);
    }
}

void Print_list_in_file(struct List *list){
    FILE *file = fopen("result.txt", "w");
    if (file == NULL) {
        printf("Unable to open file: %s", strerror(errno));
        exit(1);
    }
    for (struct Bird *bird = list->head; bird != NULL; bird = bird->next) {
        if(bird->LOTR == 1){
            fprintf(file, "Is bird the Lord of the Ring: Yes\n");
        }else{
            fprintf(file, "Is bird the Lord of the Ring: NO\n");
        }
        fprintf(file,"Name: %s\n", bird->name);
        fprintf(file, "Age: %d months\n", bird->age);
        fprintf(file, "   Home area: %d sm^2\n", bird->home.space);
        fprintf(file, "   Home height: %d sm\n", bird->home.height);
        fprintf(file, "   Home feeders amount: %d\n", bird->home.count_of_feeders);
        if(bird->home.if_nest == 1){
            fprintf(file, "   Is bird's home a nest: Yes\n");
        }else{
            fprintf(file, "   Is bird's home a nest: NO\n");
        }
        if(bird->enumSex == Male){
            fprintf(file, "Sex: male\n");
        } else if(bird->enumSex == Female){
            fprintf(file, "Sex: female\n");
        }
        fprintf(file, "\n");
    }
    fclose(file);
}


void Find_bird(struct List * list, int index) {
    bool flag = 0;
    char name[10];
    int LOTR, age, space, height, count_of_feeders, if_nest, sex;
    switch (index) {
        case 1:
            printf("\nС кольцом или без (1/0)? \n");
            printf(" --> ");
            scanf("%d", &LOTR);
            printf("\nРезультат поиска:\n\n");
            for (struct Bird *bird = list->head; bird != NULL; bird = bird->next) {
                if (bird->LOTR == LOTR) {
                    flag = 1;
                    Print_bird(bird);
                }
            }
            break;
        case 2:
            printf("\nВведите имя: \n");
            printf(" --> ");
            scanf("%s", name);
            printf("\n");
            printf("Результат поиска:\n\n");
            for (struct Bird *bird = list->head; bird != NULL; bird = bird->next) {
                if (strcmp(bird->name, name) == 0) {
                    flag = 1;
                    Print_bird(bird);
                }
            }
            break;

        case 3:
            printf("\nВведите возраст: \n");
            printf(" --> ");
            scanf("%d", &age);
            printf("\n");
            printf("Результат поиска:\n\n");

            for (struct Bird *bird = list->head; bird != NULL; bird = bird->next) {
                if (bird->age == age) {
                    flag = 1;
                    Print_bird(bird);
                }
            }
            break;
        case 4:
            printf("\nВведите площадь скворечника: \n");
            printf(" --> ");
            scanf("%d", &space);
            printf("\n");
            printf("Результат поиска:\n\n");
            for (struct Bird *bird = list->head; bird != NULL; bird = bird->next) {
                if (bird->home.space == space) {
                    flag = 1;
                    Print_bird(bird);
                }
            }
            break;
        case 5:
            printf("\nВведите высоту скворечника: \n");
            printf(" --> ");
            scanf("%d", &height);
            printf("\n");
            printf("Результат поиска:\n\n");
            for (struct Bird *bird = list->head; bird != NULL; bird = bird->next) {
                if (bird->home.height == height) {
                    flag = 1;
                    Print_bird(bird);
                }
            }
            break;
        case 6:
            printf("\nВведите кол-во кормушек скворечника: \n");
            printf(" --> ");
            scanf("%d", &count_of_feeders);
            printf("\n");
            printf("Результат поиска:\n\n");
            for (struct Bird *bird = list->head; bird != NULL; bird = bird->next) {
                if (bird->home.count_of_feeders == count_of_feeders) {
                    flag = 1;
                    Print_bird(bird);
                }
            }
            break;
        case 7:
            printf("\nВведите кол-во кормушек скворечника: \n");
            printf(" --> ");
            scanf("%d", &if_nest);
            printf("\n");
            printf("Результат поиска:\n\n");
            for (struct Bird *bird = list->head; bird != NULL; bird = bird->next) {
                if (bird->home.if_nest == if_nest) {
                    flag = 1;
                    Print_bird(bird);
                }
            }
            break;
        case 8:
            printf("\nВведите пол птицы - женский/мужской (1/0): \n");
            printf(" --> ");
            scanf("%d", &sex);
            printf("\n");
            printf("Результат поиска:\n\n");
            for (struct Bird *bird = list->head; bird != NULL; bird = bird->next) {
                if (bird->enumSex == sex) {
                    flag = 1;
                    Print_bird(bird);
                }
            }
            break;
        default:
            printf("\nERROR:Некорректный вариант\n");
            flag = 1;
            break;
    }

    if(flag == 0){
        printf("\tERROR: Такой птицы нет в списке\n\n");
    }
}

void Sort_birds_by_age(struct List *list) {
    struct List *buf_list = New_list();
    int pointer = list->head->age, i = 0, point_buf = 0;
    bool flag = 1;
    bool if_already_sorted_flag = 1;
    while (flag == 1) {
        flag = 0;
        if (i > 0) {
            point_buf = pointer;
            pointer = 10000;
        }
        for (struct Bird *bird = list->head; bird != NULL; bird = bird->next) {
            if (bird->age <= point_buf) continue;
            if (bird->age < pointer) {
                pointer = bird->age;
                flag = 1;
            }
        }
        if (flag == 1) {
            if_already_sorted_flag = 0;
            for (struct Bird *buffer = list->head; buffer != NULL; buffer = buffer->next) {
                if (buffer->age == pointer) {
                    struct Bird *buf2 = malloc(sizeof(struct Bird));
                    *buf2 = *buffer;
                    Add_element_to_end(buf_list, buf2);
                }
            }
        }
        i++;
    }
    if (if_already_sorted_flag == 0) {
        Free_list(list);
        list->head = buf_list->head;
    }
    free(buf_list);
}

void Free_list(struct List *list){
    while (list->head) {
        struct Bird *p = list->head;
        list->head = p->next;
        free(p);
    }
}


/**
 * @file data.c
 * @brief Файл з описом розроблених функцій
 *
 * @author Starovoytov N.
 * @date 07-may-2021
 * @version 1.0
 */

#include "list.h"
#include "data.h"

void Print_bird(struct Bird *bird){
    if(bird->LOTR == 1){
        printf("Is bird the Lord of the Ring: Yes\n");
    }else{
        printf("Is bird the Lord of the Ring: NO\n");
    }
    printf("Name: %s\n", bird->name);
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
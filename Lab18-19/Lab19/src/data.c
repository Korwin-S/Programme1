/**
 * @file data.c
 * @brief Файл з описом розроблених функцій
 *
 * @author Starovoytov N.
 * @date 01-may-2021
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
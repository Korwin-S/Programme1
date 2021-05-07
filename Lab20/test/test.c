#include "../src/list.h"
#include "../src/data.h"

#define N1 3

bool flag = 0;
int Exec_time = 0;

void test_Add_element_to_end (){
    int start1, finish1;
    printf("\nTesting Add_element_to_end function:\n");
    start1 = clock();
    struct List *list = New_list();

    struct Bird buf[3] = {{1, "Grus", 50, {2500, 30, 0, 1}, 0},
                          {0, "Sparrow", 60, {250, 40, 2, 0}, 1},
                          {1, "Pigeon", 70,{700, 50, 3, 0}, 0}};
    for(int i = 0; i < N1; i++){
        struct Bird *bird = malloc(sizeof (struct Bird));
        *bird = buf[i];
        Add_element_to_end(list, bird);
    }

    struct Bird struct_paste_bird = {1, "Some_bird", 27, 48, 49, 2, 0, Male};
    struct Bird *paste_bird = malloc(sizeof(struct Bird));
    *paste_bird = struct_paste_bird;

    char expected_name1[15] = {"Some_bird"};
    Add_element_to_end(list, paste_bird);
    if (!strcmp(expected_name1, list->tail->name)) printf("Test passed!\n");
    else {
        printf("Test failed!\n");
        flag = 1;
    }
    Free_list(list);
    free(list);
    finish1 = clock();
    finish1 -= start1;
    Exec_time += finish1;
    printf("Execution time: %dms%s", finish1, "\n\n");
}

void test_Add_element_to_begin (){
    int start1, finish1;
    printf("\nTesting Add_element_to_begin function:\n");
    start1 = clock();
    struct List *list = New_list();

    struct Bird buf[3] = {{1, "Grus", 50, {2500, 30, 0, 1}, 0},
                          {0, "Sparrow", 60, {250, 40, 2, 0}, 1},
                          {1, "Pigeon", 70,{700, 50, 3, 0}, 0}};
    for(int i = 0; i < N1; i++){
        struct Bird *bird = malloc(sizeof (struct Bird));
        *bird = buf[i];
        Add_element_to_end(list, bird);
    }

    struct Bird struct_paste_bird = {1, "Some_bird", 27, 48, 49, 2, 0, Male};
    struct Bird *paste_bird = malloc(sizeof(struct Bird));
    *paste_bird = struct_paste_bird;

    char expected_name1[15] = {"Some_bird"};
    Add_element_to_begin(list, paste_bird);
    if (!strcmp(expected_name1, list->head->name)) printf("Test passed!\n");
    else {
        printf("Test failed!\n");
        flag = 1;
    }
    Free_list(list);
    free(list);
    finish1 = clock();
    finish1 -= start1;
    Exec_time += finish1;
    printf("Execution time: %dms%s", finish1, "\n\n");
}

void test_Insert_element (){
    int start1, finish1;
    printf("\nTesting Insert_element function:\n");
    start1 = clock();
    struct List *list = New_list();

    struct Bird buf[3] = {{1, "Grus", 50, {2500, 30, 0, 1}, 0},
                          {0, "Sparrow", 60, {250, 40, 2, 0}, 1},
                          {1, "Pigeon", 70,{700, 50, 3, 0}, 0}};
    for(int i = 0; i < N1; i++){
        struct Bird *bird = malloc(sizeof (struct Bird));
        *bird = buf[i];
        Add_element_to_end(list, bird);
    }

    struct Bird struct_paste_bird = {1, "Some_bird", 27, 48, 49, 2, 0, Male};
    struct Bird *paste_bird = malloc(sizeof(struct Bird));
    *paste_bird = struct_paste_bird;

    char expected_name1[15] = {"Some_bird"};
    Insert_element(list, 1, paste_bird);
    if (!strcmp(expected_name1, list->head->next->name)) printf("Test passed!\n");
    else {
        printf("Test failed!\n");
        flag = 1;
    }
    Free_list(list);
    free(list);
    finish1 = clock();
    finish1 -= start1;
    Exec_time += finish1;
    printf("Execution time: %dms%s", finish1, "\n\n");
}

void test_Delete_element (){
    int start1, finish1;
    printf("\nTesting Delete_element function:\n");
    start1 = clock();
    struct List *list = New_list();

    struct Bird buf[3] = {{1, "Grus", 50, {2500, 30, 0, 1}, 0},
                          {0, "Sparrow", 60, {250, 40, 2, 0}, 1},
                          {1, "Pigeon", 70,{700, 50, 3, 0}, 0}};
    for(int i = 0; i < N1; i++){
        struct Bird *bird = malloc(sizeof (struct Bird));
        *bird = buf[i];
        Add_element_to_end(list, bird);
    }

    char expected_name1[15] = {"Some_bird"};
    Delete_element(list, 1);
    if (strcmp(expected_name1, list->head->next->name)) printf("Test passed!\n");
    else {
        printf("Test failed!\n");
        flag = 1;
    }
    Free_list(list);
    free(list);
    finish1 = clock();
    finish1 -= start1;
    Exec_time += finish1;
    printf("Execution time: %dms%s", finish1, "\n\n");
}

void test_Sort_birds_by_age (){
    int start1, finish1;
    printf("\nTesting Sort_birds_by_age function:\n");
    start1 = clock();
    struct List *list = New_list();

    struct Bird buf[3] = {{1, "Grus", 123, {2500, 30, 0, 1}, 0},
                          {0, "Sparrow", 60, {250, 40, 2, 0}, 1},
                          {1, "Pigeon", 70,{700, 50, 3, 0}, 0}};
    for(int i = 0; i < N1; i++){
        struct Bird *bird = malloc(sizeof (struct Bird));
        *bird = buf[i];
        Add_element_to_end(list, bird);
    }

    int expected_age[3] = {60, 70, 123};
    Sort_birds_by_age(list);
    if (expected_age[0] == list->head->age && expected_age[1] == list->head->next->age && expected_age[2] == list->head->next->next->age) {
        printf("Test passed!\n");
    }
    else {
        printf("Test failed!\n");
        flag = 1;
    }
    Free_list(list);
    free(list);
    finish1 = clock();
    finish1 -= start1;
    Exec_time += finish1;
    printf("Execution time: %dms%s", finish1, "\n\n");
}

int main(){
    test_Add_element_to_end();
    test_Add_element_to_begin();
    test_Insert_element();
    test_Delete_element();
    test_Sort_birds_by_age();

    if (flag == 0) printf("\nAll tests complete!\n");
    else printf("\nSomething went wrong!\n");
    printf("\nExecution time of all tests: ~%dms%s", Exec_time, "\n");

    return 0;
}
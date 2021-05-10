#include "../library/library.h"

#define N1 3

bool flag = 0;
int Exec_time = 0;

void test_Regex_Check (){
    int start1, finish1;
    printf("\nTesting Regex_Check function:\n");
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

    for (struct Bird *bird = list->head; bird != NULL; bird = bird->next) {
        if (Regex_Check(bird) == true) printf("Test passed!\n");
        else {
            printf("Test failed!\n");
            flag = 1;
        }
    }
    Free_list(list);
    free(list);
    finish1 = clock();
    finish1 -= start1;
    Exec_time += finish1;
    printf("Execution time: %dms%s", finish1, "\n\n");
}

int main(){
    test_Regex_Check();

    if (flag == 0) printf("\nAll tests complete!");
    else printf("\nSomething went wrong!");
    printf("\nExecution time of all tests: ~%dms%s", Exec_time, "\n");

    return 0;
}
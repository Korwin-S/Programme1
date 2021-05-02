#include "../src/lib.h"

#define N1 3

void test_add_bird (){
    printf("Testing add_bird function:\n");
    struct Bird * birds = (struct Bird *) malloc(N1 * sizeof (struct Bird));

    struct Bird buf0 = {1, "Grus", 50, {2500, 30, 0, 1}, 0};
    memcpy((birds + 0), &buf0, sizeof(buf0));
    struct Bird buf1 = {0, "Sparrow", 60, {250, 40, 2, 0}, 1};
    memcpy((birds + 1), &buf1, sizeof(buf1));
    struct Bird buf2 = {1, "Pigeon", 70,{700, 50, 3, 0}, 0};
    memcpy((birds + 2), &buf2, sizeof(buf2));


    struct Bird paste_bird = {1, "Some_bird", 27, 48, 49, 2, 0, Male};

    char expected_name1[10] = {"Some_bird"};
    birds = add_bird(birds, paste_bird, 3);
    if (!bool_compare_strings(expected_name1, (birds + 3)->name)) printf("Test passed!\n");
    else {
        printf("Test failed!\n");
    }

    free(birds);
}

void test_delete_bird (){
    printf("\nTesting delete_bird function:\n");
    struct Bird * birds = (struct Bird *) malloc(N1 * sizeof (struct Bird));

    struct Bird buf0 = {1, "Grus", 50, {2500, 30, 0, 1}, 0};
    memcpy((birds + 0), &buf0, sizeof(buf0));
    struct Bird buf1 = {0, "Sparrow", 60, {250, 40, 2, 0}, 1};
    memcpy((birds + 1), &buf1, sizeof(buf1));
    struct Bird buf2 = {1, "Pigeon", 70,{700, 50, 3, 0}, 0};
    memcpy((birds + 2), &buf2, sizeof(buf2));

    char expected_name2[10] = {"Sparrow"};
    birds = delete_bird(birds, 0);
    if (!bool_compare_strings(expected_name2, birds->name)) printf("Test passed!\n");
    else {
        printf("Test failed!\n");
    }

    free(birds);
}

void test_insert_string (){
    printf("\nTesting insert_string function:\n");

    char* string1 = "AA__AA";
    char* insertion_string = "BBB";
    int position = 3;
    char* result = insert_string(string1, insertion_string, position);

    if (!strcmp(result, "AA_BBB_AA")) printf("Test passed!\n");
    else printf("Test failed!\n");
}

void test_delete_string (){
    printf("\nTesting delete_string function:\n");

    char* string1 = "AAA___AAA";
    int pos1 = 3, pos2 = 5;
    char* result = delete_string(string1, pos1, pos2);

    if (!strcmp(result, "AAAAAA")) printf("Test passed!\n");
    else printf("Test failed!\n");
}


int main(){
    test_add_bird();
    test_delete_bird();
    test_insert_string();
    test_delete_string();
    return 0;
}
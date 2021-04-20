#include "../src/lib.h"

#define N1 3

void test_sort_by_criterion (){
    printf("Testing sort_by_criterion function:\n\n");
    struct Bird * birds = (struct Bird *) malloc(N1 * sizeof (struct Bird));
    bool result = true;

    struct Bird buf0 = {1, "Grus", 50, {2500, 30, 0, 1}, 0};
    memcpy((birds + 0), &buf0, sizeof(buf0));
    struct Bird buf1 = {0, "Sparrow", 60, {250, 40, 2, 0}, 1};
    memcpy((birds + 1), &buf1, sizeof(buf1));
    struct Bird buf2 = {1, "Pigeon", 70,{700, 50, 3, 0}, 0};
    memcpy((birds + 2), &buf2, sizeof(buf2));


    int expected_LOTR[N1] = {0, 1, 1};
    sort_by_criterion(birds, "ringed", N1);
    for (int i = 0; i < N1; ++i) {
        if (expected_LOTR[i] == (birds + i)->LOTR) printf("LOTR test passed\n");
        else {
            printf("LOTR test failed\n");
            result = false;
        }
    }

    char expected_name[N1][10] = {"Grus", "Pigeon", "Sparrow"};
    sort_by_criterion(birds, "name", N1);
    for (int i = 0; i < N1; ++i) {
        if (!bool_compare_strings(expected_name[i], (birds + i)->name)) printf("Name test passed\n");
        else {
            printf("Name test failed\n");
            result = false;
        }
    }

    
    int expected_age[N1] = {50, 60, 70};
    sort_by_criterion(birds, "age", N1);
    for (int i = 0; i < N1; ++i) {
        if (expected_age[i] == (birds + i)->age) printf("Age test passed\n");
        else {
            printf("Age test failed\n");
            result = false;
        }
    } 
    
    int expected_home_space[N1] = {250, 700, 2500};
    sort_by_criterion(birds, "space", N1);
    for (int i = 0; i < N1; ++i) {
        if (expected_home_space[i] == (birds + i)->home.space) printf("Home space test passed\n");
        else {
            printf("Home space test failed\n");
            result = false;
        }
    }

    int expected_home_height[N1] = {30, 40, 50};
    sort_by_criterion(birds, "height", N1);
    for (int i = 0; i < N1; ++i) {
        if (expected_home_height[i] == (birds + i)->home.height) printf("Home height test passed\n");
        else {
            printf("Home height test failed\n");
            result = false;
        }
    }

    int expected_home_COF[N1] = {0, 2, 3};
    sort_by_criterion(birds, "feeders", N1);
    for (int i = 0; i < N1; ++i) {
        if (expected_home_COF[i] == (birds + i)->home.count_of_feeders) printf("Home feeders test passed\n");
        else {
            printf("Home feeders test failed\n");
            result = false;
        }
    }

    int expected_home_nest[N1] = {0, 0, 1};
    sort_by_criterion(birds, "nest", N1);
    for (int i = 0; i < N1; ++i) {
        if (expected_home_nest[i] == (birds + i)->home.if_nest) printf("Home nest test passed\n");
        else {
            printf("Home nest test failed\n");
            result = false;
        }
    }

    int expected_sex[N1] = {0, 0, 1};
    sort_by_criterion(birds, "sex", N1);
    for (int i = 0; i < N1; ++i) {
        if (expected_sex[i] == (birds + i)->enumSex) printf("Sex test passed\n");
        else {
            printf("Sex test failed\n");
            result = false;
        }
    }
    free(birds);
    if (result) printf("\nAll tests complete!\n");
    else printf("\nSomething went wrong!\n");
}

void test_find_sex_ratio (){
    printf("\nTesting find_sex_ratio function:\n");
    struct Bird * birds = (struct Bird *) malloc(N1 * sizeof (struct Bird));

    struct Bird buf0 = {1, "Grus", 50, {2500, 30, 0, 1}, 0};
    memcpy((birds + 0), &buf0, sizeof(buf0));
    struct Bird buf1 = {0, "Sparrow", 60, {250, 40, 2, 0}, 1};
    memcpy((birds + 1), &buf1, sizeof(buf1));
    struct Bird buf2 = {1, "Pigeon", 70,{700, 50, 3, 0}, 0};
    memcpy((birds + 2), &buf2, sizeof(buf2));


    double expected_ratio = 50;
    if (expected_ratio == find_sex_ratio(birds, N1)) printf("Test passed!\n");
    else printf("Test failed!\n");
}


int main(){
    test_sort_by_criterion();
    test_find_sex_ratio();
    return 0;
}
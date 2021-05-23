#include "../src/list.h"

bool Total_result = true;

void test_Find_Sex_Ratio () {
    printf("Testing Find_Sex_Ratio function:\n");
    CList List;
    Bird bird1{false, "Cockoo", 37, {444, 9, 2, true}, Female};
    Bird bird2{true, "Sparrow", 56, {800, 15, 0, false}, Male};
    Bird bird3{true, "Pigeon", 46, {763, 81, 3, true}, Male};

    List.Add_Bird(bird1);
    List.Add_Bird(bird2);
    List.Add_Bird(bird3);

    double expected_ratio = 50;
    if (expected_ratio == List.Find_Sex_Ratio()) printf("Test passed!\n");
    else {
        printf("Test failed!\n");
        Total_result = false;
    }
}

void test_Add_Bird () {
    bool result = true;
    int expected_N = 3;
    printf("\nTesting Add_Bird function:\n");
    CList List;
    Bird bird1{false, "Cockoo", 37, {444, 9, 2, true}, Female};
    Bird bird2{true, "Sparrow", 56, {800, 15, 0, false}, Male};
    Bird bird3{true, "Pigeon", 46, {763, 81, 3, true}, Male};

    List.Add_Bird(bird1);
    List.Add_Bird(bird2);
    List.Add_Bird(bird3);

    if (List.Get_N() != 3) result = false;
    if (List.Get_Bird(0).get_name() != "Cockoo") result = false;
    if (List.Get_Bird(1).get_name() != "Sparrow") result = false;
    if (List.Get_Bird(2).get_name() != "Pigeon") result = false;

    if (result) printf("Test passed!\n");
    else {
        printf("Test failed!\n");
        Total_result = false;
    }
}

void test_Delete_Bird () {
    bool result = true;
    int expected_N = 3;
    printf("\nTesting Delete_Bird function:\n");
    CList List;
    Bird bird1{false, "Cockoo", 37, {444, 9, 2, true}, Female};
    Bird bird2{true, "Sparrow", 56, {800, 15, 0, false}, Male};
    Bird bird3{true, "Pigeon", 46, {763, 81, 3, true}, Male};

    List.Add_Bird(bird1);
    List.Add_Bird(bird2);
    List.Add_Bird(bird3);

    List.Delete_Bird(1);

    if (List.Get_N() != 2) result = false;
    if (List.Get_Bird(0).get_name() != "Cockoo") result = false;
    if (List.Get_Bird(1).get_name() != "Pigeon") result = false;

    if (result) printf("Test passed!\n");
    else {
        printf("Test failed!\n");
        Total_result = false;
    }
}


int main() {

    test_Find_Sex_Ratio();
    test_Add_Bird();
    test_Delete_Bird();
    if (Total_result) printf("\nAll tests completed!\n");
    else printf("\nSomething went wrong!\n");

    return 0;
}

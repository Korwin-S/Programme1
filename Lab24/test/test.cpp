#include "../src/list.h"

bool Total_result = true;

void test_toString () {
    cout << "\nTesting toString function:\n";
    Bird bird1{false, "Cockoo", 37, {444, 9, 2, true}, Female};

    string result = bird1.toString();
    string expected_result = "\nIs bird the Lord of the Ring: No\nName: Cockoo\nAge: 37 months\n   Home area: 444 sm^2\n   Home height: 9 sm\n   Home feeders amount: 2\n   Is bird's home a nest: Yes\nSex: female\n";
    if (result == expected_result) cout << "Test passed!\n";
    else {
        cout << "Test failed!\n";
        Total_result = false;
    }
}

void test_Add_Bird_From_String () {
    cout << "\nTesting Add_Bird_From_String function:\n";

    CList List;
    bool result = true;
    Bird bird1{false, "Cockoo", 37, {444, 9, 2, true}, Female};
    Bird bird2{true, "Sparrow", 56, {800, 15, 0, false}, Male};
    Bird bird3{true, "Pigeon", 46, {763, 81, 3, true}, Male};

    string string_bird1 = "0 Cockoo 37 444 9 2 1 Female";
    string string_bird2 = "1 Sparrow 56 800 15 0 0 Male";
    string string_bird3 = "1 Pigeon 46 763 81 3 1 Male";

    List.Add_Bird_From_String(string_bird1);
    List.Add_Bird_From_String(string_bird2);
    List.Add_Bird_From_String(string_bird3);

    if (List.Get_N() != 3) result = false;
    if (List.Get_Bird(0).get_name() != "Cockoo") result = false;
    if (List.Get_Bird(1).get_name() != "Sparrow") result = false;
    if (List.Get_Bird(2).get_name() != "Pigeon") result = false;

    if (result) cout << "Test passed!\n";
    else {
        cout << "Test failed!\n";
        Total_result = false;
    }
}

void test_FromString () {
    cout << "\nTesting FromString function:\n";

    bool result = true;
    Bird bird {false, "Eagle", 89, {2780, 10, 5, true}, Male};
    Bird check_bird {true, "", 0, {0, 0, 0, false}, Female};

    string input = "0 Eagle 89 2780 10 5 1 Male";
    check_bird.FromString(input);

    if (bird.get_LOTR() != check_bird.get_LOTR()) result = false;
    if (bird.get_name() != check_bird.get_name()) result = false;
    if (bird.get_age() != check_bird.get_age()) result = false;
    if (bird.get_space() != check_bird.get_space()) result = false;
    if (bird.get_height() != check_bird.get_height()) result = false;
    if (bird.get_count_of_feeders() != check_bird.get_count_of_feeders()) result = false;
    if (bird.get_if_nest() != check_bird.get_if_nest()) result = false;
    if (bird.get_Sex() != check_bird.get_Sex()) result = false;

    if (result) cout << "Test passed!\n";
    else {
        cout << "Test failed!\n";
        Total_result = false;
    }
}


int main() {

    test_toString();
    test_FromString();
    test_Add_Bird_From_String();

    if (Total_result) printf("\nAll tests completed!\n");
    else printf("\nSomething went wrong!\n");

    return 0;
}

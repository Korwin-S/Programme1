
#include "list.h"

int main(){

    CList List;
//    Bird bird1 {false, "Cockoo", 37, {444, 9, 2, true}, Female};
//    Bird bird2 {true, "Sparrow", 56, {800, 15, 0, false}, Male};
//    Bird bird3 {true, "Pigeon", 46, {763, 81, 3, true}, Male};
//    Bird bird4 {false, "Eagle", 89, {2780, 10, 5, true}, Male};
//
//    List.Add_Bird(bird1);
//    List.Add_Bird(bird2);
//    List.Add_Bird(bird3);
//    List.Add_Bird(bird4);

    List.Read_From_File("../birds.txt");
//    List.Read_From_File("../birds.txt");
//    List.Read_From_File("../birds.txt");

    List.Print_All();
    List.Find_Sex_Ratio();

    cout << "\n----------------------------------------------------------\n";
    List.Delete_Bird(2);
    List.Print_All();
    List.Find_Sex_Ratio();

    List.Write_To_File("../output.txt");

    return 0;
}
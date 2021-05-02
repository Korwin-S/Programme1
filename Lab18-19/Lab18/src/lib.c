#include "lib.h"

void read_from_file(struct Bird *birds){
    FILE *file = fopen("../birds.txt", "r");
    if (file == NULL) {
        printf("Unable to open file: %s", strerror(errno));
        exit(1);
    }
    for(int i = 0; i < N; i++){
        fscanf(file, "%d%s%d%d%d%d%d", &((birds + i)->LOTR), ((birds + i) ->name),
               &((birds + i)->home.space), &((birds + i)->home.height), &((birds + i)->home.count_of_feeders), &((birds + i)->home.if_nest), &((birds + i)->enumSex));
    }
    fclose(file);
}

void random_age_generation(struct Bird *birds){
    for(int i = 0; i < N; i++){
        (birds + i)->age = rand() % 207 + 23;
    }
}

void print_in_console(struct Bird *birds, int count){
    for(int i = 0; i < count; i++){
        if((birds + i)->LOTR == 1){
            printf("Is bird the Lord of the Ring: Yes\n");
        }else{
            printf("Is bird the Lord of the Ring: NO\n");
        }
        printf("Name: %s\n", (birds + i)->name);
        printf("Age: %d months\n", (birds + i)->age);
        printf("   Home area: %d sm^2\n", (birds + i)->home.space);
        printf("   Home height: %d sm\n", (birds + i)->home.height);
        printf("   Home feeders amount: %d\n", (birds + i)->home.count_of_feeders);
        if((birds + i)->home.if_nest == 1){
            printf("   Is bird's home a nest: Yes\n");
        }else{
            printf("   Is bird's home a nest: NO\n");
        }
        if((birds + i)->enumSex == Male){
            printf("Sex: male\n");
        } else if((birds + i)->enumSex == Female) {
            printf("Sex: female\n");
        }
        printf("\n");
    }
}

int bool_compare_strings(char a[10], char b[10]){
    if(strcmp(a,b) <= 0){
        return 0;
    } else if (strcmp(a,b) > 0){
        return 1;
    } else return 0;
}

struct Bird * add_bird(struct Bird *birds, struct Bird paste_bird, int pos) {
    if (pos < 0) printf("Error");
    struct Bird *result = malloc((N + 1) * sizeof(struct Bird));
    memcpy(result, birds, sizeof(struct Bird) * N);
    if (pos >= N) {
        pos = N;
        memcpy((result + N), &paste_bird, sizeof(struct Bird));
    } else {
        struct Bird *buffer = malloc((N + 1) * sizeof(struct Bird));
        memcpy(buffer, result + pos, sizeof(struct Bird) * (N - pos));
        memcpy(result + pos, &paste_bird, sizeof(struct Bird));
        memcpy(result + pos + 1, buffer, sizeof(struct Bird) * (N - pos));
        free(buffer);
    }
    free(birds);
    return result;
}

struct Bird * delete_bird(struct Bird *birds, int pos){
    if (pos < 0) printf("Error");
    struct Bird *result = malloc((N-1) * sizeof(struct Bird));
    if (pos >= N) {
        pos = N;
        memcpy(result, birds, sizeof(struct Bird) * (N-1));
    } else {
        memcpy(result, birds, sizeof(struct Bird) * pos);
        memcpy(result + pos, birds+pos+1, sizeof(struct Bird) * (N-pos-1));
    }
    free(birds);
    return result;
}

char * insert_string(char * text, char * pasted_text, int pos){
    if (pos < 0) pos = 0;
    if (pos > strlen(text)) pos = strlen(text);   //проверка корректности позиции
    char* new_text = malloc((strlen(text) + strlen(pasted_text))* sizeof (char));
    memcpy(new_text, text, pos);
    memcpy(new_text + pos, pasted_text, strlen(pasted_text));
    memcpy(new_text + pos + strlen(pasted_text), text + pos, strlen(text) - pos);
    *(new_text + strlen(pasted_text) + strlen(text)) = '\0';
    return new_text;
}

char * delete_string(char * text, int pos1, int pos2){
    if (pos1 < 0) pos1 = 0;
    if (pos2 >= strlen(text)) pos2 = strlen(text) - 1;
    if (pos1 > pos2) return "Error";    //проверка корректности позиций
    char* new_text = malloc((strlen(text) - (pos2 - pos1))* sizeof (char));
    memcpy(new_text, text, pos1);
    memcpy(new_text + pos1, text + pos2 + 1, strlen(text) - pos2);
    return  new_text;
}

void Demonstration_of_strings(){
    char* string1 = malloc(100 * sizeof (char));
    char* insertion_string = malloc(100 * sizeof (char));
    char* string2 = malloc(100 * sizeof (char));

    printf("Input text: ");
    scanf("%s", string1);
    printf("Input string you want to insert: ");
    scanf("%s", insertion_string);
    int position;
    printf("Position: ");
    scanf("%i", &position);
    char* result = insert_string(string1, insertion_string, position);
    printf("Result: %s\n\n", result);

    int pos1, pos2;
    printf("Input text: ");
    scanf("%s", string2);
    printf("First position to delete: ");
    scanf("%d", &pos1);
    printf("Second position to delete: ");
    scanf("%d", &pos2);
    result = delete_string(string2, pos1, pos2);
    printf("Result: %s\n\n\n", result);

    free(result);
    free(string1);
    free(insertion_string);
    free(string2);
    system("pause");
}
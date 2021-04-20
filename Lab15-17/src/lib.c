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

int bool_compare_strings(char a[10], char b[10]){
    if(strcmp(a,b) <= 0){
        return 0;
    } else if (strcmp(a,b) > 0){
        return 1;
    } else return 0;
}

void sort_by_criterion(struct Bird *birds, char criterion[10], int size){
    bool flag;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            flag = 0;
            if(strcmp("name", criterion) == 0) {
                flag = bool_compare_strings(((birds + j))->name, ((birds + j + 1))->name);
            }
            if(strcmp("ringed", criterion) == 0){
                if ((birds + j)->LOTR > (birds + j + 1)->LOTR){
                    flag = 1;
                }
            }
            if(strcmp("age", criterion) == 0) {
                if ((birds + j)->age > (birds + j + 1)->age) {
                    flag = 1;
                }
            }
            if(strcmp("space", criterion) == 0) {
                if ((birds + j)->home.space > (birds + j + 1)->home.space) {
                    flag = 1;
                }
            }
            if(strcmp("height", criterion) == 0) {
                if ((birds + j)->home.height > (birds + j + 1)->home.height) {
                    flag = 1;
                }
            }
            if(strcmp("feeders", criterion) == 0) {
                if ((birds + j)->home.count_of_feeders > (birds + j + 1)->home.count_of_feeders) {
                    flag = 1;
                }
            }
            if(strcmp("nest", criterion) == 0) {
                if ((birds + j)->home.if_nest > (birds + j + 1)->home.if_nest) {
                    flag = 1;
                }
            }
            if(strcmp("sex", criterion) == 0) {
                if ((birds + j)->enumSex > (birds + j + 1)->enumSex) {
                    flag = 1;
                }
            }
            if (flag){
                struct Bird buffer;
                memcpy(&buffer, (birds + j), sizeof(struct Bird));
                memcpy(birds + j, birds + j + 1, sizeof(struct Bird));
                memcpy(birds + j + 1, &buffer, sizeof(struct Bird));
            }
        }
    }
}

void print_in_console(struct Bird *birds){
    for(int i = 0; i < N; i++){
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

void print_in_file(struct Bird *birds){
    FILE *file = fopen("../result.txt", "w");
    if (file == NULL) {
        printf("Unable to open file: %s", strerror(errno));
        exit(1);
    }
    for(int i = 0; i < N; i++){
        if((birds + i)->LOTR == 1){
            fprintf(file, "Is bird the Lord of the Ring: Yes\n");
        }else{
            fprintf(file, "Is bird the Lord of the Ring: NO\n");
        }
        fprintf(file,"Name: %s\n", (birds + i)->name);
        fprintf(file, "Age: %d months\n", (birds + i)->age);
        fprintf(file, "   Home area: %d sm^2\n", (birds + i)->home.space);
        fprintf(file, "   Home height: %d sm\n", (birds + i)->home.height);
        fprintf(file, "   Home feeders amount: %d\n", (birds + i)->home.count_of_feeders);
        if((birds + i)->home.if_nest == 1){
            fprintf(file, "   Is bird's home a nest: Yes\n");
        }else{
            fprintf(file, "   Is bird's home a nest: NO\n");
        }
        if((birds + i)->enumSex == Male){
            fprintf(file, "Sex: male\n");
        } else if((birds + i)->enumSex == Female){
            fprintf(file, "Sex: female\n");
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

double find_sex_ratio(struct Bird *birds, int size){
    double counter_male = 0, counter_female = 0;
    double result;
    for(int i = 0; i < size; i++){
        if ((birds + i)->enumSex == 0) {
            counter_male++;
        } else if ((birds + i)->enumSex == 1) {
            counter_female++;
        }
    }
    result = (double) (counter_female / counter_male) * 100;
    printf("Female to male ratio is %2.2f%%\n\n", result);
    return result;
}


void write_to_binary(struct Bird *birds) {
    FILE *file = fopen("../result.bin", "wb");
    if (file == NULL) {
        printf("Unable to open file: %s", strerror(errno));
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        fwrite((birds + i), sizeof(*(birds + i)), 1, file);
    }
    fclose(file);
}

void read_from_binary(struct Bird *binary_birds){
    FILE *file = fopen("../result.bin", "rb");
    if (file == NULL) {
        printf("Unable to open file: %s", strerror(errno));
        exit(1);
    }
    for (int i = 0; i < N; ++i) {
         read_from_binary_by_index(binary_birds + i, file, i);
    }
    fclose(file);
}

void read_from_binary_by_index(struct Bird *bird, FILE *file, int index){
    fseek(file, (long)(sizeof(*bird) * index), SEEK_SET);
    fread(bird, sizeof(*bird), 1, file);
}

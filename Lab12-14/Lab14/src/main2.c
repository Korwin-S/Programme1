/**
 * @mainpage
 * # Загальне завдання
 * 1. Вивести структуру файлів та каталогів, як це робить утиліта Linux tree. Виклик функції system заборонено.
 * 2. Визначити об’єм запитаного каталогу.  Результат нормалізувати. Формат розміру:
 -#  не більше ніж 3 знаки до коми;
 -#  не більше ніж 2 знаки після коми;
 -#  єдиний випадок, коли в чисельний частині числа може бути 0 - коли *  розмір дорівнює 0 байт.
 * @author Starovoytov N.
 * @date 05-apr-2021
 * @version 1.0
 */

/**
* @file main2.c
* @brief Лабораторна робота №14
*
* @author Starovoytov N.
* @date 05-apr-2021
* @version 1.0
*/


#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>


/**
 * Функція читає з вхідного файлу текст да зберігає його в одну строку
 * @param string - строка із заданим текстом
 * @return *string - покажчик на строку із прочитаним текстом
 */
char read_from_file(char *string) {
    FILE *input;
    char *input_name = malloc(100);
    printf("Please enter input file name:");
    scanf("%s", input_name);
    getchar();
    if ((input = fopen(input_name, "r")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    fscanf(input, "%[^EOF]", string);
    free(input_name);
    fclose(input);
    return *string;
}


/**
 * Функція підраховує розмір переданного файлу
 * @param *file - покажчик на файл
 * @return file_size - розмір файлу
 */
int calculate_file_size(FILE *file)
{
    int first_position = ftell(file);   //текущее положение указателя
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, first_position, SEEK_SET);
    return file_size;
}


/**
 * Функція підраховує розмір каталогу та виводить його на екран
 * @param *path - шлях до каталогу
 * @return 1 або 0 - код неуспішного або успішного виконання функції
 */
int calculate_size_of_catalog (char *path) {
    DIR *dir;
    struct dirent *ent;
    printf("\n");
    double sum = 0.0;
    if ((dir = opendir(path)) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir(dir)) != NULL) {
            if (strchr(ent->d_name, '.') != NULL && strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                char *input_name = malloc(100);
                strcpy(input_name, path);
                strncat(input_name, "\\", 2);
                strncat(input_name, ent->d_name, sizeof(ent->d_name));

                FILE *file;
                if ((file = fopen(input_name, "r")) == NULL) {
                    printf("Cannot open file.\n");
                    exit(1);
                }
                sum += (double) calculate_file_size(file);
                free(input_name);
                fclose(file);
            }
        }

        if (sum > 999.0) sum = 999.0;
        printf("%.2f%s", sum, " bytes\n");
        closedir(dir);
        return 0;
    } else {
        perror("");
        return 1;
    }
}


/**
 * Функція виводить вміст каталогу на екран
 * @param *path - шлях до каталогу
 * @return 1 або 0 - код неуспішного або успішного виконання функції
 */
int tree (char *path){
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir (path)) != NULL) {
        /* print all the files and directories within directory */
        while ((ent = readdir (dir)) != NULL) {
            if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0) {
                printf("%s\n", ent->d_name);
            }
            if (strchr(ent->d_name, '.') == NULL) {
                char *input_name = malloc(100);
                strcpy(input_name, path);
                strncat(input_name, "\\", 2);
                strncat(input_name, ent->d_name, sizeof(ent->d_name));
                printf("   ");
                tree(input_name);
                printf("\n");
            }

        }
        closedir (dir);
        return 0;
    } else {
        perror ("");
        return 1;
    }
}


/**
 * Головна функція.
 * Послідовність дій:
 * -# Виділяємо пам'ять під строку зі шляхом до каталогу
 * -# Зчитуємо з вхідного файлу текст до строки path
 * -# Викликаємо функцію {@link tree}
 * -# Викликаємо функцію {@link calculate_size_of_catalog}
 * @return 0 - код успішного виконання програми
 */
int main()
{
    printf("\n");

    char *path = malloc(100);
    *path = read_from_file(path);
    tree(path);
    calculate_size_of_catalog(path);
	free(path);
	
    printf("\n");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h> // for usleep

#define goal 1000

void start() {
    system("clear"); // Linux 환경에서 화면을 지우기 위한 명령어
    FILE *file = fopen("welcome.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("\n");
    fclose(file);
    
    FILE *file2 = fopen("goal.txt", "r");
    char line_[256];
    while (fgets(line_, sizeof(line_), file2)) {
        printf("%s", line_);
    }
    printf("\n\n\n");
    fclose(file2);
}

void correct() {
    FILE *file = fopen("correct.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("\n");
    fclose(file);
}

void wrong() {
    FILE *file = fopen("nope.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("\n\n");
    fclose(file);
}

void show_point(int user_point) {
    char file_name[200];
    sprintf(file_name, "number_list/%d.txt", user_point);
    FILE *file = fopen(file_name, "r");
    char line[256];
    if (file) {
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        fclose(file);
    } else {
        printf("Error: File %s not found!\n", file_name);
    }
    printf("\n\n\n");
}

int main() {
    start();
    srand(time(NULL));

    int count = 0;
    int user_input;
    int user_point = 1;
    int weight = 1;
    int correct_count = 0;
    int wrong_count = 0;

    while (user_point < goal) {
        int set_random = rand();

        count++;
        weight = 2 << correct_count;
        if (weight < 2) weight = 2;

        printf("[STAGE %d] (point*%d) - Your Point : %d\n", count, weight, user_point);
        show_point(user_point);

        printf("Guess random number (odd : 1, even : 0) : ");
        scanf("%d", &user_input);
        
        if (user_input < 0 || user_input > 1) {
            printf("Wrong input\n");
            break;
        }

        usleep(500000); // Sleep for 500 milliseconds
        printf("\n> Your Guess is %s\n", (user_input == 0 ? "EVEN" : "ODD"));
        usleep(1500000); // Sleep for 1.5 seconds
        printf("> hmmm......\n");
        usleep(1500000); // Sleep for 1.5 seconds
        printf("> Computer's Choice is : %d (%d)\n", set_random % 2, set_random);
        usleep(1000000); // Sleep for 1 second

        if (user_input == set_random % 2) {
            correct();
            user_point *= weight;
            correct_count++;
        } else {
            wrong();
            wrong_count++;
            user_point /= 2;
            if (user_point <= 0) user_point = 1;
        }

        printf("\nPress 'ENTER' to next stage...\n\n\n");
        getchar();
        getchar();

        if (count % 3 == 0) {
            system("clear"); // Clear screen for Linux/Unix
            start();
        }
    }

    if (user_point >= goal) {
        system("clear");
        printf("Your point is : \n");

        char file_name[200];
        sprintf(file_name, "number_list/%d.txt", user_point);
        FILE *file = fopen(file_name, "r");
        char line[256];
        if (file) {
            while (fgets(line, sizeof(line), file)) {
                printf("%s", line);
            }
            fclose(file);
        } else {
            printf("Error: File %s not found!\n", file_name);
        }
        printf("\n\n\n");

        FILE *flag = fopen("flag.txt", "r");
        char flag_context[256];
        while (fgets(flag_context, sizeof(flag_context), flag)) {
            printf("%s", flag_context);
        }
        printf("\n");
        fclose(flag);
    }
    return 0;
}


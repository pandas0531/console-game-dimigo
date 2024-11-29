#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define goal 10000

void start(){
    system("cls");
    FILE *file = fopen("txt_list/welcome.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("\n");
    fclose(file);
    
    FILE *file2 = fopen("txt_list/goal.txt", "r");
    char line_[256];
    while (fgets(line_, sizeof(line_), file2)) {
        printf("%s", line_);
    }
    printf("\n\n\n");
    fclose(file2);
}

void correct(){
    FILE *file = fopen("txt_list/correct.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("\n");
    fclose(file);
}

void wrong(){
    FILE *file = fopen("txt_list/nope.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("\n\n");
    fclose(file);
}

void point(int point){
    char file_name[200];
    sprintf(file_name, "number_list/%d.txt", point);
    FILE *file = fopen(file_name, "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("\n\n\n");
    fclose(file);
}

int main(){

    start();
    srand(time(NULL));

    int count=0;
    
    int user_input;
    int user_point=1;
    int weight=1;
    int correct_count=0;
    int wrong_count=0;

    while(user_point < goal){

        int set_random;
        set_random = rand();

        count++;
        weight = 2<<correct_count;
        if(weight<2) weight = 2;

        printf("[STAGE %d] (point*%d) - Your Point : %d\n", count, weight, user_point);
        point(user_point);
        //printf("          Correct : %d / Wrong %d\n\n", correct_count, wrong_count);

        printf("Guess random number (odd : 1, even : 0) : ");
        scanf("%d", &user_input);
        
        if(user_input < 0 || user_input > 1){
            printf("wrong input\n");
            break;
        }

        Sleep(500);
        printf("\n> Your Guess is %s\n", (user_input==0?"EVEN":"ODD"));
        Sleep(1500);
        printf("> hmmm......\n");
        Sleep(1500);
        printf("> Computer's Choice is : %d (%d)\n", set_random%2, set_random);
        Sleep(1000);

        if(user_input==set_random%2){
            correct();
            user_point *= weight;
            correct_count++;
        }
        else{
            wrong();
            wrong_count++;
            user_point /= 2;
            if(user_point<=0) user_point = 1;
        }

        printf("\nPress 'ENTER' to next stage...\n\n\n");
        
        getchar(); 
        getchar(); 
        
        if(count%3==0){
            system("cls");
            start();
        }

    }
    if(user_point >= goal){
        system("cls");
        printf("Your point is : \n");

        char file_name[200];

        if(user_point <= 10000){
            sprintf(file_name, "number_list/%d.txt", user_point);    
        }
        else{
            sprintf(file_name, "number_list/10000+.txt");
        }        
        FILE *file = fopen(file_name, "r");
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            printf("%s", line);
        }
        printf("\n\n\n");
        fclose(file);

        FILE *flag = fopen("txt_list/flag.txt", "r");
        char flag_context[256];
        while (fgets(flag_context, sizeof(flag_context), flag)) {
            printf("%s", flag_context);
        }
        printf("\n");
        fclose(flag);
    }

}

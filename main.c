#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// #define goal 100

void start(){
    system("cls");
    FILE *file = fopen("welcome.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("\n");
    fclose(file);
}

void correct(){
    return 0;
}

void wrong(){
    FILE *file = fopen("nope.txt", "r");
    char line[256];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("\n");
    fclose(file);
}


int main(){

    start();
    srand(time(NULL));

    int count=0;
    int goal=10;
    int user_input;
    int user_point=0;

    while(user_point < goal){

        int set_random;
        set_random = rand();

        count++;
        printf("[STAGE %d] (point*%d) - Your Point : %d\n", count, count*count, user_point);

        printf("Guess random number (odd : 1, even : 0) : ");
        scanf("%d", &user_input);
        
        if(user_input < 0 || user_input > 1){
            printf("wrong input\n");
            break;
        }

        _sleep(500);
        printf("\n> Your Guess is %s\n", (user_input==0?"EVEN":"ODD"));
        _sleep(1500);
        printf("> hmmm......\n");
        _sleep(1500);
        printf("> Computer's Choice is : %d (%d)\n", set_random%2, set_random);
        _sleep(1000);

        if(user_input==set_random%2){
            printf("fd");
        }
        else{
            wrong();
        }

        printf("\nPress 'ENTER' to next stage...\n");
        
        getchar(); 
        getchar(); 
        

    }

}
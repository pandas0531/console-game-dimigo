#include <stdio.h>

int main(){
    FILE *file = fopen("number_list.txt", "r");
    char line[512];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }
    printf("\n");
    fclose(file);
}
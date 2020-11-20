#include <stdio.h>
#include <string.h>
 
int main(int argc, char **argv) {
    FILE *inFile;
    FILE *outFile;
    char before[20];
    char after[20];
    char line[1024];

    strcpy(before, "🐶" );
    strcpy(after, "if" );

   inFile = fopen(argv[1], "r");
    if (inFile == NULL) {
        return -1;
    }
    outFile = fopen(argv[2], "w");
    if (outFile == NULL) {
        fclose(inFile);
        return -1;
    }
 
    while(fgets(line, 1024, inFile) != NULL) {
        char* find = line;
        char* replace;

        do {
            replace = strstr(find, before);
            if (replace == NULL) {
                fprintf(outFile, "%s", find);
                break;
            } else {
                *replace = '\0';
                fprintf(outFile, "%s", find);
                fprintf(outFile, "%s", after);
                find = replace + strlen(before);
            }
        } while(*find);
    }

    fclose(inFile);
    fclose(outFile);
    return 0;
}

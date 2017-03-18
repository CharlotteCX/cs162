#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char filename[100];
    int ch;
    int linecount = 0, wordcount = 0, charcount = 0;
    int counter = 1;
    
    if(argc != 2) {
        printf("Help: %s filename", argv[0]);
    } else {
        strncpy(filename, argv[1], 100);
        fp = fopen(filename , "r");
        
        if(!fp) {
            perror("Input file opening failed");
            exit(1);
        }
        while((ch = fgetc(fp)) != EOF) {
            charcount++;
            
            if(isspace(ch)) {
                counter = 1;
                if(ch =='\n')
                    linecount++;
                
            }else{
                wordcount += counter;
                counter = 0;
            }
        }
    }
    printf("Line: %d, Word: %d, Character: %d.", linecount, wordcount, charcount);
    return 0;
}

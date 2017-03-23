#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    char flag;
    int appendFlag = 0;
    int i;
    char c;

    // Handle command-line flags
    while ((flag = getopt(argc, argv, "a")) != -1) {
        switch (flag) {
            case 'a':
                appendFlag = 1;
                break;
            default:
                return 1;
        }
    }

    // Increment args
    argc -= optind;
    argv += optind;

    // Store pointers to each file in files[]
    FILE *files[argc];
    for (i = 0; i < argc; i++) {
        files[i] = fopen(argv[i], (appendFlag ? "a" : "w"));
    }

    // Scan stdin char-by-char and output to files and stdout
    while (fscanf(stdin, "%c", &c) == 1) {
        for (i = 0; i < argc; i++) {
            fprintf(files[i], "%c", c);
        }
        fprintf(stdout, "%c", c);
    }

    // Output newline to files and stdout before closing
    for (i = 0; i < argc; i++) {
        fprintf(files[i], "\n");
        fclose(files[i]);
    }
    fprintf(stdout, "\n"); 

    return 0;
}

/*
Questions:
3) Handling multiple files was hard, and it took a while to figure out I could use optind to increment the number of arguments.
4) The professional code handles basically any error. My code just exits when it encourters an unknown flag.
*/

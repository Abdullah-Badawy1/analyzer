#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void print_usage(const char *program_name) {
    fprintf(stderr, "Usage: %s [-d] [-h] <filename1> [filename2 ...]\n", program_name);
    fprintf(stderr, "  -d: Display the contents of the files\n");
    fprintf(stderr, "  -h: Show this help message\n");
}

void print_help(const char *program_name) {
    printf("Usage: %s [-d] [-h] <filename1> [filename2 ...]\n", program_name);
    printf("Options:\n");
    printf("  -d    Display the contents of the files after showing the analysis\n");
    printf("  -h    Show this help message\n");
    printf("\n");
    printf("Description:\n");
    printf("  This program analyzes text files and provides statistics on the number\n");
    printf("  of lines, words, and characters in each file. If the -d option is used,\n");
    printf("  the contents of the files will also be displayed after the analysis.\n");
}

void analyze_file(const char *filename, int display_content) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int lines = 0, words = 0, characters = 0;
    char ch;
    int in_word = 0;

    
    fseek(file, 0, SEEK_SET);
    while ((ch = fgetc(file)) != EOF) {
        characters++;
        if (ch == '\n') {
            lines++;
        }
        if (isspace(ch)) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            words++;
        }
    }

    printf("\nFile: %s\n", filename);
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);

    if (display_content) {
        fseek(file, 0, SEEK_SET);
        printf("\nContent of the file:\n");
		printf("====================================================>\n");
        while ((ch = fgetc(file)) != EOF) {
            putchar(ch);
        }
        printf("\n");
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    int display_content = 0;
    int show_help = 0;
    int start_index = 1;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0) {
            display_content = 1;
            start_index++;
        } else if (strcmp(argv[i], "-h") == 0) {
            show_help = 1;
            break;
        } else if (argv[i][0] == '-') {
            fprintf(stderr, "Unknown option: %s\n", argv[i]);
            print_usage(argv[0]);
            return 1;
        } else {
            break;
        }
    }

    if (show_help) {
        print_help(argv[0]);
        return 0;
    }

    if (start_index >= argc) {
        print_usage(argv[0]);
        return 1;
    }

    for (int i = start_index; i < argc; i++) {
        analyze_file(argv[i], display_content);
    }

    return 0;
}


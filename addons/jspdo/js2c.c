#include <stdio.h>
/**
   A quick hack to dump JavaScript input from stdin
   to a C character array.
*/
int main(int argc, char const ** argv )
{
    int ch = 0;
    int col = 0;
    if( 2 != argc ) {
        fprintf(stderr, "Usage: %s dataName\n", argv[0]);
    }
    printf("static const char %s[] = {\n", argv[1]);
    while(EOF != (ch = getchar())) {
        printf("%d, ",ch);
        if( 0 == (++col%80) ) {
            putchar('\n');
            col = 0;
        }
    }
    puts("\n0};");
    return 0;
}

#ifndef SCAN_DATA
#define SCAN_DATA

int size_of_file(FILE *fp);
char *make_array(FILE *fp, int n);
int num_of_lines(char *text, int n);
char **point_array(char *text, int n, int k);

#endif

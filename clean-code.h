#ifndef CLEAN_CODE_H
#define CLEAN_CODE_H

unsigned long int cleancode(char *code, unsigned long int size);

unsigned long int wordcount(char *code, unsigned long int size);

void chartoword(char *code, unsigned long int size, char **words);

void measure_words_length(char *code, unsigned long int sizem, int *words_length);

#endif //CLEAN_CODE_H

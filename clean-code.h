#ifndef CLEAN_CODE_H
#define CLEAN_CODE_H

unsigned long int cleancode(char *code, unsigned long int size);

unsigned long int wordcount(char *code, unsigned long int size);

void loadwords(char *code, unsigned long int size, char ***words);

unsigned long int countlines(char *code, unsigned long int size);

void countwords(char *code, unsigned long int size, int *words_in_line);

void measure_words_length(char *code, unsigned long int size, int *words_length);

#endif //CLEAN_CODE_H

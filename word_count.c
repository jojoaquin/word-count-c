#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORD 1000

typedef struct {
  char word[100];
  int count;
} WordCount;

int is_word_char(char c);
void clean_file(FILE *in, FILE *out);
void count_word(FILE *in);
void sort_by_count(WordCount *list, int total);

int main() {
  FILE *in = fopen("comment_sample.txt", "r");
  FILE *out = fopen("cleaned.txt", "w");

  if (!in || !out) {
    perror("\nerr: file can't open 'comment_sample.txt' & 'cleaned.txt'");
    return 1;
  }

  clean_file(in, out);

  FILE *cleaned = fopen("cleaned.txt", "r");
  if (!cleaned) {
    perror("\n err: file can't open 'cleaned.txt'");
    return 1;
  }

  count_word(cleaned);
  fclose(cleaned);

  return 0;
}

int is_word_char(char c) { return isalnum(c) || c == ' '; };

void clean_file(FILE *in, FILE *out) {
  char line[1024];
  while (fgets(line, sizeof(line), in)) {
    for (int i = 0; line[i] != '\0'; i++) {
      char c = tolower(line[i]);

      if (is_word_char(c)) {
        fputc(c, out);
      }
    }
    fputc('\n', out);
  }

  fclose(in);
  fclose(out);
  printf("\ninfo: success cleaned -> 'cleaned.txt'\n");
}

void sort_by_count(WordCount *list, int total) {
  for (int i = 0; i < total - 1; i++) {
    for (int j = i + 1; j < total; j++) {
      if (list[j].count > list[i].count) {
        WordCount temp = list[i];
        list[i] = list[j];
        list[j] = temp;
      }
    }
  }
}

void count_word(FILE *in) {
  WordCount wordList[MAX_WORD];
  int totalWords = 0;
  char word[100];

  while (fscanf(in, "%s", word) == 1) {
    int found = 0;

    for (int i = 0; i < totalWords; i++) {
      if (strcmp(wordList[i].word, word) == 0) {
        wordList[i].count++;
        found = 1;
        break;
      }
    }

    if (!found && totalWords < MAX_WORD) {
      strcpy(wordList[totalWords].word, word);
      wordList[totalWords].count = 1;
      totalWords++;
    }
  }

  sort_by_count(wordList, totalWords);

  FILE *out = fopen("result.txt", "w");
  if (!out) {
    perror("\nerr: failed to write -> results.txt");
    return;
  }

  fprintf(out, "=== Number of word occurrences ===\n");
  for (int i = 0; i < totalWords; i++) {
    fprintf(out, "%s: %d\n", wordList[i].word, wordList[i].count);
  }

  fclose(out);
  printf("\ninfo: success write -> result.txt'");
}
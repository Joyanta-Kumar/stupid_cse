#include <stdio.h>
#define separator ','

int main(int argc, char **argv) {
  char* fileName = "";
  FILE *inFile = NULL;
  FILE *outFile = NULL;
  inFile = fopen("pages.csv", "r");
  outFile = fopen("topics.md", "a");

  if (inFile == NULL || outFile == NULL) {
    printf("Error while opening the inFile.\n");
    return 0;
  }

  char ch_code;
  char buffer[50];
  int index = 0;
  int columns = 0;

  fprintf(outFile, "\n");
  // Headings
  do {
    ch_code = fgetc(inFile);
    if (ch_code == separator || ch_code == '\n') {
      columns += 1;
      buffer[index] = '\0';
      index = -1;
      fprintf(outFile, "| %s ", buffer);
      if (ch_code == '\n') {
        fprintf(outFile, " |\n");
      }
    }
    else {
      buffer[index] = ch_code;
    }
    index++;
  } while (ch_code != '\n');

  // ---

  for (int i = 0; i < columns; i++) {
    fprintf(outFile, "| --- ");
  }
  fprintf(outFile, "|\n");

  // ---
  
  // Cells
  do {
    ch_code = fgetc(inFile);
    if (ch_code == separator || ch_code == '\n') {
      buffer[index] = '\0';
      index = -1;
      fprintf(outFile, "| %s ", buffer);
      if (ch_code == '\n') {
        fprintf(outFile, " |\n");
      }
    }
    else {
      buffer[index] = ch_code;
    }
    index++;
  } while (ch_code != EOF);
  
  fprintf(outFile, "\n");

  fclose(inFile);
  fclose(outFile);
  return 0;
}

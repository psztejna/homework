//lab 9 zad 14

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 80
#define MAX_RECORDS 10

typedef struct osobaLepsza{
  int wiek;
  int pensja;
}osobaLepsza;


int main(){

  osobaLepsza base[MAX_RECORDS];
  FILE * infile;
  char firstName[MAX_LEN];
  char lastName[MAX_LEN];
  char bestSalaryPerson[MAX_LEN];
  char youngestPerson[MAX_LEN];
  int recordNo = 0;
  int youngestAge = 0;
  int bestSalaryIndex = 0;
  int youngestAgeIndex = 0;


  infile = fopen("Dane.txt", "r");
  if (infile == NULL)
    {
      printf("Unable to open file Dane.txt\n");
      exit -1;
    }
  // Scan first line with number of records
  if (fscanf(infile, "%d", &recordNo))
    {
      printf("Number of records in file: %d\n", recordNo);
    }
  int currentRecord = 0;
  while ((!feof(infile)) && (currentRecord <= MAX_RECORDS-1)) {

    fscanf(infile, "%s %s %d %d\n", firstName, lastName, &base[currentRecord].wiek, &base[currentRecord].pensja);
    printf("name: %s %s wiek: %d pensja: %d\n", firstName, lastName, base[currentRecord].wiek, base[currentRecord].pensja);
    /* This fragment will capture name of best Salary person (string) and array index of the person */
    if (base[currentRecord].pensja >= base[bestSalaryIndex].pensja)
      {
	bestSalaryIndex = currentRecord;
	/* Clear entry from previous entry before overwriting */
	memset(bestSalaryPerson, 0, MAX_LEN);
        strncpy(bestSalaryPerson, firstName, strlen(firstName));
	strncpy(bestSalaryPerson + strlen(firstName), " ", 1);
	strncpy((bestSalaryPerson+ strlen(firstName) + 1), lastName, strlen(lastName));
      }
    /* This fragment compares age of youngest person with current Record and updates statistics if needed, also storing name of this person */
    if (base[currentRecord].wiek <= base[youngestAgeIndex].wiek)
      {
	youngestAgeIndex = currentRecord;
	/* Clear structure from previous entry before overrighting */
	memset(youngestPerson, 0, MAX_LEN);
	strncpy(youngestPerson, firstName, strlen(firstName));
	strncpy(youngestPerson + strlen(firstName), " ", 1);
	strncpy((youngestPerson+strlen(firstName)+1), lastName, strlen(lastName));

      }
    currentRecord++;
  }
  printf("Najlepiej zarabiajaca osoba to:\n %s, lat %d\n",
	 bestSalaryPerson, base[bestSalaryIndex].wiek);
  printf("Najmlodsza osoba jest:\n %s\n", youngestPerson);

  fclose(infile);
  return 0;

}

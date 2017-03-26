// wk22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

struct athlete
{
	char name[60];
	int age;
	char country[55];
	int year;
	char sport[30];
	int noG;
	int noS;
	int noB;
	int total;
	struct athlete *next;
};

struct athlete *first;
int readFile(char *FileName);
void findAthlete(int inyear, char *insport);

int main(int argc, char *argv[])
{
	char FileName[] = "athletes.txt";
	int inyear = atoi(argv[1]);
	char *insport = argv[2];
	
	
	struct athlete *current;

	if (!readFile(FileName))
	{
		printf("File could not be opened!\n");
		return 0;
	}

	current = first;
	printf("Name\t Age\t Country\t #Gold\t #Silver\t #Bronze\t #Total\n\n");
        findAthlete(inyear, insport);
		current = current->next;
	
		return 0;
}


int readFile(char *FileName)
{
	char line[400];
	FILE *fptr = fopen(FileName, "r");
	char *token;
	char delim[2] = "\t";

	struct athlete *last = NULL;
	struct athlete *current = NULL;

	if (fptr == NULL)
	{
		printf("Error opening file!\n");
		return 0;
	}


	while (!feof(fptr))
	{

		fgets(line, 200, fptr);

		if (first == NULL)
		{
			first = (struct athlete *)malloc(sizeof(struct athlete));
			first->next = NULL;
			current = first;
		}
		else
		{
			last = (struct athlete *)malloc(sizeof(struct athlete));
			current->next = last;
			current = last;
			current->next = NULL;
		}
		if ((token = strtok(line, delim)) != NULL) strcpy(current->name, token);
		if ((token = strtok(NULL, delim)) != NULL) current->age = atoi(token);
		if ((token = strtok(NULL, delim)) != NULL) strcpy(current->country, token);
		if ((token = strtok(NULL, delim)) != NULL) current->year = atoi(token);
		if ((token = strtok(NULL, delim)) != NULL) strcpy(current->sport, token);
		if ((token = strtok(NULL, delim)) != NULL) current->noG = atoi(token);
		if ((token = strtok(NULL, delim)) != NULL) current->noS = atoi(token);
		if ((token = strtok(NULL, delim)) != NULL) current->noB = atoi(token);
		if ((token = strtok(NULL, delim)) != NULL) current->total = atoi(token);
	}
	fclose(fptr);

	return 1;
}

void findAthlete(int inyear, char *insport)
{
	struct athlete *current;

	current = first;

	while (current != NULL)
	{
		if (current->year == inyear && strcmp(current->sport, insport) == 0)
		{
			printf("%20s\t\t%d\t%30s\t\t%d\t%d\t%d\t%d\t\n", current->name, current->age, current->country, current->noG, current->noS, current->noB, current->total);
			current = current->next;
		}
		
		else
		{
			current = current->next;
		}
		
	}
}

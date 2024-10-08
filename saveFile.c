#include <stdio.h>
#include <string.h>
#define MAX_LINE_LENGTH 100

void writeDetails(const char *filename) {
	FILE *file = fopen(filename, "w");
	if (file == NULL) {
		printf("Error opening file for writing.\n");
		return;
	}
	char name[MAX_LINE_LENGTH], age[MAX_LINE_LENGTH],
	email[MAX_LINE_LENGTH];
	printf("Enter your name: ");
	fgets(name, MAX_LINE_LENGTH, stdin);
	printf("Enter your age: ");
	fgets(age, MAX_LINE_LENGTH, stdin);
	printf("Enter your email: ");
	fgets(email, MAX_LINE_LENGTH, stdin);
	fprintf(file, "%s", name);
	fprintf(file, "%s", age);
	fprintf(file, "%s", email);
	fclose(file);
}

void printMatchingLines(const char *file1, const char *file2) {
	FILE *f1 = fopen(file1, "r");
	FILE *f2 = fopen(file2, "r");
	if (f1 == NULL || f2 == NULL) {
		printf("Error opening files for reading.\n");
		return;
	}
	char line1[MAX_LINE_LENGTH], line2[MAX_LINE_LENGTH];
	while (fgets(line1, MAX_LINE_LENGTH, f1) != NULL) {
		rewind(f2);
		while (fgets(line2, MAX_LINE_LENGTH, f2) != NULL) {
			if (strcmp(line1, line2) == 0) {
				printf("Matching line: %s", line1);
			}
		}
	}
	fclose(f1);
	fclose(f2);
}

int main() {
	printf("--------------------------------------------------------------------\n");
	printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
	printf("--------------------------------------------------------------------\n");
	writeDetails("my_details.txt");
	writeDetails("friends_details.txt");
	printf("\nMatching lines in both files:\n");
	printMatchingLines("my_details.txt", "friends_details.txt");
	return 0;
}
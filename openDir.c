#include <stdio.h>
#include <dirent.h>

int main() {
	printf("--------------------------------------------------------------------\n");
	printf("Name: Sarthak\tSection: A2\tRoll No: 58\n");
	printf("--------------------------------------------------------------------\n");
	struct dirent *de;
	DIR *dr = opendir("C:\\Users\\DELL\\Documents\\GuyRender");
	if (dr == NULL) {
		printf("Could not open current directory");
		return 0;
	}
	while ((de = readdir(dr)) != NULL)
		printf("%s\n", de->d_name);
	closedir(dr);
	return 0;
}
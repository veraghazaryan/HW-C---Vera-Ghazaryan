#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char name[30];
	char surname[30];
	int id;
	float grade;
} Student;

// Add a new student
Student* add_student(Student *arr, int *count) {
	arr = (Student*)realloc(arr, (*count + 1) * sizeof(Student));
	if (!arr) {
		printf("Memory allocation failed!\n");
		exit(1);
	}

	printf("Enter name: ");
	scanf("%s", arr[*count].name);
	printf("Enter surname: ");
	scanf("%s", arr[*count].surname);
	printf("Enter ID: ");
	scanf("%d", &arr[*count].id);
	printf("Enter grade: ");
	scanf("%f", &arr[*count].grade);

	(*count)++;
	return arr;
}

// Remove student by ID
Student* remove_student(Student *arr, int *count) {
	int id, i, found = 0;
	printf("Enter ID to remove: ");
	scanf("%d", &id);

	for (i = 0; i < *count; i++) {
		if (arr[i].id == id) {
			found = 1;
			break;
		}
	}
	if (!found) {
		printf("Student not found!\n");
		return arr;
	}

	for (int j = i; j < *count - 1; j++)
		arr[j] = arr[j + 1];

	(*count)--;
	arr = (Student*)realloc(arr, (*count) * sizeof(Student));
	printf("Student removed.\n");
	return arr;
}

// Search student by ID
void search_student(Student *arr, int count) {
	int id, found = 0;
	printf("Enter ID to search: ");
	scanf("%d", &id);

	for (int i = 0; i < count; i++) {
		if (arr[i].id == id) {
			found = 1;
			printf("Name: %s, Surname: %s, ID: %d, Grade: %.2f\n",
				arr[i].name, arr[i].surname, arr[i].id, arr[i].grade);
			break;
		}
	}
	if (!found)
		printf("Student not found!\n");
}

// Display all students
void display_students(Student *arr, int count) {
	if (count == 0) {
		printf("No students.\n");
		return;
	}
	for (int i = 0; i < count; i++)
		printf("%s %s, ID: %d, Grade: %.2f\n",
			arr[i].name, arr[i].surname, arr[i].id, arr[i].grade);
}

// Display average grade
void average_grade(Student *arr, int count) {
	if (count == 0) {
		printf("No students to calculate average.\n");
		return;
	}
	float sum = 0;
	for (int i = 0; i < count; i++)
		sum += arr[i].grade;
	printf("Average grade: %.2f\n", sum / count);
}

// Save students to file
void save_to_file(Student *arr, int count) {
	FILE *f = fopen("group_details.csv", "w");
	if (!f) {
		printf("Cannot open file.\n");
		return;
	}
	for (int i = 0; i < count; i++)
		fprintf(f, "%s,%s,%d,%.2f\n",
			arr[i].name, arr[i].surname, arr[i].id, arr[i].grade);
	fclose(f);
	printf("Saved to group_details.csv\n");
}

// Read students from file
Student* read_from_file(Student *arr, int *count) {
	FILE *f = fopen("group_details.csv", "r");
	if (!f) {
		printf("File not found.\n");
		return arr;
	}
	char line[100];
	while (fgets(line, sizeof(line), f)) {
		arr = (Student*)realloc(arr, (*count + 1) * sizeof(Student));
		if (!arr) exit(1);

		sscanf(line, "%[^,],%[^,],%d,%f",
			arr[*count].name, arr[*count].surname, &arr[*count].id, &arr[*count].grade);
		(*count)++;
	}
	fclose(f);
	printf("Loaded from group_details.csv\n");
	return arr;
}

int main() {
	Student *arr = NULL;
	int count = 0, choice;

	do {
		printf("\n1.Add 2.Remove 3.Search 4.Display 5.Average 6.Save 7.Load 8.Exit\n");
		printf("Enter choice: ");
		scanf("%d", &choice);

		switch(choice) {
			case 1: arr = add_student(arr, &count); break;
			case 2: arr = remove_student(arr, &count); break;
			case 3: search_student(arr, count); break;
			case 4: display_students(arr, count); break;
			case 5: average_grade(arr, count); break;
			case 6: save_to_file(arr, count); break;
			case 7: arr = read_from_file(arr, &count); break;
			case 8: break;
			default: printf("Invalid choice!\n");
		}
	} while(choice != 8);

	free(arr); // free allocated memory
	return 0;
}

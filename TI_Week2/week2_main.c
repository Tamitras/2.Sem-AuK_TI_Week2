#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

typedef struct _student_
{
	char* Id;
	// char* FirstName;
	char* LastName;
	// int   AccountNumber;
	
	// Another option is to store the size information in the data itself.
	int Index;
}student;

/// <summary>
/// Initialize Multi(MxN) Array to write pointer in pointer
/// </summary>
/// <param name="array"></param>
/// <param name="arrLength"></param>
/// <param name="elementLength"></param>
void initMultiArray(student** arr, int arrLength, int elementLength)
{
	// dynamically allocate memory of size `n` for each row
	for (int i = 0; i < arrLength; i++)
	{
		//arr[i] = (int*)calloc(elementLength, sizeof(char));
		arr[i] = malloc(elementLength * sizeof(student));
		arr[i]->Index = -1; // -1 default value
	}
}


student* StudentAlloc(char* info)
{
	int counter = 0;
	int bufferLength = 255;

	// Substrings used to "save" the info temporary
	char** subStrings = malloc(bufferLength * sizeof(char*));
	char* token;

	// Allocate new space of memory in the heap for the new student
	student* _newStudent = malloc(sizeof(student));
	_newStudent->Id = malloc(10 * sizeof(char));
	_newStudent->LastName = malloc(20 * sizeof(char));

	// Splits the buffer by " "
	token = strtok(info, " ");

	while (token)
	{
		subStrings[counter++] = token;
		token = strtok(NULL, " "); // Null means, the function strtok starts to split from the beginning position it remembers
	}

	// strcpy emitted data to new student
	strcpy(_newStudent->Id, subStrings[0]);
	strcpy(_newStudent->LastName, subStrings[1]);

	return _newStudent;
}

void StudentFree(student* info)
{
	free(info);
}

int StudentEquals(student* s1, student* s2)
{
	int equal = 0;
	
	// == 0 --> euqal
	if (strcmp(s1->Id, s2->Id) == 0 
		&& strcmp(s1->LastName, s2->LastName) == 0)
	{
		equal = 1;
	}

	return equal;
}

student* deepCopy(student* s)
{
	// allocate a new block in memory for new pointer
	student* deepStudent = malloc(sizeof(student));
	deepStudent->Id = malloc(s->Id, sizeof(char*));
	deepStudent->LastName = malloc(s->LastName, sizeof(char*));

	deepStudent->Index = s->Index;
	strcpy(deepStudent->Id, s->Id);
	strcpy(deepStudent->LastName, s->LastName);

	return deepStudent;
}

student* shallowCopy(student* s)
{
	student* shallowStudent = s;

	return shallowStudent;
}

int GetArrayLength(student** students)
{
	if (students[0]->Index == -1)
	{
		return 0;
	}

	int length = 0;
	student* current = students[0];

	while (current->Index >= 0)
	{
		length = current->Index + 1;

		// next
		current = students[current->Index + 1];
	}

	return length;
}

int contains(student** students, student* _studentKey)
{
	int length = GetArrayLength(students);

	for (int i = 0; i < length; i++)
	{
		if (StudentEquals(students[i], _studentKey) == 1) // equal
		{
			return 1;
		}
	}

	return 0;
}


void ReadFromSource(char* path, student** students)
{
	// Nullpointer
	FILE* file = NULL;

	int bufferLength = 255;
	char* buffer = malloc(bufferLength * sizeof(char));

	// Open file
	file = fopen(path, "r");

	if (!file)
	{
		// Exit application with error message
		perror("File does not exist. (Reverse)");
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, bufferLength, file)) // Read file, line by line
	{
		// Emit arraylength
		int length = GetArrayLength(students);

		// Creates a new student - add to array
		student* _student = StudentAlloc(buffer);

		// Check if an element of students contains _studentKey --> _studentKey= substrings[0]
		if (!contains(students, _student))
		{
			// Add student to list
			_student->Index = length;
			students[length] = _student;
		}
		else
		{
			printf("Redundantes Element gefunden - %s %s", _student->Id, _student->LastName);
			continue;
		}
	}
}


int main(int argc, char* argv[])
{
	// Enable to attach with debugger
	//printf("Double_Num\n");
	//Sleep(8000);

	// variables for args
	const* path = malloc(255 * sizeof(char));
	int length = 100; // max 100 students

	if (argc > 2)
	{
		exit(EXIT_FAILURE);
	}
	else if (argc == 2) // Applicationname and filepath
	{
		path = argv[1];
	}

	// Create array of student-pointers
	student** students = malloc(length * sizeof(student));

	// Init Multi-Array
	initMultiArray(students, length, sizeof(student));

	//
	ReadFromSource(path, students);

	// Exit application with success-code
	exit(EXIT_SUCCESS);
}


/*
* Vorteile:
* - Einfacher Aufbau
* - Schneller Zugriff durch Index (sofern man den Index kennt) O(1)
*
* Nachteile:
* - Umso größer das Array mit Studenten, desto mehr Zeit wird benötigt um einen spezifischen Studenten zu finden, wenn man den Index nicht kennt.
* Suchen, Einfügen und Löschen hat dementsprechen O(n)
* 
* Optimierung:
* - Man könnte das Array nach dem Einlesen aus der Text-Datei,sortieren
* - CountingSort
* - RadixSort
* um somit das Suchen eines bestimmmten Studenten zu optimieren.
* Genauer: Nachnamen mit dem Buchstaben 'A' befinden sich zwischen der Stelle 0 und 15 im Array,
* so könnte, wenn man nach einem Nachnamen, welcher mmit 'B' beginnt, 15 Stellen überspringen und somit diese Iteration einsparen.
* 
* 
* oder einen Hashtable verwenden Average O(1) - Worst O(n)
* ...
*/
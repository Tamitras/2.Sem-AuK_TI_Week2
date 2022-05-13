//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <math.h>
//#include <string.h>
//
//// Sorting type
//typedef enum {
//	Student,
//}Type;
//
//typedef struct _student_
//{
//	char* Id;
//	//char* FirstName;
//	char* LastName;
//	//int   AccountNumber;
//	struct _student_* next;
//}student;
//
//typedef struct _Student_p_
//{
//	student* students; // PointerArray of type student
//} Student_p;
//
//// Global Variable
//Student_p* _StudentHead;
//
//Student_p StudentAlloc(char* info)
//{
//
//}
//
//void StudentFree(Student_p info)
//{
//
//}
//
//int StudentEquals(Student_p s1, Student_p s2)
//{
//	int equal = 0;
//
//	//if (s1.)
//	//{
//
//	//}
//
//
//	return equal;
//}
//
//Student_p deepCopy(Student_p s)
//{
//
//}
//
//Student_p shallowCopy(Student_p s)
//{
//
//}
//
//int GetListLength(void* head, Type type)
//{
//	if (!head)
//		return 0;
//
//	int length = 0;
//	student* _student = head;
//
//	switch (type)
//	{
//	case Student:
//		_student = (student*)head;
//		break;
//
//	default:
//		printf("Cant emit list length");
//		break;
//	}
//
//	while (_student)
//	{
//		length++;
//		_student = _student->next;
//	}
//
//	return length;
//}
//
//
///// <summary>
///// Add to the end
///// </summary>
///// <param name="_head"></param>
///// <param name="val"></param>
//void AddToList(Student_p* _main, student* next)
//{
//	student* _head = _main->students;
//
//	if (_head == NULL) // List not allocated
//	{
//		_head = malloc(sizeof(student));
//		_head->Id = "-1";
//	}
//
//	student* _current = _head;
//
//	if (_current->Id == "-1")
//	{
//		(next)->next = NULL;
//		//(next)->prev = NULL;
//		_head = next;
//		_main->students = _head;
//	}
//	else
//	{
//		while (_current->next != NULL) {
//			_current = _current->next;
//		}
//
//		_current->next = next;
//		//(next)->prev = _current;
//		(next)->next = NULL;
//	}
//}
//
//int contains(Student_p* _main, char* key)
//{
//	student* _head = _main->students;
//
//	// emit the length of the student array
//	int length = GetListLength(_head, Student);
//
//	student* current = _head;
//
//	if (current != NULL && current->Id >= 0)
//	{
//		for (int i = 0; i < length; i++)
//		{
//			while (current)
//			{
//				// !!!
//				// NOT WORKING
//				// !!!
//				//if (current->Id == key)
//				//	return 1;
//
//				if (strcmp(current->Id, key) == 0)
//					return 1;
//
//				current = current->next;
//			}
//		}
//	}
//
//	return 0;
//}
//
//
///// <summary>
///// Initialize Multi(MxN) Array for write pointer in pointer
///// </summary>
///// <param name="array"></param>
///// <param name="arrayLength"></param>
///// <param name="elementLength"></param>
//void initMultiArray(char** array, int arrayLength, int elementLength)
//{
//	// dynamically allocate memory of size `n` for each row
//	for (int i = 0; i < arrayLength; i++)
//		array[i] = (int*)calloc(elementLength, sizeof(char));
//}
//
//void PrintList(Student_p* student_p)
//{
//	if (!student_p->students)
//		return;
//
//	student* _current = student_p->students;;
//
//	while (_current)
//	{
//		printf("ID: (%s) - LastName:%s", _current->Id, _current->LastName);
//		_current = _current->next;
//	}
//}
//
//void ReadFromSource(char* path)
//{
//	// Nullpointer
//	FILE* file = NULL;
//
//	int counter = 0;
//	int bufferLength = 255;
//
//	// Substrings needed to "save" the info temporary
//	char** subStrings = malloc(bufferLength * sizeof(char*));
//	char* buffer = malloc(bufferLength * sizeof(char));
//	char* token;
//
//	// Init MultiArray
//	initMultiArray(subStrings, 100, bufferLength);
//
//	// Open file
//	file = fopen(path, "r");
//
//	if (!file)
//	{
//		// Exit application with error message
//		perror("File does not exist. (Reverse)");
//		exit(EXIT_FAILURE);
//	}
//
//	while (fgets(buffer, bufferLength, file)) // Read file, line by line
//	{
//		// Reset counter
//		counter = 0;
//
//		// Splits the buffer by " "
//		token = strtok(buffer, " ");
//
//		while (token)
//		{
//			subStrings[counter++] = token;
//			token = strtok(NULL, " "); // Null means, the function strtok starts to split from the beginning position it remembers
//		}
//
//		if (!contains(_StudentHead, subStrings[0]))
//		{
//			// Allocate new space of memory in the heap for the new student
//			student* _newStudent = malloc(sizeof(student));
//			_newStudent->Id = malloc(10 * sizeof(char));
//			_newStudent->LastName = malloc(20 * sizeof(char));
//
//			// strcpy emitted data to new student
//			strcpy(_newStudent->Id, subStrings[0]);
//			strcpy(_newStudent->LastName, subStrings[1]);
//
//			// pass _head of list and element(student) address to "AddToList" function 
//			AddToList(_StudentHead, _newStudent);
//		}
//		else
//		{
//			printf("Redundantes Element gefunden - %s %s", subStrings[0], subStrings[1]);
//			continue;
//		}
//	}
//	PrintList(_StudentHead);
//}
//
//Student_p* CreateList() {
//	Student_p* mainPtr = malloc(sizeof(mainPtr));
//
//	mainPtr->students = NULL; // new end of list
//	return mainPtr;
//}
//
//int main(int argc, char* argv[])
//{
//	// Enable to attach with debugger
//	//printf("Double_Num\n");
//	//Sleep(8000);
//
//	// variables for args
//	const* path = malloc(255 * sizeof(char));
//
//	if (argc > 2)
//	{
//		exit(EXIT_FAILURE);
//	}
//	else if (argc == 2) // Applicationname and filepath
//	{
//		path = argv[1];
//	}
//
//	// Create Head
//	_StudentHead = CreateList();
//
//	//
//	ReadFromSource(path);
//
//	// Exit application with success-code
//	exit(EXIT_SUCCESS);
//}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	char letter;
	struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head)
{
	int count = 0;
	while (head) {
		count++;
		head = head->next;
	}
	return count;
}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
	int len = length(head);
	char* string = malloc(len + 1);
	int i = 0;
	while (head) {
		string[i++] = head->letter;
		head = head->next;
	}
	string[i] = '\0';
	return string;
	

	
}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c)
{
	
	node* new = malloc(sizeof(node));
	new->letter = c;
	new->next = *pHead;
	node* temp = (node*)malloc(sizeof(node));
	temp->letter = c;
	temp->next = NULL;
	if (*pHead == NULL)
		*pHead = temp;
	else
	{
		new = *pHead;
		while (new->next != NULL)
			new = new->next;
		new->next = temp;
	}
	return *pHead;
}



// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
	node* curr = *pHead;
	while (curr) {
		node* next = curr->next;
		free(curr);
		curr = next;
	}
	*pHead = NULL;

}


int main(void)
{
	int i, strLen, numInputs;
	node* head = NULL;
	char* str;
	char c;
	FILE* inFile = fopen("input.txt", "r");
	fscanf(inFile, " %d\n", &numInputs);
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &strLen);
		for (i = 0; i < strLen; i++)
		{
			fscanf(inFile, " %c", &c);
			insertChar(&head, c);
		}
		str = toCString(head);
		printf("String is : %s\n", str);
		free(str);
		deleteList(&head);
		if (head != NULL)
		{
			printf("deleteList is not correct!");
			break;
		}
	}
	fclose(inFile);
}
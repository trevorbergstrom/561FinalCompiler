#include "TypeCheck.h"

int main() {
	char* className1 = "C1";
	ClassNode* n1 = new ClassNode(className1);

	ClassTable* myTable = new ClassTable();
	
	if(myTable->checkExists(n1)) {
		printf("Can Add Class");
	} else {
		printf("Can not AddClass");
	}

	myTable->append(n1);
	
	if(myTable->checkExists(n1)) {
		printf("Class exists");
	} else {
		printf("Class does not exist");
	}
}

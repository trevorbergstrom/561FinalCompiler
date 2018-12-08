#include <stdio.h>
#include <stdlib.h>
#include "Builtins.h"
void quackmain();
int main(int argc, char** argv) {
	quackmain();
	printf("Terminated Sucessfully");
	exit(0);
}

struct class_DataPt_struct;
typedef struct class_DataPt_struct* class_DataPt;

typedef struct obj_DataPt_struct { 
	class_DataPt clazz;
	obj_Int  f;
} * obj_DataPt;

struct class_DataPt_struct the_class_DataPt_struct;

struct class_DataPt_struct {
	obj_DataPt(*constructor) ();
	obj_Nothing(*integerp) ();
	obj_DataPt (*PRINT) (obj_DataPt);
obj_Boolean (*EQUALS) (obj_Obj, obj_Obj);
};

extern class_DataPt the_class_DataPt;


/* Class Constructor */
obj_DataPt new_DataPt() {
	obj_DataPt  new_thing = (obj_DataPt) malloc(sizeof(struct obj_DataPt_struct));
	new_thing->clazz = the_class_DataPt;
	new_thing->f = int_literal(0);
	return new_thing;
}


/* Class Methods */
obj_DataPt DataPt_method_integerp(obj_DataPt this) {
	obj_Int x;
	x = int_literal(7);
	x->clazz->PRINT((obj_Obj) x);
}

/* Class Print Method */
obj_DataPt DataPt_method_PRINT(obj_DataPt this) {	obj_String lparen = str_literal("(");
	lparen->clazz->PRINT(lparen);
	this->f->clazz->PRINT((obj_Obj) this->f);
	obj_String rparen = str_literal(")");
	rparen->clazz->PRINT(rparen);
	return this;
}
struct class_DataPt_struct the_class_DataPt_struct = { 
	new_DataPt,
	DataPt_method_integerp,
	DataPt_method_PRINT,
	Obj_method_EQUALS};

class_DataPt the_class_DataPt = &the_class_DataPt_struct;

struct class_C2_struct;
typedef struct class_C2_struct* class_C2;

typedef struct obj_C2_struct { 
	class_C2 clazz;
	obj_Int  k;
} * obj_C2;

struct class_C2_struct the_class_C2_struct;

struct class_C2_struct {
	obj_C2(*constructor) (obj_Int);
	obj_Nothing(*M2) ();
	obj_C2 (*PRINT) (obj_C2);
obj_Boolean (*EQUALS) (obj_Obj, obj_Obj);
};

extern class_C2 the_class_C2;


/* Class Constructor */
obj_C2 new_C2(obj_Int j) {
	obj_C2  new_thing = (obj_C2) malloc(sizeof(struct obj_C2_struct));
	new_thing->clazz = the_class_C2;
	new_thing->k = j;
	return new_thing;
}


/* Class Methods */
obj_C2 C2_method_M2(obj_C2 this) {
	obj_Int x;
	x = int_literal(5);
	x->clazz->PRINT((obj_Obj) x);
}

/* Class Print Method */
obj_C2 C2_method_PRINT(obj_C2 this) {	obj_String lparen = str_literal("(");
	lparen->clazz->PRINT(lparen);
	this->k->clazz->PRINT((obj_Obj) this->k);
	obj_String rparen = str_literal(")");
	rparen->clazz->PRINT(rparen);
	return this;
}
struct class_C2_struct the_class_C2_struct = { 
	new_C2,
	C2_method_M2,
	C2_method_PRINT,
	Obj_method_EQUALS};

class_C2 the_class_C2 = &the_class_C2_struct;

void quackmain() {
		obj_Int x;
	x = int_literal(5);
	x->clazz->PRINT((obj_Obj) x);
		obj_Int var3;
	var3 = int_literal(4);
		obj_String y;
	y = str_literal("A String is here\n");
	y->clazz->PRINT((obj_Obj) y);
		obj_DataPt z;
z = (obj_Obj) the_class_DataPt->constructor();
	z->clazz->integerp((obj_Obj) z);
	z->clazz->PRINT((obj_Obj) z);
		obj_C2 xyz;
obj_Int tempInt_0 = int_literal(7);
;
xyz = (obj_Obj) the_class_C2->constructor(tempInt_0);
	xyz->clazz->PRINT((obj_Obj) xyz);
		obj_Int zzz;
	zzz = int_literal(4);
obj_Boolean tempBool0 = x->clazz->EQUALS((obj_Int) x, (obj_Obj) var3);
if(tempBool0 == lit_true) {
	goto label0;
}
goto label1;

label0:; 
		obj_Int l;
	l = int_literal(69);
	l->clazz->PRINT((obj_Obj) l);
goto label2;
label1:; 
		obj_Int j;
	j = int_literal(3);
	j->clazz->PRINT((obj_Obj) j);
label2:;
obj_Boolean tempBool1 = lit_true;
if(tempBool1 == lit_true) {
	goto label3;
}
goto label4;

label3:; 
		obj_String varr;
	varr = str_literal("Im a compiler that can do things\n");
	varr->clazz->PRINT((obj_Obj) varr);
goto label5;
label4:; 
	label5:;
}

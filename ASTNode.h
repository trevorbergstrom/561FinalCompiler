#ifndef REFLEXIVE_ASTNODE_H
#define REFLEXIVE_ASTNODE_H

#include <string>
#include <iostream>
#include <vector>
#include "EvalContext.h"
#include "CodegenContext.h"
#include <map>

enum nodeType {

	Holder, Program, Block, Classes, Class, Methods, Method, Constructor, Call, Formal_args, Actual_args, Assign, Return, Binop, 
	And, Or, Not, Dot, Load, If, L_expr, Ident, Intconst, Strconst, While, Typecase, Type_alt, Type_alts, ClassName,
	ClassArgs, VarIdent, TypeIdent, SuperName, MethodName, ReturnTyp, Statements, Loc, R_expr, Mult, Div, Plus, Minus, 
	Equals, AtMost, AtLeast, Greater, MethodArg, TrueState, FalseState, Less, formal_arg
};

static const char* nodeTypeNames[] {
	"Holder", "Program", "Block", "Classes", "Class", "Methods", "Method", "Constructor", "Call", "Formal_Args", "Actual_args",
	 "Assign", "Return", "Binop", "And", "Or", "Not", "Dot", "Load", "If", "L_expr", "Ident", "Int_const", "Str_const",
	 "While", "Type_case", "Type_alt", "Type_alts", "Class_name", "Class_args", "Var_Ident", "Var_type", "Super_name",
	 "Method_name", "Return_type", "Statements", "Loc", "R_expr", "Mult", "Div", "Plus", "Minus", "Eq", "AtMost",
	 "AtLeast", "Greater", "Method_args", "True_statement", "False_statement", "Less", "formal_args"

};

namespace AST {

<<<<<<< HEAD
=======
/*
	class AST_print_context {
	public:
		int indent_;
		AST_print_context() : indent_(0) {};
		void indent() { ++indent_; }
		void dedent() { --indent_; }
	};
*/
>>>>>>> origin/master
	class ASTNode {
	public:
		nodeType type_ = Holder;
		std::vector<ASTNode* > children;
		nodeType sType_ = Holder;

		int intVal_;
		char* strVal_ = NULL;

		// Constructors
		ASTNode(nodeType type) : type_(type) { };
		ASTNode(nodeType type, int val) : type_(type), intVal_(val) { };
		ASTNode(nodeType type, char* str) :type_(type), strVal_(str) {};
		ASTNode(nodeType type, nodeType styp, char* str) :type_(type), sType_(styp), strVal_(str) {};
		ASTNode(nodeType type, nodeType styp) : type_(type), sType_(styp) {};
		
		ASTNode* getNodeType(nodeType); //function to get a child node of a certain type

		void append(ASTNode* newChild) { children.push_back(newChild);} //function to add child
		void printNode(int); //recursive function to print node/ AST

		const char* getNodeName();
		const char* getSubName();
		
		std::vector<ASTNode*> getFormalArgs(); // function to get a list of formalargument child nodes
		std::vector<ASTNode*> getStatements(); //function to get a list of statement child nodes

		char* getClassName();
		char* getMethodName();
<<<<<<< HEAD
		char* getTypeIdent();
		ASTNode* getLeftMost();
=======
>>>>>>> origin/master
	};
}

#endif //REFLEXIVE_ASTNODE_H						

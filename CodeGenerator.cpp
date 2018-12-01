#include "CodeGenerator.h"


/**************************************************/
void GenCode(SynTree::SymbolTree* tree) {

	FILE* fp = fopen("code.c", "w");

	if(fp == NULL) {
		//exit(EXIT_ERROR);
	}

	fprintf(fp, "#include <stdio.h>\n#include <stdlib.h>\n#include \"Builtins.h\"\nvoid quackmain();\n");
	fprintf(fp, "int main(int argc, char** argv) {\n\tquackmain();\n\tprintf(\"Terminated Sucessfully\");\n\texit(0);\n}\n\n");

	string parts = "";
	for(int i = 0; i < tree->root_node->ClassList.size(); i++) {
		if(strcmp(tree->root_node->ClassList[i]->class_name, "main")) {
			parts += GenClass(tree->root_node->ClassList[i]);
		} else {
			parts += GenMain(tree->root_node->ClassList[i]);
		}
	}

	fprintf(fp, "%s\n", parts.c_str());

	fclose(fp);
	
}

/**************************************************/
string GenClass_ForwardDef(string c_name) {
		string classDec = "struct class_" + c_name + "_struct;\ntypedef struct class_" + c_name + "_struct* class_" + c_name + ";\n\n";

	return classDec;
}

/**************************************************/
string GenClass_Print(SynTree::Class_* classq) {
	string ret = "";
	string c_name = classq->class_name;

	SynTree::symbolTable* class_lits = classq->class_symbols;
	ret += "obj_";
	ret += c_name;
	ret += " ";
	ret += c_name;
	ret += "_method_PRINT(obj_";
	ret += c_name;
	ret += " this) {";

	ret += "\tobj_String lparen = str_literal(\"(\");\n";
	ret += "\tlparen->clazz->PRINT(lparen);\n";

	int sz = class_lits->getSize();
	for(int i = 0; i < sz; i++) {
		ret += "\tthis->";
		ret += class_lits->symbols[i]->symbol_name;
		ret += "->clazz->PRINT((obj_Obj) this->";
		ret += class_lits->symbols[i]->symbol_name;
		ret += ");\n";

		if(i != sz - 1) {
			ret += "\tobj_String comma = str_literal(\",\");\n";
			ret += "\tcomma->clazz->PRINT(comma);\n";
		}
	}

	ret += "\tobj_String rparen = str_literal(\")\");\n";
	ret += "\trparen->clazz->PRINT(rparen);\n";

	ret += "\treturn this;\n}\n";

	return ret;
}

/**************************************************/
string Gen_Class_Singleton(SynTree::Class_* classq) {
	/* struct class_DataPt_struct the_class_DataPt_struct = {
			new_DataPt,
			DataPt_method_Fuckery
		};

		class_DataPt the_class_DataPt = &the_class_DataPt_struct;
	*/
	string c_name = classq->class_name;

	string ret = "";
	ret += "struct class_";
	ret += c_name;
	ret += "_struct the_class_";
	ret += c_name;
	ret += "_struct = { \n";

	int sz = classq->class_methods->getSize();
	for(int i = 0; i < sz; i++) {
		SynTree::Method* cur_method = classq->class_methods->methods[i];
		if(cur_method->constructor) {
			ret += "\tnew_";
			ret += c_name;
		} else {
			ret += "\t";
			ret += c_name;
			ret += "_method_";
			ret += cur_method->method_name;
		}
		ret += ",\n";
	}
	ret += "\t";
	ret += c_name;
	ret += "_method_PRINT,\n";

	ret += "\t";
	ret += "Obj_method_EQUALS";


	ret += "};\n\n";

	ret += "class_";
	ret += c_name;
	ret += " the_class_";
	ret += c_name;
	ret += " = &the_class_";
	ret += c_name;
	ret += "_struct;\n\n";

	return ret;

}

/**************************************************/
string Gen_ClassStructs(SynTree::Class_* classq) {
	string c_name = classq->class_name;

	string structDec = "typedef struct obj_" + c_name + "_struct { \n\t";

	structDec += "class_" + c_name + " clazz;\n";

	SynTree::symbolTable* class_lits = classq->class_symbols;

	for(int i = 0; i < class_lits->getSize(); i++) {
		if(strcmp(class_lits->symbols[i]->ident, "Int") == 0) {
			structDec += "\tobj_Int ";
		} else if (strcmp(class_lits->symbols[i]->ident, "Str") == 0) {
			structDec += "\tobj_Str";
		} else {
			structDec += "\t";
			structDec += class_lits->symbols[i]->ident;
		}

		structDec += " ";
		structDec += class_lits->symbols[i]->symbol_name;
		structDec += ";\n";
	}

	structDec += "} * obj_" + c_name + ";\n\n";

	structDec += "struct class_" + c_name + "_struct the_class_" + c_name + "_struct;\n\n";
	
	return structDec;
}

/**************************************************/
string genMethodStruct(SynTree::Class_* classq) {
	SynTree::methodTable* method_list = classq->class_methods;
	string c_name = classq->class_name;

	string methodDec = "struct class_";
	methodDec += c_name;
	methodDec += "_struct {\n";

	for(int i = 0; i < method_list->getSize(); i++) {
		SynTree::Method* curMethod = method_list->methods[i];
		methodDec += "\tobj_";
		methodDec += curMethod->return_type;
		methodDec += "(*";
		if(curMethod->constructor == true) {
			methodDec += "constructor) (";
		} else {
			methodDec += curMethod->method_name;
			methodDec += ") (";
		}

		SynTree::symbolTable* method_symbols = curMethod->getSymbols();
		if(method_symbols->getSize() == 0) {
			methodDec += ");\n";
		} else {
			for(int i = 0; i < method_symbols->getSize(); i++) {
				methodDec += "obj_";
				methodDec += method_symbols->symbols[i]->ident;
				if(i != method_symbols->getSize() - 1){
					methodDec += ", ";
				} else {
					methodDec += ");\n";
				}
			}
		}
	}

	methodDec += "\tobj_";
	methodDec += c_name;
	methodDec += " (*PRINT) (obj_";
	methodDec += c_name;
	methodDec += ");\n";

	methodDec += "obj_Boolean (*EQUALS) (obj_Obj, obj_Obj);\n";
	methodDec += "};\n\n";

	methodDec += "extern class_" + c_name + " the_class_" + c_name + ";\n\n";
	return methodDec;
}

/**************************************************/
string GenConstructor(SynTree::Class_* classq) {
	string c_name = classq->class_name;
	string obj_c_name = "obj_" + c_name + " ";
	string obj_c_name_ns = "obj_" + c_name;

	string ret = obj_c_name + "new_" + c_name + "(";

	SynTree::Method* methodq = classq->constructor;

	for (int i = 0; i < methodq->method_symbols->getSize(); ++i)
	{
		ret += "obj_";
		ret += methodq->method_symbols->symbols[i]->ident;
		ret += " ";
		ret += methodq->method_symbols->symbols[i]->symbol_name;

		if(i < methodq->method_symbols->getSize() - 1) {
			ret += ", ";
		}
	}

	ret += ") {\n";

	ret += "\t" + obj_c_name + " new_thing = (" + obj_c_name_ns + ") malloc(sizeof(struct " + obj_c_name_ns +"_struct));\n";

	ret += "\tnew_thing->clazz = the_class_" + c_name + ";\n";

	ret += GenStatements(methodq);

	ReplaceString(ret, "this", "new_thing");

	ret += "\treturn new_thing;\n}\n\n";

	return ret;
}

/**************************************************/
string GenAssign(AST::ASTNode* stmnt) {
	string ret = "";
	ret += "\t";
	if(stmnt->getNodeType(L_expr)) {
		ret += GenLeft(stmnt->getNodeType(L_expr)); // <-------------IMPLIMENT!
		ret += " = ";
		ret += GenRight(stmnt->getNodeType(R_expr)); // <-------------IMPLIMENT!
		ret += ";\n";
	} else if(stmnt->getNodeType(Ident)) {
		ret += "obj_";
		if(stmnt->getNodeType(Ident)->children.size() == 0) {
			string constName = "";
			AST::ASTNode* right = stmnt->getNodeType(R_expr);
			if(right->type_ == Constructor) {
				constName += right->getNodeType(Ident)->strVal_;
			}

			ret += constName;
			ret += " ";
			ret += stmnt->getNodeType(Ident)->strVal_;
			ret += ";\n";

			/* get method arguments */

			AST::ASTNode* args = right->getNodeType(MethodArg);
			std::vector<string> v;

			if(args != NULL) {
				for(int i = 0; i < args->children.size(); i++){
					string tempName = GenIntName();
					v.push_back(tempName);
					ret += IntConst(args->getNodeType(Intconst), tempName);
					ret += ";\n";
				}
			}
			ret += stmnt->getNodeType(Ident)->strVal_;
			ret += " = (obj_Obj) the_class_";
			ret += constName;
			ret += "->constructor(";

			for(int i = 0; i < v.size(); i++) {
				ret += v[i];

				if(i != v.size() - 1) {
					ret += ", ";
				}
			}
			ret += ");\n";
		} else {
			ret += stmnt->getNodeType(Ident)->getNodeType(Ident)->strVal_;
			ret += " ";
			ret += stmnt->getNodeType(Ident)->strVal_;
			ret += ";\n";
			if(strcmp(stmnt->getNodeType(Ident)->getNodeType(Ident)->strVal_, "Int") == 0) {
				ret += "\t";
				ret += stmnt->getNodeType(Ident)->strVal_;
				ret += " = int_literal(";
				char num[21];
				sprintf(num, "%d", stmnt->getNodeType(R_expr)->intVal_);
				ret += num;
				ret += ");\n";
			} else if(strcmp(stmnt->getNodeType(Ident)->getNodeType(Ident)->strVal_, "String") == 0) {
				ret += "\t";
				ret += stmnt->getNodeType(Ident)->strVal_;
				ret += " = str_literal(\"";
				ret += stmnt->getNodeType(R_expr)->strVal_;
				ret += "\");\n";
			}
		}
	}
	return ret;
}

string GenIntName() {
	string ret = "tempInt_";
	char n[21];
	sprintf(n, "%d", tempIntCtr);
	tempIntCtr++;
	ret += n;
	return ret;
}

string IntConst(AST::ASTNode* num, string name) {
	string ret = "";
	ret += "obj_Int ";
	ret += name;
	ret += " = int_literal(";

	char val[21];
	sprintf(val, "%d", num->intVal_);
	ret += val;
	ret += ");\n";

	return ret;
}
/**************************************************/
string GenStatements(SynTree::Method* methodq) {
	string ret = "";
	int x = methodq->getStatementCount();

	for(int i = 0; i < x; i++) {
		AST::ASTNode* stmnt = methodq->stmnt_node_list[i];
		if(stmnt->type_ == Assign) {
			ret += GenAssign(stmnt);
			
		} else if(stmnt->type_ == Call) {
			ret += "\t";
			ret += GenCall(stmnt);
			ret += ";\n";
		} else if(stmnt->type_ == Return) {
			ret += "\treturn ";
			ret += GenRight(stmnt->getNodeType(R_expr));
			ret += ";\n";
		} else if(stmnt->type_ == If) {
			ret += GenIf(stmnt);
		}
		
	}
	return ret;
}

/**************************************************/
string GenStatements_AST(AST::ASTNode* methodq) {
	string ret = "";
	int x = methodq->children.size();

	for(int i = 0; i < x; i++) {
		AST::ASTNode* stmnt = methodq->children[i];
		if(stmnt->type_ == Assign) {
			ret += GenAssign(stmnt);
			
		} else if(stmnt->type_ == Call) {
			ret += "\t";
			ret += GenCall(stmnt);
			ret += ";\n";
		} else if(stmnt->type_ == Return) {
			ret += "\treturn ";
			ret += GenRight(stmnt->getNodeType(R_expr));
			ret += ";\n";
		} else if(stmnt->type_ == If) {
			ret += GenIf(stmnt);
		}
		
	}
	return ret;
}

/**************************************************/
string GenIf(AST::ASTNode* stmnt) {
	string ret = "";
	AST::ASTNode* args = stmnt->getNodeType(MethodArg);
			AST::ASTNode* trueBlk = stmnt->getNodeType(TrueState);
			AST::ASTNode* falseBlk = stmnt->getNodeType(FalseState);
			AST::ASTNode* left = NULL;
			AST::ASTNode* call_node = NULL;

			if(args->getNodeType(L_expr)) {
				left = args->getNodeType(L_expr);
			}

			if(args->getNodeType(Call)) {
				call_node = args->getNodeType(Call);
			}

			char num[21];
			sprintf(num, "%d", boolCtr);
			boolCtr++;

			string boolname = "tempBool";
			boolname += num;

			/*
			ret += "obj_Boolean ";
			ret += boolname;
			*/
			if(left) {
				if(strcmp(left->getNodeType(Ident)->strVal_, "true") == 0) {
					ret += "obj_Boolean ";
					ret += boolname;
					ret += " = lit_true;\n";
				} else if(strcmp(left->getNodeType(Ident)->strVal_, "false") == 0) {
					ret += "obj_Boolean ";
					ret += boolname;
					ret += " = lit_false;\n";
				} else {

				}
			} else if (call_node) {
				string decString = "";
				string functString = "obj_Boolean ";
				functString += boolname;
				functString += " = ";

				AST::ASTNode* method_type = call_node->getNodeType(Method);
				AST::ASTNode* left = call_node->getNodeType(L_expr); //lexpr x
				AST::ASTNode* argsC = call_node->getNodeType(Actual_args); //args-> contains intconst or ident
				//Lexpr = x
				//args = 5
				string leftName = "";
				string rightName = "";

				if(left) {
					if(left->getNodeType(Intconst)) {
						leftName += GenIntName();
						decString += "obj_Int ";
						decString += leftName;
						decString += " = int_literal(";
						char num[21];
						sprintf(num, "%d", left->getNodeType(Intconst)->intVal_);
						decString += num;
						decString += ");\n";

					} else if(left->getNodeType(Ident)) {
						leftName += left->getNodeType(Ident)->strVal_;
					}
				}

				functString += leftName;

				if(method_type->type_ == Equals) {
					functString += "->clazz->EQUALS((obj_Int) ";
					functString += leftName;
					functString += ", (obj_Obj) ";
				}

				if(argsC->getNodeType(L_expr)) {
					if(argsC->getNodeType(L_expr)->getNodeType(Ident)) {
						rightName += argsC->getNodeType(L_expr)->getNodeType(Ident)->strVal_;
					}
					
				} else if(argsC->getNodeType(Intconst)) {
					rightName += GenIntName();
					char num[21];
					sprintf(num, "%d", argsC->getNodeType(Intconst)->intVal_);
					decString += "obj_Int ";
					decString += rightName;
					decString += " = int_literal(";
					decString += num;
					decString += ");\n\n";
				}

				functString += rightName;
				functString += ");\n";

				ret += decString;
				ret += functString;
			}

			char lnum[21];
			sprintf(lnum, "%d", labelCtr);
			labelCtr++;
			string trueLabel = "label";
			trueLabel += lnum;

			sprintf(lnum, "%d", labelCtr);
			labelCtr++;
			string falseLabel = "label";
			falseLabel += lnum;

			sprintf(lnum, "%d", labelCtr);
			labelCtr++;
			string endLabel = "label";
			endLabel += lnum;

			ret += "if(";
			ret += boolname;
			ret += " == lit_true) {\n\tgoto ";
			ret += trueLabel;
			ret += ";\n}\ngoto ";
			ret += falseLabel;
			ret += ";\n\n";

			ret += trueLabel;
			ret += ":; \n\t";

			//ret += GenAssign(trueBlk->getNodeType(Assign));
			ret += GenStatements_AST(trueBlk);
			ret += "goto ";
			ret += endLabel;
			ret += ";\n";

			ret += falseLabel;
			ret += ":; \n\t";
			//ret += GenAssign(falseBlk->getNodeType(Assign));
			ret += GenStatements_AST(falseBlk);
			ret += endLabel;
			ret += ":;\n";

			return ret;
}

string GenWhile(AST::ASTNode* while_node) {
	string assblocks = "ass";
	return assblocks;
}
/**************************************************/
string GenMethods(SynTree::Class_* classq) {
	string ret = "";
	string c_name = classq->class_name;

	for(int i = 0; i < classq->class_methods->getSize(); i++) {
		SynTree::Method* cur_method = classq->class_methods->methods[i];
		if(!cur_method->constructor) {
			string m_name = cur_method->method_name;
			ret += "obj_" + c_name + " " + c_name + "_method_" + m_name + "(obj_" + c_name + " this) {\n";
			ret += GenStatements(cur_method);
			ret += "}\n";
		}
		
	}

	return ret;
}

/**************************************************/
string retstuff() {
	string ret = "->";
	return "->";
}

/**************************************************/
string GenClass(SynTree::Class_* classq) {
	//generate refrence to structure where methods live
	//generate structure where instance variables live
	//generate method structure

	string class_name = classq->class_name;

	string class_code = GenClass_ForwardDef(class_name);

	class_code += Gen_ClassStructs(classq);

	class_code += genMethodStruct(classq);

	class_code += "\n/* Class Constructor */\n";
	class_code += GenConstructor(classq);

	class_code += "\n/* Class Methods */\n";
	class_code += GenMethods(classq);

	class_code += "\n/* Class Print Method */\n";
	class_code += GenClass_Print(classq);

	for(int i = 0; i < classq->ClassList.size(); i++) {
		class_code += GenClass(classq->ClassList[i]);
	}

	class_code += Gen_Class_Singleton(classq);

	return class_code;
}

/**************************************************/
string GenLeft(AST::ASTNode* leftexp) {
	string ret = "";
	
	if(leftexp->type_ == Dot) {
		ret += GenDot(leftexp); // <-------------IMPLIMENT!
	}
	else if (leftexp->type_ == Load) {
		if(leftexp->getNodeType(Ident) != NULL) {
			if(strcmp(leftexp->children[0]->strVal_, "this") == 0 ) {
				ret += "this";
			} else {
				ret += leftexp->children[0]->strVal_;
			}
		} else {
			ret += GenLeft(leftexp->children[0]);
		}
	}
	else { //only other lexpr is a ident
		
	}

	return ret;
}

/**************************************************/
string GenLeft_Constructor(AST::ASTNode* leftexp) {
	string ret = "";
	
	if(leftexp->type_ == Dot) {
		ret += GenDot(leftexp); // <-------------IMPLIMENT!
	}
	else if (leftexp->type_ == Load) {
		if(leftexp->getNodeType(Ident) != NULL) {
			if(strcmp(leftexp->children[0]->strVal_, "this") == 0 ) {
				ret += "new_thing";
			} else {
				ret += leftexp->children[0]->strVal_;
			}
		} else {
			ret += GenLeft(leftexp->children[0]);
		}
	}
	else { //only other lexpr is a ident
		
	}

	return ret;
}

/**************************************************/
string GenDot(AST::ASTNode* dot_node) {
	string ret = "";

	AST::ASTNode* left_node = dot_node->getNodeType(L_expr);
	AST::ASTNode* right_node = dot_node->getNodeType(R_expr);

	ret += GenLeft(left_node);
	ret += "->";
	ret += GenRight(right_node);
	return ret;
}

/**************************************************/
string GenRight(AST::ASTNode* right) {
	string ret = "";
	if(right->type_ == Ident) {
		ret += right->strVal_;
	} else if (right->type_ == Load) {
		if(right->children[0]->type_ == Ident) {
			ret += right->children[0]->strVal_;
		} else if(right->children[0]->sType_ == L_expr) {
			ret += GenLeft(right->children[0]);
		} 
		
	} else if(right->type_ == Call) {

		ret += GenCall(right->children[0]);
	} else if(right->type_ == Actual_args) {
		ret += GenCall(right->children[0]);
	} else if (right->type_ == Intconst) {
		ret += "int_literal(";
		char num[21];
		sprintf(num, "%d", right->intVal_);
		ret += num;
		ret += ")";
	}

	return ret;
}

/**************************************************/
string GenCall(AST::ASTNode* call_node) {
	string ret = "";
	string decString = "";
	string finalString = "";
	string varn;

	if(call_node->getNodeType(Strconst)) {
		ret += call_node->getNodeType(Strconst)->strVal_;

	} else if(call_node->getNodeType(Intconst)) {
		char num[21];
		sprintf(num, "%d", call_node->getNodeType(Intconst)->intVal_);
		ret += "obj_Int ";
		ret += num;
	} 
	else if(call_node->getNodeType(Call)) {
		//ret += GenCall(call_node->children[0]);
	}
	else {
		varn = GenLeft(call_node->getNodeType(L_expr));
		ret += GenLeft(call_node->getNodeType(L_expr));
	}
	

	AST::ASTNode* mtyp = call_node->getNodeType(Method);
	AST::ASTNode* args_node;

	string leftName = "";
	string rightName = "";

	if(mtyp->type_ == Plus) {
		args_node = call_node->getNodeType(Actual_args);
		AST::ASTNode* lop = call_node->getNodeType(L_expr);

		if(lop->getNodeType(Ident)) {
			leftName = lop->getNodeType(Ident)->strVal_;
			ret += lop->getNodeType(Ident)->strVal_;
		} else if(lop->getNodeType(Intconst)) {
			string tint = GenIntName();
			decString += IntConst(lop->getNodeType(Intconst), tint);
			ret += tint;
			leftName = tint;
		}

		ret += " = ";
		ret += leftName;
		ret += "->clazz->PLUS((obj_Int) ";
		ret += leftName;
		ret += " , (obj_Obj) ";

		if(args_node->getNodeType(Ident)) {
			ret += args_node->getNodeType(Ident)->strVal_;
		} else if(args_node->getNodeType(Intconst)) {
			string tint = GenIntName();
			decString += IntConst(args_node->getNodeType(Intconst), tint);
			ret += tint;
			rightName = tint;
		} 
		ret += ");\n";
	} else if(mtyp->type_ == Minus) {

	} else if(mtyp->type_ == Ident) {
		ret += "->clazz";
		ret += "->";
		ret += mtyp->strVal_;
		args_node = call_node->getNodeType(Actual_args);
		ret += "(";
		if(args_node->children.size() != 0) {
				//do stuff
		}
		ret += "(obj_Obj) ";
		ret += varn;
		ret += ")";
	}

	finalString += decString;
	finalString += ret;
	return finalString;
}

/**************************************************/
string GenMain(SynTree::Class_* classq) {
	string ret = "";
	ret += "void quackmain() {\n";

	for(int i = 0; i < classq->main_statements.size(); i++) {
		AST::ASTNode* stmnt = classq->main_statements[i];
		if(stmnt->type_ == Assign) {
			ret += "\t";
			ret += GenAssign(stmnt);

		} else if(stmnt->type_ == Call || stmnt->sType_ == Call) {
			ret += "\t";
			ret += GenCall(stmnt);
			ret += ";\n";
		} else if(stmnt->type_ == Return) {
			ret += "\treturn ";
			ret += GenRight(stmnt->getNodeType(R_expr));
			ret += ";\n";
		} else if (stmnt->type_ == If) {
			ret += GenIf(stmnt);
		} 
		
	}
	ret += "}";

	return ret;
}

/**************************************************/
void ReplaceString(string& subject, const string& search, const string& replace) {
    size_t pos = 0;
    while((pos = subject.find(search, pos)) != string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
}

/**************************************************/
/*string genIntLit(AST::ASTNode) {

}*/

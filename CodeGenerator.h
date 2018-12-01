#include <string>
#include "ASTNode.h"
#include "TypeCheck.h"
//#include "Builtins.h"

using std::string;

static int tempIntCtr = 0;
static int tempStringCtr = 0;
static int labelCtr = 0;
static int boolCtr = 0;

void GenCode(SynTree::SymbolTree*);

string GenClass(SynTree::Class_*);
string GenClass_ForwardDef(string);
string GenClass_ref(SynTree::Class_*);
string Gen_ClassStructs(SynTree::Class_*);
string GenMethod(SynTree::Method*);
string GenMethodStruct(SynTree::methodTable*);
string GenConstructor(SynTree::Class_*);
string GenStatements(SynTree::Method*);
string GenCall(AST::ASTNode*);

string GenDot(AST::ASTNode*);
string GenLeft(AST::ASTNode*);
string GenRight(AST::ASTNode*);

string GenMain(SynTree::Class_*);

string Gen_Class_Singleton(SynTree::Class_*);

string retstuff();

string GenClass_Print(SynTree::Class_*);

string GenLeft_Constructor(AST::ASTNode*);

void ReplaceString(string& subject, const string& search, const string& replace);

string IntConst(AST::ASTNode*, string);
string GenIntName();

string GenIf(AST::ASTNode*);

string GenStatements_AST(AST::ASTNode*);

string GenWhile(AST::ASTNode*);

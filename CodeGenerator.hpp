#include <string>
#include "ASTNode.h"
#include "TypeCheck.h"
#include "Builtins.h"

using std::string;

void GenCode(SynTree::SymbolTree*);

string GenClass(SynTree::Class_*);

string GenMethod(SynTree::Method*);

string GenStatements(AST::ASTNode* statement_block);

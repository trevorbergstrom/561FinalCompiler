#include "TypeCheck.h"

namespace SynTree {
/******************************************************************/
    Symbol::Symbol(char* name_, char* ident_) {
        this->symbol_name = name_;
        this->ident = ident_;
    }

/******************************************************************/
    void symbolTable::addSymbol(Symbol* new_symbol) {
    
        this->symbols.push_back(new_symbol);
    }

/******************************************************************/
    bool symbolTable::verifyName(char* name_) {
        for(int i = 0; i < symbols.size(); i++) {
            if(strcmp(symbols[i]->symbol_name, name_)  == 0) {
                return false;
            }
        }
        return true;
    }

/******************************************************************/
    bool symbolTable::verifyType(char* name_, char* type_) {
        for(int i = 0; i < symbols.size(); i++) {
            if (strcmp(symbols[i]->symbol_name, name_) == 0) {
                if(strcmp(symbols[i]->ident, type_) == 0) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }
/******************************************************************/
    char* symbolTable::getType(char* name_) {
        for(int i = 0; i < symbols.size(); i++) {
            if(strcmp(symbols[i]->symbol_name, name_) == 0) {
                return symbols[i]->ident;
            }
        }
        return NULL;
    }
/******************************************************************/
    Method::Method(char* name_, char* ret_type) {
        this->method_name = name_;
        this->return_type = ret_type;
        method_symbols = new symbolTable();
        this->owner = NULL;
        this->constructor = false;
    }

/******************************************************************/
    bool Method::addSymbol(Symbol* newSymbol) {
        if(method_symbols->verifyName(newSymbol->symbol_name)) {
            method_symbols->addSymbol(newSymbol);
            return true;
        }
        return false;
    }

/******************************************************************/
    bool Method::lookupSymbol(char* name_) {
        return true;
    }

/******************************************************************/
    bool methodTable::addMethod (Method* new_method) {
        for(int i = 0; i < methods.size(); i++) {
            if(strcmp(methods[i]->method_name, new_method->method_name) == 0) {
                return false;
            }
        }
        methods.push_back(new_method);
        return true;
    }

/******************************************************************/
    Method* methodTable::lookupName(char* name_) {
        for(int i = 0; i < methods.size(); i++) {
            if(strcmp(methods[i]->method_name, name_) == 0) {
                return methods[i];
            }
        }
        return NULL;
    }

/******************************************************************/
    Class_::Class_(char* name_) {
        this->class_name = name_;
        this->class_symbols = new symbolTable;
        this->class_methods = new methodTable;
        this->super_class = NULL;
    }

/******************************************************************/
    bool Class_::addClass(Class_* new_class) {
        for(int i = 0; i < this->ClassList.size(); i++) {
            if(strcmp(ClassList[i]->class_name, new_class->class_name) == 0) {
                return false;
            }
        }
        ClassList.push_back(new_class);
        return true;
    }

/******************************************************************/
    bool Class_::addMethod(Method* new_method) {
        if(class_methods->addMethod(new_method)) {
            if(!strcmp(new_method->method_name, this->class_name)) {
                this->constructor = new_method;
            }
            return true;
        }
        return false;
    }

/******************************************************************/
    Class_* Class_::findClass(char* name_) {
    if(strcmp(this->class_name, name_) == 0) {
        return this;
    }
    
    Class_* c2r = NULL;
        for(int i = 0; i < this->ClassList.size(); i++) {

            if(strcmp(this->ClassList[i]->class_name, name_) == 0) {
                return this->ClassList[i];
            } else {
                c2r = ClassList[i]->findClass(name_);
            }
        }
        return c2r;
    }
/******************************************************************/
    SymbolTree::SymbolTree() {
        const char* c = "Obj";
        const char* integer = "Int";
        const char* str = "Str";
        const char* print = "PRINT";
        this->root_node = new Class_(strdup(c));
        root_node->class_symbols->addSymbol(new Symbol(strdup(integer)));
        root_node->class_symbols->addSymbol(new Symbol(strdup(str)));
        root_node->class_methods->addMethod(new Method(strdup(print), "Nothing"));
    
        built_in_methods = root_node->class_methods;
        built_in_symbols = root_node->class_symbols;
    
    }

/******************************************************************/
    bool SymbolTree::addClass(Class_* C) {
        if(root_node->addClass(C)) {
            return true;
        }
        return false;
    }

/******************************************************************/
    bool SymbolTree::addClass(Class_* c, char* extends_) {
        Class_* parent = root_node->findClass(extends_);
        if(parent == NULL) {
            return false;
        } else {
            parent->addClass(c);
            c->super_class = parent;
            return true;
        }
    }

/******************************************************************/
    Class_* SymbolTree::findClass(char* name_) {
        if(strcmp(name_, root_node->class_name) == 0) {
            return root_node;
        }
        return NULL;
    }
/******************************************************************/
    void Symbol::printSymbol() {
        printf("%s : %s\n", this->symbol_name, this->ident);
    }

    void symbolTable::printSymbols() {
        for(int i = 0; i < symbols.size(); i++) {
            symbols[i]->printSymbol();
        }
    }

    void Method::printMethod() {
        printf("%s: , return type: %s\n", this->method_name, this->return_type);
        this->method_symbols->printSymbols();
    }

    void methodTable::printMethods() {
        for(int i = 0; i < methods.size(); i++) {
            methods[i]->printMethod();
        }
    }

    void Class_::printClass() {
        printf("Class %s: ", this->class_name);
        if(this->super_class != NULL) {
            printf("My parent class is: %s\n", this->super_class->class_name);
        } else {
        printf("\n");
    }
    printf("\tClass Methods:\n");
        class_methods->printMethods();
    printf("\tClass Symbols\n");
        class_symbols->printSymbols();
    
        for(int i = 0; i < ClassList.size(); i++) {
            ClassList[i]->printClass();
        }
    }

    void SymbolTree::printTree() {
        printf("Printing Tree:\n");
        root_node->printClass();
    }
/******************************************************************/
    bool Method::evalAssign(AST::ASTNode* assign_node) {
        AST::ASTNode* left = assign_node->getNodeType(L_expr);
        AST::ASTNode* right = assign_node->getNodeType(R_expr);

        if(left == NULL || right == NULL) {
            return false;
        } 

        if(left->type_ == Dot) {
            /*eval dot*/
            AST::ASTNode* dot_left = left->getNodeType(L_expr);
            AST::ASTNode* dot_right = left->getNodeType(R_expr);

            AST::ASTNode* left_exp = dot_left->getNodeType(Ident);

            if(strcmp(left_exp->strVal_, "this") == 0)  {
                if(this->constructor) {
                    //this->owner->class_symbols.addSymbol()
                } else {
                    /* look up */
                }
            } 
        }
    }
/******************************************************************/
    AST::ASTNode* SymbolTree::getNextNode(AST::ASTNode* node_) {
        for(int i = 0; i < node_->children.size(); i++) {
            if(node_->children[i]->type_ == Class) {
                return node_->children[i];
            }
        }
        return NULL;
    }
/******************************************************************/
    void Method::checkStatements(AST::ASTNode* statements_node) {
        for(int i = 0; i < statements_node->children.size(); i++) {
            AST::ASTNode* curChild = statements_node->children[i];
            if(curChild->type_ == Assign) {
                /* evaluate assignments */
            } else if(curChild->type_ == Return) {
                /* evaluate return type */
            } else if(curChild->type_ == Call) {
                /* evaluate call */
            }
        }

    }
/******************************************************************/
    void Method::addFormalArgs(AST::ASTNode* formal_args_node) {
        std::vector<AST::ASTNode*> formal_args_list = formal_args_node->getFormalArgs();
        
        for(int i = 0; i < formal_args_list.size(); i++) {
            AST::ASTNode* var_ident = formal_args_list[i]->getNodeType(VarIdent);
            AST::ASTNode* var_type = formal_args_list[i]->getNodeType(TypeIdent);
            
            Symbol* newSym = new Symbol(var_ident->strVal_, var_type->strVal_);
            this->addSymbol(newSym);
        }
    }
/******************************************************************/

/******************************************************************/
    void Class_::addClassVars(AST::ASTNode* stmnts) {
        std::vector<AST::ASTNode*> assignNodes;

        for(int i = 0; i < stmnts->children.size(); i++) {
            AST::ASTNode* cur = stmnts->children[i];
            if(cur->type_ == Assign){
                AST::ASTNode* dt = cur->getNodeType(Dot);
                if(dt != NULL) {
                    AST::ASTNode* ld = dt->getNodeType(Load);
                    if(ld != NULL) {
                        AST::ASTNode* loc = ld->getNodeType(Loc);
                        if(loc != NULL) {
                            
                            if(strcmp(loc->strVal_, "this") == 0) {

                                char* vtyp = cur->getNodeType(R_expr)->getTypeIdent();

                                if(this->constructor->method_symbols->getType(vtyp) != NULL) {
                                    vtyp = this->constructor->method_symbols->getType(vtyp);
                                }
                                Symbol* s = new Symbol(dt->getNodeType(R_expr)->strVal_, vtyp);
                                this->class_symbols->addSymbol(s);
                            }
                        }
                    }
                    
                }
            }
        }
    } 
/******************************************************************/
    bool Class_::addConstructor(AST::ASTNode* construct_node) {
       AST::ASTNode* construct_name = construct_node->getNodeType(MethodName);
       AST::ASTNode* ret_type = construct_node->getNodeType(ReturnTyp);
       AST::ASTNode* formal_args_node = construct_node->getNodeType(Formal_args);
       AST::ASTNode* statements_node = construct_node->getNodeType(Statements);

       Method* cMethod = new Method(construct_name->strVal_, ret_type->strVal_);
       cMethod->addFormalArgs(formal_args_node);
       if(!this->addMethod(cMethod)) {
            return false;
            printf("Error Adding Constructor\n");
       }
       cMethod->constructor = true;
       this->constructor = cMethod;
       cMethod->statement_block = statements_node;
       cMethod->build_method_statements();
       return true;
    }
/******************************************************************/
    void Method::build_method_statements() {
        this->return_node = statement_block->getNodeType(Return);

        for(int i = 0; i < statement_block->children.size(); i++) {
            stmnt_node_list.push_back(statement_block->children[i]);
        }

    }
/******************************************************************/
    bool Class_::buildMethods(AST::ASTNode* methods_node) {
        for(int i = 0; i < methods_node->children.size(); i++) {
            AST::ASTNode* curMethod = methods_node->children[i];

            AST::ASTNode* method_name = curMethod->getNodeType(MethodName);
            AST::ASTNode* return_type = curMethod->getNodeType(ReturnTyp);
            AST::ASTNode* formal_args = curMethod->getNodeType(Formal_args);
            AST::ASTNode* method_statements = curMethod->getNodeType(Statements);

            Method* newMethod = new Method(method_name->strVal_, return_type->strVal_);
            newMethod->addFormalArgs(formal_args);            
            newMethod->statement_block = method_statements;

            newMethod->build_method_statements();
            if(!this->addMethod(newMethod)) {
                printf("ERROR ADDING METHOD\n");
                return false;
                
            }
        }

        return true;
    }
/******************************************************************/
    bool SymbolTree::buildTreeClasses(AST::ASTNode* classes_node) {
        
        for(int i = 0; i < classes_node->children.size(); i++) {
            AST::ASTNode* curClass = classes_node->children[i];
            
            AST::ASTNode* class_name = curClass->getNodeType(ClassName);
            AST::ASTNode* super_name = curClass->getNodeType(SuperName);
            AST::ASTNode* class_constructor = curClass->getNodeType(Constructor);
            AST::ASTNode* class_methods = curClass->getNodeType(Methods);
            AST::ASTNode* class_vars = class_constructor->getNodeType(Statements);

            Class_* newClass = new Class_(class_name->strVal_);
            
            if(!this->addClass(newClass, super_name->strVal_)) {
                  printf("Error Adding class");
                  return false;
            }
            newClass->addConstructor(class_constructor);
            if(!newClass->buildMethods(class_methods)) {
                return false;
            }
            newClass->addClassVars(class_vars);
        }
        return true;
    }
/******************************************************************/
    bool SymbolTree::buildMainMethod(AST::ASTNode* main_node) {
        Class_* mainClass = new Class_("main");

        for(int i = 0; i < main_node->children.size(); i++) {
            mainClass->main_statements.push_back(main_node->children[i]);
        }

        if(!this->addClass(mainClass, "Obj")) {
            return false;
            printf("Error Adding Main Class");
        }
        return true;
    }
/******************************************************************/

    bool SymbolTree::buildSyntaxTree(AST::ASTNode* root) {
        AST::ASTNode* classes_node = root->getNodeType(Classes);
        if(classes_node != NULL) {
            if(!this->buildTreeClasses(classes_node)) {
                return false;
            }
        }
        AST::ASTNode* main_node = root->getNodeType(Statements);
        if(main_node != NULL) {
            if(!buildMainMethod(main_node)) {
                return false;
            }
        }
        return true;
    }
}



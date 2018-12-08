#include "ASTNode.h"

using std::vector;
using std::cout;
using std::endl;

enum classType { classes, prg_stmnt, obj };
enum methodType { constructor, class_method };

class Class_;

namespace SynTree {

    /******************************************************************/
    class Symbol {
    public:
        Symbol(char* name_, char* ident);
        Symbol(char* name_) { symbol_name = name_; ident = "";};
        char* symbol_name;
        char* ident;
    
        void printSymbol();
    };

/******************************************************************/
    class symbolTable {
    private:
        
    public:
        vector<Symbol*> symbols;
        symbolTable() {};
        void addSymbol(Symbol* new_symbol); //function to add symbol to table
        bool verifyName(char* name_); //function to look for name in symbol table. ret true if does not exist
        bool verifyType(char* name_, char* type_); //function to lookup type of symbol in table. ret true if match
        char* getType(char* name_);
        int getSize() { return symbols.size(); };
        void printSymbols();
    
    };

/******************************************************************/
    class Method {
    private:
    public:
        symbolTable* method_symbols; //holds the symbols that occur in method scope

        Class_* owner;
        bool constructor; //boolean if it is constructor or not
        void setOwner(Class_* c) { owner = c; };
        char* method_name; //Holds the name of the method
        char* return_type;
        Method(char* name, char* return_type); //constructor
        bool addSymbol(Symbol* new_symbol);
        bool lookupSymbol(char* name_);
        symbolTable* getSymbols() { return this->method_symbols; };
        void addFormalArgs(AST::ASTNode*); 
        void printMethod();
        bool evalAssign(AST::ASTNode*);
        void checkStatements(AST::ASTNode*);

        void build_method_statements();
        AST::ASTNode* statement_block;

        AST::ASTNode* return_node;
        vector<AST::ASTNode*> stmnt_node_list;
        int getStatementCount() { return stmnt_node_list.size(); };
    };

/******************************************************************/
    class methodTable {
    private:
        
    public:
        methodTable() {};
        vector<Method*> methods; //list of methods
        bool addMethod(Method* new_method); //Function to add method to the list, returns false if exists
        Method* lookupName(char* name_); //finds a method in the list and returns pointer to it
        int getSize() { return methods.size(); };
        void printMethods();
    };

/******************************************************************/
    class Class_ {
    public:
        char* class_name;
        methodTable* class_methods; //Table of class methods
        Method* constructor; //Constructor method, special method.
        symbolTable* class_symbols; //Table of special class symbols, accible through "this"keyword
        classType class_type; //type of class determines if it can have methods or whatnot.
        vector<Class_*> ClassList; //list of children classes
        Class_* super_class;
    
        Class_(char* name_);
        bool addClass(Class_*); //function to add class, returns true if class was added successfully
        bool addMethod(Method*); // function to add method to the class. return true if added sucess
        Method* lookUpMethod(char* name_);
        Class_* findClass(char* name_); // returns a pointer to child class looked up by name
        bool buildMethods(AST::ASTNode*);
        bool addConstructor(AST::ASTNode*);
        void printClass();

        void addClassVars(AST::ASTNode*);
        vector<AST::ASTNode*> main_statements;
};

/******************************************************************/
    class SymbolTree {
    public:
        SymbolTree();
        Class_* root_node; //root node created by constructor. will alyways be type obj
        symbolTable* built_in_symbols; //table of built in symbols, will be built in constructor.
        methodTable* built_in_methods; //table of built in methods, will be built in constructor.
        bool addClass(Class_*); // function to add class. returns true if success
        bool addClass(Class_*, char*);
        Class_* findClass(char* name_); // searches for a class in the tree returns pointer to that class
        bool buildTreeClasses(AST::ASTNode*);
        bool buildSyntaxTree(AST::ASTNode*);
        AST::ASTNode* getNextNode(AST::ASTNode*);
        void printTree();
        bool buildMainMethod(AST::ASTNode*);
    };

}


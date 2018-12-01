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
<<<<<<< HEAD
        
    public:
    	vector<Symbol*> symbols;
=======
        vector<Symbol*> symbols;
    public:
>>>>>>> origin/master
        symbolTable() {};
        void addSymbol(Symbol* new_symbol); //function to add symbol to table
        bool verifyName(char* name_); //function to look for name in symbol table. ret true if does not exist
        bool verifyType(char* name_, char* type_); //function to lookup type of symbol in table. ret true if match
<<<<<<< HEAD
        char* getType(char* name_);
    	int getSize() { return symbols.size(); };
=======
        char* getype(char* name_);
    
>>>>>>> origin/master
        void printSymbols();
    
    };

/******************************************************************/
    class Method {
    private:
<<<<<<< HEAD
    public:
    	symbolTable* method_symbols; //holds the symbols that occur in method scope

        Class_* owner;
        bool constructor; //boolean if it is constructor or not
        void setOwner(Class_* c) { owner = c; };
=======
        symbolTable* method_symbols; //holds the symbols that occur in method scope
        bool constructor; //boolean if it is constructor or not
    public:
        Class_* owner;
>>>>>>> origin/master
        char* method_name; //Holds the name of the method
        char* return_type;
        Method(char* name, char* return_type); //constructor
        bool addSymbol(Symbol* new_symbol);
        bool lookupSymbol(char* name_);
        symbolTable* getSymbols() { return this->method_symbols; };
   	    void addFormalArgs(AST::ASTNode*); 
        void printMethod();
<<<<<<< HEAD
        bool evalAssign(AST::ASTNode*);
        void checkStatements(AST::ASTNode*);

        void build_method_statements();
        AST::ASTNode* statement_block;

        AST::ASTNode* return_node;
        vector<AST::ASTNode*> stmnt_node_list;
        int getStatementCount() { return stmnt_node_list.size(); };
=======
>>>>>>> origin/master
    };

/******************************************************************/
    class methodTable {
    private:
<<<<<<< HEAD
        
    public:
        methodTable() {};
        vector<Method*> methods; //list of methods
        bool addMethod(Method* new_method); //Function to add method to the list, returns false if exists
        Method* lookupName(char* name_); //finds a method in the list and returns pointer to it
    	int getSize() { return methods.size(); };
=======
        vector<Method*> methods; //list of methods
    public:
        methodTable() {};
        bool addMethod(Method* new_method); //Function to add method to the list, returns false if exists
        Method* lookupName(char* name_); //finds a method in the list and returns pointer to it
    
>>>>>>> origin/master
        void printMethods();
    };

/******************************************************************/
    class Class_ {
    public:
        char* class_name;
        methodTable* class_methods; //Table of class methods
<<<<<<< HEAD
        Method* constructor; //Constructor method, special method.
=======
        class Method* constructor; //Constructor method, special method.
>>>>>>> origin/master
        symbolTable* class_symbols; //Table of special class symbols, accible through "this"keyword
        classType class_type; //type of class determines if it can have methods or whatnot.
        vector<Class_*> ClassList; //list of children classes
        Class_* super_class;
    
        Class_(char* name_);
        bool addClass(Class_*); //function to add class, returns true if class was added successfully
<<<<<<< HEAD
        bool addMethod(Method*); // function to add method to the class. return true if added sucess
        Method* lookUpMethod(char* name_);
        Class_* findClass(char* name_); // returns a pointer to child class looked up by name
    	bool buildMethods(AST::ASTNode*);
	    bool addConstructor(AST::ASTNode*);
        void printClass();

        void addClassVars(AST::ASTNode*);
        vector<AST::ASTNode*> main_statements;
=======
        bool addMethod(class Method*); // function to add method to the class. return true if added sucess
        class Method* lookUpMethod(char* name_);
        Class_* findClass(char* name_); // returns a pointer to child class looked up by name
    	void buildMethods(AST::ASTNode*);
	    void addConstructor(AST::ASTNode*);
        void printClass();
>>>>>>> origin/master
};

/******************************************************************/
    class SymbolTree {
    public:
        SymbolTree();
        Class_* root_node; //root node created by constructor. will alyways be type obj
        symbolTable* built_in_symbols; //table of built in symbols, will be built in constructor.
        methodTable* built_in_methods; //table of built in methods, will be built in constructor.
<<<<<<< HEAD
        bool addClass(Class_*); // function to add class. returns true if success
        bool addClass(Class_*, char*);
        Class_* findClass(char* name_); // searches for a class in the tree returns pointer to that class
        bool buildTreeClasses(AST::ASTNode*);
        bool buildSyntaxTree(AST::ASTNode*);
        AST::ASTNode* getNextNode(AST::ASTNode*);
        void printTree();
        bool buildMainMethod(AST::ASTNode*);
=======
    
        bool addClass(Class_*); // function to add class. returns true if success
        bool addClass(Class_*, char*);
        class Class_* findClass(char* name_); // searches for a class in the tree returns pointer to that class
        void buildTreeClasses(AST::ASTNode*);
        void buildSyntaxTree(AST::ASTNode*);
        AST::ASTNode* getNextNode(AST::ASTNode*);
        void printTree();
>>>>>>> origin/master
    };

}


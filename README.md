# 561FinalCompiler

To Run: Download all files

1. Run CMake -> "cmake CMakeLists.txt"
2. Run make -> "make"
3. Compile quack code with "./parser <quackfn.qk>"
4. If code generated it is located in code.c
5. Compile code.c -> "gcc code.c builtins.c -o code"
6. Run -> "./code"

Pretty much what my compiler can do:
1. Lexical and Syntatical analysis
2. Type check class declarations for duplicate classes and invalid super classes.
3. Type check duplicate methods in classes.
4. Generate code for the following:

 class instances can be created
 Integer and string variables can be created and printed
 class methods can be called 
 simple if/ else loops can be ran, with EQUALS relational operator 
 
 
Demo file includes:
badclass.qk - class with a undeclared supertype
badmethod.qk - class with a duplicate method
simple.qk - program that displays all the working functions of the compiler

 I ran out of time to finish this compiler. If I had a partner or a few more weeks I think I could have created a fully working compiler. 

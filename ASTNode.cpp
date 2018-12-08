#include "ASTNode.h"

namespace AST {

/******************************************************************/	
	const char* ASTNode::getNodeName() {
		int typNum = this->type_;
		return nodeTypeNames[typNum];
	}
/******************************************************************/
	const char* ASTNode::getSubName() {
		int typNum = this->sType_;
		return nodeTypeNames[typNum];
	}
/******************************************************************/
	void ASTNode::printNode(int curIdent) {
		for(int i = 0; i < curIdent; i++) {
			printf("|\t");
		}

		if(this->sType_ > 0) {
			const char* mySubName = this->getSubName();
			printf("%s: ", mySubName);
		}

		const char* myName = this->getNodeName();
		printf("%s", myName);
		if(this->strVal_ != NULL) {
			printf(": %s\n", this->strVal_);
		} else if (this->type_ == Intconst) {
				printf(": %d\n", this->intVal_);
		} else {
			printf("\n");
		}

		curIdent++;
		for(int i = 0; i < children.size(); i++) {
			if(children[i] != NULL) {
				children[i]->printNode(curIdent);
			} else {
				printf("GOT SOME NULL NODES\n");
			}
		}
		curIdent--;
	}
/******************************************************************/	
	std::vector<ASTNode*> ASTNode::getFormalArgs() {
        std::vector<ASTNode*> list;
	    printf("Getting formal args from: %s - children size %d", nodeTypeNames[this->type_], this->children.size());
        for(int i = 0; i < this->children.size(); i++) {
            if(this->children[i]->type_ == ClassArgs) {
                list.push_back(this->children[i]);
            }
        }

        return list;
    }
/******************************************************************/
	ASTNode* ASTNode::getNodeType(nodeType typ) {
        	for(int i = 0; i < this->children.size(); i++) {
//			printf("Node #%d = %s - %d, subtype: %s - %d\n", i, nodeTypeNames[this->children[i]->type_], this->children[i]->type_, nodeTypeNames[this->children[i]->sType_], this->children[i]->sType_);
           		if(this->children[i]->type_ == typ || this->children[i]->sType_ == typ) {
//				printf("Found node of type %s\n", nodeTypeNames[this->children[i]->type_]);
                		return this->children[i];
            		}
        	}
//		printf("Counldnt find a node of type %s - %d", nodeTypeNames[typ], typ);
//		printf(" In children of %s - %d --- method name: %s\n", nodeTypeNames[this->type_], this->type_, this->strVal_);
        	return NULL;
    	}
/******************************************************************/

    //std::vector<ASTNode*> ASTNode::getStatements() {
    //	std::vector<ASTNode*> list;
    std::vector<ASTNode*> ASTNode::getStatements() {
    	std::vector<ASTNode*> list;
    	for(int i = 0; i < this->children.size(); i++) {

    	}
    	return list;
    }
/******************************************************************/
	char* ASTNode::getClassName() {
		if(this->type_ == Class) {
			for(int i = 0; i < children.size(); i++) {
				if(children[i]->type_ == ClassName) {
					return children[i]->children[0]->strVal_;
				}
			}
		}
		return NULL;
	}
/******************************************************************/
	char* ASTNode::getMethodName() {
		if(this->type_ == Method) {
			for(int i = 0; i < children.size(); i++) {
				if(children[i]->type_ == MethodName) {
					return children[i]->children[0]->strVal_;
				}
			}
		}
		return NULL;
	}
/******************************************************************/
	ASTNode* ASTNode::getLeftMost() {
		ASTNode* lexp = this->getNodeType(L_expr);
		ASTNode* retNode;
		if(lexp == NULL) {
			retNode = this;
		} else {
			retNode = lexp->getLeftMost();
		}

		return retNode;
	}
/******************************************************************/
	char* ASTNode::getTypeIdent() {
		if(this->type_ == Ident) {
			return this->strVal_;
		} else if(this->type_ == Intconst) {
			char* ret = "Int";
			return ret;
		} else if(this->type_ == Strconst) {
			char* ret = "Str";
		} else {
			return this->children[0]->getTypeIdent();
		}
	}
}

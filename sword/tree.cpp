#include<iostream>
#include<stack>

namespace traversal{
    /*
        preorder/inorder/postorder
            first: recursive
            second: loop with stack
            third: morris traversal  
        bfs
        dfs
    */
    struct treeNode{
        int val;
        treeNode *left;
        treeNode *right;
        treeNode(int v):val(v),left(NULL),right(NULL){}
    };

    void preorder(treeNode *root){
        if(NULL != root){
            std::cout<<root->val<<" ";
            preorder(root->left);
            preorder(root->right);
        }
    }
    void inorder(treeNode *root){
        if(NULL != root){
            inorder(root->left);
            std::cout<<root->val<<" ";
            inorder(root->right);
        }
    }
    void postorder(treeNode *root){
        if(NULL != root){
            postorder(root->left);
            postorder(root->right);
            std::cout<<root->val<<" ";
        }
    }

    void preorderLoop(treeNode *root, std::stack<treeNode*> &s){
        while(root){
            std::cout<<root->val<<" ";//preorder output
            if(root->right)s.push(root->right);
            root = root->left;
        }
    }

    void preorderLoop(treeNode *root){
        std::stack<treeNode*> s;
        while(true){
            preorderLoop(root, s);
            if(s.empty())
                break;
            root = s.top();
            s.pop();    
        }
    }

    void inorderLoop(treeNode *root, std::stack<treeNode*> &s){
        while(root){
            s.push(root);
            root = root->left;
        }
    }
    void inorderLoop(treeNode *root){
        std::stack<treeNode*> s;
        while(true){
            inorderLoop(root, s);
            if(s.empty())
                break;
            root = s.top();
            s.pop();
            std::cout<<root->val<<" ";//inorder output
            root = root->right;    
        }
    }
    void postorderLoop(treeNode *root, std::stack<treeNode*> &s, std::stack<int> &data){
        while(root){
            data.push(root->val);
            if(root->left)s.push(root->left);
            root = root->right;
        }
    }
    void postorderLoop(treeNode *root){
        std::stack<treeNode*> s;
        std::stack<int> data;
        while(true){
            postorderLoop(root, s, data);
            if(s.empty())
                break;
            root = s.top();
            s.pop();        
        }
        while(!data.empty()){
            std::cout<<data.top() <<" ";//postorder output
            data.pop();
        }
    }

    void morrisTraversal(treeNode *root){
        while(root){
            //get precursor
            treeNode *mostRight = root->left;
            if(mostRight != NULL){
                while(mostRight->right != NULL && mostRight->right != root){
                    mostRight = mostRight->right;
                }
                if(mostRight->right == NULL){//first time
                    mostRight->right = root;
                    root = root->left;
                    continue;
                }
                else{//second time
                    mostRight->right = NULL;
                }
            }
            root = root->right;    
        }
    }

    void morrisTraversalPreorder(treeNode *root){
        while(root){
            treeNode *mostRight = root->left;
            if(mostRight != NULL){
                while(mostRight->next != NULL && mostRight->next != root){
                    mostRight = mostRight->right;
                }
                if(mostRight->next == NULL){
                    std::cout<<root->val<<" ";
                    mostRight->next = root;
                    root = root->left;
                    continue;
                }
                else{
                    mostRight->next = NULL;
                }
            }
            else{
                std::cout<<root->val<<" ";
            }
            root = root->right;
        }
    }

    void morrisTraversalInorder(treeNode *root){
        while(root){
            treeNode *mostRight = root->left;
            if(mostRight != NULL){
                while(mostRight->right != NULL && mostRight->right != root){
                    mostRight = mostRight->right;
                }
                if(mostRight->right == NULL){//first time
                    mostRight->right = root;
                    root = root->left;
                    continue;
                }
                else{
                    mostRight->right = NULL;
                }
            }
            else{
                //
            }
            std::cout<<root->val<<" ";
            root = root->right;
        }
    }
    void printReverse(treeNode *root){
        if(root != NULL){
            if(root->right != NULL){
                printReverse(root->right);
            }
            std::cout<<root->val<<" ";
        }
    }
    void morrisTraversalPostorder(treeNode *root){
        treeNode *tmp = root;
        while(root){
            treeNode *mostRight = root->left;
            if(mostRight != NULL){
                while(mostRight->right != NULL && mostRight->right != root){
                    mostRight = mostRight->right;
                }
                if(mostRight->right == NULL){
                    mostRight->right = root;
                    root = root->left;
                    continue;
                }
                else{
                    mostRight->right = NULL;
                    //output 
                    printReverse(root->left);
                }
            }
            else{

            }
            root = root->right;
        }
        printReverse(tmp);
    }
    
    void bfs(treeNode *root){
        if(NULL == root)return;
        std::queue<treeNode*> sq;
        sq.push(root);
        while(!sq.empty()){
            treeNode *tmp = sq.front();
            sq.pop();
            std::cout<<tmp->val<<" ";
            if(tmp->left)sq.push(tmp->left);
            if(tmp->right)sq.push(tmp->right);
        }           
    }        
    void bfsWithEnter(treeNode *root){
        if(NULL == root)return;
        treeNode *last = root;
        treeNode *lastNext = root;
        std::queue<treeNode*> sq;
        sq.push(root);
        while(!sq.empty()){
            treeNode *tmp = sq.front();
            sq.pop();
            std::cout<<tmp->val<<" ";
            if(tmp->left){
                sq.push(tmp->left);
                lastNext = tmp->left;
            }    
            if(tmp->right){
                sq.push(tmp->right);
                lastNext = tmp->right;
            } 
            if(tmp == last){
                std::cout<<std::endl;
                last = lastNext;   
            }                
        }                    
    }      
    void dfs(treeNode *root, std::stack<treeNode*> &s){
        if(NULL == root)return;
        s.push(root);
        std::cout<<root->val<<" ";
        dfs(root->left, s);
        dfs(root->right, s);
        s.pop();        
    }        
    void dfs(treeNode *root){
        if(NULL == root)return;
        std::stack<treeNode*> s;
        dfs(root, s);               
    }        
}

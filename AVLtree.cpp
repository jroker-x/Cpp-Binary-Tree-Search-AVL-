#include<iostream>
#include<memory>
#include <algorithm>

struct Node
{
    int value;
    std::unique_ptr<Node> right;
    std::unique_ptr<Node> left;
    Node(int val)
        : value(val)
    {}

};
void insertH(std::unique_ptr<Node>& nodeTT,int value);
size_t sizeH(Node* node);
size_t heightH(Node* node);
void insertH(std::unique_ptr<Node>& nodeTT,int value);
size_t balancefactor(Node* node);
void rebalance(std::unique_ptr<Node>& node);
Node* findMin(Node* node);

class BST{

    private:
        std::unique_ptr<Node> root;

    public:
        void insert(int value){
            insertH(root,value);
        }

        void inorder(Node* node){

            if (node == nullptr)
            {
                return;
            }
            
            inorder(node->left.get());
            
            std::cout << node->value << '\n';

            inorder(node->right.get());

        }

        bool contains(Node* node, int value){

            if (node == nullptr)
            {
                return false;
            }

            if (node->value == value)
            {
               return true;
            }

            if (value < node->value)
            {
                return contains(node->left.get(),value);
            }

            if (value > node->value)
            {
                return contains(node->right.get(),value);
            }

            return false;
        }

        void remove(std::unique_ptr<Node>& node, int value){

            if (node == nullptr)
            {
                return;
            }
            if (value < node->value)
            {
                return remove(node->left, value);
            }
            else if (value > node->value)
            {
                return remove(node->right, value);
            }
            else{
                if (node->left && node->right == nullptr)
                {
                    node.reset();
                    return;
                }
                else if (node->left != nullptr && node->right == nullptr)
                {
                    node = std::move(node->left);
                    return;
                }
                else if (node->right != nullptr && node->left == nullptr)
                {
                    node = std::move(node->right);
                    return;
                }
                else{
                    Node* successor = findMin(node->right.get());
                    node->value = successor->value;
                    remove(node->right,successor->value);
                }
                
            }
            
        }

        void size(){
            sizeH(root.get());
        }

        void height(){
            heightH(root.get());
        }
    
};

int main(){




}


void insertH(std::unique_ptr<Node>& nodeTT,int value){
        
        if (nodeTT == nullptr)
        {
            nodeTT = std::make_unique<Node>(value);
            return;
        }
        else if (value < nodeTT->value)
        {
            insertH(nodeTT->left,value);
            return;
        }
        else if (value > nodeTT->value)
        {
           insertH(nodeTT->right,value);
           return;
        }
        
        rebalance(nodeTT);
    }

size_t sizeH(Node* node){
            if (node == nullptr)
            {
                return 0;
            }
            return sizeH(node->left.get())+ sizeH(node->right.get())+ 1;
        }

size_t heightH(Node* node){

            if (node == nullptr)
            {
                return 0;
            }
            return std::max(heightH(node->left.get()),heightH(node->right.get()))+ 1;
        }
    
Node* findMin(Node* node){

    if (node->left == nullptr)
    {
       return node;
    }
    return findMin(node->left.get());

}

void leftrotation(std::unique_ptr<Node>& node){

    auto newRoot = std::move(node->right);
    node->right = std::move(newRoot->left);
    newRoot->left = std::move(node);
    node = std::move(newRoot);

}

void rightrotation(std::unique_ptr<Node>& node){

    auto newRoot = std::move(node->left);
    node->left = std::move(newRoot->right);
    newRoot->right = std::move(node);
    node = std::move(newRoot);

}

size_t balancefactor(Node* node){
    return heightH(node->left.get())-heightH(node->right.get());
}

void rebalance(std::unique_ptr<Node>& node){

    int bf = balancefactor(node.get());
    if (bf < -1)
    {
        

        if (balancefactor(node->right.get()) <= 0)
        {
            leftrotation(node);
        }
        else{
            rightrotation(node->right);
            leftrotation(node);
        }

       
        
        
    }
    if (bf > 1)
    {
        rightrotation(node);

        if (balancefactor(node->left.get()) >= 0)
        {
            rightrotation(node);
        }
        else{
            leftrotation(node->left);
            rightrotation(node);
        }

      
    }


}










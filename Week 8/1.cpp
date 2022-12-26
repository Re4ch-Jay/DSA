#include <iostream>
using namespace std;

struct Element {
    int data;
    Element * left, *right;
};

Element * insertData(Element * root, int newData){

    if(root == NULL){
        root = new Element();
        root->data = newData;
        root->left = NULL;
        root->right = NULL;
    }
    else if(newData > root->data){
        root->right = insertData(root->right, newData);
    }else if(newData < root->data){
        root->left = insertData(root->left, newData);
    }

    return root;
}

void preorder(Element * root) {
    if(root!=NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Element * root) {
    if(root!=NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void postorder(Element * root) {
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}

int search(Element * root, int data) {
    if(root == NULL){
        return 0;
    }else if (data == root->data) {
        return 1;
    }else if (data >= root->data){
        return search(root->right, data);
    }else if(data <= root->data){
        return search(root->left, data);
    }
}

int main () {
    Element * e= NULL;
    e = insertData(e, 10);
    e = insertData(e, 15);
    e = insertData(e, 7);

    cout<<"\nPreorder: "; preorder(e);
    cout<<"\nInorder: "; inorder(e);
    cout<<"\nPostorder: "; postorder(e);
    cout<<"\nSearch: ";

    int find = search(e, 10);
    if(find == 1) {
        cout<<"Data found"<<endl;
    }else if (find == 0){
        cout<<"Data not found"<<endl;
    }

    return 0;
}
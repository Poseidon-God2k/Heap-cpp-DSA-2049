/*********************************************************************************************************************************/
/************************************               **  ** ******    **    ******       *************************************/
/************************************               **  ** **     **    ** **    **     *************************************/
/************************************               ****** ****   ******** ******       *************************************/
/************************************               **  ** **     **    ** **           *************************************/
/************************************               **  ** ****** **    ** **           *************************************/
#include<iostream>
#include<algorithm>
#include<fstream>
#include<queue>
using namespace std;
/**********************************************************************************************/
/*******************************     Heap for arr    ******************************************/
/**********************************************************************************************/
// Heap up element of heap
void heap_up(int * arr , int index){
    if(index==0)
      return;
     if(arr[index]>arr[(index-1)/2])
        swap(arr[index],arr[(index-1)/2]);
     return heap_up(arr, (index-1)/2);
}
// heap down element of heap to balance
void heap_down(int* arr, int index, int size){
    int childl =index*2+1;
    int childr = index*2+2;
    if(childl>size)
    return;
    int right_child;
    if(arr[childl] >= arr[childr] && childl<size)
        right_child = childl;
    else
        right_child =childr;
    if(right_child<size){
        swap(arr[index],arr[right_child]);
        heap_down(arr,right_child,size);
    }
}
// build heap from arr
void build_max_heap(int* arr, int size){
       int walker =1;
       while (walker!=size)
       {
       heap_up(arr,walker);
       walker++;
       }
}
// return max of heap
int top_max_Heap(int* arr, int size){
      int out = arr[0];
      arr[0]=arr[size-1];
      heap_down(arr,0,size);
      return out;
}
// print heap
void print(int * arr, int size){
    for(int i=0; i<size; i++)
      cout<<arr[i]<<" ";
      cout<<endl;
}
/**********************************************************************************************/
/*******************************     Heap for tree    *****************************************/
/**********************************************************************************************/
struct node{
    node * pre;
     int data;
     node * left;
     node * right;
};
class Tree_heap{
    public:
    void heap_up(node * &root){
        if(root==NULL)
        return;
        if(root->data>root->pre->data)
          swap(root->data,root->pre->data);
        heap_up(root->pre);
    }
    void insert_node_BFS(node * &root, int data){
        node * new_node = new node();
        new_node->pre =NULL;
        new_node->data =data;
        queue<struct node*> Queue;
        Queue.push(root);
        while(!Queue.empty()){
            if(root->left==NULL){
                  root->left=new_node;
                  new_node->pre = root;
                  heap_up(root->left);
                  break;
            }
            else  Queue.push(root->left);
            if(root->right==NULL){
                root->right = new_node;
                new_node->pre = root;
                heap_up(root->right);
                break;
            }
            else Queue.push(root->right);
        }
    }
    void print(node * root){
        if(root!=NULL){
        print(root->left);
        print(root->right);
        cout<< root->data<<" ";
        }
    }

};
int main(){
   /* fstream InFile;
    InFile.open("input.txt");
    int *arr = new int [8];
    int i=0;
    while(!InFile.eof()){
        InFile>>arr[i];
        i++;
    }
    print(arr,8);
    build_max_heap(arr,8);
    print(arr,8);
    int size = 8;
    for(int i=0; i<8 ;i++){
       cout<<"MAX top : "<<top_max_Heap(arr,size)<<endl;
       size--;
    }*/
    node * root = new node();
    Tree_heap heap;
    fstream InFile;
    InFile.open("input.txt");
    int temp;
    InFile>> temp;
    root->data = temp;
    while(!InFile.eof()){
        InFile>> temp;
        heap.insert_node_BFS(root,temp);
    }
    heap.print(root);
}
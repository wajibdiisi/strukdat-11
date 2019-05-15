/*
Nama Program : Exercise-02
Nama : Ahmad Irfan Fadholi
NPM  : 140810180034
Deskripsi : BST (Binary Search Tree)
Tgl : 15 Mei 2019
*/

#include<iostream>
using namespace std;

struct Simpul {
    int info;
    Simpul* left;
    Simpul* right;
};
typedef Simpul* pointer;
typedef pointer Tree;
const int data[15] ={7, 11, 3, 4, 5 , 9, 12, 15, 1, 10, 2, 25, 8, 14,19};

void createSimpul(pointer& pBaru, int data) {
    pBaru = new Simpul;
    pBaru->info=data;
    pBaru->left = NULL;
    pBaru->right = NULL;
}

void insertBST (Tree& Root, pointer pBaru){
    if ( Root == NULL)
        Root = pBaru;
    else if (pBaru->info < Root->info)
        insertBST(Root->left,pBaru);
    else if (pBaru->info > Root->info)
        insertBST(Root->right,pBaru);
    else
        cout<<"Sudah Ada";
}

void preOrder (Tree Root) {
    if (Root != NULL){
        cout << Root->info <<endl;
        preOrder(Root->left);
        preOrder(Root->right);
    }
}

void inOrder (Tree Root) {
    if (Root != NULL){
        inOrder(Root->left);
        cout<< Root->info <<endl;
        inOrder(Root->right);
    }
}

void postOrder (Tree Root) {
    if (Root != NULL){
        postOrder(Root->left);
        postOrder(Root->right);
        cout<< Root->info <<endl;
    }
}
int height(Tree Root){
    if (Root==NULL) 
		return 0;
    else{
        int leftHeight=height(Root->left);
        int rightHeight=height(Root->right);

        if (leftHeight>rightHeight)
			return (leftHeight+1);
        else 
			return (rightHeight+1);
    }
}


void givenLevel(Tree Root, int level){
    if (Root==NULL) 
        return;
    if (level==1) 
        cout << Root->info << " ";
    else if (level>1){
        givenLevel(Root->left,level-1);
        givenLevel(Root->right,level-1);
    }
}

void kedalaman(Tree Root){
    int h=height(Root);
    for (int i=1; i<=h; i++){
        cout << i-1 << ": " <<" [ ";
        givenLevel(Root,i);
        cout<< "]"<< endl;
    }
}

void levelOrder(Tree Root){
    int h=height(Root);
    for (int i=1; i<=h; i++){
        cout << i << ": " <<" [ ";
        givenLevel(Root,i);
        cout<< "]"<< endl;
    }
}

void Anak(Tree Root, pointer pBaru){
    pBaru= Root;
    if(pBaru!=NULL){
        cout<<"Parent Node = "<<pBaru->info<<endl;
        if(pBaru->left == NULL)
            cout<<"Left Child = NULL"<<endl;
        else
            cout<<"Left Child = "<<pBaru->left->info<<endl;
                     
        if(pBaru->right == NULL)
            cout<<"Right Child = NULL"<<endl;
        else
            cout<<"Right Child = "<<pBaru->right->info<<endl;
		
		cout<<endl;
        Anak(Root->left, pBaru);
        Anak(Root->right, pBaru);
    }
}

int main(){
    Tree Root;
    pointer p;
    int choice,temp;
	Root=NULL;
	for (int i=0;i<15;i++){ 
		createSimpul(p,data[i]);
        insertBST(Root,p); 
    }
    do{
    	cout<<"\n1.Insert BST(Binary Search Tree)"
    		<<"\n2.PreOrder"
    		<<"\n3.InOrder"
    		<<"\n4.PostOrder"
    		<<"\n5.Kedalaman"
    		<<"\n6.Level"
    		<<"\n7.Anak"
    		<<"\n8.Quit"
    		<<"\n====================="
    		<<"\nMasukkan Pilihan : ";cin>>choice;
    	system("CLS");
    switch(choice){
    	case 1:
    		cout<<"\nInsert BST(Binary Search Tree)"<<endl;
    		cout<<"Masukkan Data : ";cin>>temp;
        	createSimpul(p,temp);
        	insertBST(Root,p);
        case 2:
        	cout<<"\nPreOrder"<<endl;
        	preOrder(Root);
        	break;
        case 3:
        	cout<<"\nInOrder"<<endl;
        	inOrder(Root);
       	 	break;
        case 4:
        	cout<<"\nPostOrder"<<endl;
        	postOrder(Root);
        	break;
  		case 5:
        	cout<<"\nKedalaman"<<endl;
        	kedalaman(Root);
        	break;  	
        case 6:
        	cout<<"\nLevel"<<endl;
        	levelOrder(Root);
        	break;     	
        case 7:
        	cout<<"\nAnak"<<endl;
            Anak(Root, p);
            break;          
		case 8:
            cout<<"\nProgram Berhenti "<<endl;
            return 0;
            break;		
        default:
        	cout<<"Pilihan Salah"<<endl;
        	break;
    }
}
 while(choice != 8);
    return 0;
}

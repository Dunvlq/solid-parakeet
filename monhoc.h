#pragma once
#include "svanddk.h"
#define TRUE 1
#define FALSE 0


struct dsmonhoc { // cau truc danh sach mon hoc
	char MAMH[10]; //ma mon hoc bat dau bang so 2 (10 ki tu)
	char TENMH[50]; // ten mon hoc
	int STCLT; // so tin chi ly thuyet
	int STCTH; // so tin chi thuc hanh
};
typedef struct dsmonhoc dsmh; 

struct nodetree { // cay nhi phan tim kiem
	dsmh monhoc; // du lieu la cau truc danh sach mon hoc
	struct nodetree *LEFT; // cay con ben trai
	struct nodetree *RIGHT; // cay con ben phai
	
};
typedef struct nodetree NODETREE;
typedef NODETREE* PTR_NODETREE;

struct temp {
	char ten[50];
};
typedef struct temp TEMP;

struct arr { 
	char MAMH[10]; 
	char TENMH[50]; 
	int STCLT; 
	int STCTH;
};
typedef struct arr ARR; 

void InitializeTree(PTR_NODETREE &root);
bool Isempty (PTR_NODETREE ds);
int Compare(dsmh x,dsmh y);
void Insert_Node_Tree(PTR_NODETREE &ds, dsmh mh);
void Insert_Node_Tree_From_File(PTR_NODETREE &ds, dsmh mh);
dsmh Input_Tree (PTR_NODETREE &ds);
void Show_Tree (PTR_NODETREE ds,ARR arr[],int k);
void Inorder(PTR_NODETREE p);
void CreatTree_Dsmh(PTR_NODETREE &ds, dsmh mh);
NODETREE* FindMin(PTR_NODETREE ds);
void RemoveTree (PTR_NODETREE &ds, dsmh mh);
int Transfer_Name(PTR_NODETREE p,TEMP arr[],int k);
int Transfer(PTR_NODETREE p,ARR arr[],int k);
void DocFile_MH(PTR_NODETREE &ds);
void GhiFile_MH(PTR_NODETREE &ds);
int CountNode(PTR_NODETREE &t);
int Search_TenMonHoc(PTR_NODETREE ds, char *mh);
int Search_MaMonHoc(PTR_NODETREE ds, char *mh);



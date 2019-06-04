#include "monhoc.h"
#include "menu.h"


void InitializeTree(PTR_NODETREE &root) {
	root = NULL;
}

bool Isempty (PTR_NODETREE ds) {
	return ds = NULL;
}

int Compare(dsmh x,dsmh y) {
	return stricmp(x.MAMH,y.MAMH);
}

void Insert_Node_Tree(PTR_NODETREE &ds, dsmh mh) {
	if (ds==NULL) {
		NODETREE *p = new NODETREE;
		p->monhoc = mh;
		p->LEFT = NULL;
		p->RIGHT = NULL;
		ds = p;
	} else {
		if (stricmp(mh.MAMH,ds->monhoc.MAMH) < 0) {
			Insert_Node_Tree (ds->LEFT,mh);
		}else if (stricmp(mh.MAMH,ds->monhoc.MAMH) > 0) {
			Insert_Node_Tree (ds->RIGHT,mh);
		}
	}
}

bool Check_MaMonHoc(PTR_NODETREE ds, char *mh) {
	if (ds==NULL) {
		return false;
	} 
	else {
		if (stricmp(Trim(mh),ds->monhoc.MAMH) == 0)
		{
			return true;
		}
		else if (stricmp(Trim(mh),ds->monhoc.MAMH) < 0)
		{
			Search_MaMonHoc(ds->LEFT, mh);
		}
		else if (stricmp(Trim(mh),ds->monhoc.MAMH) > 0 ) 
		{
			Search_MaMonHoc(ds->RIGHT, mh);
		}
	}
}

void Fix_MaMonHoc(PTR_NODETREE &ds,char *temp,dsmh mh) {
	if (ds==NULL) {
		return;
	} 
	else {
		if (stricmp(Trim(temp),ds->monhoc.MAMH) == 0)
		{
			strcpy(ds->monhoc.MAMH,mh.MAMH);
			strcpy(ds->monhoc.TENMH,mh.TENMH);
			ds->monhoc.STCLT = mh.STCLT;
			ds->monhoc.STCTH = mh.STCTH;
			return;
//			gotoxy(20,20);
//			cout << "dung";
//			getch();
		}
		else if (stricmp(Trim(temp),ds->monhoc.MAMH) < 0)
		{
			Fix_MaMonHoc(ds->LEFT,temp, mh);
		}
		else if (stricmp(Trim(temp),ds->monhoc.MAMH) > 0 ) 
		{
			Fix_MaMonHoc(ds->RIGHT,temp, mh);
		}
	}
}

PTR_NODETREE Search_MaMonHoc(PTR_NODETREE ds, char *mh) { // tim kiem theo key
	if (ds==NULL) {
		return NULL;
	} 
	else {
		if (stricmp(Trim(mh),ds->monhoc.MAMH) == 0)
		{
			return ds;
		}
		else if (stricmp(Trim(mh),ds->monhoc.MAMH) < 0)
		{
			Search_MaMonHoc(ds->LEFT, mh);
		}
		else if (stricmp(Trim(mh),ds->monhoc.MAMH) > 0 ) 
		{
			Search_MaMonHoc(ds->RIGHT, mh);
		}
	}
}

dsmh Input_Tree (PTR_NODETREE &ds) {
	dsmh mh;
	int a=0;
	int exit=0;
	int thaotac=0;
	int maxten = 50;
	int maxma = 10;
	char mmh[11], tmh[51], stclt[11], stcth[11];
	do {
		gotoxy(112,6);
		cout<< "                                        ";
		DrawBox(110,5,54,2);
		a=0;
		gotoxy(112,5);
		cout <<"Nhap Ma mon hoc:";
		fflush(stdin);
		gotoxy(112,6);
		InputString(mmh,maxma);
		if (strlen(mmh)==0) {
			gotoxy(112,6);
			cout<< "                                        ";
			gotoxy(112,6);
			cout << "khong duoc de trong!";
			a = 1;
			getch();
		}
		if (Check_MaMonHoc(ds,mmh)) {
			gotoxy(112,6);
			cout<< "                                        ";
			gotoxy(112,6);
			cout << "Ma mon hoc da co, nhap lai!";
			a = 1;
			getch();
		}
	} while (a == 1);
	strcpy(mh.MAMH,mmh);
	do {
		gotoxy(112,10);
		cout<< "                                        ";
		DrawBox(110,9,54,2);
		a = 0;
		gotoxy(112,9);
		cout <<"Nhap ten mon hoc: ";
		rewind(stdin);
		gotoxy(112,10);
		InputStringSpace(tmh,maxten);
		if (strlen(tmh)==0) {
			gotoxy(112,10);
			cout<< "                                        ";
			gotoxy(112,10);
			cout << "khong duoc de trong!";
			a = 1;
			getch();
		}
	} while (a == 1 );
	strcpy(mh.TENMH,tmh);
	do {
		gotoxy(112,14);
		cout<< "                                        ";
		DrawBox(110,13,54,2);
		a=0;
		gotoxy(112,13);
		cout <<"Nhap so tin chi ly thuyet: ";
		fflush(stdin);
		gotoxy(112,14);
		InputNumber(stclt,maxma);
		if (strlen(stclt)==0) {
			gotoxy(112,14);
			cout<< "                                        ";
			gotoxy(112,14);
			cout << "khong duoc de trong!";
			a = 1;
			getch();
		}
	} while (a==1);
	mh.STCLT = atoi(stclt);
	do {
		gotoxy(112,18);
		cout<< "                                        ";
		DrawBox(110,17,54,2);
		a=0;
		gotoxy(112,17);
		cout <<"Nhap so tin chi thuc hanh: ";
		fflush(stdin);
		gotoxy(112,18);
		InputNumber(stcth,maxma);
		if (strlen(stcth)==0) {
			gotoxy(112,18);
			cout<< "                                        ";
			gotoxy(112,18);
			cout << "khong duoc de trong!";
			a = 1;
			getch();
		}				
	} while (a==1);
	mh.STCTH = atoi(stcth);
	DrawBox(131,21,23,2);
	gotoxy(139,21);
	cout << "LUU LAI";
	gotoxy(135,22);
	cout << "CO";
	gotoxy(147,22);
	cout << "KHONG";
	gotoxy(135,22);
	//hight light co
	TextColor(140);
	cout << "CO";
	TextColor(DEN);
	while (exit == 0) {
		char key;
		key = getch();
		if (key == Left) {
			gotoxy(135,22);
			TextColor(140);
			cout << "CO";
			if (thaotac == 0)
				thaotac = 2 - 1;
			else thaotac--;	
			gotoxy(147,22);
			TextColor(DEN);
			cout << "KHONG";
		}
		else if (key == Right) {
			gotoxy(147,22);
			TextColor(140);
			cout << "KHONG";
			if (thaotac == 2 - 1)
				thaotac = 0;
			else thaotac++;
			gotoxy(135,22);
			TextColor(DEN);
			cout << "CO";
		}
		else if (key == ESC) {
			exit = 1;
		}
		else if (key == ENTER) {
			if (thaotac == 0) {
				return mh;
			}
			else if (thaotac == 1 ) {
				strcpy(mh.MAMH,"null");
				
				return mh;
			}
		}	
	}
}

NODETREE* FindMin(PTR_NODETREE ds)
{
	while (ds->LEFT != NULL) ds = ds->LEFT;
	return (ds);
}


void RemoveTree (PTR_NODETREE &ds, dsmh mh) {
	
	if (ds==NULL) {
		return;
	} 
	else {
		if (stricmp(mh.MAMH,ds->monhoc.MAMH) < 0)
		{
			RemoveTree(ds->LEFT, mh); // duyet sang nhanh trai cua cay
		}
		else if (stricmp(mh.MAMH,ds->monhoc.MAMH) >  0 )
		{
			RemoveTree(ds->RIGHT, mh); // duyet sang nhanh phai cua c�y 
		}
		else  // thay node can xoa
		{
			NODETREE *x = ds;  
			if (ds->RIGHT == NULL && ds->LEFT == NULL) {
				delete ds;
				ds = NULL;
			}
			else if (ds->LEFT == NULL)
			{
				// duyet sang phai 
				ds = ds->RIGHT; 
				delete x; 
			}
			else if (ds->RIGHT == NULL)
			{
				// duyet sang trai
				ds = ds->LEFT;
				delete x; 
			}
			else // node co hai cay con
			{
				x = FindMin(ds->RIGHT);
				ds->monhoc = x->monhoc;
				ds = x;
				delete x;
			}
		}
	}
}

void DeleteNode (PTR_NODETREE &ds, dsmh mh) {
	char m[50];
	DrawBox(114,19,50,2);
	gotoxy(116,19);
	cout << "Nhap ma mon hoc can xoa!";
	gotoxy(116,20);
	InputString(m,50);
	if (Search_MaMonHoc(ds,m) != NULL) {
		mh = Search_MaMonHoc(ds,m)->monhoc;
		RemoveTree(ds,mh);
		gotoxy(116,20);
		cout << "DONE";	
		getch();
	} else {
		gotoxy(116,20);
		cout << "Khong tim thay!";	
		getch();
	}
	
}

void Inorder(PTR_NODETREE p) { // duyet theo left node right
	if (p!=NULL) {
		Inorder (p->LEFT);
		cout << p->monhoc.MAMH << endl;
		cout << p->monhoc.TENMH << endl;
		cout << p->monhoc.STCLT << endl;
		cout << p->monhoc.STCTH << endl;
		Inorder (p->RIGHT);
	}
}

void Show_Tree (PTR_NODETREE ds,int k) {
	PTR_NODETREE p = ds;
	dsmh *arrtemp[500];
	PTR_NODETREE Stack[500];
	int sp = -1;
	int i = 0;
	while(p != NULL)
	{
		arrtemp[i] = new dsmh;
		strcpy(arrtemp[i]->MAMH,p->monhoc.MAMH);
		strcpy(arrtemp[i]->TENMH,p->monhoc.TENMH);
		arrtemp[i]->STCLT = p->monhoc.STCLT;
		arrtemp[i]->STCTH = p->monhoc.STCTH;
		if(p->RIGHT != NULL)
		{
			Stack[++sp] = p->RIGHT;
		}
		if(p->LEFT != NULL)
		{
			p = p->LEFT;
		}
		else if(sp == -1)
				break;
		else p = Stack[sp--];
		i++;
	}
//	Sort(arrtemp,0,i-1);
	int j=0;
	TextColor(DEN);
	for (k;k<=i;k++) {	
		gotoxy(6,j+7);
		cout << k+1;
		gotoxy(14,j+7);
		cout << arrtemp[k]->MAMH;
		gotoxy(29,j+7);
		cout << arrtemp[k]->TENMH;
		gotoxy(87,j+7);
		cout << arrtemp[k]->STCLT;
		gotoxy(95,j+7);
		cout << arrtemp[k]->STCTH;
		j++;
		if (j==30) {
			break; 
		}
	}
}

void Fix_Data_MH(PTR_NODETREE &ds,int j, int k) {
	dsmh mh,ab;
	PTR_NODETREE p = ds;
	dsmh *arrtemp[500];
	PTR_NODETREE Stack[500];
	int sp = -1;
	int i = 0;
	while(p != NULL)
	{
		arrtemp[i] = new dsmh;
		strcpy(arrtemp[i]->MAMH,p->monhoc.MAMH);
		strcpy(arrtemp[i]->TENMH,p->monhoc.TENMH);
		arrtemp[i]->STCLT = p->monhoc.STCLT;
		arrtemp[i]->STCTH = p->monhoc.STCTH;
		if(p->RIGHT != NULL)
		{
			Stack[++sp] = p->RIGHT;
		}
		if(p->LEFT != NULL)
		{
			p = p->LEFT;
		}
		else if(sp == -1)
				break;
		else p = Stack[sp--];
		i++;
	}
	strcpy(mh.MAMH,arrtemp[k+j]->MAMH);
	strcpy(mh.TENMH,arrtemp[k+j]->TENMH);
	mh.STCLT = arrtemp[k+j]->STCLT;
	mh.STCTH = arrtemp[k+j]->STCTH;
	RemoveTree(ds,mh);
//	
	int max = 10,max1 = 50,max2 = 4;
	int exit=0;
	int thaotac=0;
	int soitem = 4;
	char mmh[11], tmh[51], stclt[11], stcth[11];
	ClearSignalMH(j + 7);
	ChoiceDataMH(thaotac,j+7);
	while (1) {
		char key1;
		key1 = getch();
		if (key1 == Left)
		{
			thaotac--;
			if (thaotac<=0) {
				thaotac=0;
			} 
			ClearSignalMH(j + 7);
			ChoiceDataMH(thaotac,j+7);
		}
		else if (key1 == Right)
		{
			thaotac++;
			if (thaotac > 3) {
				thaotac = 3;
			}
			ClearSignalMH(j + 7);
			ChoiceDataMH(thaotac,j+7);
		}
		else if (key1 == ESC)
		{
			break;
		}
		else if (key1 == ENTER) {
			if (thaotac==0) {
				int o=0;
				do {
					o=0;
					ClearSignalMH(j + 7);
					gotoxy(13,j+7);
					cout << "           ";
					gotoxy(14,j+7);
					InputString(mmh,max);
					if (strlen(mmh)==0) {
						o = 1;
					}
					if (Check_MaMonHoc(ds,mmh)) {
						gotoxy(13,j+7);
						cout << "          ";
						gotoxy(14,j+7);
						cout << "Bi trung";
						o = 1;
						getch();
					}
					ChoiceDataMH(thaotac,j+7);
				} while (o==1);
				strcpy(mh.MAMH,mmh);
			}
			if (thaotac==1) {
				int o=0;
				do {
					o=0;
					ClearSignalMH(j + 7);
					gotoxy(29,j+7);
					cout << "                                                  ";
					gotoxy(29,j+7);
					InputStringSpace(tmh,max1);
					if (strlen(tmh)==0) {
						o = 1;
					}
					ChoiceDataMH(thaotac,j+7);
				} while (o==1);
				strcpy(mh.TENMH,tmh);
			}
			if (thaotac==2) {
				int o=0;
				do {
					o=0;
					ClearSignalMH(j + 7);
					gotoxy(87,j+7);
					cout << "    ";
					gotoxy(87,j+7);
					InputNumber(stclt,max2);
					if (strlen(stclt)==0) {
						o = 1;
					}
					ChoiceDataMH(thaotac,j+7);
				} while (o==1);
				mh.STCLT = atoi(stclt);
			}
			if (thaotac==3) {
				int o=0;
				do {
					o=0;
					ClearSignalMH(j + 7);
					gotoxy(95,j+7);
					cout << "    ";
					gotoxy(95,j+7);
					InputNumber(stcth,max2);
					if (strlen(stcth)==0) {
						o = 1;
					}
					ChoiceDataMH(thaotac,j+7);
				} while (o==1);
				mh.STCTH = atoi(stcth);
			}
		}	
	}
	Insert_Node_Tree(ds,mh);
//	Fix_MaMonHoc(ds,arrtemp[k+j]->MAMH,mh);
}

void Sort(dsmh *a[500],int q, int r) {
	int i=q;
	int j=r;
	dsmh x;
	dsmh *temp = new dsmh;
	strcpy(x.TENMH,a[(int)(q+r)/2]->TENMH);
	do {
		while (stricmp(a[i]->TENMH,x.TENMH) < 0) i++;
		while (stricmp(a[j]->TENMH,x.TENMH) > 0) j--;
		if (i<=j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	} while (i<=j);
	if (q<j) {
		Sort(a,q,j);
	}
	if (i<r) {
		Sort(a,i,r);
	}
}

dsmh* ConvertArray(PTR_NODETREE t,int j)
{
	PTR_NODETREE p = t;
	dsmh *arrtemp[500];
	PTR_NODETREE Stack[500];
	int sp = -1;
	int i = 0;
	while(p != NULL)
	{
		arrtemp[i] = new dsmh;
		strcpy(arrtemp[i]->MAMH,p->monhoc.MAMH);
		strcpy(arrtemp[i]->TENMH,p->monhoc.TENMH);
		arrtemp[i]->STCLT = p->monhoc.STCLT;
		arrtemp[i]->STCTH = p->monhoc.STCTH;
		if(p->RIGHT != NULL)
		{
			Stack[++sp] = p->RIGHT;
		}
		if(p->LEFT != NULL)
		{
			p = p->LEFT;
		}
		else if(sp == -1)
				break;
			 else p = Stack[sp--];
		i++;
	}
	
}

int CountNode(PTR_NODETREE &t)
{
	int c = 1;             // ban than node duoc dem la 1;
	if (t == NULL)
		return 0;
	else
	{
		c += CountNode(t->LEFT);
		c += CountNode(t->RIGHT);
		return c;
	}
}

void DocFile_MH(PTR_NODETREE &ds) {
	dsmh mh;
	int so;
	string temp;
	fstream filein;
	filein.open("monhoc.txt",ios::in);
	if (filein.is_open()) {
		while (!filein.eof()) {
			getline(filein,temp);
			filein.getline(mh.MAMH,10);
			filein.getline(mh.TENMH,50);
			filein >> mh.STCLT;
			filein >> mh.STCTH;
			Insert_Node_Tree(ds,mh);
			if(filein == NULL) {
	        	break;
	    	}
		}
	} else {
		
	}
	
	filein.close();
}

//void GhiFile_MH(PTR_NODETREE &ds) {
//	fstream fileout("monhoc.txt",ios_base::out);
//	const int STACKSIZE = 100;
//	PTR_NODETREE Stack[STACKSIZE];
//	int sp = -1;
//	do 
//	{
//		
//		while(ds != NULL)
//		{
//			Stack[++sp] = ds;
//			ds = ds -> LEFT;
//		}
//		if(sp != -1)
//		{
//			ds = Stack[sp--];
//			fileout << "\n";
//			fileout << ds->monhoc.MAMH << "\n";
//			fileout << ds->monhoc.TENMH << "\n";
//			fileout << ds->monhoc.STCLT << "\n";
//			fileout << ds->monhoc.STCTH;
//			ds = ds -> RIGHT;
//		} else break;
//	} while (1);	
//
//}

void GhiFile_MH(PTR_NODETREE &ds) {
	fstream fileout("monhoc.txt",ios_base::out);
	const int STACKSIZE = 100;
	PTR_NODETREE Stack[STACKSIZE];
	int sp = -1;
	do 
	{
		
		while(ds != NULL)
		{
			Stack[++sp] = ds;
			ds = ds -> LEFT;
		}
		if(sp != -1)
		{
			ds = Stack[sp--];
			fileout << "\n";
			fileout << ds->monhoc.MAMH << "\n";
			fileout << ds->monhoc.TENMH << "\n";
			fileout << ds->monhoc.STCLT << "\n";
			fileout << ds->monhoc.STCTH;
			ds = ds -> RIGHT;
		} else break;
	} while (1);	

}

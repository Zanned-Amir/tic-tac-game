#include <iostream>
#include <vector>
#include<cstdlib>
#include <string>
using namespace std;
void show_mat(vector<vector<char>>& v);
bool test_diagonal(vector<vector<char>>& v,char c);
bool rev_test_diagonal(vector<vector<char>>& v,char c);
bool test_vertical(vector<vector<char>>& v,char c);
bool test_horizontal(vector<vector<char>>& v,char c);
bool win_check(vector<vector<char>>& v,char c);
string input(char *c);
string input2(char c,char *c1);
void turn(string p);
void choose_index(vector<vector<char>>& v, char c,char c1,string p );

int main()
{
	// vector of vector for tic tac
vector<vector<char>> t(3,vector<char>(3,' '));
// variable of X or O for each player
string p1,p2;
int k=0; //counter to number of input's player
char c=' '; //variable of player 1
char c1=' '; //variable of player 2
cout<<"\t"<<"hello to tic tac game"<<endl;
	p1=input(&c);
	p2=input2(c,&c1);
	show_mat(t);
	cout<<endl;
	do{ 
		turn(p1);
		choose_index(t,c,c1,p1);
		if(win_check(t,c)==1){//when one of 4 condition in win_check are true game will stop 
			cout<<"\t" <<p1<< " win "<<endl;
			show_mat(t);
			break;
		}
		show_mat(t);	
		k++;
		if(k==9)// when all index are full the game will stop
		{
			cout<<"draw"<<endl;
			show_mat(t);
		break;
		
		}
		turn(p2);
		choose_index(t,c1,c,p2); //when one of 4 condition in win_check are true game will stop 
		if(win_check(t,c)==1){
			cout <<p2<< " win "<<endl;
			show_mat(t);
			break;
		}
		show_mat(t);
		k++;
		cout<<k<<endl;
		}while(true);
		system("pause");
}
// input name of player 1
string input(char *c){
	string p1; // name of player
	char p; //X or O
	cout <<"    name of player 1 :"<<endl;
	cin>>p1;
	    do{
		cout<<"\t"<<p1<<" choose X or O :" <<endl;
		cin>>p;
		}while((p!='X')&&(p!='O'));
    cout<<"\t"<< p1<<" you have choosed "<< p<<": "<<endl;
	*c=p;
	return p1;
}
// input name of player 2
// if player 1 choose X player 2 take O
string input2(char c,char *c1){
	string p2; // name of player
	cout <<" name of player 2 "<<endl;
	cin>>p2;
	if (c =='X') 
		{
		*c1='O';
		}
	else 
		{
		*c1='X';	
		}
	 cout<<"\t"<<p2<<" you have choosed : "<<*c1 <<endl;
	return p2;
}
// player choose where he put X or O
void choose_index(vector<vector<char>>& v, char c,char c1 ,string p ){
	int l,co,k=0,k1=0,k2=0;
	do{
		if(k>0){cout<<"   choose empty index "<<endl;}
	do{
		if(k1>0){cout<<"   choose right row  "<<endl;}
	cout<<"    choose ligne : "<< p<<endl;
	cin>>l;
	k1++;
	}
	while(l>=3);
	do{
		if(k2>0){cout<<"   choose right column "<<endl;}
	cout<<"     choose column : "<< p<<endl;
	cin>>co;
	k2++;
	}while(co>=3);
	k++;k1=0;k2=0;
	}while((v[l][co]==c1 )||(v[l][co]==c ));
   v[l][co]=c;
      

}
// printing name of next player
void turn(string p){
	cout<<"  your turn :"<<p<<endl; 
}
//show you matrice 
void show_mat(vector<vector<char>>& v)
	{
		cout<<"\t"<<"    0      1      2"<<endl;
		for(int i=0;i<3;i++)
		{   
			 cout<<"\t"<<"  ___________________"<<endl;
			 cout<<"\t"<<i<<" ";
 			for (int j=0;j<3;j++)
			{
	 			cout<< "| " <<v[i][j]<<" |"<<"  " ;
			}
 		cout<<endl;
 		}
		     cout<<"\t"<< "  ___________________"<<"\n";
	}
	// verify if diagonal position are the same 
bool test_diagonal(vector<vector<char>>& v,char c){
	int k=0;
	bool test=true;
	for (int i=0;i<3;i++)
		{
     	if(v[i][i]== c)
			{
			k++; 
			}
		else
			{
			test=false;
			}
		  }
    return test ;	
    }
// verify if reverse diagonal position are the same 
bool rev_test_diagonal(vector<vector<char>>& v,char c){
	int k=2;
	bool test=true;
	for (int i=0;i<3;i++)
		{
     	if(v[k][i]== c)
			{
			k--; 
			}
		else
			{
			test=false;
			}
		  }
    return test ;	
    }
	// verify if one of 3 column are same horizontally
bool test_horizontal(vector<vector<char>>& v,char c){
	bool test =false;
	for(int i=0;i<3;i++)
		{
		int k=0;
		for(int j=0;j<3;j++)
			{
				if (v[i][j]==c) 
				k++;
		    }
		if (k==3)	
			{
			test=true;
			}
		}
	return test;

}
// verify if one of the row are same vertically
bool test_vertical(vector<vector<char>>& v,char c){
	bool test =false;
	for(int i=0;i<3;i++)
		{
		int k=0;
		for(int j=0;j<3;j++)
			{
				if (v[j][i]==c) 
				k++;
		    }
		if (k==3)	
			{
			test=true;
			}
		}
	return test;}
	// testing all conditions in one function 
	bool win_check(vector<vector<char>>& v,char c){
		if((test_diagonal(v,c)==true)||(test_horizontal(v,c)==true)||(test_vertical(v,c)==true)||(rev_test_diagonal(v,c)==true)){
			return true;
		}
		else return false;
	}

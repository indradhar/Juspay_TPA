/**************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

***************************/
#include<bits/stdc++.h>
using namespace std;

//Position validating function, based on previously positioned Bishops
bool checkPos(int r, int c, int n, vector<string> &V)
{
	for (int i = r, j = c; i >= 0 && j >= 0; i--, j--) 
	{
	    if (V[i][j] == 'B')return false;
	}

	for (int i = r, j = c; i >= 0 && j < n; i--, j++)
	{
	    if (V[i][j] == 'B')return false;
	}

	return true;
}

void Bishop(int i, int n, vector<string> &V, vector<vector<string>> &ans)
{
	if (i == n)
	{
		ans.push_back(V);
		return;
	}

	//Validating all positions in each row
	//If valid, place the Bishop and move further
	for (int j = 0; j < n; j++)
	{
		
        if (checkPos(i, j, n, V))
        {
        	V[i][j] = 'B';
        	Bishop(i + 1, n, V, ans);
        	V[i][j] = '.';
        }
    }
}

int main()
{
	//8-Bishops
	int n = 8;
	vector<string> V;

	string S = "";
	for (int j = 0; j < n; j++)S += '.';

	for (int i = 0; i < n; i++)
	{
		V.push_back(S);
	}

	vector<vector<string>> ans;

	//Calling recursive helper function
	Bishop(0, n, V, ans);

	//Printing all possible solutions
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j] << endl;
		}
		cout << endl << endl;
	}
}
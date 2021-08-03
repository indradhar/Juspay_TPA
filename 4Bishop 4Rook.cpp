#include<bits/stdc++.h>
using namespace std;
bool checkPos(int r, int c, int n, vector<string> &V);
void Bishop(int row, int n, vector<string> &v, vector<vector<string>> &res);

int main()
{
	//4-Bishops and 4-Rooks
	int n = 8;
	vector<string> v;
	string s = "";
	for (int j = 0; j < n; j++)s += ',';

	for (int i = 0; i < n; i++)
	{
		v.push_back(s);
	}

	vector<vector<string>> ans;

	//Calling recursive helper function
	Bishop(0, n, v, ans);

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

//Position validating function, based on previously positioned Bishops and Rooks
bool checkPos(int r, int c, int n, vector<string> &V)
{
	//If current row is even, validate for positioning Bishop
	if (r % 2 == 0)
	{
		for (int i = 0; i<= r; i++) 
		{
		    if (V[i][c] == 'R')return false;
		}

		for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
		{
		    if (V[i][j] == 'B' || V[i][j] == 'R')return false;
		}

		for (int i = r, j = c; i >= 0 && j < n; i--, j++)
		{
		    if (V[i][j] == 'B' || V[i][j] == 'R')return false;
		}
	}
	else  //If current row is odd, validate for positioning Rook
	{
		for (int i = 0; i <= r; i++)
		{
		    if (V[i][c] == 'R' || V[i][c] == 'B')return false;
		}

		for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
		{
		    if (V[i][j] == 'B')return false;
		}

		for (int i = r, j = c; i >= 0 && j < n; i--, j++)
		{
		    if (V[i][j] == 'B')return false;
		}
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
	//If valid, place the Bishop or Rook and move further
	for (int j = 0; j < n; j++)
	{
		if (checkPos(i, j, n, V))
		{
			if (i % 2 == 0) V[i][j] = 'B';                     //If row is even, place Bishop
			else V[i][j] = 'R';				//If row is odd, place Rook

			Bishop(i + 1, n, V, ans);
			V[i][j] = ',';
		}
	}
}

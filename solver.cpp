
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;

const char *insatstr="intmp.txt";
const char *outsatstr="outtmp.txt";

int N=0;
vector<vector<int>> cla;

void gen(vector<int> &v)
{
	cla.push_back(vector<int>(v.begin(), v.end()));
	for(int i=0; i<v.size(); i++)
		for(int j=i+1; j<v.size(); j++)
			cla.push_back({-v[i], -v[j]});
}

int to(int i, int j, int d)
{
	return 1+(i*N*N+j*N+d-1);
}

int main(int argc, char **argv)
{
	ifstream in(argv[1]);
	ofstream out(argv[2]);
	string str;
	vector<vector<int>> mat;
	while(getline(in, str))
	{
		N++;
		mat.push_back({});
		istringstream iss(str);
		int x;
		while(iss>>x)
			mat.back().push_back(x);
	}
	int n=sqrt(N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
		{
			vector<int> v;
			for(int k=1; k<=N; k++)
				v.push_back(to(i, j, k));
			gen(v);
			if(mat[i][j]!=0)
				cla.push_back({to(i, j, mat[i][j])});
		}
	for(int i=0; i<N; i++)
		for(int k=1; k<=N; k++)
		{
			vector<int> v;
			for(int j=0; j<N; j++)
				v.push_back(to(i, j, k));
			gen(v);
			v.clear();
			for(int j=0; j<N; j++)
				v.push_back(to(j, i, k));
			gen(v);
		}
	for(int x=0; x<N; x+=n)
		for(int y=0; y<N; y+=n)
			for(int k=1; k<=N; k++)
			{
				vector<int> v;
				for(int i=0; i<n; i++)
					for(int j=0; j<n; j++)
						v.push_back(to(x+i, y+j, k));
				gen(v);
			}
	ofstream insat(insatstr);
	insat<<"p cnf "<<(N*N*N)<<" "<<cla.size()<<endl;
	for(vector<int> &v: cla)
	{
		for(int x: v)
			insat<<x<<" ";
		insat<<0<<endl;
	}
	insat.flush();
	insat.close();
	string cmd="./"; cmd+=argv[3]; cmd+=" "; cmd+=insatstr; cmd+=" "; cmd+=outsatstr;
	system(cmd.c_str());
	ifstream outsat(outsatstr);
	outsat>>str;
	if(str=="SAT")
	{
		for(int x; outsat>>x && x; )
			if((x--)>0)
				mat[x/N/N][x/N%N]=x%N+1;
		for(int i=0; i<N; i++, out<<endl)
			for(int j=0; j<N; j++)
				out<<setw(2)<<mat[i][j]<<" ";
	}
	else
		out<<"NO"<<endl;
	remove(insatstr);
	remove(outsatstr);
}

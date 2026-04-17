#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int> _map;
vector<string> v;

int main()
{
	int n, m;
	char name[25];

	scanf(" %d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		scanf(" %s", name);
		_map[name] = 1;
	}
	for(int i = 0; i < m; i++)
	{
		scanf(" %s", name);
		if (_map[name] == 1)
			v.push_back(name);
	}

	sort(v.begin(), v.end());

	printf("%d\n", v.size());
	for (int i = 0; i < v.size(); i++)
		printf("%s\n", v[i].c_str());
}
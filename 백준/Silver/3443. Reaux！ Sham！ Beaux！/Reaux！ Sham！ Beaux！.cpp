#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int>pii;
int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	map<string, int>mm = { {"Kamen",2},{"Rock",2} ,{"Pierre",2} ,{"Stein",2} ,
	{"Ko",2} ,{"Koe",2} ,{"Sasso",2} ,{"Roccia",2} ,{"Guu",2} ,{"Kamien",2} ,{"Piedra",2},
		{"Nuzky",1},{"Scissors",1},{"Ciseaux",1},{"Schere",1},{"Ollo",1},{"Olloo",1},{"Forbice",1},
		{"Choki",1},{"Nozyce",1},{"Tijera",1},
		{"Papir",3},{"Paper",3},{"Feuille",3},{"Papier",3},{"Carta",3},{"Rete",3},{"Paa",3},
		{"Papel",3}
	};
	// 가위, 바위, 보
	auto check = [&](int a, int b)
		{
			if (a == b)
			{
				return 0;
			}
			else if ((a == 1 && b == 3) || (a == 2 && b == 1) || (a == 3 && b == 2))
			{
				return 1;
			}
			else
			{
				return -1;
			}
		};
	int cnt = 1;
	while (1)
	{
		string na, nb;
		cin >> na;
		int sa = 0, sb = 0;
		bool crash = false, now = false;
		cin >> na >> nb >> nb;
		vector<pii>v;
		string a, b;
		while (1)
		{
			cin >> a;
			if (a == "-")
			{
				break;
			}
			else if (a == ".")
			{
				crash = true;
				break;
			}
			cin >> b;
			int res = check(mm[a], mm[b]);
			if (res == 1)
			{
				sa++;
			}
			else if (res == -1)
			{
				sb++;
			}
		}
		cout << format("Game #{}:\n", cnt++);
		cout << format("{}: {} point", na, sa);
		if (sa != 1)
		{
			cout << "s";
		}
		cout << '\n';
		cout << format("{}: {} point", nb, sb);
		if (sb != 1)
		{
			cout << "s";
		}
		cout << '\n';
		if (sa == sb)
		{
			cout << "TIED GAME\n";
		}
		else if (sa > sb)
		{
			cout << format("WINNER: {}\n", na);
		}
		else
		{
			cout << format("WINNER: {}\n", nb);
		}
		if (crash)
		{
			break;
		}
		cout << '\n';
	}
	return 0;
}
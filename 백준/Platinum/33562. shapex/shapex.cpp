#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void)
{
	cin.tie(0)->sync_with_stdio(0);
	int n = 0, m = 0;
	cin >> n >> m;
	vector<vector<vector<string>>>R(101);
	for (int i = 1; i <= n; ++i)
	{
		string str, tt;
		cin >> str;
		vector<string>temp;
		int idx = 0, cnt = 0;
		while (idx < (int)str.size())
		{
			tt += str[idx];
			tt += str[idx + 1];
			temp.push_back(tt);
			tt = "";
			cnt++;
			if (cnt == 4)
			{
				R[i].push_back(temp);
				temp.clear();
				cnt = 0;
				idx++;
			}
			idx += 2;
		}
	}
	auto check = [&](vector<string>& v)
		{
			for (auto& i : v)
			{
				if (i != "--")
				{
					return true;
				}
			}
			return false;
		};
	auto prt = [&](int idx)
		{
			int cnt = 0;
			string ans = "";
			for (auto& i : R[idx])
			{
				for (auto& j : i)
				{
					cnt++;
					ans += j;
					if (cnt == 4)
					{
						ans += ":";
						cnt = 0;
					}
				}
			}
			if (ans.empty())
			{
				cout << "None";
			}
			else
			{
				ans.pop_back();
				cout << ans;
			}
		};
	auto cut1 = [&](int idx)
		{
			vector<vector<string>>ans;
			for (auto& i : R[idx])
			{
				vector<string>ok = { "--","--",i[2],i[3] };
				if (check(ok))
				{
					ans.push_back(ok);
				}
			}
			return ans;
		};
	auto cut2 = [&](int idx)
		{
			vector<vector<string>>ans;
			for (auto& i : R[idx])
			{
				vector<string>ok = { i[0],i[1] , "--","--" };
				if (check(ok))
				{
					ans.push_back(ok);
				}
			}
			return ans;
		};
	auto rot = [&](int idx, int num)
		{
			vector<vector<string>>ans = R[idx];
			for (auto& i : ans)
			{
				for (int j = 0; j < num; ++j)
				{
					auto temp = i;
					i[0] = temp[3], i[1] = temp[0], i[2] = temp[1], i[3] = temp[2];
				}
			}
			return ans;
		};

	auto sv = [&](int A, int B)
		{
			auto a = R[A];
			auto b = R[B];
			int alen = a.size(), blen = b.size();
			auto cal = [&](int p)
				{
					for (int i = 0; i < blen; ++i)
					{
						int pivot = p + i;
						if (pivot < alen)
						{
							for (int j = 0; j < 4; ++j)
							{
								if (a[pivot][j] != "--" && b[i][j] != "--")
								{
									return false;
								}
							}
						}
					}
					return true;
				};
			if (a.empty())
			{
				return b;
			}
			if (b.empty())
			{
				return a;
			}
			int pivot = alen;
			while (pivot > 0 && cal(pivot - 1))
			{
				pivot--;
			}
			vector<vector<string>>ans(max(alen, pivot + blen), vector<string>(4, "--"));
			for (int i = 0; i < alen; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (a[i][j] != "--")
					{
						ans[i][j] = a[i][j];
					}
				}
			}
			for (int i = 0; i < blen; ++i)
			{
				for (int j = 0; j < 4; ++j)
				{
					if (b[i][j] != "--")
					{
						ans[i + pivot][j] = b[i][j];
					}
				}
			}
			vector<vector<string>>fin;
			int len = ans.size();
			for (int i = 0; i < min(4, len); ++i)
			{
				fin.push_back(ans[i]);
			}
			return fin;
		};
	auto pt = [&](int idx, char pp)
		{
			vector<vector<string>>ans = R[idx];
			for (auto& i : ans)
			{
				for (auto& j : i)
				{
					if (j[0] != '-')
					{
						j[1] = pp;
					}
				}
			}
			return ans;
		};
	while (m--)
	{
		int a = 0, b = 0, c = 0;
		cin >> a >> b >> c;
		if (a == 1)
		{
			int d = 0;
			cin >> d;
			if (R[b].empty())
			{
				R[c].clear();
				R[d].clear();
				continue;
			}
			auto aa = cut1(b);
			auto bb = cut2(b);
			R[c] = aa;
			R[d] = bb;
		}
		else if (a == 2)
		{
			int d = 0;
			cin >> d;
			if (R[b].empty())
			{
				R[c].clear();
				continue;
			}
			auto aa = rot(b, d);
			R[c] = aa;
		}
		else if (a == 3)
		{
			int d = 0;
			cin >> d;
			if (R[b].empty() || R[c].empty())
			{
				R[d].clear();
				continue;
			}
			auto aa = sv(b, c);
			R[d] = aa;
		}
		else
		{
			char d;
			cin >> d;
			if (R[b].empty())
			{
				R[c].clear();
				continue;
			}
			auto aa = pt(b, d);
			R[c] = aa;
		}
	}
	prt(100);
	return 0;
}
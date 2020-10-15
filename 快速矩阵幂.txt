#include<iostream>
#include<cstring>
using namespace std;
#define _CRT_SECURE_NO_WARNINGS

typedef long long ll;
const int mod = 1e9 + 7;

ll n=2, M,ans;

struct Matrix {
	ll m[15][15];

	Matrix() {
		memset(m, 0, sizeof(m));
		for (int i = 0; i <= n + 1; i++) {
			m[i][n + 1] = 1;
			if (i == n + 1) continue;
			m[i][0] = 10;
			for (int j = 1; j <= i; j++)
				m[i][j] = 1;
		}
	}

	void clear() {
		memset(m, 0, sizeof(m));
		for (int i = 0; i <= n + 1; i++)
			m[i][i] = 1;
	}

	void display() {
		cout << "Matrix's begin:" << endl;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << m[i][j] << ' ';
			}
			cout << '\n';
		}
		cout << "Matrix's end:" << endl;
	}

	friend Matrix operator*(Matrix a, Matrix b) {
		Matrix ans;
		for (int i = 0; i <= n + 1; i++)
			for (int j = 0; j <= n + 1; j++) {
				ans.m[i][j] = 0;
				for (int k = 0; k <= n + 1; k++)
					ans.m[i][j] += a.m[i][k] * b.m[k][j] % mod;
			}
		return ans;
	}

	friend Matrix operator^(Matrix base, ll k) {
		Matrix ans;
		ans.clear();
		while (k) {
			if (k & 1) ans = ans * base;
			base = base * base;
			k >>= 1;
		}
		return ans;
	}

};

int main() {
	cin >> M;
	//	cout<<"hello"<<endl;
		Matrix base; ans = 0;
		/*for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				cin >> base.m[i][j];
		}*/
		base.m[1][1] = 0; base.m[1][2] = 1;
		base.m[2][1] = 1; base.m[2][2] = 1;
		base = base ^ (M-1);
			//	base.display();
		ans += base.m[1][1] + base.m[1][2];
		cout<<(ans % mod);
	return 0;
}
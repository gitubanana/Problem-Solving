#include <bits/stdc++.h>

// 테스트용

using namespace std;

using ii = pair<int, int>;

const int dx[4]{1, -1, 0, 0};
const int dy[4]{0, 0, 1, -1};

int R, C;
vector<string> A;
vector<ii> B;

bool dfs(int x, int y) {
	if (x == R - 1) {
		return false;
	}
	A[x][y] = '.';
	B.push_back({x, y});
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < R && 0 <= ny && ny < C && A[nx][ny] == 'x') {
			if (!dfs(nx, ny)) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> R >> C;
	cin.ignore();
	A.resize(R);
	for (int i = 0; i < R; ++i) {
		getline(cin, A[i]);
	}
	int Q{};
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int x{};
		cin >> x;
		x = R - x;
		int y = i % 2 ? C - 1 : 0;
		while (0 <= y && y < C && A[x][y] == '.') {
			y += i % 2 ? -1 : 1;
		}
		if (y == -1 || y == C) {
			continue;
		}
		A[x][y] = '.';
		B.clear();
		for (int j = 0; j < 4; ++j) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (0 <= nx && nx < R && 0 <= ny && ny < C && A[nx][ny] == 'x') {
				if (dfs(nx, ny)) {
					break;
				}
				for (auto &[x, y] : B) {
					A[x][y] = 'x';
				}
				B.clear();
			}
		}
		if (B.empty()) {
			continue;
		}
		int p{};
		while (true) {
			bool yes = true;
			for (auto &[x, y] : B) {
				if (x + p == R - 1 || A[x + p + 1][y] == 'x') {
					yes = false;
					break;
				}
			}
			if (!yes) {
				break;
			}
			++p;
		}
		for (auto &[x, y] : B) {
			A[x + p][y] = 'x';
		}
	}
	for (auto &s : A) {
		cout << s << "\n";
	}
	return 0;
}

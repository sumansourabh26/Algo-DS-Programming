#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <numeric>
#include <cassert>
#include <cmath>
using namespace std;
typedef unsigned int uint;
typedef vector<int> VI;
typedef vector<VI> VVI;

#define FOR(k,a,b) for(uint k(a); k < (b); ++k)
#define REP(k,a) for(uint k=0; k < (a); ++k)

int N, M, T, a, b;
VVI A, vSum;

struct RMQ
{
	int L, R, OS, S, ans, prev;
	VI data;

	void init(const VI& v)
	{
		data.clear();
		S = 1, OS = v.size();
		while (S < v.size())
		{
			S <<= 1;
		}
		data.resize(2 * S + 2);
		REP(i, v.size())
		{
			data[S - 1 + i] = v[i];
		}
		for (int i = S - 2;i > -1;--i)
		{
			data[i] = max(data[2 * i + 1], data[2 * i + 2]);
		}
		prev = -1;
	}

	int query(int from, int to)
	{
		ans = 0;
		if(from == to)
			return data[S - 1 + from];
		L = from + 1, R = to + 1;
		int z = data[S - 1 + to];
 		if (z >= prev && prev != -1)
 			return prev = z;
		if (S - 2 + from > -1)
		{
			int s = data[S - 2 + from];
			if (s < prev)
				return prev;
		}
		return prev = query(0, 1, S);
	}
private:
	inline int query(int pos, int currl, int currr)
	{
		if (currr < L || currl > R || ans > data[pos])
			return 0;
		if (currl >= L && R >= currr)
			return ans = data[pos];
		int left = query(2 * pos + 1, currl, (currl + currr) / 2);
		int right = query(2 * pos + 2, (currl + currr) / 2 + 1, currr);
		return ans = max(left, right);
	}
};

int main(int argc, char** argv) {
#ifdef HOME
	freopen("in.txt", "rb", stdin);
	freopen("out.txt", "wb", stdout);
#endif
	int N, M;
	scanf("%d %d", &N, &M);
	A = VVI(N, VI(M));
	vSum = VVI(N, VI(M));
	REP(i, N) REP(j, M)
	{
		scanf("%d", &A[i][j]);
	}
	vSum[0][0] = A[0][0];
	FOR(i, 1, N)
	{
		vSum[i][0] = vSum[i - 1][0] + A[i][0];
	}
	FOR(j, 1, M)
	{
		vSum[0][j] = vSum[0][j - 1] + A[0][j];
	}
	FOR(i, 1, N) FOR(j, 1, M)
	{
		vSum[i][j] = A[i][j] + vSum[i - 1][j] + vSum[i][j - 1] - vSum[i - 1][j - 1];
	}

	vector<RMQ> vRMQ(N);
	vector<int> vMX;
	RMQ rr;
	REP(i, N)
		vRMQ[i].init(A[i]);
	scanf("%d", &T);
	REP(tc, T)
	{
		scanf("%d %d", &a, &b);
		int bst = 1e9, bsti, bstj;
		REP(i, N)
			vRMQ[i].prev = -1;
		REP(j, M + 1 - b)
		{
			vMX.clear();
			REP(i, N)
			{
				int tmp = vRMQ[i].query(j, j + b - 1);
				vMX.push_back(tmp);
			}
			rr.init(vMX);
			rr.prev = -1;
			REP(i, N + 1 - a)
			{
				int su = vSum[i + a - 1][j + b - 1];
				if (i)
					su -= vSum[i - 1][j + b - 1];
				if (j)
					su -= vSum[i + a - 1][j - 1];
				if (i && j)
					su += vSum[i - 1][j - 1];
				int mx = rr.query(i, i + a - 1);
				mx = mx * a * b - su;
				//printf("steps i:%d j:%d are %d\n",i,j, mx);
				if (bst > mx)
				{
					bst = mx;
					bsti = i;
					bstj = j;
				}
			}
		}
		printf("%d\n", bst);
		//printf("%d %d %d\n", bst, bsti, bstj);
	}

	return 0;
}
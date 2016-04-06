#include <iostream>
#include <cmath>

using namespace std;
int ALL_N[1000];

bool isok(int ans, int N, int P, int W ,int H)
{
    int oneline = floor(W/ans);
    int lines = floor(H/ans) * P;
	int line_sum = 0;

	for (int i = 0; i < N; i++) {
		line_sum += ceil(ALL_N[i] / oneline);
	}

	if (line_sum > lines)
		return false;
	return true;
}


int solve(int N, int P, int W ,int H)
{
	int v_sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> ALL_N[i];
		v_sum += ALL_N[i];
	}
	int maxs = std::min(W,H);

	while(maxs > 0) {
		if(isok(maxs, N, P, W, H)){
			return maxs;
		}
		maxs--;
	}
	return -1;
}

int main(void) {
    	
	int  TASKS;
	cin >> TASKS;
	while(TASKS--){
		int N, P, W ,H;
		cin >> N >> P >> W >> H;
		cout<< solve(N, P, W ,H) << endl;
	}
    return 0;
}
// 求平面上距离最近的两点的距离

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using std::cin; using std::cout; using std::endl;
using std::string;
using std::sort;

const double INF = 0x3f3f3f3f;
struct point
{
	double x;
	double y;
}p[100005], tmp[100005];

int cmp(const point &a, const point &b) 
{
	if(a.x == b.x)
		return a.y < b.y;
	return a.x < b.x;
}

int cmp_y(const point &a, const point &b) 
{
	return a.y < b.y;
}

double dis(const point &a, const point &b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double closest(int left, int right)
{
	double d = INF;
	if (left == right)
		return d;
	if(left + 1 == right)
		return dis(p[left], p[right]);

	int mid = (left + right) / 2;
	double dl = closest(left, mid);
	double dr = closest(mid + 1, right);
	d = dl < dr ? dl : dr;

	//找出来自左右两边的可能点
	int near_k = 0;
	for(int i = left; i <= right ; i++) {
		if (fabs(p[mid].x - p[i].x) <= d) {
			tmp[near_k++] = p[i];
		}
	}

	sort(tmp, tmp + near_k, cmp_y);

	//按y方向进行选择
	for(int i = 0; i < near_k; i++) 
	    for(int j = i+1; j < near_k && tmp[j].y-tmp[i].y < d; j++) {
	    	double newd = dis(tmp[i], tmp[j]);
	    	if ( newd < d )
	    		d = newd;
	    }
	return d;
}

int main(int argc, char const *argv[])
{
	int n;
	while(scanf("%d",&n)==1 && n)
    {
        for(int i=0; i < n; i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        sort(p,p+n,cmp);
        printf("%.2lf\n",closest(0,n-1)/2);
    }
	
	return 0;
}
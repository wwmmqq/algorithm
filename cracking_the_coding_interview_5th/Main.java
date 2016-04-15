import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

class Point {
	double x;
	double y;

	public Point() {
	}

	public Point(double x, double y) {
		this.x = x;
		this.y = y;
	}
	
}

class PointSortByx implements Comparator<Point> {
	@Override
	public int compare(Point p1, Point p2) {
		// TODO Auto-generated method stub
		// 按照由小到大排序
		if (p1.x < p2.x)
			return -1;
		if (p1.x > p2.x)
			return 1;
		return 0;
	}
}

public class Main {
	static Point[] p = new Point[100000];
	static Point[] nearPoints=new Point[100000];
	public static double nearestPoint(int start,int end){
		//只有一个点
		if(start==end){
			return Double.MAX_VALUE;
		}
		//只有两个点
		if(start+1==end){
			return computeDistance(p[start],p[end]);
		}
		//三个点以上的情况
		int center = start + (end-start) / 2;
		int flag=0;
		double distanceLeft=nearestPoint(start,center);
		double distanceRight=nearestPoint(center+1,end);
		double distanceMin=min(distanceLeft,distanceRight);
		//选出距离中间线小于distanceMin的点
		for(int i=start;i<=end;i++){
			if(Math.abs(p[center].x-p[i].x) <= distanceMin){
				nearPoints[flag++]=p[i];
			}
		}
		//按照y的从小到大排序
		Arrays.sort(nearPoints, 0,flag-1,new Comparator<Point>(){
			@Override
			public int compare(Point p1, Point p2) {
				// TODO Auto-generated method stub
				// 按照由小到大排序
				if (p1.y < p2.y)
					return -1;
				if (p1.y > p2.y)
					return 1;
				return 0;
			}
		});

		for (int i = 0; i < flag; i++) {
			for (int j = i + 1; j < flag && nearPoints[j].y-nearPoints[i].y < distanceMin; j++) {
				double d = computeDistance(nearPoints[j], nearPoints[i]);
				if (d < distanceMin) {
					distanceMin = d;
				}
			}
		}
		return distanceMin;
	}

	public static double min(double x,double y){
		return x<=y ? x : y;
	}
	public static double computeDistance(Point p1,Point p2){
		if(p1==p2){
			return 0;
		}
		else{
			double square=Math.pow(p1.x-p2.x,2)+Math.pow(p1.y-p2.y,2);
			double distance=Math.sqrt(square);
			return distance;
		}
		
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner console = new Scanner(System.in);
		while (true) {
			int N = console.nextInt();
			double x;
			double y;
			double min;
			if (N == 0) {
				break;
			} else {
				for (int i = 0; i < N; i++) {
					x = console.nextDouble();
					y = console.nextDouble();
					p[i] = new Point(x, y);
				}
				//按照x的从小到大排序
				Arrays.sort(p, 0, N-1, new PointSortByx());
				//进行最近邻对求解
				min=nearestPoint(0,N-1);
				String result = String.format("%.2f",min/2);
				System.out.println(result);
			}
		}
	}
}
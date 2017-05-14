// Tested by https://leetcode.com/problems/erect-the-fence/#/description
public class ConvexHull {
	// (a - o) * (b - o)
	private int cross(Point o, Point a, Point b) {
		return Long.signum(((long) a.x - o.x) * (b.y - o.y) - ((long) a.y - o.y) * (b.x - o.x));
	}

	public List<Point> convexHull(Point[] points, boolean inclusive/* includes inline points */) {
		Arrays.sort(points, (a, b) -> {
			return (a.x == b.x) ? Integer.compare(a.y, b.y) : Integer.compare(a.x, b.x);
		});
		int n = points.length, signum = (inclusive ? 1 : 0), m1 = 0, m2 = 0;
		Point[] q1 = new Point[n], q2 = new Point[n];
		for (int i = 0; i < n; i++) {
			while (m1 >= 2 && cross(q1[m1 - 2], q1[m1 - 1], points[i]) >= signum)
				m1--;
			while (m2 >= 2 && cross(q2[m2 - 2], q2[m2 - 1], points[i]) <= -signum)
				m2--;
			q1[m1++] = q2[m2++] = points[i];
		}
		List<Point> res = new ArrayList<>();
		for (int i = 0; i < m1; i++)
			res.add(q1[i]);
		if (res.size() < n) {
			int r = m2 - 2, l = 1;
			if (inclusive) {
				while (l <= r && q2[r].x == q2[m2 - 1].x && q2[r].y == q2[m2 - 1].y)
					r--;
				while (l <= r && q2[l].x == q2[0].x && q2[l].y == q2[0].y)
					l++;
			}
			for (int i = r; i >= l; i--)
				res.add(q2[i]);
		}
		return res;
	}
}

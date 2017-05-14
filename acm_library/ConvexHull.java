// Tested by https://leetcode.com/problems/erect-the-fence/#/description
public class ConvexHull {
	// (a - o) * (b - o)
	private int cross(Point o, Point a, Point b) {
		return Long.signum(((long) a.x - o.x) * (b.y - o.y) - ((long) a.y - o.y) * (b.x - o.x));
	}

	public Point[] convexHull(Point[] points, boolean inclusive) {
		int n = points.length, signum = (inclusive ? 1 : 0);
		if (n <= 2) {
			if (n == 2 && !inclusive && points[0].x == points[1].x && points[0].y == points[1].y) {
				return Arrays.copyOf(points, 1);
			} else {
				return Arrays.copyOf(points, n);
			}
		}
		Arrays.sort(points, (a, b) -> {
			return (a.x == b.x) ? Integer.compare(a.y, b.y) : Integer.compare(a.x, b.x);
		});
		int m1 = 0, m2 = 0;
		Point[] q1 = new Point[n], q2 = new Point[n];
		for (int i = 0; i < n; i++) {
			while (m1 >= 2 && cross(q1[m1 - 2], q1[m1 - 1], points[i]) >= signum)
				m1--;
			while (m2 >= 2 && cross(q2[m2 - 2], q2[m2 - 1], points[i]) <= -signum)
				m2--;
			q1[m1++] = q2[m2++] = points[i];
		}
		if (m1 < n) {
			for (int i = m2 - 2; i >= 1; i--) {
				if (!(q2[i].x == q2[0].x && q2[i].y == q2[0].y)
						&& !(q2[i].x == q2[m2 - 1].x && q2[i].y == q2[m2 - 1].y)) {
					q1[m1++] = q2[i];
				}
			}
		}
		return Arrays.copyOf(q1, m1);
	}
}

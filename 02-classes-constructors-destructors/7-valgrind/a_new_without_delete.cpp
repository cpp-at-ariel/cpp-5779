class Point {
	int x, y;
	void f() { x=5; }
	void g() { y=x*x; }
	void h() { x=y+x; }
};

int main() {
	Point* array = new Point[1000];
	//delete[] array;
	return 0;
}

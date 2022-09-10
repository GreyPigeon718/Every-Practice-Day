#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;


class R
{
public:
	R(int r1, int r2)
	{
		R1 = r1;
		R2 = r2;
	}
	void print();
	void print() const;
private:
	int R1, R2;
};
void R::print()
{
	cout << R1 << ", " << R2 << endl;
};
void R::print()const
{
	cout << R1 << ", " << R2 << endl;
}
int main()
{
	vector A = (4, 2);
	/*R a(5, 6);
	const R b(66, 78);
	b.print();*/
	/*char* p = NULL;
	char str[] = "hello";
	p = str;*/
	int arr[3] = { 0,1,2 };
	int* p, * q;
	p = arr;
	q = &arr[2];
	cout << arr[q - p];
	return 0;



	return 0;
}
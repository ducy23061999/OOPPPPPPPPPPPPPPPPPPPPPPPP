#include <iostream>
#include "math.h"
using namespace std;
// C:\Users\Dell\AppData\Roaming\Sublime Text 3\Packages\User
#define ll long long
 
class SoPhuc
{
	private: int a,b;
	public:
		void nhap()
		{
			cout << "Nhap phan thuc a = "; cin >> a;
			cout << "Nhap phan ao b = "; cin >> b;
		}
		void xuat()
		{
			cout << a << " + " << b << "i" << endl; 
		}
		SoPhuc nhan(SoPhuc ob2)
		{
			SoPhuc ob3; 
			ob3.a = a*ob2.a - b*ob2.b;
			ob3.b = a*ob2.b + b * ob2.a;
			return ob3; 
		}
		void chia(SoPhuc ob2)
		{
			SoPhuc ob3;
			int temp = (float)(pow(ob2.a,2) + pow(ob2.b,2));
			if((a*ob2.a + b * ob2.b)%temp == 0) cout << (a*ob2.a + b * ob2.b)/temp;
			else cout << (a*ob2.a + b * ob2.b) << "/" << temp << " ";
			if((b*ob2.a - a * ob2.b) > 0) cout << "+ ";
			if((b*ob2.a - a * ob2.b)%temp == 0) cout << (b*ob2.a - a * ob2.b)/temp << "i" << endl;
			else cout << (b*ob2.a - a * ob2.b)  << "i/" << temp << endl;
		}
		SoPhuc operator + (int n)
		{
			a = a + n;
			return (*this);
		}
		SoPhuc operator + ()
		{
			int n;
			cout << "Nhap so n2 = "; cin >> n;
			a = a + n;
			return (*this);
		}
		float operator ! ()
		{
			return (float)sqrt(pow(a,2) + pow(b,2));
		}
 
};
int main()
{
//	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	SoPhuc ob1,ob2;
	ob1.nhap();
	ob2.nhap();
	ob1.xuat();
	ob2.xuat();
	cout << "Ket qua phep nhan ob1 va ob2 la: "; 
	SoPhuc ob3 = ob1.nhan(ob2);
	ob3.xuat();
	cout << "Ket qua phep chia ob1 va ob2 la: ";
	ob1.chia(ob2);
	cout << "Nhap vao so nguyen n: ";
	int n; cin >> n;
	cout << "Ket qua khi cong so phuc ob3 voi so nguyen n1 la: ";
	ob3 = n + ob1;
	ob3.xuat();
	SoPhuc ob4;
	ob4.nhap();
	+ob4;
	cout << "Ket qua khi cong so n2 voi so phuc ob1 la: ";
	ob4.xuat();
	cout << "Do dai cua ob2 la: " << !ob2 << endl;
}
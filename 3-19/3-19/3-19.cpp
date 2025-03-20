//#include <iostream>
//using namespace std;
//
//int main()
//{
	/*int a;
	cin >> a;
	cout << "a=" << a << endl;*/

	/*int x;
	cin >> x;
	if (x & 1)
	{
		cout << "x是奇数";
	}*/


	//条件运算符
	/*int a = 3, b = 4;
	int x = -1;


	a>b ? x=a:x= b;
	cout << x << endl;*/



	//	return 0;
	//}

//switch
//#include <iostream>
//using namespace std;
//int main()
//{
//	int x = 0;
//	cin >> x;
//	switch (x)
//	{
//	case 66:
//		cout << 66;
//		break;
//	case 9:
//		cout << 23;
//		break;
//	default:
//		cout << "打错了";
//		break;
//	}
//	return 0;
//}


//do while 
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 0;
//	do {
//		cout << a << endl;
//		a += 1;
//	} while (a < 3);
//	return 0;
//}

/*
HDOJ 1000 A + B Problem
https://acm.hdu.edu.cn/showproblem.php?pid=1000
*/
#include  <iostream>
using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b) {
		cout << a + b << endl;
	}
	return 0;
}

///*
//HDOJ 1092 A+B for Input-Output Practice (IV)
//
//https://acm.hdu.edu.cn/showproblem.php?pid=1092
//
//*/
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int n, x, sum;
//	while (cin >> n && n)
//	{
//		sum = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> x;
//			sum += x;
//		}
//		int ret = sum;
//		cout << ret << endl;
//	}
//
//	return 0;
//}

///*
//
//HDOJ   1093  A+B for Input-Output Practice (V)
//
//https://acm.hdu.edu.cn/showproblem.php?pid=1093
//
//*/
//#include <iostream>
//using namespace std;
//int main()
//{
//	int t, n, x, sum;
//	cin >> t;
//	while (t--)
//	{
//		cin >> n;
//		sum = 0;
//		for (int i = 0; i < n; i++)
//		{
//			cin >> x;
//			sum += x;
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}



///*
//
//HDOJ 2023 人见人爱A+B
//https://acm.hdu.edu.cn/showproblem.php?pid=2033
//
//*/
//#include <iostream>
//using namespace std;
//int main()
//{
//	int N,x1,x2,x3,x4,x5,x6;
//	cin >> N;
//	while (N--)
//	{
//		int sum = 0;
//		
//		
//		cin >> x1>>x2>>x3>>x4>>x5>>x6;
//		int a = x1 + x4;
//		int b = x2 + x5;
//		int c = x3 + x6;
//
//		b += c / 60;
//		c = c % 60;
//
//		a += b / 60;
//		b = b % 60;
//		cout << a <<' ' <<  b <<" " << c << endl;
//	}
//
//	return 0;
//}


///*
//
//HDOJ 2055  An easy problem
//https://acm.hdu.edu.cn/showproblem.php?pid=2055
//
//*/
//#include <iostream>
//using namespace std;
//int main()
//{
//	int  t;
//	cin >> t;
//	while (t--)
//	{
//		char s[3];
//		char x;
//		int y;
//		int ans = 0;
//		cin >> s;
//		x = s[0];
//		cin >> y;
//		if (x >= 'A' && x <= 'Z')
//		{
//			ans = y + (x - 'A' + 1);
//		}
//		else if (x >= 'a' && x <= 'z')
//		{
//			ans = y - (x - 'a' + 1);
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}



//函数声明  可用于两个函数相互调用






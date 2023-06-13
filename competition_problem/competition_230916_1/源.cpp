//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <queue>
//#include <unordered_map>
//
//using namespace std;
//
//typedef long long ll;
//typedef pair<int, int> pii;
//
//int cnt[3] = { 0 };
//
//void solve()
//{
//	int V; cin >> V;
//	string s; cin >> s;
//	int n = s.length();
//	int num = 0;
//	int now = 0;
//	int i = 0;
//	int ans = 0;
//	for (; now +(s[i]-'0') <= V && i < n; i++)
//	{
//		now += (s[i] - '0');
//		cnt[s[i] - '0']++;
//		num++;
//		ans += num;
//	}
//	for (; i < n; i++)
//	{
//		if (now + (s[i] - '0') <= V)
//		{
//			now += (s[i] - '0');
//			num++;
//			cnt[s[i] - '0']++;
//		}
//		if (s[i] == '1' && cnt[2])
//		{
//			cnt[2]--;
//			now--;
//		}
//		ans += num;
//	}
//	cout << ans << endl;
//}
//
//int main()
//{
//	int t = 1; 
//	while (t--)
//	{
//		solve();
//	}
//	return 0;
//}

//#include "StdAfx.h"

#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int Status;
//typedef struct Book ElemType;
typedef int ElemType;
#define MAXSIZE 100			


struct Book {
	string id;//
	string name;//
	double price;//
};

typedef struct {
	ElemType* elem; //
	int length; //
} SqList;

Status InitList(SqList& L);
Status GetElem(SqList L, int i, ElemType& e);
int LocateElem(SqList L, ElemType e);
Status ListInsert(SqList& L, int i, ElemType e);
Status ListDelete(SqList& L, int i);
Status ListPrint(SqList& L);
Status reverse(SqList& L);
int main()
{


	SqList L;  // 
	ElemType e;
	int i = 0, ret, choose = -1;
	double price;

	cout << "0. 退出\n";
	cout << "1. 初始化\n";
	cout << "2. 取值\n";
	cout << "3. 查找\n";
	cout << "4. 插入\n";
	cout << "5. 删除\n";
	cout << "6. 输出\n";
	cout << "7. 倒置顺序表\n"; // 新增选项

	while (choose != 0)
	{
		cout << "请选择:";
		cin >> choose;
		switch (choose)
		{
		case 1:
			InitList(L);
			break;
		case 2:
			cout << "输入序号"; cin >> i;
			cout << "输入数据:"; cin >> e;
			GetElem(L, i, e);
			break;
		case 3:
			cout << "输入要查找的数据:"; cin >> e;
			cout << "要查找的数据的序号为" << LocateElem(L, e) << endl;
			break;
		case 4:
			cout << "输入插入数据序号";
			cin >> i;
			cout << "输入插入的数据:"; cin >> e;
			ListInsert(L, i, e);
			break;
		case 5:
			cout << "输入删除元素的序号:"; cin >> i;
			ListDelete(L, i);
			break;
		case 6:
			ListPrint(L);
			break;
		case 7: // 倒置顺序表
			reverse(L);
			cout << "顺序表已倒置" << endl;
			break;
		}

	}
	return 0;
}
Status InitList(SqList& L)

{
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem) exit(OVERFLOW);
	L.length = 0;
	return OK;
}

Status GetElem(SqList L, int i, ElemType& e)
{
	if (i < 1 || i > L.length) return ERROR;
	e = L.elem[i - 1];
	return OK;
}

int LocateElem(SqList L, ElemType e)
{
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e) return i + 1;
	}
	return 0;
}

Status ListInsert(SqList& L, int i, ElemType e) {
	if (i < 1 || i > MAXSIZE) return ERROR;
	if (L.length == MAXSIZE) return ERROR;
	for (int j = L.length - 1; j >= i - 1; j--)
		L.elem[j + 1] = L.elem[j];
	L.elem[i - 1] = e;
	++L.length;
	return OK;
}

Status ListDelete(SqList& L, int i)
{
	if (i < 1 || i > L.length) return ERROR;
	for (int j = i; j <= L.length - 1; j++)
		L.elem[j - 1] = L.elem[j];
	--L.length;
	return OK;
}

Status ListPrint(SqList& L)
{
	cout << "顺序表的打印如下";
	for (int i = 0; i < L.length; i++) {
		printf("%d", L.elem[i]);
	}
	return OK;
}

// 倒置顺序表
Status reverse(SqList& L) {
	int left = 0;           // 左边界的索引
	int right = L.length - 1; // 右边界的索引

	while (left < right) {
		// 交换左右边界的元素
		ElemType temp = L.elem[left];
		L.elem[left] = L.elem[right];
		L.elem[right] = temp;

		// 更新边界索引
		left++;
		right--;
	}
	return OK;
}
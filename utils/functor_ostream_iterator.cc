//functor_ostream_iterator
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <iterator>
using namespace std;

struct MyType
{
	unsigned int x:4;//0~15
 	unsigned int y:4;
	unsigned int z:4;
};
bool operator < (const MyType& rf1, const MyType& rf2)
{
	if (rf1.x != rf2.x)
		return rf1.x < rf2.x;
	else if (rf1.y != rf2.y)
		return rf1.y < rf2.y;
	else return rf1.z < rf2.z;
}
ostream& operator << (ostream& os, const MyType& rf)
{
	os << rf.x << "\t" << rf.y << "\t" << rf.z << endl;
	return os;
}

int main()
{
	srand(time(NULL));
	vector<MyType> S;
	for (int i=0; i<100; ++i)
	{
		MyType temp;
		temp.x = rand()%10;
		temp.y = rand()%10;
		temp.z = rand()%10;
		S.push_back(temp);
	}
	std::copy(S.begin(), S.end(), ostream_iterator<MyType>(cout));
	cout << endl;
	sort(S.begin(), S.end(), less<MyType>());
	std::copy(S.begin(), S.end(), ostream_iterator<MyType>(cout));
	cout << endl;
	cout << sizeof(MyType) << endl;
	system("PAUSE");
	return 0;
}

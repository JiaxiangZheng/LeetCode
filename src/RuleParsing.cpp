#include <iostream>
#include <functional>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <array>
#include <list>
#include <sstream>
#include <numeric>
#include <array>
#include <random>
using namespace std;
using namespace std;
const int SIZE = 100;

int main()
{
	std::vector<double> buf(SIZE);
	static int i = 0;
	for_each(buf.begin(), buf.end(), [&](double& v){v=i++;});
	i = 100;
	while (i--)
	{
		int pos[2] = {rand()%buf.size(), rand()%buf.size()};
		std::swap(buf[pos[0]], buf[pos[1]]);
	}
	std::copy(buf.begin(), buf.end(), std::ostream_iterator<double>(cout, "\t"));
	cout << endl;
	return 0;
}
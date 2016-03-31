#include <vector>
#include <iostream>
using namespace std;

class insert_sort{
	public:
		void sort(vector<int> &v)
		{
			int len = v.size(), i, j;
			for(i = 1; i < len; i++)
				for(j = i; j > 0 && less(v[j], v[j-1]); j--)
					exchange(v[j-1],v[j]);
		}
	    void show(vector<int> &v)
		{
			for(auto a : v)
				std::cout << a << " ";
			std::cout << std::endl;
		}
	private:
		bool less(int a, int b)
		{return a < b;}
		void exchange(int &a, int &b)
		{
			int temp = a;
			a = b;
			b = temp;
		}
};

int main()
{
	int a;
	vector<int> v;
	while(std::cin >> a)
		v.push_back(a);
	insert_sort S;
	S.sort(v);
	S.show(v);
	return 0;
}

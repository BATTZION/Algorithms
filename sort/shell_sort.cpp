#include <vector>
#include <iostream>
using namespace std;

class shell_sort{
	public:
		void sort(vector<int> &v)
		{
			int len = v.size(), h = 1;
			while(h < len/3)
				h = 3*h + 1;
			while(h > 0)
			{
				for(int i = h; i < len; i++){
					for(int j = i; j >= h && less(v[j],v[j-h]); j--)
						exchange(v[j],v[j-h]);
				}
				h = h / 3;
			}
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
	shell_sort S;
	S.sort(v);
	S.show(v);
	return 0;
}

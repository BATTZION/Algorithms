#include <vector>
#include <iostream>
using namespace std;

class merge_sort{
	public:
		void sort(vector<int> &v)
		{
		    re_sort(v, 0, v.size() - 1);
		}
		void show(vector<int> &v)
		{
			for(auto a : v)
				std::cout << a << " ";
			std::cout << std::endl;
		}
	private:
		void merge(vector<int> &v, int l, int m, int h)
		{
			vector<int> a;
			for(int i = l; i <= h; i++)
				a.push_back(v[i]);
			int j = m + 1, i = l;
			for(int k = l; k <=h; k++){
				if(i > m)  v[k] = a[j++ - l];
				else if(j > h) v[k] = a[i++ - l];
				else if(a[i - l] < a[j - l]) v[k] = a[i++ - l];
				else v[k] = a[j++ - l];
			}

		}
		void re_sort(vector<int> &v, int l, int h)
		{
			int m = l + (h - l)/2;
			if(l >= h)
				return;
			re_sort(v, l , m);
			re_sort(v, m+1, h);
			merge(v, l, m , h);
		}

};

int main()
{
	int a;
	vector<int> v;
	while(std::cin >> a)
		v.push_back(a);
	merge_sort S;
	S.sort(v);
	S.show(v);
	return 0;
}


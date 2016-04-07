#include <vector>
#include <iostream>
using namespace std;

class quick_sort{
	public:
		void sort(vector<int> &v)
		{
			re_sort(v, 0, v.size() - 1);
		}
		void show(vector<int> &v)
		{
			for(auto x : v)
				cout << x << " ";
			cout << endl;
		}
	private:
		int partition(vector<int> &v, int begin, int end)
		{
			int middle = v[begin];
			int low_position = begin, hig_position = end + 1;
			while(true)
			{
				while(v[++low_position] < middle && low_position != end);
				while(v[--hig_position] >= middle && hig_position != begin);
				if(low_position >= hig_position)
					break;
				exchang(v, low_position, hig_position);
			}
			exchang(v,hig_position,begin);
			return hig_position;
		}
		void re_sort(vector<int> &v, int begin, int end)
		{
			if(!(end > begin))
				return;
			int par = partition(v, begin, end);
			re_sort(v, begin, par - 1);
			re_sort(v, par + 1, end);
		}
		void exchang(vector<int> &v, int i, int j)
		{
			int temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
};

int main()
{
	int a;
	vector<int> v;
	while(std::cin >> a)
		v.push_back(a);
	quick_sort S;
	S.sort(v);
	S.show(v);
	return 0;
}


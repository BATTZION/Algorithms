#include <vector>
#include <iostream>
using namespace std;

class heap_sort{
	public:
		void sort(vector<int> &v)
		{
			int N = v.size() - 1;
			for(int i = (N - 1) / 2; i > - 1; i--)
				sink(v, i, N);
			while(N > 0){
				exchang(v, 0 , N--);
				sink(v, 0, N);
			}
		}
		void show(vector<int> &v)
		{
			for(auto x : v)
				cout << x << " ";
			cout << endl;
	    }
	private:
		void exchang(vector<int> &v, int i, int j)
		{
			int temp = v[i];
			v[i] = v[j];
			v[j] = temp;
		}
		void sink(vector<int> &v, int i, int N)
		{
			while((i*2 + 1) <= N){
				int j = i*2 + 1;
				if(j < N && v[j] < v[j+1])
					j++;
				if(v[j] <= v[i])
					break;
				exchang(v, i, j);
				i = j;
			}
		}
};

int main()
{
	int a;
	vector<int> v;
	while(cin >> a)
		v.push_back(a);
	heap_sort s;
	s.sort(v);
	s.show(v);
	return 0;
}

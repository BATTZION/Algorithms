#include <vector>
#include <iostream>
using std::vector;

class selection_sort{
	public:
		void sort(vector<int> &v)
		{
			int len = v.size(), i, j;
			for(i = 0; i < len; i++){
				int min = i;
				for(j = i + 1; j < len; j++){
					if(less(v[j],v[min]))
						min = j;
				}
				exchange(v[i], v[min]);
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
	selection_sort S;
	S.sort(v);
	S.show(v);
	return 0;
}

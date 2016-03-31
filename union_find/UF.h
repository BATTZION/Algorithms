#include <vector>
using std::vector;
class UF{
	public:
		UF() = default;
		UF(int N)
		{
			for(int i = 0; i < N; i++)
				id.push_back(i);
			n = N;
		}
		int count(){ return n;}
		bool connected(int p, int q);
		int find(int p);
		void union_p(int p, int q);
	private:
		vector<int> id;
		int n;
};

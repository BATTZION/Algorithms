/*
 * 八皇后问题
 */

#include <iostream>
#include <vector>
using namespace std;

class Solution{
	public:
		auto eigthQueens() -> vector<vector<int>> &
		{
			return queen_cols(8);
		}
		void show(vector<vector<int>> &v)
		{
			for(auto &vi : v){
				cout << "( ";
				for(auto i : vi)
					cout << i << " ";
				cout << ")\n";
			}
		}
	private:
		auto queen_cols(int k) -> vector<vector<int>> &
		{
			static vector<vector<int>> a = {{1},{2},{3},{4},{5},{6},{7},{8}};
			if(k == 1)
				return a;
			else{
				vector<vector<int>> &sol = queen_cols(k-1);
				int len = sol.size();
				while(len > 0){
					vector<int> v = sol[0];
					sol.erase(sol.begin());
					for(int i = 1; i < 9; i++){
						v.push_back(i);
						if(is_safe(v,k))
							sol.push_back(v);
						v.pop_back();
					}
					len--;
				}
				return sol;
			}
		}
		bool is_safe(vector<int> &v, int position)
		{
			for(int i = 0; i < position - 1; i++){
				if(v[i] == v[position - 1])
					return false;
				if((position - 1 - i) == (v[position - 1] - v[i]) || (position - 1 - i) == (v[i] - v[position - 1]))
					return false;
			}
			return true;
		}
};
int main()
{
	Solution s;
	s.show(s.eigthQueens());
	return 0;
}

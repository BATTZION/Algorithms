#include "UF.h"
#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	UF uf = UF(N);
	int p , q;
	while(cin >> p >> q){
		if(!uf.connected(p,q)){
			uf.union_p(p,q);
			cout << p << "----" << q << endl;
		}
	}
	return 0;
}

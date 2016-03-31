#include "UF.h"

bool UF::connected(int p, int q)
{
	if(id[p] == id[q])
		return true;
	else
		return false;
}
void UF::union_p(int p, int q)
{
	if(id[p] != id[q]){
		for(auto &c : id){
			if(c == id[p]){
				c = id[q];
			}
		}
		n--;
	}
}
int UF::find(int p)
{
	return id[p];
}

#include <cstdio>
#include <vector>
using namespace std;
int main() {
	vector<int> v;

	v.push_back(12);
	v.push_back(5);
	v.push_back(96);

	for (int i = 0; i < v.size(); i++)
		printf("%d\n", v[i]);

	return 0;
}

/*
#include <cstdio>
#include <stack>
using namespace std;
int main() {
	stack<int> st;

	st.push(4);
	st.push(5);
	st.pop();

	printf("%d\n", st.top());
	printf("%d\n", st.empty());
	printf("%d\n", st.size());

	return 0;
}
*/

/*
#include <cstdio>
#include <queue>
using namespace std;
int main() {
	queue<int> q;

	q.push(4);
	q.push(5);

	q.pop();

	printf("%d\n", q.front());
	printf("%d\n", q.empty());
	printf("%d\n", q.size());

	return 0;
}
*/

/*
#include <cstdio>
#include <utility>
using namespace std;
int main() {
	pair<int, char> p(15, 'H');

	printf("%d %c\n", p.first, p.second);
	p.first = 40;

	p.second = '*';
	printf("%d %c\n", p.first, p.second);

	return 0;
}
*/

/*
#include <cstdio>
#include <map>
using namespace std;
int main(){
	map<int, int> m;

	m.insert(make_pair(4, 5));
	m[5]=6;

	printf("%d\n", m.find(4)->second);

	return 0;
}
*/

/*
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const int a, const int b){
	return a>b;
}

int main(){

	int arr1[10] = { 1, 3, 8, 2, 7, 10, 20, 4, 6, 5};
	vector<int> arr2 (arr1, arr1 + sizeof(arr1)/sizeof(int));
	int n=10;

	sort(arr1, arr1+n);
	for(int i=0;i<10;i++)
        printf("%d\n", arr1[i]);

	sort(arr2.begin(), arr2.end());
	for(int i=0;i<10;i++)
        printf("%d\n", arr2[i]);

	sort(arr1, arr1+n, cmp);
	for(int i=0;i<10;i++)
        printf("%d\n", arr1[i]);

    return 0;
}
*/

/*
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
	int arr[10];

	for(int i=0;i<10;i++)
		arr[i]=i;

	do{
		for(int i=0;i<10;i++)
			printf("%d ", arr[i]);
		printf("\n");
	}while(next_permutation(arr, arr+10));

    return 0;
}
*/

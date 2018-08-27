#include <stdio.h>
#include <vector>
using namespace std;

const int MAX = 100001;
int arr[MAX],des[MAX];

int findBestSum(int i,int n,int m){
	int left = i+1;
	int right = n;
	int mid;
	while(left < right){			//采用二分法查找
		mid = (left + right)/2;
		if(arr[mid]-arr[i] >= m){	//arr[x]-arr[i] 表示[i+1,...,x]的数据和
			right = mid;
		}else{
			left = mid;
		}
	}
	des[i] = right;				//记录下右边界
	return arr[right]-arr[i];
}

int main(){
	int n,m;
	scanf("%d %d",&n,&m);

	int i,j;
	arr[0]=0;
	for(i=1;i<=n;i++){
		scanf("%d",&arr[i]);
		arr[i]=arr[i]+arr[i-1];
	}
	vector<int> vec;
	int res,mm;
	mm = 0x7fffffff;

	for(i=0;i<n;i++){
		res = findBestSum(i,n,m);			//寻找从i+1开始，最接近m的和
		if(res >= m){
			if(res == mm){					//和当前最小值相等，则加入vector
				vec.push_back(i);
			}else if(res < mm){				//比当前最小值还小，则清空vector，重新加入新值
				mm = res;
				vec.clear();
				vec.push_back(i);
			}
		}else{								//后面肯定更小，无必要再算
			break;
		}
	}

	for(i=0;i<vec.size();i++){
		printf("%d-%d\n",vec[i]+1,des[vec[i]]);
	}
	return 0;
}

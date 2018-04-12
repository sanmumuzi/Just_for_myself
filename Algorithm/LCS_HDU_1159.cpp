/*
LCS(最长公共子序列)[动态规划]
HDU 1159
参考：https://blog.csdn.net/yangliuy/article/details/6070057
*/

#include<cstdio>
#include<cstring>
using namespace std;

int main(){
	int f[500][500];  // f[i][j]表示字符串a的第i个字母与字符串b的第j个字母比较，第i或j个字母之前相同字母个数
	// 核心：如果a[i-1]==b[j-1], f(i,j)= f(i-1,j-1)+1;否则，f(i,j)=max(f(i,j-1),f(i-1,j))
	char a[500], b[500];
	while(scanf("%s%s", a, b) != EOF){
		int len_a = strlen(a);
		int len_b = strlen(b);
		for(int i = 0; i < len_b; i++)  // 字符串a无字符,无论b如何都将为0
			f[0][i] = 0;
		for(int i = 0; i < len_a; i++)  // 字符串b无字符，无论a如何都为0
			f[i][0] = 0;
		for(int i = 1; i < len_a+1; i++){  // Note: f表示 **之前**，所以从1开始，< len_a + 1
			for(int j = 1; j < len_b+1; j++){
				if(a[i-1] == b[j-1])  // DP方程
					f[i][j] = f[i-1][j-1] + 1;
                else
                    if(f[i][j-1] > f[i-1][j])  // 取其大者
                        f[i][j] = f[i][j-1];
                    else
                        f[i][j] = f[i-1][j];
			}
		}
		printf("%d\n", f[len_a][len_b]);  // len_a, len_b 之前的一个元素
	}
	return 0;
}

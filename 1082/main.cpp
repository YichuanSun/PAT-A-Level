#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    //freopen("F://Temp/input.txt", "r", stdin);
    string a[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };//存放数字对应的字符串
    string b[] = { "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi" };//存放位对应的字符串，称作位标识符吧
    vector<string> res;//存放字符串：包括位标示符和其位上的数字
    vector<int> digit;//存放各个位上数字
    int num, e;
    cin >> num;

    if (num == 0)
    {
        cout << "ling";
        return 0;
    }
    else if (num < 0)
    {
        cout << "Fu ";
        num = -num;
    }
    while (num != 0)
    {
        digit.push_back(num % 10);
        num /= 10;
    }
    for (e = 0; e < digit.size() && digit[e] == 0; ++e);//从低位开始找到第一位不等于0的
//if (e == 8){//如果过亿了，因为最多九位数所以只能是几亿
//	cout << a[digit[e]] << " Yi";
//	return 0;
//}
    for (int i = e; i < digit.size(); ++i)
    {
        if (i != 0 && (digit[i] != 0 || i == 4 || i == 8)) //如果不是个位；位上的数字不是0；是万位或亿位，则放入位标识符
        {
            res.push_back(b[i]);
        }
        res.push_back(a[digit[i]]);//放入位上的数字
    }
    for (int i = res.size() - 1; i >= 0; --i) //倒着来，因为是从小到大放进去，而要从大到小读出来
    {
        if (i != res.size() - 1)    cout << " ";
        int cnt = 0;
        while (i >= 0 && res[i] == "ling") //统计连续的0，注意这里万左右的0是不算连续的，因为中间有一个Wan隔着
        {
            --i;
            ++cnt;
        }
        if (cnt != 0 && res[i] != "Wan")  // 当之前有0，并且当前不是Wan，那么当前就是数字或万或亿，所以要输出ling
        {
            //这里不用担心i会递减到个位为0的情况，因为前面e已经把最后的0的因素给考虑过了，所以最后一位肯定是数字或者是位标示符
            cout << "ling ";
        }
        cout << res[i];
    }
    return 0;
}

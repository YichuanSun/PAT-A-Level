#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    //freopen("F://Temp/input.txt", "r", stdin);
    string a[] = { "ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu" };//������ֶ�Ӧ���ַ���
    string b[] = { "", "Shi", "Bai", "Qian", "Wan", "Shi", "Bai", "Qian", "Yi" };//���λ��Ӧ���ַ���������λ��ʶ����
    vector<string> res;//����ַ���������λ��ʾ������λ�ϵ�����
    vector<int> digit;//��Ÿ���λ������
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
    for (e = 0; e < digit.size() && digit[e] == 0; ++e);//�ӵ�λ��ʼ�ҵ���һλ������0��
//if (e == 8){//��������ˣ���Ϊ����λ������ֻ���Ǽ���
//	cout << a[digit[e]] << " Yi";
//	return 0;
//}
    for (int i = e; i < digit.size(); ++i)
    {
        if (i != 0 && (digit[i] != 0 || i == 4 || i == 8)) //������Ǹ�λ��λ�ϵ����ֲ���0������λ����λ�������λ��ʶ��
        {
            res.push_back(b[i]);
        }
        res.push_back(a[digit[i]]);//����λ�ϵ�����
    }
    for (int i = res.size() - 1; i >= 0; --i) //����������Ϊ�Ǵ�С����Ž�ȥ����Ҫ�Ӵ�С������
    {
        if (i != res.size() - 1)    cout << " ";
        int cnt = 0;
        while (i >= 0 && res[i] == "ling") //ͳ��������0��ע�����������ҵ�0�ǲ��������ģ���Ϊ�м���һ��Wan����
        {
            --i;
            ++cnt;
        }
        if (cnt != 0 && res[i] != "Wan")  // ��֮ǰ��0�����ҵ�ǰ����Wan����ô��ǰ�������ֻ�����ڣ�����Ҫ���ling
        {
            //���ﲻ�õ���i��ݼ�����λΪ0���������Ϊǰ��e�Ѿ�������0�����ظ����ǹ��ˣ��������һλ�϶������ֻ�����λ��ʾ��
            cout << "ling ";
        }
        cout << res[i];
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
//22001010216 庞子琨 

const int N = 10010;
char sd1[N][1000];
char sd2[N][1000];
string s1[N], s2[N];
string bigwrong[N] = {
    "多了一行: ",
    "缺了一行: ",
};
void print(string s, int cnt)
{
    int num = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] == ',') num++;
        else if (num == cnt) cout << s[i];
        if (num > cnt) break;
    }
    puts("");
    return;
}




string smallwrong[N] = {
"序号",
"学号",
"姓名",
"班级",
"年级",
"层次",
"实习方式",
"单位名称",
"企业所在省份",
"企业所在城市",
"企业详细地址",
"社会统一信用代码",
"实习岗位",
"是否专业对口",
"企业联系人",
"开始时间",
"结束时间"
};
int ans = 0;
int main()
{
    //22001010216 庞子琨
    fstream in1("D:\\original_data.csv");
    fstream in2("D:\\data_for_check.csv");
    int idx1 = 0, idx2 = 0;
    while (in1.getline(sd1[idx1], 1000, '\n'))
        s1[idx1] = sd1[idx1++];
    while (in2.getline(sd2[idx2], 1000, '\n'))
        s2[idx2] = sd2[idx2++];
    //s1[]是原始的
    //s2[]是新来的
    for (int i = 0, j = 0; i < idx1; i++)
    {
        if (s1[i] != s2[j])
        {
            if (s1[i] == s2[j + 1])
            {
                cout << bigwrong[0] << endl;
                cout << "多出来的是： " << s2[j++] << endl;
                puts("");
                ans++;
            }
            else if (s1[i + 1] == s2[j])
            {
                cout << bigwrong[1] << endl;
                cout << "缺少的是： " << s1[i++] << endl;
                puts("");
                ans++;
            }
            else
            {
                int cnt = 0;
                for (int z = 0; s1[i][z]; z++)
                    if (s1[i][z] != s2[j][z])    break;
                    else if (s1[i][z] == ',') cnt++;

                cout << "第" << i << "行: " << endl;
                cout << smallwrong[cnt] << "错误 " << endl;
                cout << "正确的 " << smallwrong[cnt] << " 是： ";
                print(s1[i], cnt);
                cout << "错误的 " << smallwrong[cnt] << " 是： ";
                print(s2[j], cnt);
                puts("");
                ans++;
            }

        }
        ++j;
    }

    printf("共 %d 处错误\n", ans);
    printf("22001010216 庞子琨") ; 
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
//22001010216 ������ 

const int N = 10010;
char sd1[N][1000];
char sd2[N][1000];
string s1[N], s2[N];
string bigwrong[N] = {
    "����һ��: ",
    "ȱ��һ��: ",
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
"���",
"ѧ��",
"����",
"�༶",
"�꼶",
"���",
"ʵϰ��ʽ",
"��λ����",
"��ҵ����ʡ��",
"��ҵ���ڳ���",
"��ҵ��ϸ��ַ",
"���ͳһ���ô���",
"ʵϰ��λ",
"�Ƿ�רҵ�Կ�",
"��ҵ��ϵ��",
"��ʼʱ��",
"����ʱ��"
};
int ans = 0;
int main()
{
    //22001010216 ������
    fstream in1("D:\\original_data.csv");
    fstream in2("D:\\data_for_check.csv");
    int idx1 = 0, idx2 = 0;
    while (in1.getline(sd1[idx1], 1000, '\n'))
        s1[idx1] = sd1[idx1++];
    while (in2.getline(sd2[idx2], 1000, '\n'))
        s2[idx2] = sd2[idx2++];
    //s1[]��ԭʼ��
    //s2[]��������
    for (int i = 0, j = 0; i < idx1; i++)
    {
        if (s1[i] != s2[j])
        {
            if (s1[i] == s2[j + 1])
            {
                cout << bigwrong[0] << endl;
                cout << "��������ǣ� " << s2[j++] << endl;
                puts("");
                ans++;
            }
            else if (s1[i + 1] == s2[j])
            {
                cout << bigwrong[1] << endl;
                cout << "ȱ�ٵ��ǣ� " << s1[i++] << endl;
                puts("");
                ans++;
            }
            else
            {
                int cnt = 0;
                for (int z = 0; s1[i][z]; z++)
                    if (s1[i][z] != s2[j][z])    break;
                    else if (s1[i][z] == ',') cnt++;

                cout << "��" << i << "��: " << endl;
                cout << smallwrong[cnt] << "���� " << endl;
                cout << "��ȷ�� " << smallwrong[cnt] << " �ǣ� ";
                print(s1[i], cnt);
                cout << "����� " << smallwrong[cnt] << " �ǣ� ";
                print(s2[j], cnt);
                puts("");
                ans++;
            }

        }
        ++j;
    }

    printf("�� %d ������\n", ans);
    printf("22001010216 ������") ; 
    return 0;
}

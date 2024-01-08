#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs)
    {
        int n = croakOfFrogs.length();
        vector<int> list(5);
        for (char c : croakOfFrogs)
        {
            switch (c)
            {
            case'c':
                if (list[4])
                {
                    list[0]++;
                    list[4]--;
                }
                else
                    list[0]++;
                break;
            case'r':
                if (list[0])
                {
                    list[0]--;
                    list[1]++;
                }
                else
                    return -1;
                break;
            case'o':
                if (list[1])
                {
                    list[1]--;
                    list[2]++;
                }
                else
                    return -1;
                break;
            case'a':
                if (list[2])
                {
                    list[2]--;
                    list[3]++;
                }
                else
                    return -1;
                break;
            case'k':
                if (list[3])
                {
                    list[3]--;
                    list[4]++;
                }
                else
                    return -1;
                break;
            }
        }
        if (list[0] || list[1] || list[2] || list[3])
            return -1;
        return list[4];
    }
};

void test()
{
    Solution s;
    vector<string> test_cases = { "croakcroak", "crcoakroak", "croakcrook", "croakcroa" ,"ccccccccccrrccccccrcccccccccccrcccccccccrcccccccccccrcccccrcccrrcccccccccccccrocrrcccccccccrccrocccccrccccrrcccccccrrrcrrcrccrcoccroccrccccccccorocrocccrrrrcrccrcrcrcrccrcroccccrccccroorcacrkcccrrroacccrrrraocccrrcrrccorooccrocacckcrcrrrrrrkrrccrcoacrcorcrooccacorcrccccoocroacroraoaarcoorrcrcccccocrrcoccarrorccccrcraoocrrrcoaoroccooccororrrccrcrocrrcorooocorarccoccocrrrocaccrooaaarrcrarooaarrarrororrcrcckracaccorarorocacrrarorrraoacrcokcarcoccoorcrrkaocorcrcrcrooorrcrroorkkaaarkraroraraarooccrkcrcraocooaoocraoorrrccoaraocoorrcokrararrkaakaooroorcororcaorckrrooooakcarokokcoarcccroaakkrrororacrkraooacrkaraoacaraorrorrakaokrokraccaockrookrokoororoooorroaoaokccraoraraokakrookkroakkaookkooraaocakrkokoraoarrakakkakaroaaocakkarkoocokokkrcorkkoorrkraoorkokkarkakokkkracocoaaaaakaraaooraokarrakkorokkoakokakakkcracarcaoaaoaoorcaakkraooaoakkrrroaoaoaarkkarkarkrooaookkroaaarkooakarakkooaokkoorkroaaaokoarkorraoraorcokokaakkaakrkaaokaaaroarkokokkokkkoakaaookkcakkrakooaooroaaaaooaooorkakrkkakkkkaokkooaakorkaroaorkkokaakaaaaaocrrkakrooaaroroakrakrkrakaoaaakokkaaoakrkkoakocaookkakooorkakoaaaaakkokakkorakaaaaoaarkokorkakokakckckookkraooaakokrrakkrkookkaaoakaaaokkaokkaaoakarkakaakkakorkaakkakkkakaaoaakkkaoaokkkakkkoaroookakaokaakkkkkkakoaooakcokkkrrokkkkaoakckakokkocaokaakakaaakakaakakkkkrakoaokkaakkkkkokkkkkkkkrkakkokkroaakkakaoakkoakkkkkkakakakkkaakkkkakkkrkoak" };
    vector<int> expected_outputs = { 1, 2, -1, -1,229 };

    for (int i = 0; i < test_cases.size(); i++)
    {
        int result = s.minNumberOfFrogs(test_cases[i]);
        if (result == expected_outputs[i])
            cout << "测试用例" << i + 1 << "通过。" << endl;
        else
            cout << "测试用例" << i + 1 << "失败。 应输出：" << expected_outputs[i] << "，实际输出： " << result << endl;
    }
}

int main()
{
    test();
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

class Solution
{
#define ft first
#define sd second

#define yes cout << "yes\n"
#define no cout << "no\n"

#define Yes cout << "Yes\n"
#define No cout << "No\n"

#define YES cout << "YES\n"
#define NO cout << "NO\n"

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define all(x) x.begin(), x.end()
#define all1(x) x.begin() + 1, x.end()
#define unq_all(x) x.erase(unique(all(x)), x.end())
#define unq_all1(x) x.erase(unique(all1(x)), x.end())
#define sort_all(x) sort(all(x))
#define sort1_all(x) sort(all1(x))
#define reverse_all(x) reverse(all(x))
#define reverse1_all(x) reverse(all1(x))

#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

    typedef long long ll;
    typedef unsigned long long ull;
    typedef long double ld;
    // typedef __int128_t i128;

    typedef pair<int, int> pii;
    typedef pair<ll, ll> pll;
    typedef pair<ld, ld> pdd;
    typedef pair<ll, int> pli;
    typedef pair<string, string> pss;
    typedef pair<string, int> psi;
    typedef pair<string, ll> psl;

    typedef tuple<int, int, int> ti3;
    typedef tuple<ll, ll, ll> tl3;
    typedef tuple<ld, ld, ld> tld3;

    typedef vector<bool> vb;
    typedef vector<int> vi;
    typedef vector<ll> vl;
    typedef vector<string> vs;
    typedef vector<pii> vpii;
    typedef vector<pll> vpll;
    typedef vector<pli> vpli;
    typedef vector<pss> vpss;
    typedef vector<ti3> vti3;
    typedef vector<tl3> vtl3;
    typedef vector<tld3> vtld3;

    typedef vector<vi> vvi;
    typedef vector<vl> vvl;

    typedef queue<int> qi;
    typedef queue<ll> ql;
    typedef queue<pii> qpii;
    typedef queue<pll> qpll;
    typedef queue<psi> qpsi;
    typedef queue<psl> qpsl;

    typedef priority_queue<int> pqi;
    typedef priority_queue<ll> pql;
    typedef priority_queue<string> pqs;
    typedef priority_queue<pii> pqpii;
    typedef priority_queue<psi> pqpsi;
    typedef priority_queue<pll> pqpll;
    typedef priority_queue<psi> pqpsl;

    typedef map<int, int> mii;
    typedef map<int, bool> mib;
    typedef map<ll, ll> mll;
    typedef map<ll, bool> mlb;
    typedef map<char, int> mci;
    typedef map<char, ll> mcl;
    typedef map<char, bool> mcb;
    typedef map<string, int> msi;
    typedef map<string, ll> msl;

    typedef unordered_map<int, int> umii;
    typedef unordered_map<ll, ll> uml;
    typedef unordered_map<char, int> umci;
    typedef unordered_map<char, ll> umcl;
    typedef unordered_map<string, int> umsi;
    typedef unordered_map<string, ll> umsl;

    struct cmp
    {
        bool operator()(const pii &a, const pii &b) const
        {
            if (a.ft != b.ft)
                return a.ft > b.ft;
            return a.sd > b.sd;
        }
    };

public:
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        vector<long long> answer;

        // 边界情况处理
        if (k > n)
            return answer;

        // 频率映射
        unordered_map<int, int> freq_map;

        // 初始化前k个元素的频率
        for (int i = 0; i < k; ++i)
        {
            freq_map[nums[i]]++;
        }

        // 创建一个有序集合，按照频率降序、值降序排序
        set<pair<int, int>, cmp> set_all;
        for (auto &[num, cnt] : freq_map)
        {
            set_all.emplace(make_pair(cnt, num));
        }

        // set_top 存储前x个元素，set_rest 存储其余元素
        set<pair<int, int>, cmp> set_top;
        set<pair<int, int>, cmp> set_rest;

        // 维护前x个元素的总和
        long long current_sum = 0;
        int cnt = 0;
        for (auto it = set_all.begin(); it != set_all.end(); ++it)
        {
            if (cnt < x)
            {
                set_top.emplace(*it);
                current_sum += static_cast<long long>(it->first) * it->second;
                cnt++;
            }
            else
            {
                set_rest.emplace(*it);
            }
        }

        // 记录第一个窗口的x-sum
        answer.emplace_back(current_sum);

        // 滑动窗口
        for (int i = k; i < n; ++i)
        {
            int outgoing = nums[i - k];
            int incoming = nums[i];

            // 处理移出的元素
            int freq_out = freq_map[outgoing];
            pair<int, int> elem_out = make_pair(freq_out, outgoing);

            // 判断该元素是在 set_top 还是 set_rest 中
            auto it_top_out = set_top.find(elem_out);
            if (it_top_out != set_top.end())
            {
                // 从 set_top 移除
                set_top.erase(it_top_out);
                current_sum -= static_cast<long long>(freq_out) * outgoing;
            }
            else
            {
                // 从 set_rest 移除
                set_rest.erase(elem_out);
            }

            // 更新频率映射
            freq_map[outgoing]--;
            if (freq_map[outgoing] == 0)
            {
                freq_map.erase(outgoing);
            }
            else
            {
                // 插入更新后的频率到 set_all
                pair<int, int> updated_out = make_pair(freq_map[outgoing], outgoing);
                // 决定插入 set_top 还是 set_rest
                // 如果 set_top 还未满x个，直接插入到 set_top
                if (set_top.size() < x)
                {
                    set_top.emplace(updated_out);
                    current_sum += static_cast<long long>(updated_out.first) * updated_out.second;
                }
                else
                {
                    // 比较 updated_out 是否优于 set_top 中最小的元素
                    auto it_smallest_top = prev(set_top.end());
                    if (cmp()(updated_out, *it_smallest_top))
                    {
                        // 插入 set_top
                        set_top.emplace(updated_out);
                        current_sum += static_cast<long long>(updated_out.first) * updated_out.second;
                        // 移除 set_top 中最小的元素到 set_rest
                        set_rest.emplace(*it_smallest_top);
                        current_sum -= static_cast<long long>(it_smallest_top->first) * it_smallest_top->second;
                        set_top.erase(it_smallest_top);
                    }
                    else
                    {
                        // 插入 set_rest
                        set_rest.emplace(updated_out);
                    }
                }
            }

            // 处理加入的元素
            // 获取当前 incoming 元素的频率（在更新前）
            int freq_in = freq_map.count(incoming) ? freq_map[incoming] : 0;
            // 如果之前存在，需从 set_top 或 set_rest 中移除
            if (freq_in > 0)
            {
                pair<int, int> elem_in_old = make_pair(freq_in, incoming);
                auto it_top_in = set_top.find(elem_in_old);
                if (it_top_in != set_top.end())
                {
                    set_top.erase(it_top_in);
                    current_sum -= static_cast<long long>(it_top_in->first) * it_top_in->second;
                }
                else
                {
                    set_rest.erase(elem_in_old);
                }
            }

            // 增加频率
            freq_map[incoming]++;
            int freq_in_new = freq_map[incoming];
            pair<int, int> elem_in_new = make_pair(freq_in_new, incoming);

            // 决定插入 set_top 还是 set_rest
            if (set_top.size() < x)
            {
                set_top.emplace(elem_in_new);
                current_sum += static_cast<long long>(elem_in_new.first) * elem_in_new.second;
            }
            else
            {
                // 比较 elem_in_new 是否优于 set_top 中最小的元素
                auto it_smallest_top = prev(set_top.end());
                if (cmp()(elem_in_new, *it_smallest_top))
                {
                    // 插入 set_top
                    set_top.emplace(elem_in_new);
                    current_sum += static_cast<long long>(elem_in_new.first) * elem_in_new.second;
                    // 移除 set_top 中最小的元素到 set_rest
                    set_rest.emplace(*it_smallest_top);
                    current_sum -= static_cast<long long>(it_smallest_top->first) * it_smallest_top->second;
                    set_top.erase(it_smallest_top);
                }
                else
                {
                    // 插入 set_rest
                    set_rest.emplace(elem_in_new);
                }
            }

            // 记录当前窗口的x-sum
            answer.emplace_back(current_sum);
        }

        return answer;
    }
};

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    Solution sol;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        // cout << nums[i] << " ";
    }
    // cout << "\n";
    int k, x;
    cin >> k >> x;
    // cout << k << " " << x << "\n";
    vector<long long> res = sol.findXSum(nums, k, x);
    for (auto i : res)
    {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}
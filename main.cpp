#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char **argv)
{
    std::ifstream inf("day8.in");
    std::string l;
    std::vector<std::vector<uint8_t>> m;
    while (std::getline(inf, l))
    {
        std::vector<uint8_t> t;
        for (int i = 0; i < l.size(); i++)
        {
            t.push_back(l[i] - '0');
        }
        m.push_back(t);
    }

    int vt = 0;
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m[0].size(); j++)
        {
            if (i == 0 || j == 0 || i == m.size() - 1 || j == m[0].size() - 1)
            {
                vt++;
                continue;
            }
            bool v = true;
            for (size_t k = 0; k < i; k++)
            {
                if (m[k][j] >= m[i][j])
                {
                    v = false;
                    break;
                }
            }
            if (v)
            {
                vt++;
                continue;
            }
            v = true;
            for (size_t k = m.size() - 1; k > i; k--)
            {
                if (m[k][j] >= m[i][j])
                {
                    v = false;
                    break;
                }
            }
            if (v)
            {
                vt++;
                continue;
            }
            v = true;
            for (size_t k = 0; k < j; k++)
            {
                if (m[i][k] >= m[i][j])
                {
                    v = false;
                    break;
                }
            }
            if (v)
            {
                vt++;
                continue;
            }
            v = true;
            for (size_t k = m[0].size() - 1; k > j; k--)
            {
                if (m[i][k] >= m[i][j])
                {
                    v = false;
                    break;
                }
            }
            if (v)
                vt++;
        }
    }
    std::cout << vt << std::endl;

    uint32_t mss = 0;
    for (size_t i = 0; i < m.size(); i++)
    {
        for (size_t j = 0; j < m[0].size(); j++)
        {
            if (i == 0 || j == 0 || i == m.size() - 1 || j == m[0].size() - 1)
            {
                continue;
            }
            uint32_t lss1 = 0;
            for (int32_t k = i - 1; k >= 0; k--)
            {
                lss1++;
                if (m[k][j] >= m[i][j])
                    break;
            }
            uint32_t lss2 = 0;
            for (size_t k = i + 1; k < m.size(); k++)
            {
                lss2++;
                if (m[k][j] >= m[i][j])
                    break;
            }
            uint32_t lss3 = 0;
            for (int32_t k = j - 1; k >= 0; k--)
            {
                lss3++;
                if (m[i][k] >= m[i][j])
                    break;
            }
            uint32_t lss4 = 0;
            for (size_t k = j + 1; k < m[0].size(); k++)
            {
                lss4++;
                if (m[i][k] >= m[i][j])
                    break;
            }
            uint32_t ss = lss1 * lss2 * lss3 * lss4;
            if(ss > mss)
                mss = ss;
        }
    }
    std::cout << mss << std::endl;

    return 0;
}
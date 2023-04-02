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

    const size_t height = m.size() - 1;
    const size_t width = m.front().size() - 1;
    size_t vt =  2 * (width + height);
    for (size_t i = 1; i < height; i++)
    {
        for (size_t j = 1; j < width; j++)
        {
            size_t idx = 0;
            while (m[idx][j] < m[i][j])
            {
                idx++;
            }
            bool visible_top = idx == i;

            idx = height;
            while(m[idx][j] < m[i][j])
            {
                idx--;
            }
            bool visible_bottom = idx == i;

            idx = 0;
            while (m[i][idx] < m[i][j])
            {
                idx++;
            }
            bool visible_left = idx == j;

            idx = width;
            while (m[i][idx] < m[i][j])
            {
                idx--;
            }
            bool visible_right = idx == j;

            if (visible_top || visible_bottom || visible_left || visible_right)
            {
                vt++;
            }
        }
    }
    std::cout << vt << std::endl;

    uint32_t mss = 0;
    for (size_t i = 1; i < height; i++)
    {
        for (size_t j = 1; j < width; j++)
        {
            uint32_t lss1 = 1;
            size_t idx = i - 1;
            while (idx > 0 && m[idx][j] < m[i][j])
            {
                idx--;
                lss1++;
            }

            uint32_t lss2 = 1;
            idx = i + 1;
            while (idx < height && m[idx][j] < m[i][j])
            {
                lss2++;
                idx++;
            }

            uint32_t lss3 = 1;
            idx = j - 1;
            while (idx > 0 && m[i][idx] < m[i][j])
            {
                lss3++;
                idx--;
            }

            uint32_t lss4 = 1;
            idx = j + 1;
            while (idx < width && m[i][idx] < m[i][j])
            {
                lss4++;
                idx++;
            }

            mss = std::max(mss, lss1 * lss2 * lss3 * lss4);
        }
    }
    std::cout << mss << std::endl;

    return 0;
}
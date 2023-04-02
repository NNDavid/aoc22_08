#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char **argv)
{
    std::ifstream input_file("day8.in");
    std::string line;
    std::vector<std::vector<uint8_t>> map;
    while (std::getline(input_file, line))
    {
        map.emplace_back(std::vector<uint8_t>(line.size()));
        for (int i = 0; i < line.size(); i++)
        {
            map.back()[i] = line[i] - '0';
        }
    }

    const size_t height = map.size() - 1;
    const size_t width = map.front().size() - 1;
    size_t visible_trees =  2 * (width + height);
    for (size_t i = 1; i < height; i++)
    {
        for (size_t j = 1; j < width; j++)
        {
            size_t idx = 0;
            while (map[idx][j] < map[i][j])
            {
                idx++;
            }
            bool visible_top = idx == i;

            idx = height;
            while(map[idx][j] < map[i][j])
            {
                idx--;
            }
            bool visible_bottom = idx == i;

            idx = 0;
            while (map[i][idx] < map[i][j])
            {
                idx++;
            }
            bool visible_left = idx == j;

            idx = width;
            while (map[i][idx] < map[i][j])
            {
                idx--;
            }
            bool visible_right = idx == j;

            if (visible_top || visible_bottom || visible_left || visible_right)
            {
                visible_trees++;
            }
        }
    }
    std::cout << visible_trees << std::endl;

    uint32_t max_scenic_score = 0;
    for (size_t i = 1; i < height; i++)
    {
        for (size_t j = 1; j < width; j++)
        {
            uint32_t top_scenic_score = 1;
            size_t idx = i - 1;
            while (idx > 0 && map[idx][j] < map[i][j])
            {
                idx--;
                top_scenic_score++;
            }

            uint32_t bottom_scenic_score = 1;
            idx = i + 1;
            while (idx < height && map[idx][j] < map[i][j])
            {
                bottom_scenic_score++;
                idx++;
            }

            uint32_t left_scenic_score = 1;
            idx = j - 1;
            while (idx > 0 && map[i][idx] < map[i][j])
            {
                left_scenic_score++;
                idx--;
            }

            uint32_t right_scenic_score = 1;
            idx = j + 1;
            while (idx < width && map[i][idx] < map[i][j])
            {
                right_scenic_score++;
                idx++;
            }

            max_scenic_score = std::max(max_scenic_score, top_scenic_score * bottom_scenic_score * left_scenic_score * right_scenic_score);
        }
    }
    std::cout << max_scenic_score << std::endl;

    return 0;
}
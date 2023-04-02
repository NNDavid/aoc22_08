#include "Day8.h"
#include <fstream>
#include <algorithm>

Day8::Day8(const std::string& filename)
{
    std::ifstream input_file(filename);
    std::string line;
    while (std::getline(input_file, line))
    {
        map.emplace_back(std::vector<uint8_t>(line.size()));
        for (int i = 0; i < line.size(); i++)
        {
            map.back()[i] = line[i] - '0';
        }
    }
    input_file.close();

    height = map.size() - 1;
    width = map.back().size() - 1;
}

size_t Day8::solvePart1() const
{
    size_t visible_trees = 2 * (width + height);
    for (size_t i = 1; i < height; i++)
    {
        for (size_t j = 1; j < width; j++)
        {
            if (visible_top(i, j) || visible_bottom(i, j) || visible_left(i, j) || visible_right(i, j))
            {
                visible_trees++;
            }
        }
    }
    return visible_trees;
}

uint32_t Day8::solvePart2() const
{
    uint32_t max_scenic_score = 0;
    for (size_t i = 1; i < height; i++)
    {
        for (size_t j = 1; j < width; j++)
        {
            const uint32_t scenic_score = scenic_score_top(i, j) * scenic_score_bottom(i, j) * scenic_score_left(i, j) * scenic_score_right(i, j);
            max_scenic_score = std::max(max_scenic_score, scenic_score);
        }
    }
    return max_scenic_score;
}

bool Day8::visible_top(const size_t row_idx, const size_t column_idx) const
{
    size_t idx = 0;
    while (map[idx][column_idx] < map[row_idx][column_idx])
    {
        idx++;
    }
    return idx == row_idx;
}

bool Day8::visible_bottom(const size_t row_idx, const size_t column_idx) const
{
    size_t idx = height;
    while (map[idx][column_idx] < map[row_idx][column_idx])
    {
        idx--;
    }
    return idx == row_idx;
}

bool Day8::visible_left(const size_t row_idx, const size_t column_idx) const
{
    size_t idx = 0;
    while (map[row_idx][idx] < map[row_idx][column_idx])
    {
        idx++;
    }
    return idx == column_idx;
}

bool Day8::visible_right(const size_t row_idx, const size_t column_idx) const
{
    size_t idx = width;
    while (map[row_idx][idx] < map[row_idx][column_idx])
    {
        idx--;
    }
    return idx == column_idx;
}

uint32_t Day8::scenic_score_top(const size_t row_idx, const size_t column_idx) const
{
    uint32_t scenic_score = 1;
    size_t idx = row_idx - 1;
    while (idx > 0 && map[idx][column_idx] < map[row_idx][column_idx])
    {
        idx--;
        scenic_score++;
    }
    return scenic_score;
}

uint32_t Day8::scenic_score_bottom(const size_t row_idx, const size_t column_idx) const
{
    uint32_t scenic_score = 1;
    size_t idx = row_idx + 1;
    while (idx < height && map[idx][column_idx] < map[row_idx][column_idx])
    {
        scenic_score++;
        idx++;
    }
    return scenic_score;
}

uint32_t Day8::scenic_score_left(const size_t row_idx, const size_t column_idx) const
{
    uint32_t scenic_score = 1;
    size_t idx = column_idx - 1;
    while (idx > 0 && map[row_idx][idx] < map[row_idx][column_idx])
    {
        scenic_score++;
        idx--;
    }
    return scenic_score;
}

uint32_t Day8::scenic_score_right(const size_t row_idx, const size_t column_idx) const
{
    uint32_t scenic_score = 1;
    size_t idx = column_idx + 1;
    while (idx < width && map[row_idx][idx] < map[row_idx][column_idx])
    {
        scenic_score++;
        idx++;
    }
    return scenic_score;
}
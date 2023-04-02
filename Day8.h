#pragma once

#include <cstdint>
#include <string>
#include <vector>

class Day8
{
public:
	/**
	* Constructor of AOC 2022 Day8 solver
	*
	* @param filename The name of the file that contains the input data
	*/
	Day8(const std::string& filename);

	/**
	* Solve Part 1 of AOC 2022 Day8
	*
	* @return The number of trees that are visible from at least one direction (top, bottom, left, right)
	*/
	size_t solvePart1() const;

	/**
	* Solve Part 2 of AOC 2022 Day8
	*
	* @return The maximum scenic score
	*/
	uint32_t solvePart2() const;
private:
	/**
	* Check if tree is visible from top
	*
	* @param row_idx Row index of tree
	* @param column_idx Column index of tree
	* @return true if the height of all trees above checked tree are smaller, false otherwise
	*/
	bool visible_top(const size_t row_idx, const size_t column_idx) const;

	/**
	* Check if tree is visible from bottom
	*
	* @param row_idx Row index of tree
	* @param column_idx Column index of tree
	* @return true if the height of all trees below checked tree are smaller, false otherwise
	*/
	bool visible_bottom(const size_t row_idx, const size_t column_idx) const;

	/**
	* Check if tree is visible from left
	*
	* @param row_idx Row index of tree
	* @param column_idx Column index of tree
	* @return true if the height of all trees to the left of the checked tree are smaller, false otherwise
	*/
	bool visible_left(const size_t row_idx, const size_t column_idx) const;

	/**
	* Check if tree is visible from right
	*
	* @param row_idx Row index of tree
	* @param column_idx Column index of tree
	* @return true if the height of all trees to the right of the checked tree are smaller, false otherwise
	*/
	bool visible_right(const size_t row_idx, const size_t column_idx) const;

	/**
	* Calculates the scenic score to the top of a tree
	*
	* @param row_idx Row index of tree
	* @param column_idx Column index of tree
	* @return Scenic score to the top of the tree
	*/
	uint32_t scenic_score_top(const size_t row_idx, const size_t column_idx) const;

	/**
	* Calculates the scenic score to the bottom of a tree
	*
	* @param row_idx Row index of tree
	* @param column_idx Column index of tree
	* @return Scenic score to the bottom of the tree
	*/
	uint32_t scenic_score_bottom(const size_t row_idx, const size_t column_idx) const;

	/**
	* Calculates the scenic score to the left of a tree
	*
	* @param row_idx Row index of tree
	* @param column_idx Column index of tree
	* @return Scenic score to the left of the tree
	*/
	uint32_t scenic_score_left(const size_t row_idx, const size_t column_idx) const;

	/**
	* Calculates the scenic score to the right of a tree
	*
	* @param row_idx Row index of tree
	* @param column_idx Column index of tree
	* @return Scenic score to the right of the tree
	*/
	uint32_t scenic_score_right(const size_t row_idx, const size_t column_idx) const;

	std::vector<std::vector<uint8_t>> map;
	size_t width;
	size_t height;
};
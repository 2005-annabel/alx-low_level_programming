#!/usr/bin/python3
"""function that returns perimeter of the island described in grid
grid is the list of integers
"""
def island_perimeter(grid):
    """Returns the perimeter of the island.
    grid represents water by 0 and land by 1.
    Args: the grid list : is a list of lists of ints representing an island.
    Returns:it is the perimeter of the island defined in the grid.
    """
    width = len(grid[0])
    height = len(grid)
    edges = 0
    size = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                size += 1
                if j > 0 and grid[i][j - 1] == 1:
                    edges += 1
                if i > 0 and grid[i - 1][j] == 1:
                    edges += 1

    return size * 4 - edges * 2


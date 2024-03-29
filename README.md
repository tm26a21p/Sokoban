## Sokoban

**sokoban - A Warehouse Keeper Game**

---

## Project Details

- **Binary Name**: sokoban
- **Language**: C
- **Compilation**: Via Makefile, including `re`, `clean`, and `fclean` rules
- **Source Files**: All source files (except for useless files like binaries, temp files, obj files, etc.) are included.
---

## Overview

Sokoban, which means "warehouse keeper" in Japanese, is a type of transport puzzle game. In this game, the player pushes boxes or crates around in a warehouse, trying to get them to storage locations. The objective is to solve the puzzle by moving all the boxes to the storage locations.

---

## Features

- Terminal-based gameplay using the ncurses library
- Dynamic map dimensions (non-square maps are allowed)
- Reset game functionality by pressing the space bar
- Handling of terminal redimensioning
- Arrow key controls (LEFT, RIGHT, UP, DOWN)
- Valid map characters: SPACE, '\n', '#', 'X', 'O', 'P'
- Error handling for invalid maps
- Game status checking (win or lose)
- Unit tests for core functionalities

---

## Usage

### Compilation and Execution

> **⚠️ Warning**
>
> You will need a C compiler and ncurses library installed on your system to compile and run the puzzle.

1. Compile the project using the provided Makefile:
    ```sh
    make
    ```
2. Run the game with a map file:
    ```sh
    ./my_sokoban /path/to/map_file
    ```

### Command-line Options

- `-h`: Display usage information

### Map File Format

The map file represents the warehouse map, containing:
- `#` for walls
- `P` for the player
- `X` for boxes
- `O` for storage locations

Example map file:
```
##############  
#  OX        #  
#         P  #
########     #  
#OX          #  
#            #  
##############  
```
---

## Unit Tests

Unit testing is encouraged to ensure the project's core functionalities are working as expected. External calls are isolated to make the core functionalities easier to test.

Example unit test using Criterion:
```c
# include <criterion/criterion.h>
# include "sokoban.h"

Test(sokoban, check_player_position)
{
    struct sokoban_map *map;
    struct position *pos;
    
    map = make_map_from_string("##########\n" \
                               "#        #\n" \
                               "#  P     #\n" \
                               "# #XO####\n" \
                               "#        #\n" \
                               "#  # OX  #\n" \
                               "##########\n");
    
    pos = get_player_position(map);
    
    cr_assert_neq(pos, NULL);
    cr_assert_eq(pos->x, 2);
    cr_assert_eq(pos->y, 2);
    
    free(pos);
    free_map(map);
}
```
import mineField as mf
import random, sys, time

if len(sys.argv) < 2:
        print("Please enter difficulty level 1, 2 or 3 "
            "as a command line argument.")
        exit(1)
elif sys.argv[1] == '1':
    DIFFICULTY = mf.BEGINNER_FIELD
elif sys.argv[1] == '2':
    DIFFICULTY = mf.INTERMEDIATE_FIELD
elif sys.argv[1] == '3':
    DIFFICULTY = mf.EXPERT_FIELD
else:
    print("Invalid command line argument. Please enter 1, 2 or 3.")
    exit(1)

DELAY = 0.1

rows, cols, mines = (
    DIFFICULTY['height'],
    DIFFICULTY['width'],
    DIFFICULTY['number_of_mines'])

mine_field = mf.MineField(
    width=cols,
    height=rows,
    number_of_mines=mines)

# Create mirror grid to show solver progress
grid = [[' ' for _ in range(cols + 2)] for _ in range(rows + 2)]
tiles_left = rows * cols
for r in range(0, rows + 2):
    for c in range(0, cols + 2):
        if r == 0 or r == rows + 1:
            grid[r][c] = '#'
        else:
            grid[r][0] = '#'
            grid[r][cols + 1] = '#'


def print_grid():
    for i in grid:
        print(i)
    print('Tiles left: ', tiles_left)
    print('Mines left: ', mines)
    time.sleep(DELAY)


def probe_tile(tile_row, tile_col):
    global tiles_left
    tiles_left -= 1
    try:
        grid[tile_row + 1][tile_col + 1] = str(
            mine_field.sweep_cell(tile_col, tile_row))
    except:
        grid[tile_row + 1][tile_col + 1] = '*'
        print_grid()
        print('BOOM!')
        exit(1)
    print_grid()


def probe_random():
    r = random.randint(0, rows - 1)
    c = random.randint(0, cols - 1)
    if grid[r + 1][c + 1] == ' ':
        probe_tile(r, c)
        return True
    return False


def probe_surrounding(tile_row, tile_col):
    for i in range (-1, 2):
        for j in range (-1, 2):
            if grid[tile_row + i][tile_col + j] == ' ':
                probe_tile(tile_row + i - 1, tile_col + j - 1)


def check_surrounding(tile_row, tile_col):
    blanks = 0
    flags = 0
    for i in range (-1, 2):
        for j in range (-1, 2):
            if grid[tile_row + i][tile_col + j] == ' ':
                blanks += 1
            elif grid[tile_row + i][tile_col + j] == 'f':
                flags += 1
    return str(blanks), str(flags)


def solver_loop():
    global mines, tiles_left
    for r in range (1, rows + 1):
        for c in range (1, cols + 1):
            target = grid[r][c]
            if target != ' ':
                if target == '0':
                    probe_surrounding(r, c)
                elif target != 'f':
                    blanks, flags = check_surrounding(r, c)
                    if int(flags) < int(target) and int(blanks) == (int(target) - int(flags)):
                        for i in range (-1, 2):
                            for j in range (-1, 2):
                                if grid[r + i][c + j] == ' ':
                                    grid[r + i][c + j] = 'f'
                                    tiles_left -= 1
                                    mines -= 1
                                    print_grid()
                    elif int(flags) == int(target) and int(blanks) > 0:
                        probe_surrounding(r, c)


probe_random()

while tiles_left > 0:
    previous_round = tiles_left
    solver_loop()
    if tiles_left == previous_round:
        found_new = False
        while not found_new:
            found_new = probe_random()

if mines == 0:
    print('FOUND ALL MINES!')



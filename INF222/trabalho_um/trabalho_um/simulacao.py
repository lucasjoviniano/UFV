import random
import pandas as pd


def walk(starting_position, n_steps, home, ufv):
    path = [starting_position]

    for i in range(0, n_steps):
        movements = get_possible_coordinates(path[-1])
        print(movements)
        position = random.choice(movements)
        path.append(position)
        if position == home:
            return 'Home'
        elif position == ufv:
            return 'UFV'

    return 'Street'


def get_possible_coordinates(position):
    x, y = position

    x_possible = get_possible_moves(x)
    y_possible = get_possible_moves(y)

    return [(i, y) for i in x_possible] + [(x, i) for i in y_possible]


def get_possible_moves(line):
    if line == 0:
        return [line + 1]
    elif line == 15:
        return [line - 1]

    return [line + 1, line - 1]


def main():
    n_iter = 1000
    number_of_steps = 300
    bar = (3, 2)
    home = (5, 10)
    ufv = (14, 11)

    check = []

    for i in range(0, n_iter):
        arrival = walk(bar, number_of_steps, home, ufv)
        if arrival == 'Home':
            check.append([True, False, False])
        elif arrival == 'UFV':
            check.append([False, True, False])
        else:
            check.append([False, False, True])

    df = pd.DataFrame(check, columns=['Casa', 'UFV', 'Rua'])

    df.to_csv('output.csv')


main()

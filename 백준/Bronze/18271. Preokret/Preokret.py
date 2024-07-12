def count_1(i, dx):
    length = 0
    while i > 0 and i + dx < N and (difference[i] - difference[i + dx] == dx):
        length += 1
        i += dx
    return length

def count_2(i, dx):
    length = 0
    while i > 0 and i + dx < N and (difference[i] - difference[i + dx] == -dx):
        length += 1
        i += dx
    return length

N = int(input())

city_goals = opponent_goals = 0
difference = [0] * N
ties = []

for i in range(N):
    goal = int(input())

    if goal == 1:
        city_goals += 1
    else:
        opponent_goals += 1

    difference[i] = city_goals - opponent_goals

    if difference[i] == 0:
        ties.append(i)

print(city_goals, opponent_goals)
print(difference.count(0) + 1)

turnover = 0
for i in ties:
    left = count_1(i, -1)
    right = count_1(i, 1)
    if left != 0 and right != 0 and left + right > turnover:
        turnover = left + right
    left = count_2(i, -1)
    right = count_2(i, 1)
    if left != 0 and right != 0 and left + right > turnover:
        turnover = left + right

print(turnover)
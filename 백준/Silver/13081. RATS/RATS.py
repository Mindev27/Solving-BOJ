import sys
import re

def main():
    import sys

    input_lines = sys.stdin.read().split()
    t = int(input_lines[0])
    idx = 1
    chain_pattern1 = re.compile(r'^1233+4444$')
    chain_pattern2 = re.compile(r'^5566+7777$')

    for _ in range(t):
        M = int(input_lines[idx])
        idx += 1
        N = input_lines[idx]
        idx += 1
        sequence = [N]
        seen = set()
        repeat_or_chain_detected = False

        for i in range(1, M + 1):
            current = sequence[-1]

            if current in seen:
                print(f'R {i}')
                repeat_or_chain_detected = True
                break
            seen.add(current)

            if chain_pattern1.match(current) or chain_pattern2.match(current):
                print(f'C {i}')
                repeat_or_chain_detected = True
                break

            # 다음 항 계산
            if i < M:
                rev = current[::-1]
                sum_value = str(int(current) + int(rev))
                sorted_digits = ''.join(sorted(sum_value))
                sorted_digits = sorted_digits.lstrip('0')  # 앞의 0 제거
                if not sorted_digits:
                    sorted_digits = '0'
                sequence.append(sorted_digits)

        if not repeat_or_chain_detected:
            print(sequence[M - 1])

if __name__ == '__main__':
    main()

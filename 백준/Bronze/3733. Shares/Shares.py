import sys

def main():
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    
    i = 0
    results = []
    while i < len(data):
        N = data[i]
        S = data[i + 1]
        i += 2

        x = S // (N + 1)
        results.append(x)
    
    for result in results:
        print(result)

if __name__ == "__main__":
    main()
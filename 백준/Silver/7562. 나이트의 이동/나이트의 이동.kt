import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)
    var T: Int = scanner.nextInt()

    for(i in 1..T){

        val n = scanner.nextInt()
        val start = Pair(scanner.nextInt(), scanner.nextInt())
        val end   = Pair(scanner.nextInt(), scanner.nextInt())

        val result = BFS(start, end, n)

        print("$result\n")
    }
}

fun BFS(s: Pair<Int, Int>, e: Pair<Int, Int>, n: Int): Int {
    val dx = listOf(-1, -1, 1, 1, -2, -2, 2, 2)
    val dy = listOf(-2, 2, -2, 2, 1, -1, 1, -1)
    var matrix = Array(n) { IntArray(n) {0} }   // 횟수를 저장
    var visited = Array(n) { BooleanArray(n) }  // 방문 표시
    var q: Queue<Pair<Int, Int>> = LinkedList() // 좌표

    q.add(s)
    visited[s.first][s.second] = true

    while(!q.isEmpty()){
        val x = q.peek().first
        val y = q.peek().second
        q.remove()

        if(x == e.first && y == e.second)
            return matrix[x][y]

        for(i in 0..7){
            val nx = x + dx[i]
            val ny = y + dy[i]
            val count = matrix

            if(nx < 0 || n <= nx || ny < 0 || n <= ny || visited[nx][ny])
                continue

            visited[nx][ny] = true;
            matrix[nx][ny] = matrix[x][y] + 1
            q.add(Pair(nx, ny))
        }
    }

    return 0;
}

fun main(args: Array<String>) {
    var a : Int = readLine()!!.toInt()

    for(i in 1..a){
        for(j in 1..i-1) print(" ")
        for(j in i..a) print("*")
        println("")
    }
}
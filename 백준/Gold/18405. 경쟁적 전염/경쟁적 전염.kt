import java.io.*;
import java.util.*;
import kotlin.reflect.typeOf
import kotlin.text.StringBuilder

data class T(val cnt : Int, val num : Int, val x : Int, val y : Int)

fun main(args : Array<String>) = with(System.`in`.bufferedReader())
{
    val(n,k) = readln()!!.split(" ").map {it.toInt()}
    val v : MutableList<MutableList<Int>> = MutableList(n) {MutableList(n) {0} }
    val visited : MutableList<MutableList<Boolean>> = MutableList(n) {MutableList(n) {false} }
    val pq = PriorityQueue<T>(compareBy({it.cnt}, {it.num}))
    val dir = listOf(Pair(-1, 0), Pair(1, 0), Pair(0, -1), Pair(0, 1))
    for(i in 0 until n)
    {
        val s = readln()!!.split(" ").map {it.toInt()}
        for(j in 0 until n)
        {
            v[i][j] = s[j]
            if(v[i][j] != 0) {
            visited[i][j] = true
                pq.add(T(0, v[i][j], i, j))
            }
        }
    }
    val (s,x,y) = readln()!!.split(" ").map{it.toInt()}
    while(pq.isNotEmpty())
    {
        val (a,b,c,d) = pq.poll() 
        for((dx, dy) in dir)
        {
            val nx = c + dx
            val ny = d + dy
            if(nx in 0 until n && ny in 0 until n && !visited[nx][ny])
            {
                if(a == s)
                {
                    continue
                }
                v[nx][ny] = b
                visited[nx][ny] = true
                pq.add(T(a + 1, b, nx, ny))
            }
        }
    }
    print(v[x-1][y-1])
}
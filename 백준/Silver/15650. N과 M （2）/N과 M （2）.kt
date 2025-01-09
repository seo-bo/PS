import java.io.*;
import java.lang.StringBuilder
import java.util.*;
import kotlin.reflect.typeOf

var ans = StringBuilder()

fun dfs(mask : Int, start : Int, n : Int,pivot : Int, depth : Int, temp : MutableList<Int>)
{
    if(depth == pivot)
    {
        for(i in temp)
        {
            ans.append("${i} ")
        }
        ans.append("\n")
        return;
    }
    for(i in start..n)
    {
        if((mask and (1 shl i)) == 0)
        {
            temp.add(i)
            dfs((mask or (1 shl i)), i+1,n, pivot, depth+1, temp)
            temp.removeLast()
        }
    }

}
fun main(args : Array<String>) = with(System.`in`.bufferedReader())
{
   val str = StringTokenizer(readLine())
    val temp : MutableList<Int> = mutableListOf()
    val n = str.nextToken().toInt()
    val k = str.nextToken().toInt()
    dfs(0,1,n,k,0,temp)
    print(ans)
}
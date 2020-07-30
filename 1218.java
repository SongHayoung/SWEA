import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.LinkedList;
 
public class Solution {
    public static LinkedList<Integer> ll = new LinkedList<>();
    public static void main(String[] args) throws Exception {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = 10, tc = 1;
        while(T-- != 0){
            bf.readLine();
            bw.write("#" + tc++ + " " + result(bf.readLine()) + "\n");
        }
        bw.flush();
    }
    public static int result(String str) {
        ll.clear();
        switch (str.charAt(0)) {
            case ')':
            case ']':
            case '}':
            case '>': return 0;
            default: break;
        }
        for(int i = 0; i < str.length(); ++i) {
            switch (str.charAt(i)) {
                case '(' : ll.push(1); break;
                case '[' : ll.push(2); break;
                case '{' : ll.push(3); break;
                case '<' : ll.push(4); break;
                case ')' : if(ll.isEmpty() || ll.pop() != 1) return 0; break;
                case ']' : if(ll.isEmpty() || ll.pop() != 2) return 0; break;
                case '}' : if(ll.isEmpty() || ll.pop() != 3) return 0; break;
                case '>' : if(ll.isEmpty() || ll.pop() != 4) return 0; break;
                default: break;
            }
        }
        return 1;
    }
}

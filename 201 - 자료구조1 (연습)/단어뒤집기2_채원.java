package boj_basic.cp_2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

public class 단어뒤집기2_채원 {

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        Stack<Character> stack = new Stack<>();
        
        String S = br.readLine(); //입력받음
        
        boolean in = false; //<> 안에 있으면 true <>밖에 있으면 false
        
        for(int i = 0; i < S.length(); i++) {
        	if(S.charAt(i)=='<') {
        		in=true; //<> 안에 있게 되므로 true
        		
        		while(!stack.isEmpty()) {
        			bw.write(stack.pop());
        		}
        		bw.write(S.charAt(i)); //< 출력
        	}
        	
        	else if(S.charAt(i)=='>') {
        		in=false; // <> 밖에 있게 되므로 false
         		
        		bw.write(S.charAt(i)); //> 출력
        	}
        	
        	else if(in) {
        		bw.write(S.charAt(i));  //안에 있는 수들은 순서 뒤집지 않고 그냥 출력
        	}
        	
        	else if(!in) {
        		if(S.charAt(i)==' ') {  //공백이면
        			while(!stack.isEmpty()) {
        				bw.write(stack.pop());  
        			}
        			bw.write(S.charAt(i));
        		}
        		else {
        			stack.push(S.charAt(i)); //스택에다 넣음
        		}
        		
        		
        	}
        }
        	
        	while(!stack.isEmpty())
        		bw.write(stack.pop());
        
        bw.flush();
        bw.close();
        br.close();
	}

}

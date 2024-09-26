package io.rishabh.prac1;

import java.util.Iterator;
import java.util.Stack;

public class StackExample {
    public static void main(String[] args) {
        Stack<Integer> stk = new Stack<>();

        stk.push(40);
        stk.push(12);
        stk.push(24);
        stk.push(34);

        stk.forEach(System.out::println);
        stk.pop();
        System.err.println("element at top " + stk.peek());
        Iterator it = stk.iterator();

        while (it.hasNext()) {
            System.out.println(it.next());
        }
        
        System.out.println("size of stk " + stk.size());
    }
}
package io.rishabh.prac1;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

public class QueueExample {
    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();

        q.offer(40);
        q.offer(12);
        q.offer(24);
        q.offer(34);

        q.forEach(System.out::println);
        q.poll();
        System.err.println("element at top" + q.peek());
        System.out.println("size of q " + q.size());
        System.out.println("after operations");
        @SuppressWarnings("rawtypes")
        Iterator it = q.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }
    }
}

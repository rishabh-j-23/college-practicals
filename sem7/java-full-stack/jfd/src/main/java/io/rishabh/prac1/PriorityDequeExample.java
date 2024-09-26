package io.rishabh.prac1;

import java.util.PriorityQueue;
import java.util.Comparator;
import java.util.Iterator;
public class PriorityDequeExample {
    public static void main(String[] args) {
        PriorityQueue<Integer> pq = new PriorityQueue<>();

        pq.offer(40);
        pq.offer(12);
        pq.offer(24);
        pq.offer(34);

        System.out.println("PriorityDeque: " + pq);
        pq.poll();
        System.err.println("element at top" + pq.peek());
        System.out.println("size of pq " + pq.size());
        System.out.println("after operations");
        Iterator it = pq.iterator();
        while (it.hasNext()) {
            System.out.print(it.next() + " ");
        }

        pq = new PriorityQueue<>(Comparator.reverseOrder());

        pq.offer(40);
        pq.offer(12);
        pq.offer(24);
        pq.offer(34);

        System.out.println("\nPriorityDeque: " + pq);
    }
    
}

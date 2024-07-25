import java.util.ArrayDeque;
import java.util.Iterator;

public class ArrayDequeExample {
    public static void main(String[] args) {

        ArrayDeque<Integer> q = new ArrayDeque<>();

        q.offer(40);
        q.offer(12);
        q.offer(24);
        q.offer(34);

        q.forEach(System.out::println);
        q.poll();
        System.err.println("element at top" + q.peek());
        System.out.println("size of q " + q.size());
        System.out.println("after operations");
        Iterator it = q.iterator();
        while (it.hasNext()) {
            System.out.println(it.next());
        }
    }

}

import java.util.HashSet;
import java.util.Iterator;

public class HashSetExample {
    public static void main(String[] args) {
        HashSet<Integer> set = new HashSet<>();

        set.add(40);
        set.add(12);
        set.add(24);
        set.add(34);

        set.forEach(System.out::println);

        set.remove(34);

        System.out.println("Set contains 24: " + set.contains(24));

        Iterator<Integer> it = set.iterator();

        while (it.hasNext()) {
            System.out.println(it.next());
        }
        
        System.out.println("Size of set: " + set.size());
    }
}

import java.util.Scanner;
public class Cocomo {
    public static double effort(double kloc, double[] constants) {
      return constants[0] * (Math.pow(kloc, constants[1]));
  }
  public static double timefordev(double effort, double[] constants) {
      return 2.5 * (Math.pow(effort, constants[2]));
  }
  public static double[] organic(double kloc) {
      double effort = effort(kloc, Constants.organic());
      double time = timefordev(effort, Constants.organic());
      return new double[] { effort, time };
  }
  public static double[] semidetached(double kloc) {
      double effort = effort(kloc, Constants.semidetached());
      double time = timefordev(effort, Constants.semidetached());
      return new double[] { effort, time };
  }
  public static double[] embedded(double kloc) {
      double effort = effort(kloc, Constants.embedded());
      double time = timefordev(effort, Constants.embedded());
      return new double[] { effort, time };
  }
  public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      System.out.print("Enter number of KLOC: ");
    int kloc = sc.nextInt();
    if(kloc >=2 && kloc < 50) {
        toString("Organic", organic(kloc));
    } else if (kloc >= 50 && kloc < 300) {
        toString("Semi-detached", semidetached(kloc));
    } else if(kloc >= 300) {
        toString("embedded", embedded(kloc));
    }
    sc.close();
  }
  public static void toString(String mode, double[] results) {
      System.out.println("\nMode: " + mode);
    System.out.println("Effort: " + results[0] + "\nTime: " + results[1]);
  }
}
class Constants {
    public static double[] organic() {
      return new double[] { 2.4, 1.05, 0.38 };
  }
  public static double[] semidetached() {
      return new double[] { 3, 1.12, 0.35 };
  }
  public static double[] embedded() {
      return new double[] { 3.6, 1.2, 0.32 };
  }
}

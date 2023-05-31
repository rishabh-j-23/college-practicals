class Bank {
    double getRateOfInterest() {
        return 0.00;
    }
}

class Sbi extends Bank {
    @Override
    double getRateOfInterest() {
        return 0.07;
    }
}

class Icici extends Bank {
    @Override
    double getRateOfInterest() {
        return 0.06;
    }
}

class Axis extends Bank {
    @Override
    double getRateOfInterest() {
        return 0.08;
    }
}

public class Prac6 {
    public static void main(String[] args) {
        Sbi sbi = new Sbi();
        System.out.println("Rate of interest of sbi : " + sbi.getRateOfInterest());
        Icici icici = new Icici();
        System.out.println("Rate of interest of icici : " + icici.getRateOfInterest());
        Axis axis = new Axis();
        System.out.println("Rate of interest of axis : " + axis.getRateOfInterest());
    }
}

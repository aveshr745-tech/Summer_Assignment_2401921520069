import java.util.Random;

// Abstract Class
abstract class Compartment {
    public abstract String notice();
}

// FirstClass Class
class FirstClass extends Compartment {
    public String notice() {
        return "First Class Compartment";
    }
}

// Ladies Class
class Ladies extends Compartment {
    public String notice() {
        return "Ladies Compartment";
    }
}

// General Class
class General extends Compartment {
    public String notice() {
        return "General Compartment";
    }
}

// Luggage Class
class Luggage extends Compartment {
    public String notice() {
        return "Luggage Compartment";
    }
}

// Main Class
public class TestCompartment {
    public static void main(String[] args) {

        Compartment[] compartments = new Compartment[10];
        Random random = new Random();

        for (int i = 0; i < compartments.length; i++) {

            int choice = random.nextInt(4) + 1; // Generates 1 to 4

            switch (choice) {
                case 1:
                    compartments[i] = new FirstClass();
                    break;

                case 2:
                    compartments[i] = new Ladies();
                    break;

                case 3:
                    compartments[i] = new General();
                    break;

                case 4:
                    compartments[i] = new Luggage();
                    break;
            }
        }

        System.out.println("Railway Compartments:");

        for (int i = 0; i < compartments.length; i++) {
            System.out.println("Compartment " + (i + 1) + ": "
                    + compartments[i].notice());
        }
    }
}

interface LibraryUser {
    void registerAccount();
    void requestBook();
}

// KidUsers Class
class KidUsers implements LibraryUser {

    int age;
    String bookType;

    public void registerAccount() {
        if (age < 12) {
            System.out.println("You have successfully registered under a Kids Account");
        } else {
            System.out.println("Sorry, Age must be less than 12 to register as a kid");
        }
    }

    public void requestBook() {
        if (bookType.equals("Kids")) {
            System.out.println("Book Issued successfully, please return the book within 10 days");
        } else {
            System.out.println("Oops, you are allowed to take only kids books");
        }
    }
}

// AdultUser Class
class AdultUser implements LibraryUser {

    int age;
    String bookType;

    public void registerAccount() {
        if (age > 12) {
            System.out.println("You have successfully registered under an Adult Account");
        } else {
            System.out.println("Sorry, Age must be greater than 12 to register as an adult");
        }
    }

    public void requestBook() {
        if (bookType.equals("Fiction")) {
            System.out.println("Book Issued successfully, please return the book within 7 days");
        } else {
            System.out.println("Oops, you are allowed to take only adult Fiction books");
        }
    }
}

// Main Class
public class LibraryInterfaceDemo {

    public static void main(String[] args) {

        // Test Case 1 - Kid User

        KidUsers kid1 = new KidUsers();

        kid1.age = 10;
        kid1.registerAccount();

        kid1.bookType = "Kids";
        kid1.requestBook();

        System.out.println();

        KidUsers kid2 = new KidUsers();

        kid2.age = 18;
        kid2.registerAccount();

        kid2.bookType = "Fiction";
        kid2.requestBook();

        System.out.println();

        // Test Case 2 - Adult User

        AdultUser adult1 = new AdultUser();

        adult1.age = 5;
        adult1.registerAccount();

        adult1.bookType = "Kids";
        adult1.requestBook();

        System.out.println();

        AdultUser adult2 = new AdultUser();

        adult2.age = 23;
        adult2.registerAccount();

        adult2.bookType = "Fiction";
        adult2.requestBook();
    }
}



/*Output
You have successfully registered under a Kids Account
Book Issued successfully, please return the book within 10 days

Sorry, Age must be less than 12 to register as a kid
Oops, you are allowed to take only kids books

Sorry, Age must be greater than 12 to register as an adult
Oops, you are allowed to take only adult Fiction books

You have successfully registered under an Adult Account
Book Issued successfully, please return the book within 7 days */

import customer5.Customer5;
import employee5.Employee5;
import manager5.Manager5;
import person5.Person5;
import personexception.PersonException;

public class Kadai11 {
    public static void main(String[] args) {
        String[] names = {null, "田中"};
        for (int i = 0 ; i < names.length ; i++) {
            try {
                System.out.print("nameが " + names[i] + " の時、");
                Person5 person = new Person5(names[i]);
                System.out.println(person.toString());
            } catch (PersonException e) {
               System.out.println( e.toString() );
            }
        }

        String[] departments={"総務部", "財務部", "営業部", "開発部", "製造部", "それら以外"};
         for (int i = 0 ; i < departments.length ; i++) {
            try {
                System.out.print("departmentが " + departments[i] + " の時、");
                Employee5 employee = new Employee5("田中", departments[i]);
                System.out.println(employee.toString());
            } catch (PersonException e) {
                System.out.println(e.toString());
            }
         }

        String[] posts={"社長", "部長", "係長", "それら以外"};
        for (int i = 0 ; i < posts.length ; i++) {
           try {
                System.out.print("postが " + posts[i] + " の時、");
               Manager5 manager= new Manager5("田中", "総務部", posts[i]);
               System.out.println(manager.toString());
           } catch (PersonException e) {
               System.out.println(e.toString());
           }
        }

         String[] addresses = {null, "日本"};
         for(int i = 0 ; i < addresses.length ; i++) {
            try {
                 System.out.print("addressが " + addresses[i] + " の時、");
                Customer5 customer = new Customer5("田中", addresses[i], 24);
                System.out.println(customer.toString());
            } catch (PersonException e) {
                System.out.println(e.toString());
            }
         }

        int[] ages = {-1, 0, 24, 130, 131};
        for (int i = 0 ; i < ages.length ; i++){
            try {
                System.out.print("ageが " + ages[i] + " の時、");
                Customer5 customer = new Customer5 ("田中", "日本", ages[i]);
                System.out.println(customer.toString());
            } catch (PersonException e) {
                System.out.println(e.toString());
            }
        }

    }
}

import java.util.Date;
import java.text.DateFormat;

public class Main {

    public static void main(String[] args) {
        Employee e1 = new Employee(1,10,10);
        Employee e2 = new Employee(2,20,10);
        Employee e3 = new Employee(3,30,10);
        Date d = new Date();
        DateFormat df = DateFormat.getDateInstance(DateFormat.MEDIUM);

        System.out.println("Payroll for Week Ending in " + df.format(d));
        System.out.println("---------------------------------------");
        System.out.println("\tEmployee #......" + e1.get_id());
        System.out.println("\tHours Worked...." + e1.get_hours_worked());
        System.out.println("\tHourly Rate....." + e1.get_hourly_pay_rate());
        System.out.println("\tYour Salary is.." + e1.get_salary());
        System.out.println("\t--------------------------------");
        System.out.println("\tEmployee #......" + e2.get_id());
        System.out.println("\tHours Worked...." + e2.get_hours_worked());
        System.out.println("\tHourly Rate....." + e2.get_hourly_pay_rate());
        System.out.println("\tYour Salary is.." + e2.get_salary());
        System.out.println("\t--------------------------------");
        System.out.println("\tEmployee #......" + e3.get_id());
        System.out.println("\tHours Worked...." + e3.get_hours_worked());
        System.out.println("\tHourly Rate....." + e3.get_hourly_pay_rate());
        System.out.println("\tYour Salary is.." + e3.get_salary());
        System.out.println("\t--------------------------------");
        System.out.println("\nTotal payout amount..."+ (e1.get_salary() + e2.get_salary() + e3.get_salary()));
        System.out.println("------------- End of Report ------------");
    }
}

public class Employee {
    private int id;
    private double hours_worked;
    private double hourly_pay_rate;
    private double salary;

    public Employee(int id, double hours_worked, double hourly_pay_rate){
        this.id = id;
        this.hours_worked = hours_worked;
        this.hourly_pay_rate = hourly_pay_rate;
    }

    public double get_salary(){
        return this.hours_worked * this.hourly_pay_rate;
    }

    public int get_id(){
        return this.id;
    }

    public double get_hours_worked(){
        return this.hours_worked;
    }

    public double get_hourly_pay_rate(){
        return this.hourly_pay_rate;
    }

    public void set_id(int id){
        this.id = id;
    }

    public void set_hours_worked(double hours_worked){
        this.hours_worked = hours_worked;
    }

    public void set_hourly_pay_rate(double hourly_pay_rate){
        this.hourly_pay_rate = hourly_pay_rate;
    }
}

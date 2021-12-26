
/**
 * Write a description of class Tester here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */

import java.util.*;

public class Tester
{
    public void testLogEntry() {
        LogEntry le = new LogEntry("1.2.3.4", new Date(), "example request", 200, 500);
        System.out.println(le);
        LogEntry le2 = new LogEntry("1.2.100.4", new Date(), "example request 2", 300, 400);
        System.out.println(le2.getAccessTime());
    }
    
    public void testLogAnalyzer() {
        // complete method
        LogAnalyzer la = new LogAnalyzer();
        la.readFile("/Users/robertndungu/Documents/Programming/Java/Coursera/Object Oriented Programming in Java Specialization/WebLogProgram/weblog1_log");
        la.printAll();
    }
    
    public void testUniqueIP(){
        LogAnalyzer la = new LogAnalyzer();
        la.readFile("/Users/robertndungu/Documents/Programming/Java/Coursera/Object Oriented Programming in Java Specialization/WebLogProgram/short-test_log");
        System.out.println("There are " + la.countUniqueIPs() + " unique IPs");
    }
    
    public void testIPVisit(){
        LogAnalyzer la = new LogAnalyzer();
        la.readFile("/Users/robertndungu/Documents/Programming/Java/Coursera/Object Oriented Programming in Java Specialization/WebLogProgram/weblog-short_log");
        System.out.println(la.uniqueIPVisitsOnDay("Sep 14").size());
    }
    
    public void testUniqueRange(){
        LogAnalyzer la = new LogAnalyzer();
        la.readFile("/Users/robertndungu/Documents/Programming/Java/Coursera/Object Oriented Programming in Java Specialization/WebLogProgram/short-test_log");
        System.out.println(la.countUniqueIPsInRange(200,299));
    }
    
    public void testVisits(){
        LogAnalyzer la = new LogAnalyzer();
        la.readFile("/Users/robertndungu/Documents/Programming/Java/Coursera/Object Oriented Programming in Java Specialization/WebLogProgram/weblog3-short_log");
        System.out.println(la.mostNumberVisitsByIP(la.countVisitsPerIP()));
    }
    
    public void testiPsMostVisits(){
        LogAnalyzer la = new LogAnalyzer();
        la.readFile("/Users/robertndungu/Documents/Programming/Java/Coursera/Object Oriented Programming in Java Specialization/WebLogProgram/weblog3-short_log");
        System.out.println(la.iPsMostVisits(la.countVisitsPerIP()));
    }
    
    public void testiPsForDays(){
        LogAnalyzer la = new LogAnalyzer();
        la.readFile("/Users/robertndungu/Documents/Programming/Java/Coursera/Object Oriented Programming in Java Specialization/WebLogProgram/weblog3-short_log");
        System.out.println(la.iPsForDays());
    }
    
    public void testdayWithMostIPVisits(){
        LogAnalyzer la = new LogAnalyzer();
        la.readFile("/Users/robertndungu/Documents/Programming/Java/Coursera/Object Oriented Programming in Java Specialization/WebLogProgram/weblog3-short_log");
        System.out.println(la.dayWithMostIPVisits(la.iPsForDays()));
    }
    
    public void testiPsWithMostVisitsOnDay(){
        LogAnalyzer la = new LogAnalyzer();
        la.readFile("/Users/robertndungu/Documents/Programming/Java/Coursera/Object Oriented Programming in Java Specialization/WebLogProgram/weblog3-short_log");
        System.out.println(la.iPsWithMostVisitsOnDay(la.iPsForDays(), "Sep 30"));
    }
}

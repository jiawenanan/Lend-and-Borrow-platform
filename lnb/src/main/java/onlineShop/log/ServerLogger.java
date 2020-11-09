package onlineShop.log;


import org.springframework.stereotype.Component;

@Component //notice it is a spring bean
public class ServerLogger implements Logger {
    public void log(String info) {
        System.out.println("server log = " + info); // from server logger
    }
}


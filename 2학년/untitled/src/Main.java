import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("미국: 1000.00 달러 --> 영국: 88.35 파운드\n");
        System.out.print("환전하 통화 국가를 입력하세요: ");
        String from_Nation = sc.next();

        System.out.print("환전 대상 통화 국가를 입력하세요: ");
        String to_Nation = sc.next();

        System.out.print("환전 금액을 입력하세요: ");
        double price = sc.nextDouble();
        ExchangeRate er1 = new ExchangeRate("미국",1438.5,"달러");
        ExchangeRate er2 = new ExchangeRate("중국",197.85,"위안");
        ExchangeRate er3 = new ExchangeRate("영국",1628.24,"파운드");
        ExchangeRate er4 = new ExchangeRate("유로",1414.62,"유로");
        ExchangeRate er5 = new ExchangeRate("스위스",1439.08,"프랑");
        ExchangeBank eb = new ExchangeBank();
        eb.add(er1.getCountryName(),er1.getExchangeRate(),er1.getCurrencyUnit());
        eb.add(er2.getCountryName(),er2.getExchangeRate(),er2.getCurrencyUnit());
        eb.add(er3.getCountryName(),er3.getExchangeRate(),er3.getCurrencyUnit());
        eb.add(er4.getCountryName(),er4.getExchangeRate(),er4.getCurrencyUnit());
        eb.add(er5.getCountryName(),er5.getExchangeRate(),er5.getCurrencyUnit());

        double price2 =eb.exchange(price,from_Nation,to_Nation);
        ExchangeRate from_Nation_key = eb.findExchangeRate(from_Nation);
        ExchangeRate to_Nation_key = eb.findExchangeRate(to_Nation);






        System.out.printf("%s: %.2f %s --> %s: %.2f %s",from_Nation, price,from_Nation_key, to_Nation, price2, to_Nation_key);


    }
}
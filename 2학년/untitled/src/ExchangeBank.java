public class ExchangeBank {
    private ExchangeRate[] rate; // ExchangeRate 객체를 저장하는 배열
    private int count; // ExchangeRate 배열에 저장된 객체의 개수

    public ExchangeBank() {
        rate = new ExchangeRate[5];
        count = 0;
    }

    // ExchangeRate 객체를 rate 배열에 추가하는 메서드
    public void add(String countryName, double exchangeRate, String currencyUnit) {
        if (count < 5) {
            rate[count] = new ExchangeRate(countryName, exchangeRate, currencyUnit);
        } else {
            // 6개 이상 추가하는 경우, 새로운 배열을 생성하여 기존 배열의 요소를 복사하고 추가 객체를 저장
            ExchangeRate[] newRate = new ExchangeRate[count + 1];
            for (int i = 0; i < count; i++) {
                newRate[i] = rate[i];
            }
            newRate[count] = new ExchangeRate(countryName,exchangeRate,currencyUnit);
            rate = newRate;
        }
        count++;
    }

    // from 국가의 금액을 to 국가의 통화로 환전하고 환전된 금액을 반환하는 메서드
    public double exchange(double amount, String from, String to) {
        ExchangeRate fromRate = findExchangeRate(from);
        ExchangeRate toRate = findExchangeRate(to);
        if (fromRate == null || toRate == null) {
            return 0.0;
        }
        double fromExchangeRate = fromRate.getExchangeRate();
        double toExchangeRate = toRate.getExchangeRate();
        double exchangedAmount = amount * fromExchangeRate / toExchangeRate;
        return exchangedAmount;
    }

    // name 국가의 ExchangeRate 객체를 rate 배열에서 찾아서 반환하는 메서드
    public ExchangeRate findExchangeRate(String name) {
        for (int i = 0; i < count; i++) {
            if (rate[i].getCountryName().equals(name)) {
                return rate[i];
            }
        }
        return null;
    }



}

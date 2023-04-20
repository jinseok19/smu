public class ExchangeRate {
    private String countryName; // 국가 이름
    private String currencyUnit; // 화폐 단위
    private double exchangeRate; // 한국 원화 대비 환율

    public ExchangeRate(String countryName,   double exchangeRate, String currencyUnit) {
        this.countryName = countryName;
        this.exchangeRate = exchangeRate;
        this.currencyUnit = currencyUnit;
    }

    public String getCountryName() {

        return countryName;
    }

    public String getCurrencyUnit() {

        return currencyUnit;
    }

    public double getExchangeRate() {

        return exchangeRate;
    }

    public String toString() {
        return " " + currencyUnit;
    }
}

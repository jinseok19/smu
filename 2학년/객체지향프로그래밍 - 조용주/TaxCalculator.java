import java.util.Scanner;

public class TaxCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 근로 소득 입력 받기
        System.out.print("근로 소득을 입력하세요: ");
        int income = scanner.nextInt();

        // 공제 대상 여부 확인

        System.out.print("신용카드 사용 금액을 입력하세요: ");
        int creditCardExpense = scanner.nextInt();

        System.out.print("전통시장 사용 금액을 입력하세요: ");
        int traditionalMarketExpense = scanner.nextInt();

        System.out.print("교통비 사용 금액을 입력하세요: ");
        int transportationExpense = scanner.nextInt();

        System.out.print("도서/공연 사용 금액을 입력하세요: ");
        int bookPerformanceExpense = scanner.nextInt();

        int deduction = 0;
        int deduction_book = 0;

        // 공제 대상인 경우
        int totalExpense = creditCardExpense + traditionalMarketExpense + transportationExpense + bookPerformanceExpense;

        if (totalExpense > income * 0.25) {
            deduction += (int) ((creditCardExpense - income * 0.25) * 0.15);
            deduction += (int) (traditionalMarketExpense * 0.3);
            deduction += (int) (transportationExpense * 0.3);
            // 연간 총 급여액 7000만원 이하 근로 소득자만 공제 가능
            if (income <= 70000000){
                deduction_book += (int) (bookPerformanceExpense * 0.3);
                if(deduction_book > 1000000){
                    deduction += 1000000;
                }
                else{
                    deduction += deduction_book;
                }
            }

        }


        // 누진 공제 계산
        int taxableIncome = income - deduction;
        int tax = 0;

        if (taxableIncome <= 14000000) {
            tax = (int) (taxableIncome * 0.06);
        } else if (taxableIncome <= 50000000) {
            tax = (int) (taxableIncome * 0.15 - 1260000);
        } else if (taxableIncome <= 88000000) {
            tax = (int) (taxableIncome * 0.24 - 5760000);
        } else if (taxableIncome <= 150000000) {
            tax = (int) (taxableIncome * 0.35 - 15440000);
        } else if (taxableIncome <= 300000000) {
            tax = (int) (taxableIncome * 0.38 - 19940000);
        } else {
            tax = (int) (taxableIncome * 0.4 - 25940000);
        }

        System.out.printf("근로 소득세는 %d원입니다.\n", tax);
    }
}

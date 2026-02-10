import java.util.Objects;

class Rational {
    private final int numerator;
    private final int denominator;

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw new IllegalArgumentException("Denominator cannot be zero.");
        }
        int commonDivisor = gcd(Math.abs(numerator), Math.abs(denominator));
        int sign = (denominator < 0) ? -1 : 1;
        this.numerator = (sign * numerator) / commonDivisor;
        this.denominator = (sign * denominator) / commonDivisor;
    }

    int getNumerator() { return numerator; }
    int getDenominator() { return denominator; }

    // Métodos de soma, subtração, multiplicação e divisão (mantê-los como estão)
    Rational add(Rational other) { return new Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator); }
    Rational subtract(Rational other) { return new Rational(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator); }
    Rational multiply(Rational other) { return new Rational(numerator * other.numerator, denominator * other.denominator); }
    Rational divide(Rational other) { return new Rational(numerator * other.denominator, other.numerator * denominator); }
    Rational abs() { return new Rational(Math.abs(numerator), Math.abs(denominator)); }

    /**
     * Exponenciação para potência inteira: r^n
     */
    Rational pow(int n) {
        int m = Math.abs(n);
        int newNumerator = (int) Math.pow(numerator, m);
        int newDenominator = (int) Math.pow(denominator, m);
        return (n >= 0) ? new Rational(newNumerator, newDenominator) : new Rational(newDenominator, newNumerator);
    }

    
    double exp(double base) {
        // x^(a/b) é o mesmo que Math.pow(x, a/b)
        //
        return Math.pow(base, (double) numerator / denominator);
    }

    private int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof Rational)) return false;
        Rational other = (Rational) obj;
        return numerator == other.numerator && denominator == other.denominator;
    }

    @Override
    public int hashCode() { return Objects.hash(numerator, denominator); }
}
import java.util.Objects;

class ComplexNumber {
    private final double real;
    private final double imaginary;

    ComplexNumber(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }

    double getReal() {
        return real;
    }

    double getImaginary() {
        return imaginary;
    }

    double abs() {
        return Math.hypot(real, imaginary);
    }

    ComplexNumber conjugate() {
        return new ComplexNumber(real, -imaginary);
    }

    ComplexNumber add(ComplexNumber other) {
        return new ComplexNumber(real + other.real, imaginary + other.imaginary);
    }

    ComplexNumber subtract(ComplexNumber other) {
        return new ComplexNumber(real - other.real, imaginary - other.imaginary);
    }

    ComplexNumber multiply(ComplexNumber other) {
        
        // (a*c - b*d)
        double newReal = Math.fma(real, other.real, -(imaginary * other.imaginary));
        // (b*c + a*d)
        double newImaginary = Math.fma(imaginary, other.real, real * other.imaginary);
        return new ComplexNumber(newReal, newImaginary);
    }

    ComplexNumber divide(ComplexNumber other) {
        double d = Math.fma(other.real, other.real, other.imaginary * other.imaginary);
        // (a*c + b*d) / d
        double newReal = Math.fma(real, other.real, imaginary * other.imaginary) / d;
        // (b*c - a*d) / d
        double newImaginary = Math.fma(imaginary, other.real, -real * other.imaginary) / d;
        return new ComplexNumber(newReal, newImaginary);
    }

    
    ComplexNumber exponentialOf() {
        double expA = Math.exp(real);
        return new ComplexNumber(
            expA * Math.cos(imaginary),
            expA * Math.sin(imaginary)
        );
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof ComplexNumber)) return false;
        ComplexNumber other = (ComplexNumber) obj;
        return Double.compare(real, other.real) == 0 && 
               Double.compare(imaginary, other.imaginary) == 0;
    }

    @Override
    public int hashCode() {
        return Objects.hash(real, imaginary);
    }
}
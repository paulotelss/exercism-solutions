public class Greeter { // Mude de HelloWorld para Greeter
    public String getGreeting() { // O teste espera este método
        return "Hello, World!";
    }

    // Se quiser manter o main para testes locais, tudo bem:
    public static void main(String[] args) {
        System.out.println("Hello, World!");
    }
}
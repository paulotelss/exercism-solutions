import java.util.Collection;
import java.util.ArrayList;
import java.util.List;

class CustomSet<T> {
    private final List<T> elements;

    CustomSet() {
        this.elements = new ArrayList<>();
    }

    CustomSet(Collection<T> data) {
        this();
        if (data != null) {
            data.forEach(this::add);
        }
    }

    boolean isEmpty() {
        return elements.isEmpty();
    }

    boolean contains(T element) {
        return elements.contains(element);
    }

    boolean add(T element) {
        if (!contains(element)) {
            return elements.add(element);
        }
        return false;
    }

    
    boolean isSubset(CustomSet<T> other) {
        // Se o outro está vazio, ele é subconjunto de qualquer coisa.
        if (other.isEmpty()) {
            return true;
        }
        // Se o outro não está vazio, mas este está, não pode ser subconjunto.
        if (this.isEmpty()) {
            return false;
        }
        // Verifica se TODOS os elementos de 'other' estão presentes em 'this'.
        for (T item : other.elements) {
            if (!this.contains(item)) {
                return false;
            }
        }
        return true;
    }

    boolean isDisjoint(CustomSet<T> other) {
        for (T item : this.elements) {
            if (other.contains(item)) {
                return false;
            }
        }
        return true;
    }

    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (!(obj instanceof CustomSet)) return false;
        CustomSet<T> other = (CustomSet<T>) obj;
        // Dois conjuntos são iguais se têm o mesmo tamanho e um contém o outro.
        return this.elements.size() == other.elements.size() && this.isSubset(other);
    }

    CustomSet<T> getIntersection(CustomSet<T> other) {
        CustomSet<T> result = new CustomSet<>();
        for (T item : this.elements) {
            if (other.contains(item)) {
                result.add(item);
            }
        }
        return result;
    }

    CustomSet<T> getUnion(CustomSet<T> other) {
        CustomSet<T> result = new CustomSet<>(this.elements);
        for (T item : other.elements) {
            result.add(item);
        }
        return result;
    }

    CustomSet<T> getDifference(CustomSet<T> other) {
        CustomSet<T> result = new CustomSet<>();
        for (T item : this.elements) {
            if (!other.contains(item)) {
                result.add(item);
            }
        }
        return result;
    }
}
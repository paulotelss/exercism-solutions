import java.util.*;

class Tree {
    private final String label;
    private final List<Tree> children;

    private Tree(String label, List<Tree> children) {
        this.label = label;
        this.children = new ArrayList<>(children);
    }

    public static Tree of(String label) {
        return new Tree(label, Collections.emptyList());
    }

    public static Tree of(String label, List<Tree> children) {
        return new Tree(label, children);
    }

    public String getLabel() {
        return label;
    }

    public List<Tree> getChildren() {
        return children;
    }

    public Tree fromPov(String from) {
        List<Tree> path = findPathToRoot(this, from);
        if (path == null) {
            throw new UnsupportedOperationException("Tree could not be reoriented");
        }

        // Inverte a árvore ao longo do caminho encontrado
        for (int i = path.size() - 1; i > 0; i--) {
            Tree current = path.get(i);
            Tree parent = path.get(i - 1);
            
            parent.children.remove(current);
            current.children.add(parent);
        }
        
        return path.get(path.size() - 1);
    }

    public List<String> pathTo(String from, String to) {
        Tree rootPov;
        try {
            rootPov = fromPov(from);
        } catch (UnsupportedOperationException e) {
            // Se falhar ao reorientar (porque 'from' não existe), 
            // o teste exige esta mensagem específica.
            throw new UnsupportedOperationException("No path found");
        }

        List<Tree> pathNodes = findPathToRoot(rootPov, to);
        
        if (pathNodes == null) {
            throw new UnsupportedOperationException("No path found");
        }

        return pathNodes.stream()
                .map(Tree::getLabel)
                .collect(java.util.stream.Collectors.toList());
    }

    /**
     * DFS para encontrar o caminho da raiz até o nó alvo.
     * Retorna uma lista de nós representando o caminho.
     */
    private List<Tree> findPathToRoot(Tree current, String target) {
        if (current.label.equals(target)) {
            List<Tree> path = new ArrayList<>();
            path.add(current);
            return path;
        }

        for (Tree child : current.children) {
            List<Tree> path = findPathToRoot(child, target);
            if (path != null) {
                path.add(0, current);
                return path;
            }
        }
        return null;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Tree tree)) return false;
        return Objects.equals(label, tree.label) &&
               children.size() == tree.children.size() &&
               new HashSet<>(children).equals(new HashSet<>(tree.children));
    }

    @Override
    public int hashCode() {
        return Objects.hash(label, children);
    }
}
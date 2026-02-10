import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class LogLevels {

    
    private static final Pattern LOG_PATTERN = Pattern.compile("\\[(?<level>\\w+)\\]:\\s*(?<message>.*)");

    public static String message(String logLine) {
        Matcher matcher = LOG_PATTERN.matcher(logLine);
        if (matcher.find()) {
            // .trim() remove \r\n e espaços extras conforme solicitado
            return matcher.group("message").trim();
        }
        return "";
    }

    public static String logLevel(String logLine) {
        Matcher matcher = LOG_PATTERN.matcher(logLine);
        if (matcher.find()) {
            // Retorna o nível em minúsculas
            return matcher.group("level").toLowerCase();
        }
        return "";
    }

    public static String reformat(String logLine) {
        // Combinamos os métodos anteriores para criar o novo formato
        return String.format("%s (%s)", message(logLine), logLevel(logLine));
    }
}